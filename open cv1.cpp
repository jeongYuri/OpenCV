open cv1.cpp


#include "opencv2/opencv.hpp"
#include <iostream>
using namespace cv;
using namespace std;
 
Mat img, res,roi,clone;
int mx1, my1, mx2, my2;
bool cropping = false;
 
// 마우스 이벤트가 발생하면 호출되는 콜백 함수이다.
void onMouse(int event, int x, int y, int flags, void* param)
{
res = img.clone();
 
if (event == EVENT_LBUTTONDOWN) {
cropping = true;
mx1 = x;
my1 = y;
}
else if (event == EVENT_MOUSEMOVE) {
if (cropping) {
rectangle(res, Point(mx1, my1),Point(x,y), Scalar(0, 255, 0), 2);
imshow("image", res);
}
}
else if (event == EVENT_LBUTTONUP) {

mx2 = x;
my2 = y;
cropping = false;
rectangle(res,Rect(mx1, my1, mx2 - mx1, my2 - my1), Scalar(0, 255, 0), 2);
imshow("image", res);
}
}
int main() {
img = imread("C:/Users/user/Desktop/유리/2021 1학기/영상처리/images/Lenna.jpg");
imshow("image", img);

setMouseCallback("image", onMouse);
 
while (1) {
int key = waitKey(100);
if (key == 'q') break;
else if (key == 'c') {
roi = clone(Rect(mx1, my1, mx2 - mx1, my2 - my1));
imwrite("d:/result.jpg", roi);
}
}
return 0;
}