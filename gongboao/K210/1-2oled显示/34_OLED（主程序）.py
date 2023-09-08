#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# －－－－湖南创乐博智能科技有限公司－－－－
#  文件名：34_OLED.py
#  版本：V2.0
#  author: zhulin
# 说明：OLED显示实验
#####################################################
import time
from ssd1306 import Oled
# 定义IO口，SCL为IO6，SDA为IO7
oled96 = Oled(6,7)
# 显示的内容，x坐标，Y坐标，显示字符
oled96.oled_showstr(10,2,"Hello World!")
oled96.oled_showstr(10,4,"Makerobo Kit!")

