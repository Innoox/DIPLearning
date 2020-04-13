#include "RasterResize.h"
#include <opencv2/imgproc.hpp>

rRes::RasterResize::RasterResize()
{
}

int rRes::RasterResize::getImgHeight()
{
	return this->__Height;
}

int rRes::RasterResize::getImgWidth()
{
	return this->__Width;
}

void rRes::RasterResize::imgRastResize(std::map<std::string, cv::Mat>* tmpImg)
{
	__setImgs(tmpImg);
	for (auto i : *tmpImg)
	{
		//cv::Mat tmpAimImg(i.second.size(), i.second.type());
		//cv::Mat mapX(i.second.size(), CV_32FC1);
		//cv::Mat mapY(i.second.size(), CV_32FC1);
		//cv::Mat mapX(cv::Size(this->__Width, this->__Height), CV_32FC1);
		//cv::Mat mapY(cv::Size(this->__Width, this->__Height), CV_32FC1);
		//__UpdateMap(mapX, mapY);
		//cv::remap(i.second, tmpAimImg, mapX, mapY, cv::INTER_LINEAR, cv::BORDER_CONSTANT, cv::Scalar(0, 0, 0));
		//cv::Mat tmpAimImg(cv::Size(this->__Width, this->__Height), i.second.type());
		//tmpAimImg.setTo(cv::Scalar(0, 0, 0));

		//i.second.copyTo(tmpAimImg(cv::Rect((tmpAimImg.cols - i.second.cols) / 2, (tmpAimImg.rows - i.second.rows) / 2, i.second.cols, i.second.rows)));

		//__aimImgs.insert({ i.first, tmpAimImg });

		cv::Mat tmpAimImg;
		cv::resize(i.second, tmpAimImg, __mySize, 0, 0, cv::INTER_LINEAR);
		__aimImgs.insert({ i.first, tmpAimImg });
	}
	this->__saveImgs(this->__aimImgs);
}

std::map<std::string, cv::Mat> rRes::RasterResize::getRastResizedImages()
{
	return this->__aimImgs;
}

void rRes::RasterResize::__setImgs(std::map<std::string, cv::Mat>* tmpImgs)
{
	this->__Height = 0;
	this->__Width = 0;
	for (auto i : *tmpImgs)
	{
		__Height = (__Height < i.second.size().height) ? i.second.size().height : __Height;
		__Width = (__Width < i.second.size().width) ? i.second.size().width : __Width;
	}
	this->__mySize = {__Width, __Height};
}

void rRes::RasterResize::__saveImgs(std::map<std::string, cv::Mat>& tmpImgs)
{
	for (auto i : tmpImgs)
	{
		std::string tmpPath = "../imgResult/RasterResize/" + i.first;
		cv::imwrite(tmpPath, i.second);
	}
}

void rRes::RasterResize::__UpdateMap(cv::Mat& mapX, cv::Mat& mapY)
{
	for (int cnt1 = 0; cnt1 < mapX.rows; ++cnt1)
	{
		for (int cnt2 = 0; cnt2 < mapY.cols; ++cnt2)
		{
			if (cnt2 > mapX.cols * 0.25 && cnt2 < mapX.cols * 0.75 && cnt1 > mapX.rows * 0.25 && cnt1 < mapX.rows * 0.75)
			{
				mapX.at<float>(cnt1, cnt2) = 2 * (cnt2 - mapX.cols * 0.25f) + 0.5f;
				mapY.at<float>(cnt1, cnt2) = 2 * (cnt1 - mapX.rows * 0.25f) + 0.5f;
			}
			else
			{
				mapX.at<float>(cnt1, cnt2) = 0;
				mapY.at<float>(cnt1, cnt2) = 0;
			}
		}
	}
}
