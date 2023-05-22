open cv5_1.cpp

#include "opencv2/opencv.hpp"
#include <iostream>
using namespace cv;
using namespace std;
 
int main()
{
Mat src = imread("Lenna.jpg", IMREAD_GRAYSCALE),dst;
int threshold_value = 127;
int lowsum = 0, highsum = 0, lowcount = 0, highcount = 0;
int u1 = 0, u2 = 0;
cout << "threshold value:" << threshold_value << endl;

while(1) {
for (int i = 0; i < src.rows; i++)
{
for (int j = 0; j < src.cols; j++) {
if (src.at<uchar>(i, j) < threshold_value) {
lowsum += src.at<uchar>(i, j);
lowcount++;
}
else {
highsum += src.at<uchar>(i, j);
highcount++;
}
}
}
if (lowsum / lowcount == u1 && highsum / highcount == u2)
break;
else {
u1 = lowsum / lowcount;
u2 = highsum / highcount;
threshold_value = (u1 + u2) / 2.0f;
cout << "threshold:" << threshold_value << endl;
lowsum = lowcount = highsum = highcount = 0;
}
}
threshold(src, dst, threshold_value, 255, THRESH_BINARY);
imshow("전", src);
imshow("후", dst);
waitKey();
return 0;
}