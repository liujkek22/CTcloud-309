import board
import os, wifi
import time
import ssl
import socketpool
import adafruit_requests

from adafruit_display_text import bitmap_label
from adafruit_bitmap_font import bitmap_font

JSON_TIME_URL = "http://quan.suning.com/getSysTime.do"
JSON_WEATHER_URL = "http://t.weather.sojson.com/api/weather/city/{}"
#请求获取JSON

#获取数据,返回str
def get_date():
    response = requests.get(JSON_TIME_URL)
    time_date = response.json()

    city_code = "101071401"#城市码
    url = JSON_WEATHER_URL.format(city_code)
    response = requests.get(url)
    city_date = response.json()   

    City_Name = city_date['cityInfo']['parent']+'省 '+city_date['cityInfo']['city']
    City_Weather = city_date['data']
    City_Forecast = City_Weather['forecast']
    CurrentTime = time_date['sysTime2'] + '  ' + City_Forecast[0]['week']
    TotalStr = City_Name
    TotalStr += "\n时间：" + CurrentTime
    TotalStr += "\n空气质量：" + City_Weather['quality']
    TotalStr += "\t天气状态：" + City_Forecast[0]['type']
    TotalStr += "\n最高温度：" + City_Forecast[0]['high'][2:]
    TotalStr += "\n最低温度：" + City_Forecast[0]['low'][2:]
    TotalStr += "\n寄语：" + City_Forecast[0]['notice'] 
    #print(type(TotalStr))
    return TotalStr

font = bitmap_font.load_font("Word_bank.pcf")
display = board.DISPLAY
color = {
        "black" : 0x000000,
        "white" : 0xFFFFFF,
        "red" : 0xFF0000,
        "green" : 0x00FF00,
        "blue" : 0x0000FF,
        "yellow" : 0xFFFF00,
        }
def screen_display(text):
    text_area = bitmap_label.Label(font,color=color["white"])
    text_area.scale = 1
    text_area.x = 0
    text_area.y = 5
    text_area.text = text
    display.show(text_area)
#显示屏显示初始化  

while not wifi.radio.connected:
    try:
        wifi.radio.connect('FTP_LI','interlinked')
    except ConnectionError as e:
        print("Wifi connect error:{},wait for retry".format(e))
    time.sleep(0.1)
#wifi连接

pool = socketpool.SocketPool(wifi.radio)
requests = adafruit_requests.Session(pool, ssl.create_default_context())


while True:       
    screen_display(get_date())
    time.sleep(1)


