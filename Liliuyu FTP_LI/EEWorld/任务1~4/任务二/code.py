import board
import terminalio
import os
import wifi
from adafruit_display_text import bitmap_label
from adafruit_bitmap_font import bitmap_font
import time

font = bitmap_font.load_font("Word_bank.pcf")

display = board.DISPLAY

wifi.radio.connect('FTP_LI', 'interlinked')
#连接的wifi格式	wifi.radio.connect('wifi名称', '密码')				
adress = "IP地址" + str(wifi.radio.ipv4_address)

color = {
        "black" : 0x000000,
        "white" : 0xFFFFFF,
        "red" : 0xFF0000,
        "green" : 0x00FF00,
        "blue" : 0x0000FF,
        "cyan" : 0x00FFFF,
        "magenta" : 0xFF00FF,
        "yellow" : 0xFFFF00,
        }#字体颜色配置

text_area = bitmap_label.Label(font,color=color["white"])       #字体颜色
text_area.x = 0                                                 #初始X位置
text_area.y = 60                                               #初始Y位置
text_area.text = "任务二展示"
text_area.scale = 2
display.show(text_area)
time.sleep(2)

text_area = bitmap_label.Label(font,color=color["white"])       #字体颜色
text_area = bitmap_label.Label(font,text=adress)
text_area.scale = 2
text_area.x = 0
text_area.y = 60
display.show(text_area)

while True:
    pass
