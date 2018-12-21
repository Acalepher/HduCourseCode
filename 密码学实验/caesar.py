# -*- coding: utf-8 -*-
# author = Acaleph

import sys
from PyQt5.QtWidgets import (QMainWindow, QWidget, QLabel, QGridLayout, QPushButton, QApplication, QInputDialog, QTextBrowser,
QTextEdit, QLineEdit) 


class Example(QWidget):

    def __init__(self):
        super().__init__()
        
        self.initUI()
        
    def initUI(self):
        
        #参数类别设置
        self.text = QLabel('Text: ', self)
        self.textEdit = QLineEdit('messgae', self)
        
        self.key = QLabel('Key: ', self)
        self.keyEdit = QLineEdit('0', self)

        self.review = QLabel('After: ', self)
        self.reviewEdit = QLineEdit(self)

        #设置各框在屏幕中的位置
        
        self.text.move(30,130)
        self.textEdit.move(88,130)
        self.key.move(30,50)
        self.keyEdit.move(88,50)
        self.review.move(30,200)
        self.reviewEdit.move(88,200)

        #Button
        self.btn_e = QPushButton('Encrypt', self)
        self.btn_e.resize(self.btn_e.sizeHint())
        self.btn_e.move(150,250)
        self.btn_e.clicked.connect(self.InputInfo) #绑定函数

        self.btn_d = QPushButton('Decrypt', self) 
        self.btn_d.resize(self.btn_d.sizeHint())
        self.btn_d.move(240,250)
        self.btn_d.clicked.connect(self.InputInfo)

        self.setGeometry(300, 300, 350, 300) #设置窗口位置与大小
        self.setWindowTitle("Wl's Caesar Cipher") #设置窗口标题
        self.show()

    def WL_Cipher(self, msg, key):
        after = ''
        for i in msg:
            if i.isalpha():
                if i.isupper():
                    asc = ord(i)
                    asc = ord('A') + (asc - ord('A') + key%26 + 26)%26
                elif i.islower():
                    asc = ord(i)
                    asc = ord('a') + (asc - ord('a') + key%26 + 26)%26
                after += chr(asc)

            elif (ord(i)>=ord('0') and ord(i)<=ord('9')):
                asc = ord(i)
                asc = ord('0') + (asc - ord('0') + key%10 + 10)%10
                after += chr(asc)

            #符号处理
            elif (ord(i)>=32 and ord(i)<=47 ):
                asc = ord(i)
                asc = 32 + (asc - 32 + key%16 + 16)%16
                after += chr(asc)

            elif (ord(i)>=58 and ord(i)<=64 ):
                asc = ord(i)
                asc = 58 + (asc - 58 + key%7 + 7)%7
                after += chr(asc)

            elif (ord(i)>=123 and ord(i)<=126 ):
                asc = ord(i)
                asc = 123 + (asc - 123 + key%4 + 4)%4
                after += chr(asc)

            elif (ord(i)>=91 and ord(i)<=96 ):
                asc = ord(i)
                asc = 91 + (asc - 91 + key%6 + 6)%6
                after += chr(asc)

            else:
                after += i
        return after

    def WLCaesar_A(self, msg, key):
        after = ''

        for i in msg:
            asc = ord(i)
            asc += key
                
            after += chr(asc)

        return after

    def InputInfo(self):
        sender = self.sender()
        msg = ''
        k = 0
        msg = self.textEdit.text()
        k = int(self.keyEdit.text())

        # --------------------------
        #""" 处理字母（区分大小写），处理数字，处理符号功能的集成
        a = self.WL_Cipher(msg,k)
        b = self.WL_Cipher(msg,-k)
        #"""

        #""" 处理任意字母
        #a = self.WLCaesar_A(msg,k)
        #b = self.WLCaesar_A(msg,-k)
        #"""
        # --------------------------

        if sender == self.btn_e:
            self.reviewEdit.setText(a)

        if sender == self.btn_d:
            self.reviewEdit.setText(b)

if __name__ == '__main__':
    
    app = QApplication(sys.argv)
    ex = Example()
    sys.exit(app.exec_())