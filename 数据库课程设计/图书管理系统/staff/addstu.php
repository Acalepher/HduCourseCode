<?php
/**
 * Created by PhpStorm.
 * User: cyris
 * Date: 2018/12/5
 * Time: 下午9:18
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

@$stuid = $_POST["stu-id"];
@$stuname = $_POST["stu-name"];
@$stupswd = $_POST["stu-pswd"];
@$stutel = $_POST["stu-tel"];

if (!$stuid or !$stuname or !$stupswd or !$stutel) {echo "Plz fill out the form!"; exit;}
try {
    $sql = "INSERT INTO `STUDENT`(`Sno`, `Sname`, `Spwd`, `Stel`) VALUES (:id,:name,:pswd,:tel)";
    $exc = $pdo->prepare($sql);
    $exc->execute(array('id' => $stuid, 'name' => $stuname, 'pswd' => $stupswd, 'tel' => $stutel));
    echo "Add student info success: "."<br/>".$stuname;

}catch (PDOException $e){
    echo "Something wrong";
}