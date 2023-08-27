from pynput.keyboard import Key, Controller

keyboard = Controller()

# 输入空格
keyboard.press(Key.space)
keyboard.release(Key.space)

# 输入小写a
keyboard.press('a')
keyboard.release('a')

# 输入大写A
keyboard.press('A')
keyboard.release('A')

#输入大写A，且不锁定大写
with keyboard.pressed(Key.shift):
    keyboard.press('a')
    keyboard.release('a')

# 输入一串按键
keyboard.type('Hello World')