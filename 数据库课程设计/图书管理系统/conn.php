<?php
/**
 * Created by PhpStorm.
 * User: cyris
 * Date: 2018/11/19
 * Time: 上午11:55
 */
$user = 'root';
$password = 'root';
$db = 'library';
$host = '127.0.0.1';
$port = 8889;

try {
    $pdo = new PDO("mysql:host=$host; port=$port; dbname=$db", $user, $password);
    $pdo -> setAttribute(PDO::ATTR_EMULATE_PREPARES, false);
}
catch (PDOException $e) {
    echo 'Connection failed: ' . $e->getMessage();
}

