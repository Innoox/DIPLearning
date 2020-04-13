#pragma once

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>

#include <map>

namespace load {

	class MyImgLoader
	{
	public:

		MyImgLoader();

		std::map<std::string, cv::Mat> getColorImgs();
		std::map<std::string, cv::Mat> getMonoImgs();

		void myShowImgs(std::map<std::string, cv::Mat>* imgType);

	private:
		std::string __ColorImgPath;
		std::string __MonoImgPath;

		std::map<std::string, cv::Mat> __ColorImgs;
		std::map<std::string, cv::Mat> __MonoImgs;

	private:
		void __LoadImgs();
	};

} // img namespace end