#pragma once

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>

#include <map>

namespace rRes
{
	class RasterResize
	{
	public:
		RasterResize();

		int getImgHeight();
		int getImgWidth();

		void imgRastResize(std::map<std::string, cv::Mat>* tmpImg);
		std::map<std::string, cv::Mat> getRastResizedImages();

	private:
		void __setImgs(std::map<std::string, cv::Mat>* tmpImgs);
		void __saveImgs(std::map<std::string, cv::Mat>& tmpImgs);
		void __UpdateMap(cv::Mat& mapX, cv::Mat& mapY);

	private:
		int __Width;
		int __Height;
		cv::Size __mySize;

		std::map<std::string, cv::Mat> __aimImgs;
	};
} // rRes namespace end