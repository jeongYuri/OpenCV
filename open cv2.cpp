open cv2.cpp

#include "opencv2/opencv.hpp"
#include <iostream>
using namespace cv;
using namespace std;
 
Mat img, roi,res;
int x, y, width, height;
Point p1(0.0);
Point p2(0, 0);
void showNewImg();
void onMouse(int event, int x, int y, int flags, void* param) {
switch (event) {
case EVENT_LBUTTONDOWN:
p1.x = x;
p1.y = y;
p2.x = x;
p2.y = y;
break;
case EVENT_LBUTTONUP:
p2.x = x;
p2.y = y;
showNewImg();
 
default:
break;
}
}
 
int main() {
img = imread("C:/Users/user/Desktop/유리/2021 1학기/영상처리/images/Lenna.jpg", 1);

 
imshow("image", img);
setMouseCallback("image", onMouse);
waitKey();
return 0;
}
void showNewImg() {
int width = p2.x - p1.x;
int height = p2.y - p1.y;
Rect roi(p1.x, p1.y, width, height);
Mat draggedImage = img.clone();
Mat newing = draggedImage(roi);
newing = newing * 3.0 + 50;
 


imshow("img", draggedImage);
}