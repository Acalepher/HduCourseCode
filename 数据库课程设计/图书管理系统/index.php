<?php
session_start();
if (isset($_SESSION['login'])){
    if ($_SESSION['login']===1) {
        if (@$_SESSION['utp']==="student"){
            header('Location: ./student/index.php'); exit;
        }
        if (@$_SESSION['utp']==="teacher"){
            header('Location: ./staff/index.php'); exit;
        }
    }
}
?>

<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="UTF-8">
        <title>神奇海螺图书馆</title>
    </head>
    <link rel="stylesheet" type="text/css" href="./stylesheets/index.css">
    <body>
        <div class="main">
            <form class="form-box">
                <div class="box-body">
                    <div class="box-title">
                        <h2>神奇海螺图书管理系统</h2>
                        <h3>"为什么不问问神奇海螺呢？"</h3>
                    </div>
                    <div class="box-input">
                        <div class="box-input__info">
                            <span>账号：</span>
                            <input id="username" name="userid" type="text" placeholder="学号／工号" maxlength="8">
                        </div>
                        <div class="box-input__info">
                            <span>密码：</span>
                            <input id="password" name="password" type="password" placeholder="密码" maxlength="16">
                        </div>
                    </div>
                    <div class="box-choice">
                        <input class="info-idt" type="radio" name="identity" value="student" checked> Student
                        <input class="info-idt" type="radio" name="identity" value="teacher"> Librarian
                    </div>
                    <div class="box-button">
                        <button onclick="showFeedback()" id="box-button__sub" type="button">登陆</button>
                    </div>
                    <div class="box-feedback">
                        <div id="box-feedback__text"></div>
                    </div>
                </div>
            </form>
        </div>
    </body>
    <script>
        function showFeedback()
        {
            let xmlhttp = new XMLHttpRequest();
            let elements = document.getElementsByClassName("form-box")[0];
            let formData = new FormData(elements);
            let identity = document.getElementsByClassName("info-idt");
            xmlhttp.onreadystatechange=function()
            {
                if (xmlhttp.readyState===4 && xmlhttp.status===200)
                {
                    document.getElementById("box-feedback__text").innerHTML=xmlhttp.responseText;
                    if (xmlhttp.responseText === "Login Success\n\n") {
                        for (i=0; i<identity.length; i++){
                            if (identity[i].checked) {
                                var go = identity[i];
                                break;
                            }
                        }
                        if (go.value === "student"){
                            setTimeout((window.location.replace("./student/index.php")), 4000);
                        }
                        else if (go.value === "teacher"){
                            setTimeout((window.location.replace("./staff/index.php")), 4000);
                        }
                        else {alert("Please fill out the form")}
                    }
                }
            };
            xmlhttp.open("POST","./login.php");
            xmlhttp.send(formData);
        }
    </script>
</html>
