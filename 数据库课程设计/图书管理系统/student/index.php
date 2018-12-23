<?php
/**
 * Created by PhpStorm.
 * User: cyris
 * Date: 2018/11/25
 * Time: 下午3:05
 */
session_start();
require ("../conn.php");

if (isset($_SESSION['login'])){
    if ($_SESSION['utp']==="teacher") {echo "您无权访问此页面"; exit;}
    if ($_SESSION['login']===1) {echo "Welcome, " . $_SESSION['uid'];}
}
else {
    echo "You must <a href=\"../index.php\">login</a> first";
    exit;
}
?>

<!DOCTYPE html>
<html>
<head>
    <meta charset="UTF-8">
    <title>学生管理页面</title>
</head>
<link rel="stylesheet" type="text/css" href="../stylesheets/student-index.css">
<body>
    <div class="main">
        <div class="head">
            <div>学生管理页面</div>
        </div>
        <div class="body">
            <div class="part__borrow-info">
                <button onclick="showFeedback_Self()" id="borrow-info__btn"  type="button">个人借阅信息查询</button>
                <div id="borrow-info__result"></div>
            </div>
            <div class="part__search-book">
                <div class="search-book__title">查找图书</div>
                <form class="search-book__form">
                    <input class="info-bk-t" name="feed" type="text" placeholder="请输入查询内容" maxlength="20">
                    <input class="info-bk" type="radio" name="bookinfo" value="bookname" checked> 按书名查找
                    <input class="info-bk" type="radio" name="bookinfo" value="bookid"> 按书号查找
                    <input class="info-bk" type="radio" name="bookinfo" value="bookauth"> 按作者查找
                    <input class="info-bk" type="radio" name="bookinfo" value="bookph"> 按出版社查找
                    <input class="info-bk" type="radio" name="bookinfo" value="booktp"> 按类别查找
                </form>
                <div class="search-book__button">
                    <button onclick="showFeedback_Book()" id="search-button" type="button">查询</button>
                </div>
                <div id="search-book__result"></div>
            </div>
        </div>
        <div class="exit">
            <a href="../logout.php" >Exit</a>
        </div>
    </div>
</body>
<script>
    function showFeedback_Book()
    {
        let xmlhttp = new XMLHttpRequest();
        let elements = document.getElementsByClassName("search-book__form")[0];
        let formData = new FormData(elements);
        xmlhttp.onreadystatechange=function()
        {
            if (xmlhttp.readyState===4 && xmlhttp.status===200)
            {
                document.getElementById("search-book__result").innerHTML=xmlhttp.responseText;

            }
        };
        xmlhttp.open("POST","./search.php");
        xmlhttp.send(formData);
    }
    function showFeedback_Self() {
        let xmlhttp = new XMLHttpRequest();
        xmlhttp.onreadystatechange=function () {
            if (xmlhttp.readyState===4 && xmlhttp.status===200)
            {
                document.getElementById("borrow-info__result").innerHTML=xmlhttp.responseText;
            }
        };
        xmlhttp.open("POST","./borrow.php");
        xmlhttp.send();
    }
</script>
</html>