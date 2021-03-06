#include "GeomResize.h"
#include <opencv2/imgproc.hpp>

namespace gRes {

	gRes::GeomResize::GeomResize()
	{
	}

	void GeomResize::__setImgs(std::map<std::string, cv::Mat>* tmpImgs)
	{
		this->__Height = 0;
		this->__Width = 0;
		for (auto i : *tmpImgs)
		{
			this->__Height = (this->__Height < i.second.size().height) ? i.second.size().height : this->__Height;
			this->__Width = (this->__Width < i.second.size().width) ? i.second.size().width : this->__Width;
		}
		this->__mySize = {__Width, __Height};
	}

	void GeomResize::__saveImgs(std::map<std::string, cv::Mat>& tmpImgs)
	{
		for (auto i : tmpImgs)
		{
			std::string tmpPath = "../imgResult/GeometricalResize/" + i.first;
			cv::imwrite(tmpPath, i.second);
		}
	}

	int GeomResize::getImgHeight()
	{
		return this->__Height;
	}

	int GeomResize::getImgWidth()
	{
		return this->__Width;
	}

	void GeomResize::imgGeomResize(std::map<std::string, cv::Mat>* tmpImg)
	{
		__setImgs(tmpImg);
		for (auto i : *tmpImg)
		{

			cv::Mat tmpAimImg(cv::Size(this->__Width, this->__Height), i.second.type());
			tmpAimImg.setTo(cv::Scalar(0, 0, 0));

			i.second.copyTo(tmpAimImg(cv::Rect((tmpAimImg.cols - i.second.cols) / 2, (tmpAimImg.rows - i.second.rows) / 2, i.second.cols, i.second.rows)));

			__aimImgs.insert({ i.first, tmpAimImg });

			//cv::Mat tmpAimImg;
			//cv::resize(i.second, tmpAimImg, __mySize, 0, 0, cv::INTER_LINEAR);
			//__aimImgs.insert({ i.first, tmpAimImg });
		}
		__saveImgs(__aimImgs);
	}

	std::map<std::string, cv::Mat> GeomResize::getGeomResizedImages()
	{
		return this->__aimImgs;
	}

} // gRes namespace end