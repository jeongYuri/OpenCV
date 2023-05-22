open cv2_1.cpp

#include"opencv2/opencv.hpp"
 
 
using namespace cv;
using namespace std;
 
int input = 0;
double alpha, beta;
Mat img1, img2, dst;
int slide;
 
void onchange(int, void* ) {
 
alpha = (double)slide / 100;
beta = 1.0 - alpha;
addWeighted(img1, alpha, img2, beta, 0.0, dst);
imshow("image", dst);
}
 
int main() {

img1 = imread("test1.jpg");
img2 = imread("test2.jpg");

if (img1.empty()) { cout << "영상1을 로드할 수 없습니다." << endl; return-1; }
 
if (img2.empty()) { cout << "영상2을 로드할 수 없습니다." << endl; return-1; }
 
namedWindow("image",1);
createTrackbar("alpha", "image", &slide, 100, onchange);
 
waitKey();
return 0;
}