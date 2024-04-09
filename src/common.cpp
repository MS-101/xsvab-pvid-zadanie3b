#include "common.h"


void outputImage(std::vector<std::vector<cv::Mat>> images, OutputArgs outputArgs)
{
	std::vector<cv::Mat> mergedImageRows;
	for (auto& imageRow : images) {
		cv::Mat mergedImageRow;
		cv::hconcat(imageRow, mergedImageRow);
		mergedImageRows.push_back(mergedImageRow);
	}

	cv::Mat mergedImage;
	cv::vconcat(mergedImageRows, mergedImage);

    cv::imwrite(outputArgs.dir + outputArgs.name + outputArgs.extension, mergedImage);
}
