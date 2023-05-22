open cv3_3.cpp

#include "opencv2/opencv.hpp"
#include <iostream>
using namespace std;
using namespace cv;
 
void shuffleDFT(Mat& src) {
int cX = src.cols / 2;
int cY = src.rows / 2;
 
Mat q1(src, Rect(0, 0, cX, cY));
Mat q2(src, Rect(cX, 0, cX, cY));
Mat q3(src, Rect(0, cY, cX, cY));
Mat q4(src, Rect(cX, cY, cX, cY));
 
Mat tmp;
q1.copyTo(tmp);
q4.copyTo(q1);
tmp.copyTo(q4);
q2.copyTo(tmp);
q3.copyTo(q2);
tmp.copyTo(q3);
}
void displayDFT(Mat& src) {
Mat image_array[2] = { Mat::zeros(src.size(), CV_32F), Mat::zeros(src.size(), CV_32F) };
split(src, image_array);
Mat mag_image;
magnitude(image_array[0], image_array[1], mag_image);
mag_image += Scalar::all(1);
log(mag_image, mag_image);
normalize(mag_image, mag_image, 0, 1, NORM_MINMAX);
imshow("DFT", mag_image);
}
 
Mat getFilter(Size size)
{
Mat filter = Mat::ones(size, CV_32FC2);
circle(filter, size / 2, 40, Vec2f(0, 0), -1);
return filter;
}
Mat hgpass(Mat src) {
Mat src_float;
 
src.convertTo(src_float,CV_32FC1, 1.0 / 255.0);
Mat dft_image;
dft(src_float, dft_image, DFT_COMPLEX_OUTPUT);
shuffleDFT(dft_image);
Mat highpass = getFilter(dft_image.size());
Mat result;
multiply(dft_image, 0.5 + 0.75 * highpass, result);
displayDFT(result);
Mat inverted_image;
shuffleDFT(result);
idft(result, inverted_image, DFT_SCALE | DFT_REAL_OUTPUT);
return inverted_image;
}
Mat eqHist(Mat src)
{
Mat img;
src.convertTo(src, CV_8UC1, 255);
equalizeHist(src, img);
return img;
}
int main()
{
Mat src = imread("Q1.tif", IMREAD_GRAYSCALE);
Mat src_float;
imshow("original", src);
Mat inverted_image = hgpass(src);
imshow("inverted", inverted_image);
Mat eqH = eqHist(inverted_image);
imshow("Histogram Equlization", eqH);
waitKey(0);
return 1;
}