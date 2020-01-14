#include <opencv2\opencv.hpp>
#include <iostream>
#include <opencv2\highgui.hpp>

using namespace std;
//using namespace cv;

cv::Mat img;
string s;
int rotate_v;
int on_rotate;

char window_name[50] = "Rotate Image (press 'r')";

void onRotate(int n, void*) {
	cv::Mat img_temp;
	cv::Point2f center(img.cols / 2.0F, img.rows / 2.0F);
	cv::warpAffine(img, img_temp, cv::getRotationMatrix2D(center,360-rotate_v,1.0),img.size());
	cv::imshow(window_name, img_temp);
}

void imgRotate() {
	cv::namedWindow("rotatecontrol", cv::WINDOW_AUTOSIZE);
	cv::createTrackbar("Rotate", "rotatecontrol", &rotate_v, 720,onRotate);
}




int main() {
	img = cv::imread("docotel.jpg");
	cv::namedWindow(window_name, cv::WINDOW_AUTOSIZE);
	cv::imshow(window_name, img);
	int key = 0;
	while (key != 27) {
		key = cv::waitKey();
		imgRotate();
	}
	imgRotate();


	cv::waitKey();
	

	return 0;
}