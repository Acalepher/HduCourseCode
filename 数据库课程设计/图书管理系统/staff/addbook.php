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

@$bookid = $_POST["book-id"];
@$bookname = $_POST["book-name"];
@$bookauth = $_POST["book-auth"];
@$bookpb = $_POST["book-pb"];
@$booktp = $_POST["book-tp"];

if (!$bookid or !$bookname or !$bookauth or !$bookpb or !$booktp) {echo "Plz fill out the form!"; exit;}
try {
    $sql = "INSERT INTO `BOOKS`(`Bno`, `Bname`, `Bauth`, `Bph`, `Btag`) VALUES (:id,:name,:auth,:pb,:tag)";
    $exc = $pdo->prepare($sql);
    $exc->execute(array('id' => $bookid, 'name' => $bookname, 'auth' => $bookauth, 'pb' => $bookpb, 'tag' => $booktp));
    echo "Add book success: "."<br/>"."《".$bookname."》";

}catch (PDOException $e){
    echo "Something wrong";
}