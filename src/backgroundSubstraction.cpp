#include "backgroundSubstraction.h"
#include "common.h"


void accumWeighted(std::string name, cv::VideoCapture input)
{
    std::string outputName = "../output/Pedestrian/accumWeighted/" + name;
    int width = input.get(cv::CAP_PROP_FRAME_WIDTH);
    int height = input.get(cv::CAP_PROP_FRAME_HEIGHT);
    double fps = input.get(cv::CAP_PROP_FPS);
    
    cv::VideoWriter output(outputName, cv::VideoWriter::fourcc('M', 'J', 'P', 'G'), fps, cv::Size(width, height));

	double alpha = 0.02;
    cv::Mat frame;
    cv::Mat accum = cv::Mat::zeros(cv::Size(width, height), CV_32FC3);
    while (input.read(frame)) {
		cv::accumulateWeighted(frame, accum, alpha);

        cv::Mat background;
        cv::convertScaleAbs(accum, background);

		cv::Mat foreground;
		cv::absdiff(frame, background, foreground);

        output << foreground;
    }

	output.release();
}

void mog2(std::string name, cv::VideoCapture input)
{
    std::string outputName = "../output/Pedestrian/mog2/" + name;
    int width = input.get(cv::CAP_PROP_FRAME_WIDTH);
    int height = input.get(cv::CAP_PROP_FRAME_HEIGHT);
    double fps = input.get(cv::CAP_PROP_FPS);
    
    cv::VideoWriter output(outputName, cv::VideoWriter::fourcc('M', 'J', 'P', 'G'), fps, cv::Size(width, height));
    cv::Ptr<cv::BackgroundSubtractor> mog2 = cv::createBackgroundSubtractorMOG2();

    cv::Mat frame, fgMask;
    while (input.read(frame)) {
        mog2->apply(frame, fgMask);

        cv::Mat foreground;
        applyMask(frame, fgMask, foreground);

        output << foreground;
    }

	output.release();
}
