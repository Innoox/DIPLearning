#pragma once

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>

#include <map>

namespace gRes {
	class GeomResize
	{
	public:

		GeomResize();

		int getImgHeight();
		int getImgWidth();

		void imgGeomResize(std::map<std::string, cv::Mat>* tmpImg);
		std::map<std::string, cv::Mat> getGeomResizedImages();

	private:
		void __setImgs(std::map<std::string, cv::Mat>* tmpImgs);
		void __saveImgs(std::map<std::string, cv::Mat>& tmpImgs);

	private:
		int __Width;
		int __Height;
		cv::Size __mySize;

		std::map<std::string, cv::Mat> __aimImgs;
	};
} // gRes namespace end