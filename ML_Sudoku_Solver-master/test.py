import cv2

print(cv2.__version__)
print(cv2.__file__)



img = cv2.imread("D:\\TCSOOPs\\akash_pycharm\\PROJECTS\\ML_Sudoku_Solver-master\\NumberCells\\six.jpeg")

cv2.imshow("Iamge : ",img)

img = cv2.resize(img, (140, 140))
cv2.imwrite(str("D:\\TCSOOPs\\akash_pycharm\\PROJECTS\\ML_Sudoku_Solver-master\\NumberCells\\cell\\"+str("a") + str("h")+".jpg"), img)
cv2.waitKey(0)