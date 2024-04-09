#include "superpixels.h"
#include <opencv2/ximgproc.hpp>

void superpixels(cv::Mat input, cv::Mat truth)
{
    cv::Mat converted;
    cvtColor(input, converted, cv::COLOR_BGR2Lab);
    
    auto slic = cv::ximgproc::createSuperpixelSLIC(converted, cv::ximgproc::SLIC, 50, 10.0f);
    slic->iterate(10);

    cv::Mat mask;
    slic->getLabelContourMask(mask, false);

    cv::Mat segmented_image = input.clone();
    segmented_image.setTo(cv::Scalar(0, 255, 0), mask);

    cv::imwrite("Original Image", input);
    cv::imwrite("Segmented Image", segmented_image);
}
