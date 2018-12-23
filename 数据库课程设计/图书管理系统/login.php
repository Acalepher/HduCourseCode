<?php
/**
 * Created by PhpStorm.
 * User: cyris
 * Date: 2018/11/19
 * Time: 上午11:56
 */

session_start();

require_once ("./conn.php");
@$userid = $_POST['userid'];
@$password = $_POST['password'];
@$identity = $_POST['identity'];


if (!(isset($_POST['userid']) && isset($_POST['password']) && isset($_POST['identity']))) {
    echo "ohh, you need to fill out the whole form.";
    exit;
}

$_SESSION['uid']=$userid;
$_SESSION['utp']=$identity;

if ($_SESSION['utp']==="student"){
    $sql = "select Spwd from STUDENT where Sno = :userid ";
    $result = $pdo -> prepare($sql);
    $result -> execute(array('userid' => $userid));
    $row = $result->fetchColumn();

    if ($password !== $row) {
        $_SESSION['login']=0;
        echo "Wrong password";
    }
    else {
        $_SESSION['login']=1;
        echo "Login Success";
    }
}
if ($_SESSION['utp']==="teacher"){
    $sql = "select Apwd from ADMIN where Ano = :userid ";
    $result = $pdo -> prepare($sql);
    $result -> execute(array('userid' => $userid));
    $row = $result->fetchColumn();

    if ($password !== $row) {
        $_SESSION['login']=0;
        echo "Wrong password";
    }
    else {
        $_SESSION['login']=1;
        echo "Login Success";
    }
}

?>


