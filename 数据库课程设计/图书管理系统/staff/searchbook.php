<?php
/**
 * Created by PhpStorm.
 * User: cyris
 * Date: 2018/12/2
 * Time: 下午7:03
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

@$book_info = $_POST['bookinfo'];
@$feed = $_POST['feed'];

require ("../conn.php");

function searchByBookName($f_pdo, $book_info){
    $book_name = '%'.$book_info.'%';
    $sql = "SELECT BOOKS.* FROM BOOKS WHERE BOOKS.Bname LIKE :bookname";
    $results = $f_pdo -> prepare($sql);
    $results -> execute(array('bookname' => $book_name));
    $rows = $results->fetchAll();
    if ($rows) {
        foreach ($rows as $row) {
            print_r("序号：".$row[0]."<br/>"." 书名："."《".$row[1]."》"."<br/>"." 作者：".$row[2]."<br/>"." 出版社：".$row[3]."<br/>"." 类别：".$row[4]."<br>"." 借阅人数：".$row[5]."<br>"." 借阅者学号：".$row[6]."<br>"." 到期时间：".$row[7]."<br/><br/>");
        }
    }
    else {
        print_r("No such book");
    }
}

function searchByBookNo($f_pdo, $book_info){
    $book_no = $book_info;
    $sql = "SELECT BOOKS.* FROM BOOKS WHERE BOOKS.Bno = :bookname";
    $result = $f_pdo -> prepare($sql);
    $result -> execute(array('bookname' => $book_no));
    $row = $result -> fetch();
    if ($row) {
        print_r("序号：".$row[0]."<br/>"." 书名："."《".$row[1]."》"."<br/>"." 作者：".$row[2]."<br/>"." 出版社：".$row[3]."<br/>"." 类别：".$row[4]."<br>"." 借阅人数：".$row[5]."<br>"." 借阅者学号：".$row[6]."<br>"." 到期时间：".$row[7]."<br/><br/>");
    }
    else {
        print_r("No such book");
    }
}

function searchByBookAuth($f_pdo, $book_info){
    $book_auth = '%'.$book_info.'%';
    $sql = "SELECT BOOKS.* FROM BOOKS WHERE BOOKS.Bauth LIKE :auth";
    $results = $f_pdo -> prepare($sql);
    $results -> execute(array('auth' => $book_auth));
    $rows = $results -> fetchAll();
    if ($rows) {
        foreach ($rows as $row) {
            print_r("序号：".$row[0]."<br/>"." 书名："."《".$row[1]."》"."<br/>"." 作者：".$row[2]."<br/>"." 出版社：".$row[3]."<br/>"." 类别：".$row[4]."<br>"." 借阅人数：".$row[5]."<br>"." 借阅者学号：".$row[6]."<br>"." 到期时间：".$row[7]."<br/><br/>");
        }
    }
    else {
        print_r("No such book");
    }
}

function searchByBookPh($f_pdo, $book_info){
    $book_ph = '%'.$book_info.'%';
    $sql = "SELECT BOOKS.* FROM BOOKS WHERE BOOKS.Bph LIKE :ph";
    $results = $f_pdo -> prepare($sql);
    $results -> execute(array('ph' => $book_ph));
    $rows = $results -> fetchAll();
    if ($rows) {
        foreach ($rows as $row) {
            print_r("序号：".$row[0]."<br/>"." 书名："."《".$row[1]."》"."<br/>"." 作者：".$row[2]."<br/>"." 出版社：".$row[3]."<br/>"." 类别：".$row[4]."<br>"." 借阅人数：".$row[5]."<br>"." 借阅者学号：".$row[6]."<br>"." 到期时间：".$row[7]."<br/><br/>");
        }
    }
    else {
        print_r("No such book");
    }
}

function searchByBookType($f_pdo, $book_info){
    $book_type = '%'.$book_info.'%';
    $sql = "SELECT BOOKS.* FROM BOOKS WHERE BOOKS.Btag LIKE :tag";
    $results = $f_pdo -> prepare($sql);
    $results -> execute(array('tag' => $book_type));
    $rows = $results -> fetchAll();
    if ($rows) {
        foreach ($rows as $row) {
            print_r("序号：".$row[0]."<br/>"." 书名："."《".$row[1]."》"."<br/>"." 作者：".$row[2]."<br/>"." 出版社：".$row[3]."<br/>"." 类别：".$row[4]."<br>"." 借阅人数：".$row[5]."<br>"." 借阅者学号：".$row[6]."<br>"." 到期时间：".$row[7]."<br/><br/>");
        }
    }
    else {
        print_r("No such book");
    }
}

switch ($book_info) {
    case "bookname":
        searchByBookName($pdo, $feed); break;
    case "bookid":
        searchByBookNo($pdo, $feed); break;
    case "bookauth":
        searchByBookAuth($pdo, $feed); break;
    case "bookph":
        searchByBookPh($pdo, $feed); break;
    case "booktp":
        searchByBookType($pdo, $feed); break;
    default: echo "alie"; break;
}