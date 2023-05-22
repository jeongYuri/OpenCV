open cv5_4.cpp

#include "opencv2/opencv.hpp"
using namespace cv;
 
int main()
{
int t1 = 193;
int t2 = 243;
 
Mat src, cell, nucleus, bg, dst;
src = imread("Fig1.tif", IMREAD_GRAYSCALE);
 

equalizeHist(src, src);
 
threshold(src, cell, t1, 255, THRESH_BINARY);
threshold(src, nucleus, t2, 255, THRESH_BINARY);
threshold(src, bg, t1, 255, THRESH_BINARY_INV);
 
cvtColor(cell, cell, COLOR_GRAY2BGR);
cvtColor(nucleus, nucleus, COLOR_GRAY2BGR);
cvtColor(bg, bg, COLOR_GRAY2BGR);
 
cell -= Scalar(20, 40, 125);
bg -= Scalar(50, 0, 0);
nucleus -= Scalar(0, 50, 0);
 
dst = bg.clone();
bitwise_or(dst, cell, dst);
bitwise_or(dst, nucleus, dst);
 
imshow("Original", src);
imshow("cell", cell);
imshow("nucleus", nucleus);
imshow("background", bg);
imshow("dst", dst);
 
waitKey(0);
}