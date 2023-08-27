from pynput import keyboard ,mouse
from pynput.mouse import Button, Controller

if __name__=="__main__":
  print("loading...")
  
  mouse=Controller()
  # 读取鼠标位置
  print("The current pointer position is" + format(mouse.position))
  # 设置鼠标位置
  mouse.position = (10, 20)
  # print('Now we have moved it to '+format(mouse.position))

  #移动鼠标
  # mouse.move(500, 0)
  # print('Now we have moved it to '+format(mouse.position))

  # 点击鼠标
  # mouse.press(Button.left)
  # mouse.release(Button.left)

  # 双击鼠标
  # mouse.click(Button.left, 2)
  # 滚动鼠标
  # mouse.scroll(0,-1)