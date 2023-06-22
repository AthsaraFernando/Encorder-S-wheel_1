import serial
import time
import pyautogui
pyautogui.size()
pyautogui.PAUSE = 0
width, height = pyautogui.size()

n=0

ArduinoSerial = serial.Serial('com23',9600)


while 1:
    
    data = int(ArduinoSerial.readline())
    print(data)
    


    if data < 0:
        pyautogui.typewrite('d')
        
        
     
        
    if data > 0:        
        pyautogui.typewrite('a')
        
    
