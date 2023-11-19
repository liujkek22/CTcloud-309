import board
import time
import neopixel
from digitalio import DigitalInOut,Direction,Pull
from adafruit_led_animation.animation.blink import Blink
from adafruit_led_animation.animation.colorcycle import ColorCycle
from adafruit_led_animation.color import RED, YELLOW, BLUE, GREEN,BLACK

pixel_pin = board.NEOPIXEL
pixel_num = 1
pixels = neopixel.NeoPixel(pixel_pin, pixel_num, brightness=0.1, auto_write=False, pixel_order=neopixel.GRB)
#初始化像素灯

buttom = DigitalInOut(board.BOOT0)
buttom.direction = Direction.INPUT
buttom.pull = Pull.UP
#初始化BOOT0按键

#LED模式状态指示物
pixel_modeflag = 0
blink = Blink(pixels, speed=0.5, color=BLACK)
colorcycle = ColorCycle(pixels, speed=0.5)
print("LED ColorCycle")

while True:
    if not buttom.value: #监测按键
        pixel_modeflag = pixel_modeflag + 1
        if (pixel_modeflag % 5 == 1):
            blink = Blink(pixels, speed=0.2, color=RED)
            print("LED Blink in RED")
        elif (pixel_modeflag % 5 == 2):
            blink = Blink(pixels, speed=0.2, color=YELLOW)
            print("LED Blink in YELLOW")
        elif (pixel_modeflag % 5 == 3):
            blink = Blink(pixels, speed=0.2, color=BLUE)
            print("LED Blink in BLUE")
        elif (pixel_modeflag % 5 == 4):
            blink = Blink(pixels, speed=0.2, color=GREEN)
            print("LED Blink in GREEN")            
        elif (pixel_modeflag % 5 == 0):
            colorcycle = ColorCycle(pixels, speed=0.1)
            print("LED ColorCycle")
    else:
        pass
    time.sleep(0.2)
        
    if (pixel_modeflag % 5 == 0):
        colorcycle.animate()#循环显示配置输出
    else:
        blink.animate()#闪烁显示配置输出
