#pragma once

#include <opencv2/opencv.hpp>


void grabcut(cv::Mat input, cv::Mat mask, cv::Mat truth);
void toGrabcutMask(cv::Mat mask, cv::Mat& output);
void toDisplayMask(cv::Mat mask, cv::Mat& output);
void applyGrabcutMask(cv::Mat input, cv::Mat mask, cv::Mat& output);
void outputGrabcutResults(cv::Mat input, cv::Mat maskBefore, cv::Mat maskAfter, cv::Mat output, cv::Mat truth);
