# 图书借阅管理系统

## 数据库设计

### 学生信息表
学生学号（主） Sno
学生姓名      Sname
密码         Spwd
手机号        Stel
已借数量      Sbknm

### 管理员信息表
管理员编号（主）Ano
管理员名字    Aname
密码         Apwd
手机号        Atel

### 图书信息表
书号          Bno
书名          Bname
作者          Bauth
出版社         Bph
类别          Btag
借阅次数        Bct
借阅者学号      Bsno
到期时间        Bdt

#图书信息查询
SELECT BOOKS.*
FROM BOOKS
WHERE BOOKS.Bno LIKE '%2%'

SELECT BOOKS.*
FROM BOOKS
WHERE BOOKS.Bname LIKE '%镇%'

SELECT BOOKS.*
FROM BOOKS
WHERE BOOKS.Bauth LIKE 'P%'

SELECT BOOKS.*
FROM BOOKS
WHERE BOOKS.Bph LIKE '水母出版%'

SELECT BOOKS.*
FROM BOOKS
WHERE BOOKS.Btag LIKE '爱情%'



#本人借阅信息查询
SELECT Bno, Bname, Bauth, Bph, Btag, Bdt
FROM STUDENT, BOOKS
WHERE Sno=Bsno AND Sno='16272001'


#新进图书录入
INSERT INTO `BOOKS`(`Bno`, `Bname`, `Bauth`, `Bph`, `Btag`) VALUES ('3','致青春','辛咿唔','水母出版社','爱情')

#借书证办理
INSERT INTO `STUDENT`(`Sno`, `Sname`, `Spwd`, `Stel`) VALUES ('16272005','吴邪','272005','13800000005')

#查找图书
SELECT Bno, Bname, Bauth, Bph, Btag, Bdt
FROM  BOOKS
WHERE Bno like ''

#借书
UPDATE `BOOKS` SET `Bct`=Bct+1,`Bsno`=16272001 WHERE Bno='2'
UPDATE `STUDENT` SET `Sbknm`=Sbknm+1 WHERE Sno='16272001'
(BOOKS表中，借书时需要将Bdt设置为当前日期的一个月后，用php完成)

#续借
（php完成）

#还书
UPDATE `BOOKS` SET `Bsno`=NULL,`Bdt`=NULL WHERE Bno='2'
UPDATE `STUDENT` SET `Sbknm`=Sbknm-1 WHERE Sno='16272001'

#根据学号查姓名
SELECT Sname
FROM STUDENT
WHERE Sno='16272003'

#登陆判断
SELECT Spwd
FROM STUDENT
WHERE Sno='16272003'

#查询借阅次数排名前五的书籍
SELECT Bno, Bname, Bauth, Bph, Btag, Bct, Bdt
FROM BOOKS
ORDER BY Bct DESC
LIMIT 5

#查询逾期未还的书籍
SELECT Bsno, Sname, Bno, Bname, Bauth, Bph, Btag, Bdt
FROM BOOKS, STUDENT
WHERE Bsno = Sno AND Bdt < 2018.12.9