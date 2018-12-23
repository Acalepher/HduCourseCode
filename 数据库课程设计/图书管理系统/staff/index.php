<?php
/**
 * Created by PhpStorm.
 * User: cyris
 * Date: 2018/12/3
 * Time: 上午11:45
 */

session_start();
require ("../conn.php");

if (isset($_SESSION['login'])){
    if ($_SESSION['utp']==="student") {echo "您无权访问此页面"; exit;}
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
    <title>管理员页面</title>
</head>
<link rel="stylesheet" type="text/css" href="../stylesheets/staff-index.css">
<body>
    <div id="main">
        <div class="head">
            管理员页面
        </div>
        <div class="body">
            <div class="switch-part">
                <div id="switch-part__btn1" onclick="f(1)">图书录入</div>
                <div id="switch-part__btn2" onclick="f(2)">借书证办理</div>
                <div id="switch-part__btn3" onclick="f(3)">借书／续借、还书</div>
                <div id="switch-part__btn4" onclick="f(4)">图书信息查询</div>
                <div id="switch-part__btn5" onclick="f(5)">借书统计与超时信息查询</div>
            </div>
            <div class="operation-part">
                <div id="op-part__1" class="op-part">
                    <div class="p-title">新进图书录入</div>
                    <div class="op1-form staff-form">
                        <form class="form-box">
                            <div>
                                <span>图书编号：</span>
                                <input name="book-id" type="text" placeholder="图书编号" maxlength="8">
                            </div>
                            <div>
                                <span>图书名称：</span>
                                <input name="book-name" type="text" placeholder="图书名称" maxlength="20">
                            </div>
                            <div>
                                <span>作者：</span>
                                <input name="book-auth" type="text" placeholder="作者" maxlength="8">
                            </div>
                            <div>
                                <span>出版社：</span>
                                <input name="book-pb" type="text" placeholder="出版社编号" maxlength="8">
                            </div>
                            <div>
                                <span>类别：</span>
                                <input name="book-tp" type="text" placeholder="图书类别" maxlength="8">
                            </div>
                            <div class="form-button">
                                <button onclick="showFeedback(1,'addbook.php',1)" class="form-button__sub" type="button">添加</button>
                            </div>
                        </form>
                    </div>
                    <div class="box-feedback" id="box-feedback__1"></div>
                </div>
                <div id="op-part__2" class="op-part">
                    <div class="p-title">借书证办理</div>
                    <div class="op2-form staff-form">
                        <form class="form-box">
                            <div>
                                <span>学号：</span>
                                <input name="stu-id" type="text" placeholder="学号" maxlength="8">
                            </div>
                            <div>
                                <span>学生姓名：</span>
                                <input name="stu-name" type="text" placeholder="学生姓名" maxlength="10">
                            </div>
                            <div>
                                <span>密码：</span>
                                <input name="stu-pswd" type="password" placeholder="密码" maxlength="16">
                            </div>
                            <div>
                                <span>电话：</span>
                                <input name="stu-tel" type="text" placeholder="电话" maxlength="11">
                            </div>
                            <div class="form-button">
                                <button onclick="showFeedback(2,'addstu.php',2)" class="form-button__sub" type="button">添加</button>
                            </div>
                        </form>
                    </div>
                    <div class="box-feedback" id="box-feedback__2"></div>
                </div>
                <div id="op-part__3" class="op-part">
                    <div class="p-title">借书／续借、还书</div>
                    <div class="op3-form staff-form">
                        <form class="form-box">
                            <div>
                                <span>书籍编号</span>
                                <input name="bookid" type="text" placeholder="请输入书籍编号">
                            </div>
                            <div>
                                <span>学生学号</span>
                                <input name="stuid" type="text" placeholder="请输入学号">
                            </div>
                            <div>
                                <span>借阅时间</span>
                                <input name="datetime" type="date" placeholder="请输入日期">
                            </div>
                            <br/>
                            <div>
                                <span>借书／续借</span>
                                <input name="operation" type="radio" value="borrow" checked>
                            </div>
                            <div>
                                <span>还书</span>
                                <input name="operation" type="radio" value="return">
                            </div>
                        </form>
                        <div class="form-button">
                            <button onclick="showFeedback(3,'opbook.php',3)" class="form-button__sub" type="button">提交</button>
                        </div>
                    </div>
                    <div class="box-feedback" id="box-feedback__3"></div>
                </div>
                <div id="op-part__4" class="op-part">
                    <div class="p-title">图书信息查询</div>
                    <div class="op4-form staff-form">
                        <form class="form-box">
                            <div><input name="feed" type="text" placeholder="请输入查询内容" maxlength="20"></div>
                            <div><input type="radio" name="bookinfo" value="bookname" checked> 按书名查找</div>
                            <div><input type="radio" name="bookinfo" value="bookid"> 按书号查找</div>
                            <div><input type="radio" name="bookinfo" value="bookauth"> 按作者查找</div>
                            <div><input type="radio" name="bookinfo" value="bookph"> 按出版社查找</div>
                            <div> <input type="radio" name="bookinfo" value="booktp"> 按类别查找</div>
                        </form>
                        <div class="form-button">
                            <button onclick="showFeedback(4,'searchbook.php',4)" class="form-button__sub" type="button">查询</button>
                        </div>
                    </div>
                    <div class="box-feedback" id="box-feedback__4"></div>
                </div>
                <div id="op-part__5" class="op-part">
                    <div class="p-title">借书统计与超时信息查询</div>
                    <div class="op5-form staff-form">
                        <form class="form-box">
                        </form>
                        <div class="form-button">
                            <button onclick="showFeedback(5,'countbook.php',5)" class="form-button__sub" type="button">查询</button>
                        </div>
                    </div>
                    <div class="box-feedback" id="box-feedback__5"></div>
                </div>
            </div>
        </div>
        <div class="exit">
            <a href="../logout.php" >Exit</a>
        </div>
    </div>
</body>
<script>
    function f(num) {
        let op_parts = document.getElementsByClassName("op-part");
        let real_id = "op-part__" + num;
        for (let i=0; i<op_parts.length; i++){
            if (op_parts[i] === document.getElementById(real_id)){
                op_parts[i].style.display = 'block';
            }
            else {
                op_parts[i].style.display = 'none';
            }
        }
    }
    function showFeedback(form_num, t_php, fdbk_num){
        let xmlhttp = new XMLHttpRequest();
        let elements = document.getElementsByClassName("form-box")[form_num-1];
        let formData = new FormData(elements);
        let fdbk = "box-feedback__" + fdbk_num;
        t_php = "./" + t_php;
        xmlhttp.onreadystatechange = function()
        {
            if (xmlhttp.readyState===4 && xmlhttp.status===200)
            {
                document.getElementById(fdbk).innerHTML=xmlhttp.responseText;
            }
        };
        xmlhttp.open("POST",t_php);
        xmlhttp.send(formData);
    }
</script>
</html>
