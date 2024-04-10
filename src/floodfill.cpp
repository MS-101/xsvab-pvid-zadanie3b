#include "floodfill.h"
#include "common.h"


void floodfill(std::string name, cv::Mat input, cv::Mat truthMask, cv::Mat truth)
{
    cv::Mat gray;
    cv::cvtColor(input, gray, cv::COLOR_BGR2GRAY);

    cv::Mat threshold;
    cv::threshold(gray, threshold, 0, 255, cv::THRESH_BINARY_INV | cv::THRESH_OTSU);

    cv::Mat mask = threshold.clone();
    cv::Point seedPoint(0, 0);
    cv::floodFill(mask, seedPoint, cv::Scalar(255));
    cv::bitwise_not(mask, mask);

    cv::Mat output;
    applyMask(input, mask, output);

    outputFloodfill(name, input, mask, output, truthMask, truth);
}

void outputFloodfill(std::string name, cv::Mat input, cv::Mat mask, cv::Mat output, cv::Mat truthMask, cv::Mat truth)
{
    outputDiceScore(name, mask, truthMask);

    cv::Mat empty = input.clone();
    empty = 0;

    cv::cvtColor(mask, mask, cv::COLOR_GRAY2BGR);
    cv::cvtColor(truthMask, truthMask, cv::COLOR_GRAY2BGR);

	std::vector<std::vector<cv::Mat>> images = {
		{ input, empty },
        { mask, output },
        { truthMask, truth }
	};

	outputImage(images, { name, "../output/VOC12/floodfill/", ".jpg" });   
}