from bs4 import BeautifulSoup
import socket, re, requests, random, http.client, time



headers = {
    'Accept':'text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8',
    'Accept-Encoding':'gzip, deflate,sdch',
    'Accept-Language':'zh-CN,zh;q=0.9,en;q=0.8',
    'Connection': 'keep-alive',
    'User-Agent':'Mozilla/5.0 (Macintosh; Intel Mac OS X 10_12_6) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/64.0.3282.186 Safari/537.36'
}

def get_url(cityName):
    cityCode = -1
    if cityName == "exit":
    	return "exit"
    f = open('dict.txt','r').readlines()
    for i in f:
        if cityName in i:
            cityCode = i.strip().split(':')[1]
    if (cityCode == -1):
        print ('CITY DOSEN\'T EXISTED!')
        return "FAILED"
    weather_url = "http://www.weather.com.cn/weather/%s.shtml" % cityCode
    return weather_url

def get_html(url):
    while True:
        try:
            rep = requests.get(url,headers=headers,timeout=69)
            rep.encoding = "utf-8"
            break
        except Exception as e:
            print (e)
            time.sleep(9)
    return rep.text

def get_data(htmlTxt):
    weather_7 = []
    bs = BeautifulSoup(htmlTxt, "html.parser")
    body = bs.body
    data = body.find("div",{"id":"7d"})
    ul = data.find("ul")
    li = ul.find_all("li")

    for day in li:
        weather_1 = []
        date = day.find("h1").string
        weather_1.append(date)	#1 日期
        detail = day.find_all("p")
        weather_1.append(detail[0].string)	#2 天气概况

        temhigh = detail[1].find("span").string
        temlow = detail[1].find("i").string
        temlow = temlow.replace('℃','')

        wind = detail[2].find("i").string

        weather_1.append(temhigh)	#3 最高温
        weather_1.append(temlow)	#4 最低温
        weather_1.append(wind)		#4 风力

        weather_7.append(weather_1)

    return weather_7

while True:
    cityName = input("input the city name: ")
    weatherUrl = get_url(cityName)
    if weatherUrl == "FAILED":
        print("Searching again. Input \"exit\" to exit.")
        continue
    elif weatherUrl == "exit":
        break
    htmlTxt = get_html(weatherUrl)
    result = get_data(htmlTxt)
    for i in result:
        print (i)

