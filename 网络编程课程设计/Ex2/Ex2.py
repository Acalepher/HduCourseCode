from scapy.all import *
import matplotlib.pyplot as plt 
#引入自己抓的包
path = "img_pkg.pcapng"
#读那个包
pcapfile = rdpcap(path)
#经过自己观察发现在我抓到的包里，tcp的三次握手分别位于第234个位置，所以分别赋给变量pkg123
pkg1 = False
pkg2 = False
pkg3 = False

sunsite=['218.75.123.181', '218.75.123.182']

#三次嵌套，依次查找三次握手，填入pkg123
for i in range(0,len(pcapfile)):
    if (str(pcapfile[i][IP].dst) in sunsite and str(pcapfile[i][TCP].flags) == 'S'):
        print("Get the first handshake.\n")
        pkg1 = pcapfile[i]
        for j in range(i,len(pcapfile)):
            if (str(pcapfile[j][IP].src) in sunsite and str(pcapfile[j][TCP].flags) == "SA" and (int(pcapfile[j][TCP].ack) == int(pkg1[TCP].seq) + 1)):
                print("Get the second handshake.\n")
                pkg2 = pcapfile[j]
                for k in range(j,len(pcapfile)):
                    if (str(pcapfile[k][IP].dst) in sunsite and str(pcapfile[k][TCP].flags) == 'A' and (int(pcapfile[k][TCP].ack) == int(pkg2[TCP].seq) + 1)):
                        print("Get the third handshake.\n")
                        pkg3 = pcapfile[k]
                        break
                if pkg3 == False:       #for结束时，查看是否找到第三次握手，若没有则输出提示信息。
                    print("Lost the third handshake.\n")
                break
        if pkg2 == False:
            print("Lost the second handshake.\n")
        break
if pkg1 == False:
    print("Lost the second handshake.\n")

                        


src1 = str(pkg1[IP].src)
dst1 = str(pkg1[IP].dst)
ack1 = str(pkg1.ack)
seq1 = str(pkg1.seq)

src2 = str(pkg2[IP].src)
dst2 = str(pkg2[IP].dst)
ack2 = str(pkg2.ack)
seq2 = str(pkg2.seq)

src3 = str(pkg3[IP].src)
dst3 = str(pkg3[IP].dst)
ack3 = str(pkg3.ack)
seq3 = str(pkg3.seq)


#开始画图！ .title函数设置图的标题
plt.title('TCP simulation')
#下面五条线，前三条是tcp的三次握手连线，后两条代表主机A和B
plt.plot([0, 8],[8, 6], 'b')
plt.plot([0, 8],[4, 6], 'black')
plt.plot([0, 8],[4, 2], 'b')
plt.plot([0, 0],[0, 8], 'green')
plt.plot([8, 8],[0, 8], 'green')

#添加每个数据包的信息
plt.text(0, 6, r'$Seg1: $'+'\n'+r'$src1: $'+src1+'\n'+r'$dst1: $'+dst1+'\n'+r'$seq1: $'+seq1+'\n'+r'$ack1: $'+ack1+'\n',
         fontdict={'size': 8, 'color': 'black'})
plt.text(2, 4.5, r'$Seg2: $'+'\n'+r'$src2: $'+src2+'\n'+r'$dst2: $'+dst2+'\n'+r'$seq2: $'+seq2+'\n'+r'$ack2: $'+ack2+'\n',
         fontdict={'size': 8, 'color': 'black'})
plt.text(0, 2, r'$Seg3: $'+'\n'+r'$src3: $'+src3+'\n'+r'$dst3: $'+dst3+'\n'+r'$seq3: $'+seq3+'\n'+r'$ack3: $'+ack3+'\n',
         fontdict={'size': 8, 'color': 'black'})

plt.text(0, 8, r'$HOST A$',
		 fontdict={'size': 12, 'color': 'black'})
plt.text(8, 8, r'$HOST B$',
         fontdict={'size': 12, 'color': 'black'})

#去除丑陋的横纵坐标显示
plt.axis('off')

#展示
plt.show()


