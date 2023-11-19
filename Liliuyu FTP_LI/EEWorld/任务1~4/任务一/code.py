import board
import terminalio
from adafruit_display_text import bitmap_label
from adafruit_bitmap_font import bitmap_font
import time

font = bitmap_font.load_font("Word_bank.pcf")

display = board.DISPLAY

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

txtCollection = ["用户名：黎琉一御","Hello World!"]
#显示位
scaleCollection = [2,4]
#字体大小

text_area = bitmap_label.Label(font,color=color["white"])       #字体颜色
text_area.x = 0                                                 #初始X位置
text_area.y = 60                                               #初始Y位置
text_area.text = "任务一展示"
text_area.scale = 2
display.show(text_area)
time.sleep(2)
#基础显示

while True:
        text_area = bitmap_label.Label(font,color=color["blue"])       #字体颜色
        text_area.x = 0                                                 #初始X位置
        text_area.y = 60                                               #初始Y位置
        text_area.text = txtCollection[0]
        text_area.scale = scaleCollection[0]
        display.show(text_area)
        time.sleep(1)
        text_area = bitmap_label.Label(font,color=color["yellow"])       #字体颜色
        text_area.x = 0                                                 #初始X位置
        text_area.y = 60                                               #初始Y位置
        text_area.text = txtCollection[1]
        text_area.scale = scaleCollection[1]
        display.show(text_area)
        time.sleep(1)
#循环显示
