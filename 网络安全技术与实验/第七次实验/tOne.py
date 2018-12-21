from selenium import webdriver
import time  #调入time函数
import re
from selenium.webdriver.support.ui import WebDriverWait # available since 2.4.0
from selenium.webdriver.support import expected_conditions as EC # available since 2.26.0
from selenium.webdriver.common.by import By


def scroll_chrome(driver):
    for i in range(500,5000,500):
        driver.execute_script("scrollTo(0,"+str(i)+")")
        time.sleep(0.5)

# 查找ip跟端口
def find_ip_port(html):
	# 此处代码请同学自己补充
    pattern = r"\b(?:(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.){3}(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\b"
    ip_array = re.findall(pattern, html)
    index_array = [m.start() for m in re.finditer(pattern, html)]
    proxy_list = []
    for ip_item in zip(index_array, ip_array):
        index = int(ip_item[0])
        ip = ip_item[1]
        port = re.search(r">([0-9]{1,4})</", html[index: index+100])
        if port:
            port = port.group(1)
            if (ip!='0.0.0.0'):
                proxy_list.append(ip+":"+port)
    return proxy_list


# 选择chrome浏览器的webdriver
browser = webdriver.Chrome(r"/Users/acaleph/AcStudy/HduCourse/网络安全技术与实践/第七次实验/chromedriver")
# file_path = 'file:///' + os.path.abspath('IP代理_百度搜索.html')
browser.get("https://www.baidu.com/")
print("get_success")
# browser.maximize_window()  #将浏览器最大化显示
# print(browser.title)
# print(browser.page_source)
time.sleep(1)
browser.find_element_by_id("kw").send_keys("免费IP代理")

time.sleep(4)
WebDriverWait(browser, 20).until(EC.visibility_of_element_located((By.CLASS_NAME, "t")))
scroll_chrome(browser)
t_list = browser.find_elements_by_class_name("t")
url_list = []
for t in t_list:
    a = t.find_element_by_tag_name("a")
    href = a.get_attribute('href')
    url_list.append(href)

print("遍历url")
print(url_list)
for url in url_list:
    browser.get(url)
    # we have to wait for the page to refresh, the last thing that seems to be updated is the title
    # WebDriverWait(browser, 10).until(EC.title_contains(title))
    time.sleep(4)
    scroll_chrome(browser)
    html = browser.page_source
    proxy_list = find_ip_port(html)
    with open("record.txt", "a") as file:
        for proxy in proxy_list:
            file.write(proxy + "\n")

time.sleep(1)
browser.quit()