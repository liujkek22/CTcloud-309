from pynput import keyboard
from pynput import mouse

with keyboard.Events() as keyEvent:
  with mouse.Events() as mouseEvent:    
    while(1):
      Mevent = mouseEvent.get(0.03)
      Kevent = keyEvent.get(0.01)

      if Kevent is None:
        pass
      else:
          print(format(Kevent))

      if Mevent is None:
          pass
      else:
          print(format(Mevent))