open cv5_3.cpp

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
imshow("eqh", src);
imshow("cell", cell);
imshow("nucleus", nucleus);
imshow("background", bg);

waitKey(0);
}