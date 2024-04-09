#include <opencv2/opencv.hpp>
#include "grabcut.h"
#include "superpixels.h"


int main() {
	// VOC12 dataset segmentation

	cv::Mat input1 = cv::imread("../input/images/2007_000033.jpg");
	cv::Mat mask1 = cv::imread("../input/masks/2007_000033.jpg", cv::IMREAD_GRAYSCALE);
	cv::Mat truth1 = cv::imread("../input/truth/2007_000033.png");

	/*
	cv::Mat input2 = cv::imread("../input/images/2007_000123.jpg");
	cv::Mat mask2 = cv::imread("../input/masks/2007_000123.jpg", cv::IMREAD_GRAYSCALE);
	cv::Mat truth2 = cv::imread("../input/truth/2007_000123.png");

	cv::Mat input3 = cv::imread("../input/images/2007_000063.jpg");
	cv::Mat mask3 = cv::imread("../input/masks/2007_000063.jpg", cv::IMREAD_GRAYSCALE);
	cv::Mat truth3 = cv::imread("../input/truth/2007_000063.png");
	*/

	grabcut(input1, mask1, truth1);
	/*
	grabcut(input2, mask2, truth2);
	grabcut(input3, mask3, truth3);
	*/

	/*
	superpixels(input1, truth1);
	superpixels(input2, truth2);
	superpixels(input3, truth3);
	*/

	return 0;
}
