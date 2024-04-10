#pragma once

#include <opencv2/opencv.hpp>


void sparseOpticalFlow(std::string name, cv::VideoCapture input);
void denseOpticalFlow(std::string name, cv::VideoCapture input);
