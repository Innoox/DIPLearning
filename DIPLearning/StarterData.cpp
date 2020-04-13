#include "StarterData.h"

namespace mySTD
{
	StarterData::StarterData()
	{
		this->__ColorImagesSourceFolder = "../imgSource/Color/*.BMP";
		this->__MonoImageSourceFolder = "../imgSource/MonoChrome/*.BMP";
	}

	std::string StarterData::getColorImagesSourceFolder()
	{
		return this->__ColorImagesSourceFolder;
	}

	std::string StarterData::getMonoImageSourceFolder()
	{
		return this->__MonoImageSourceFolder;
	}
}
