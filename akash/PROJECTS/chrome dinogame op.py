import pyautogui # pip install pyautogui
from PIL import Image, ImageGrab # pip install pillow
from numpy import asarray
import time

def hit(key):
    pyautogui.keyDown(key)
    return

def takeScreenshot():

    return image


# def draw():
#     for i in range(300, 415):
#         for j in range(410, 563):
#             data[i, j] = 0








if __name__ == "__main__":
    time.sleep(1)
    image = ImageGrab.grab().convert('L')
    image = takeScreenshot()
    data = image.load()
    # print(asarray(image))
    for i in range(250, 350):
        for j in range(590, 690):
            data[i, j] = 0

    image.show()







# def isCollide(data):
#     # Draw the rectangle for birds
#     for i in range(300, 415):
#         for j in range(410, 563):
#             if data[i, j] < 100:
#                 hit("down")
#                 return
#
#     for i in range(300, 415):
#         for j in range(563, 650):
#             if data[i, j] < 100:
#                 hit("up")
#                 return
#     return
