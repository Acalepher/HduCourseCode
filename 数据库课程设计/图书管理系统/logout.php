<?php
/**
 * Created by PhpStorm.
 * User: cyris
 * Date: 2018/12/3
 * Time: 上午12:02
 */
session_start();
session_unset();
session_destroy();

?>

<!DOCTYPE html>
<html>
<head>
	<title>注销登录</title>
</head>
<body>
<p align="center">已成功注销登录。</p>
<p align="center"><a href="./index.php">重新登录</a></p>
</body>
</html>