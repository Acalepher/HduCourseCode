<?php
/**
 * Created by PhpStorm.
 * User: cyris
 * Date: 2018/12/8
 * Time: 下午11:11
 */

session_start();

if (isset($_SESSION['login'])){
    if ($_SESSION['utp']==="student") {echo "您无权访问此页面"; exit;}
    if ($_SESSION['login']!==1) {echo "You must <a href=\"../index.php\">login</a> first";}
}
else {
    echo "You must <a href=\"../index.php\">login</a> first";
    exit;
}

require ("../conn.php");

$local_date = date ( "Y-m-d" );

try {
    echo "查询时间：".$local_date."<br/><br/>";
    echo "【借阅排行榜（前五）】"."<br/><br/>";

    $sql = "SELECT Bno, Bname, Bauth, Bph, Btag, Bct FROM BOOKS ORDER BY Bct DESC LIMIT 5";
    $results = $pdo -> prepare($sql);
    $results -> execute();
    $rows = $results -> fetchAll();
    if ($rows) {
        foreach ($rows as $row) {
            print_r("序号：".$row[0]."<br/>"." 书名："."《".$row[1]."》"."<br/>"." 作者：".$row[2]."<br/>"." 出版社：".$row[3]."<br/>"." 类别：".$row[4]."<br>"." 借阅人数：".$row[5]."<br><br/>");
        }
    }
    else {
        print_r("No such book");
    }

    echo "【逾期未还】"."<br/><br/>";
    $sql = "SELECT Bno, Bname, Bauth, Bph, Btag, Bdt, Bsno, Sname FROM BOOKS, STUDENT WHERE Bsno = Sno AND Bdt < :localdate";
    $results = $pdo->prepare($sql);
    $results->execute(array('localdate' => $local_date));
    $rows = $results -> fetchAll();
    if ($rows) {
        foreach ($rows as $row) {
            print_r("序号：".$row[0]."<br/>"." 书名："."《".$row[1]."》"."<br/>"." 作者：".$row[2]."<br/>"." 出版社：".$row[3]."<br/>"." 类别：".$row[4]."<br>"." 借阅到期时间：".$row[5]."<br>"." 借阅者学号：".$row[6]."<br/>"." 借阅者姓名：".$row[7]."<br/><br/>");
        }
    }
    else {
        print_r("No such book");
    }

    exit;

}catch (PDOException $e){
    echo "Something wrong";
}