<?php
/**
 * Created by PhpStorm.
 * User: cyris
 * Date: 2018/12/5
 * Time: 下午9:18
 */
session_start();

require ("../conn.php");

if (isset($_SESSION['login'])){
    if ($_SESSION['utp']==="student") {echo "您无权访问此页面"; exit;}
    if ($_SESSION['login']!==1) {echo "You must <a href=\"../index.php\">login</a> first";}
}
else {
    echo "You must <a href=\"../index.php\">login</a> first";
    exit;
}

@$bookid = $_POST['bookid'];
@$stuid = $_POST['stuid'];
@$date = $_POST['datetime'];
@$operation = $_POST['operation'];

$local_date = date ( "Y-m-d" );

if (!$bookid or !$stuid or !$operation ){
    echo "Plz fill the form";
    exit;
}

$sql = "SELECT Sname FROM STUDENT WHERE Sno= :uid";
$result = $pdo -> prepare($sql);
$result -> execute(array('uid' => $stuid));
$row = $result->fetch();
if (!$row[0]) {echo "【借阅失败】该学生未办理借书证，无法借阅"; exit;}

if ($operation === 'borrow'){
    if ($date > $local_date){
        echo "日期设置错误";
        exit;
    }

    if (!$date) {
        echo "请填写借阅日期";
        exit;
    }

    $sql = "SELECT Bsno FROM BOOKS WHERE Bno = :bookid";
    $result = $pdo -> prepare($sql);
    $result -> execute(array('bookid' => $bookid));
    $row = $result->fetch();
    if ($row[0]) {echo "【借阅失败】本书已经被借阅"; exit;}

    $sql = "SELECT Sbknm FROM STUDENT WHERE Sno = :sno";
    $result = $pdo -> prepare($sql);
    $result -> execute(array('sno' => $stuid));
    $row = $result->fetch();
    if ($row[0] >= 5) {echo "【借阅失败】该同学已借满五本书，请归还图书后再进行新的借阅"; exit;}

    else {
        $bdt = date("Y-m-d", strtotime("+1 months", strtotime($date)));
        try {
            $sql = "UPDATE `BOOKS` SET `Bct`=Bct+1,`Bsno`= :sno, `Bdt`= :dt WHERE Bno= :bno;";
            $result = $pdo -> prepare($sql);
            $result -> execute(array('dt' => $bdt, 'sno' => $stuid, 'bno' => $bookid));

            $sql = "UPDATE `STUDENT` SET `Sbknm`=Sbknm+1 WHERE Sno= :sno";
            $result = $pdo -> prepare($sql);
            $result -> execute(array('sno' => $stuid));

            echo "【借阅成功】";
        }
        catch (Exception $e) {echo "插入失败：".$e->getMessage(); exit;}
        exit;
    }
}
elseif ($operation === 'return'){
    $sql = "SELECT Bsno FROM BOOKS WHERE Bno = :bookid";
    $result = $pdo -> prepare($sql);
    $result -> execute(array('bookid' => $bookid));
    $row = $result->fetch();
    if (!$row[0] or $row[0]!==$stuid) {
        echo "未查到该条借阅记录";
        exit;
    }

    try {
        $sql = "UPDATE `BOOKS` SET `Bsno`=NULL,`Bdt`=NULL WHERE Bno=:bno";
        $result = $pdo -> prepare($sql);
        $result -> execute(array('bno' => $bookid));

        $sql = "UPDATE `STUDENT` SET `Sbknm`=Sbknm-1 WHERE Sno= :sno";
        $result = $pdo -> prepare($sql);
        $result -> execute(array('sno' => $stuid));

        echo "【归还成功】";
    }
    catch (Exception $e) {echo "归还失败：".$e->getMessage(); exit;}
    exit;



}

else { exit; }
