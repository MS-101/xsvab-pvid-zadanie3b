#include "common.h"
#include "grabcut.h"
#include "superpixels.h"
#include "floodfill.h"
#include "threshold.h"
#include "backgroundSubstraction.h"
#include "opticalFlow.h"
#include <opencv2/opencv.hpp>

void voc12()
{
	std::string inputDir = "../input/VOC12/images/";
	std::string labelDir = "../input/VOC12/labels/";
	std::string maskDir = "../input/VOC12/masks/";

	std::string inputExtension = ".jpg";
	std::string labelExtension = ".png";
	std::string maskExtension = ".jpg";

	std::vector<std::string> imageNames = {
		"2007_000033",
		"2007_000123",
		"2007_000063"
	};

	for (std::string imageName : imageNames)
	{
		// load input images

		cv::Mat input = cv::imread(inputDir + imageName + inputExtension);
		cv::Mat label = cv::imread(labelDir + imageName + labelExtension);
		cv::Mat mask = cv::imread(maskDir + imageName + maskExtension, cv::IMREAD_GRAYSCALE);

		// create truth mask

		cv::Mat truthMask, truth;
		createTruthMask(label, truthMask, 0, 0, 128);
		applyMask(input, truthMask, truth);
		outputTruthMask(imageName, input, label, truthMask, truth);

		// perform segmentation

		grabcut(imageName, input, mask, truthMask, truth);
		superpixels(imageName, input, truthMask, truth);
		floodfill(imageName, input, truthMask, truth);
		threshold(imageName, input, truthMask, truth);
	}
}

void pedestrian()
{
	std::vector<std::string> videoNames = {
		"fourway.avi"
	};

	std::string inputDir = "../input/Pedestrian/";

	for (std::string videoName : videoNames)
	{
		// load input

		cv::VideoCapture input(inputDir + videoName);	

		// perform motion tracking

		accumWeighted(videoName, input);
		mog2(videoName, input);
		sparseOpticalFlow(videoName, input);
		denseOpticalFlow(videoName, input);

		// close input

		input.release();
	}


}


int main() {
	// voc12();
	// pedestrian();

	return 0;
}
