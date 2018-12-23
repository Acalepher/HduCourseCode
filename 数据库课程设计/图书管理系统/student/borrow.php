<?php
/**
 * Created by PhpStorm.
 * User: cyris
 * Date: 2018/12/3
 * Time: 上午11:14
 */

session_start();

require ("../conn.php");

if (isset($_SESSION['login']) and $_SESSION['login']===1){
    if ($_SESSION['utp']==="teacher") {echo "您无权访问此页面"; exit;}
}
else {
    echo "You must <a href=\"../index.php\">login</a> first";
    exit;
}

$uid = $_SESSION['uid'];

function searchSelf($f_pdo, $f_uid){
    $local_date = date ( "Y-m-d" );
    $uid = $f_uid;
    $sql = "SELECT Bno, Bname, Bauth, Bph, Btag, Bdt FROM STUDENT, BOOKS WHERE Sno = Bsno AND Sno = :userid";
    $results = $f_pdo -> prepare($sql);
    $results -> execute(array('userid' => $uid));
    $rows = $results->fetchAll();
    if ($rows) {
        foreach ($rows as $row) {
            print_r("书籍号：".$row[0]."<br/>"." 书名："."《".$row[1]."》"."<br/>"." 作者：".$row[2]."<br/>"." 出版社：".$row[3]."<br/>"." 类别：".$row[4]."<br/>"." 到期时间：".$row[5]."<br/>");
            if ($row[5] < $local_date) {
                echo "【通知】已逾期，请续借或及时归还<br/><br/>";
            }
        }
    }
    else {
        print_r("您未借阅任何书籍");
    }
}

searchSelf($pdo, $uid);