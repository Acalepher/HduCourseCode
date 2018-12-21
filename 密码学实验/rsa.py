# -*- coding: utf-8 -*-
# author = WL

import sys
import math
import random
from PyQt5 import QtCore, QtGui, QtWidgets

#--------RSA--------

# Miller-Rabin 素数测试
def is_prime(n, rounds=50):
    r = n - 1
    s = 0
    # need to represent n - 1 as 2^s * t (t is even)
    while (not r & 1): #r % 2 == 0
        r = r >> 1 #r = r / 2
        s = s + 1
    for _ in range(rounds):
        # calculating a^t mod m
        a = random.randint(2, n - 1)
        y = pow(a, r, n)
        if (y != 1 and y != n - 1):
            for _ in range(s - 1):
                if (y != n - 1):
                    y = y * y % n
                    if (y == 1):
                        return False #complex
            if (y != n-1):
                return False #complex
    return True #probably prime

# 系统中获取随机数（指定长度）
def random_number(size):
    a = random.SystemRandom().getrandbits(size)
    return a

# 欧几里德算法，获取两数的公因数
def gcd(a, b):
    if a < b:
        a, b = b, a
    while b != 0:
        a, b = b, a % b
    return a

# 欧几里德扩展算法，诸如 ax+by=gcd(a,b)，求出x，y，返回的r为gcd(a,b)
def extend_gcd(a, b):
    if b == 0:
        return 1, 0, a
    else:
        x, y, r = extend_gcd(b, a % b)
        x, y = y, (x - (a // b) * y)
    return x, y, r

# 生成公钥
def gen_e(p, q):
    a = p-1
    b = q-1
    phin = a * b
    e = random.randint(1, phin)
    while gcd(e,phin)!=1:
        e = random.randint(1, phin)
    return e

# 生成密钥
def gen_d(e, phin):
    x, y, q = extend_gcd(e, phin)
    if (q!=1 or x<0):
        return False
    else:
        return x

# 自动生成 n e d
def gen_key(size):
    p, q, n, phin = get_n_and_phin(size)
    e = 65537
    d = gen_d(e, phin)
    while d is False:
        p, q, n, phin = get_n_and_phin(size)
        d = gen_d(e, phin)
    return [p, q, n, e, d]

# 生成任意素数
def gen_prime_number(size):
    a = random_number(size)
    while is_prime(a) is False:
        a = random_number(size)
    return a

def get_n_and_phin(length):
    p = gen_prime_number(length)
    q = gen_prime_number(length)
    while p == q:
        q = get_prime(length)
    
    n = p * q
    phin = (p-1) * (q-1)
    return p, q, n, phin

# RSA 加密
def encrypt(n, e, text):
    text = pkcs5Pad(text)
    text = hex_to_d(str_2_hex(text))
    cipher_text = pow(text, e, n)
    cipher_text = d_to_hex(cipher_text)
    return cipher_text

# RSA 解密
def decrypt(n, d, cipher_text):
    cipher_text = hex_to_d(cipher_text)
    text = pow(cipher_text, d, n)
    text = hex_2_str(d_to_hex(text))
    return pkcs5Unpad(text)
    
# 字符串转16进制
def str_2_hex(text):
    hex_text = ""  
    for i in range(0, len(text)):  
        hex_text += (hex(ord(text[i])).replace('0x','').zfill(4)) 
    return hex_text

# 16进制转字符串
def hex_2_str(hex_text):
    text = ""
    for i in range(0, len(hex_text)//4):
        chr(int(hex_text[i*4:i*4+4], 16))
        text += chr(int(hex_text[i*4:i*4+4], 16))
    return text

# 16进制转10进制
def hex_to_d(hex_n):
    hex_n = '0x' + str(hex_n)
    return int(hex_n,16)

# 10进制转16进制
def d_to_hex(d_n):
    rst = hex(d_n).replace('0x','')
    if len(rst)%4 != 0:
        rst = '0'* (4-len(rst)%4) + rst
    return rst

# pkcs5填充／去填充
blocksize = 117
pkcs5Pad = lambda s: s + (blocksize - len(s) % blocksize) * chr(blocksize - len(s) % blocksize) 
pkcs5Unpad = lambda s : s[0:-ord(s[-1])]


#--------View--------

class Ui_Dialog(object):
    def setupUi(self, Dialog):
        Dialog.setObjectName("Dialog")
        Dialog.resize(640, 480)
        self.textEdit = QtWidgets.QTextEdit(Dialog)
        self.textEdit.setGeometry(QtCore.QRect(50, 20, 241, 31))
        self.textEdit.setObjectName("textEdit")
        self.textEdit_2 = QtWidgets.QTextEdit(Dialog)
        self.textEdit_2.setGeometry(QtCore.QRect(360, 20, 231, 31))
        self.textEdit_2.setObjectName("textEdit_2")
        self.label = QtWidgets.QLabel(Dialog)
        self.label.setGeometry(QtCore.QRect(20, 30, 60, 16))
        self.label.setObjectName("label")
        self.label_2 = QtWidgets.QLabel(Dialog)
        self.label_2.setGeometry(QtCore.QRect(320, 30, 60, 16))
        self.label_2.setObjectName("label_2")
        self.textEdit_3 = QtWidgets.QTextEdit(Dialog)
        self.textEdit_3.setGeometry(QtCore.QRect(50, 70, 541, 31))
        self.textEdit_3.setObjectName("textEdit_3")
        self.label_3 = QtWidgets.QLabel(Dialog)
        self.label_3.setGeometry(QtCore.QRect(20, 80, 60, 16))
        self.label_3.setObjectName("label_3")
        self.label_4 = QtWidgets.QLabel(Dialog)
        self.label_4.setGeometry(QtCore.QRect(10, 130, 60, 16))
        self.label_4.setObjectName("label_4")
        self.label_5 = QtWidgets.QLabel(Dialog)
        self.label_5.setGeometry(QtCore.QRect(10, 180, 60, 16))
        self.label_5.setObjectName("label_5")
        self.textEdit_4 = QtWidgets.QTextEdit(Dialog)
        self.textEdit_4.setGeometry(QtCore.QRect(50, 120, 541, 31))
        self.textEdit_4.setObjectName("textEdit_4")
        self.textEdit_5 = QtWidgets.QTextEdit(Dialog)
        self.textEdit_5.setGeometry(QtCore.QRect(50, 170, 541, 31))
        self.textEdit_5.setObjectName("textEdit_5")
        self.pushButton = QtWidgets.QPushButton(Dialog)
        self.pushButton.setGeometry(QtCore.QRect(50, 211, 113, 41))
        self.pushButton.setObjectName("pushButton")
        self.pushButton.clicked.connect(self.run)
        self.pushButton_2 = QtWidgets.QPushButton(Dialog)
        self.pushButton_2.setGeometry(QtCore.QRect(250, 210, 113, 41))
        self.pushButton_2.setObjectName("pushButton_2")
        self.pushButton_2.clicked.connect(self.run_encrypt)
        self.pushButton_3 = QtWidgets.QPushButton(Dialog)
        self.pushButton_3.setGeometry(QtCore.QRect(480, 211, 113, 41))
        self.pushButton_3.setObjectName("pushButton_3")
        self.pushButton_3.clicked.connect(self.run_decrypt)
        self.textEdit_6 = QtWidgets.QTextEdit(Dialog)
        self.textEdit_6.setGeometry(QtCore.QRect(50, 260, 541, 61))
        self.textEdit_6.setObjectName("textEdit_6")
        self.textEdit_7 = QtWidgets.QTextEdit(Dialog)
        self.textEdit_7.setGeometry(QtCore.QRect(50, 330, 541, 61))
        self.textEdit_7.setObjectName("textEdit_7")
        self.textEdit_8 = QtWidgets.QTextEdit(Dialog)
        self.textEdit_8.setGeometry(QtCore.QRect(50, 400, 541, 61))
        self.textEdit_8.setObjectName("textEdit_8")
        self.label_6 = QtWidgets.QLabel(Dialog)
        self.label_6.setGeometry(QtCore.QRect(10, 280, 60, 16))
        self.label_6.setObjectName("label_6")
        self.label_7 = QtWidgets.QLabel(Dialog)
        self.label_7.setGeometry(QtCore.QRect(10, 350, 60, 16))
        self.label_7.setObjectName("label_7")
        self.label_8 = QtWidgets.QLabel(Dialog)
        self.label_8.setGeometry(QtCore.QRect(10, 420, 60, 16))
        self.label_8.setObjectName("label_8")

        self.retranslateUi(Dialog)
        QtCore.QMetaObject.connectSlotsByName(Dialog)


    def run(self):
        if self.pushButton:
            self.p, self.q, self.n, self.e, self.d = gen_key(1024)
            self.textEdit.setPlainText(str(self.p))
            self.textEdit_2.setPlainText(str(self.q))
            self.textEdit_3.setPlainText(str(self.n))
            self.textEdit_4.setPlainText(str(self.e))
            self.textEdit_5.setPlainText(str(self.d))

    def run_encrypt(self):    
        if self.pushButton_2:
            self.e = int(self.textEdit_4.toPlainText())
            self.d = int(self.textEdit_5.toPlainText())

            self.text = self.textEdit_6.toPlainText()
            result = encrypt(self.n, self.e, self.text)
            self.textEdit_7.setPlainText(result)
        
    def run_decrypt(self):    
        if self.pushButton_3:
            cipher = self.textEdit_7.toPlainText()
            result = decrypt(self.n, self.d, cipher)
            self.textEdit_8.setPlainText(result)
    

    def retranslateUi(self, Dialog):
        _translate = QtCore.QCoreApplication.translate
        Dialog.setWindowTitle(_translate("Dialog", "WL's RSA"))
        self.label.setText(_translate("Dialog", "P"))
        self.label_2.setText(_translate("Dialog", "Q"))
        self.label_3.setText(_translate("Dialog", "N"))
        self.label_4.setText(_translate("Dialog", "公钥e"))
        self.label_5.setText(_translate("Dialog", "私钥d"))
        self.pushButton.setText(_translate("Dialog", "随机生成密钥"))
        self.pushButton_2.setText(_translate("Dialog", "加密"))
        self.pushButton_3.setText(_translate("Dialog", "解密"))
        self.label_6.setText(_translate("Dialog", "明文"))
        self.label_7.setText(_translate("Dialog", "密文"))
        self.label_8.setText(_translate("Dialog", "解密"))

if __name__ == "__main__":
    
    app=QtWidgets.QApplication(sys.argv)
    Form=QtWidgets.QWidget()
    ui=Ui_Dialog()
    ui.setupUi(Form)
    Form.show()
    sys.exit(app.exec_())
