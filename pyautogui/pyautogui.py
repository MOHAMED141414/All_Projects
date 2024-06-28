
# Using PyAutoGUI
# - To open vscode
# - install clangd from extension
# - install c++ testmate from extension
# - install c++ helper from extension
# - install cmake tools from extension
import pyautogui 
from time import sleep
def myfun():
    pyautogui.leftClick(549,324)
    sleep(2)
    pyautogui.leftClick(1010,382)
    sleep(2)
    pyautogui.move(587,267)
    sleep(2)
    pyautogui.tripleClick(587,267)
    sleep(3)
    pyautogui.press("backspace")
    sleep(3)
# sleep(10)
# print(pyautogui.position())
# Point(x=27, y=329)
# Point(x=126, y=268)
# Point(x=471, y=433) extension
# Point(x=549, y=324)
# Point(x=1010, y=382)
# Point(x=587, y=267)
# Point(x=1455, y=171)
sleep(2)
pyautogui.rightClick(27,329)
sleep(2)
pyautogui.leftClick(126,268)
sleep(2)
pyautogui.leftClick(471,433)
sleep(2)
pyautogui.write('clangd')
sleep(3)
myfun()
pyautogui.write('c++ testmate')
sleep(3)
myfun()
pyautogui.write('c++ helper')
sleep(3)
myfun()
pyautogui.write('cmake')
sleep(3)
myfun()
pyautogui.write('cmake tools')
sleep(3)
myfun()
pyautogui.leftClick(1455,171)





