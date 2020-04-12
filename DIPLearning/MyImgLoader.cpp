#include "MyImgLoader.h"
#include "iostream"
#include <vector>

namespace dip {

	dip::MyImgLoader::MyImgLoader()
	{
		this->__ColorImgPath = "../../imgSource/Color/*.BMP";
		this->__MonoImgPath = "../../imgSource/MonoChrome/*.BMP";
		__LoadImgs();
	}

	std::map<std::string, cv::Mat> MyImgLoader::getColorImgs()
	{
		return this->__ColorImgs;
	}

	std::map<std::string, cv::Mat> MyImgLoader::getMonoImgs()
	{
		return this->__MonoImgs;
	}

	void MyImgLoader::myShowImgs(std::map<std::string, cv::Mat>* imgType)
	{
		//for (auto it = imgType.begin(); it != imgType.end(); ++it)
		//{
		//	cv::imshow(it->first, it->second);
		//}
		for (auto i : *imgType)
		{
			cv::imshow(i.first, i.second);
		}
	}

	void MyImgLoader::__LoadImgs()
	{
		std::vector<std::string> tmpFN;
		cv::glob(this->__ColorImgPath, tmpFN, false);
		for (auto i : tmpFN)
		{
			this->__ColorImgs.insert({ i.substr(i.find_last_of("\\") + 1, i.size()), cv::imread(i) });
		}
		tmpFN.clear();
		cv::glob(this->__MonoImgPath, tmpFN, false);
		for (auto i : tmpFN)
		{
			this->__MonoImgs.insert({ i.substr(i.find_last_of("\\") + 1, i.size()), cv::imread(i) });
		}
	}

}