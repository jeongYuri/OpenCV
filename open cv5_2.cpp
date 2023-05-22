open cv5_2.cpp


#include "opencv2/opencv.hpp"
using namespace cv;
int main()
{
int tv1 = 193;
int tv2 = 243;
Mat src, cell, nucleus, bg, dst;
src = imread("Fig1.tif", IMREAD_GRAYSCALE);
equalizeHist(src, src);
imshow("eqh", src);
waitKey(0);
}