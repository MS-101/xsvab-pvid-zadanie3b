#include "threshold.h"
#include "common.h"


void threshold(std::string name, cv::Mat input, cv::Mat truthMask, cv::Mat truth)
{
    cv::Mat gray;
    cv::cvtColor(input, gray, cv::COLOR_BGR2GRAY);

    cv::Mat mask;
    cv::threshold(gray, mask, 0, 255, cv::THRESH_BINARY_INV | cv::THRESH_OTSU);

    cv::Mat output;
    applyMask(input, mask, output);

    outputThreshold(name, input, mask, output, truthMask, truth);
}

void outputThreshold(std::string name, cv::Mat input, cv::Mat mask, cv::Mat output, cv::Mat truthMask, cv::Mat truth)
{
    cv::Mat empty = input.clone();
    empty = 0;

    cv::cvtColor(mask, mask, cv::COLOR_GRAY2BGR);
    cv::cvtColor(truthMask, truthMask, cv::COLOR_GRAY2BGR);

    std::vector<std::vector<cv::Mat>> images = {
		{ input, empty },
        { mask, output },
        { truthMask, truth }
	};

    outputImage(images, { name, "../output/VOC12/threshold/", ".jpg" });
    outputDiceScore(name, mask, truthMask);
}