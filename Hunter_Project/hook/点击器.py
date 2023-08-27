from pynput.keyboard import Key, Listener, Controller as KeyboardController
from pynput.mouse import Button, Listener, Controller as MouseController
import time 

if __name__=="__main__":
  print("loading...")
  time.sleep(3)
  # 创建键盘和鼠标的Controller类实例
  keyboard = KeyboardController()
  mouse = MouseController()
  a=30
  # 读取鼠标位置
  # print("The current pointer position is" + format(mouse.position))
  while(a>0):
    mouse.position = (1087, 814)
    keyboard.type('略略略略略略')
    mouse.position = (1381, 877)
    mouse.press(Button.left)
    mouse.release(Button.left)
    a-=1
    time.sleep(0.5)
