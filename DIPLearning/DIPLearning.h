#pragma once

#include "MyImgLoader.h"
#include "GeomResize.h"
#include "RasterResize.h"

namespace dip {

	class DIPLearning : public load::MyImgLoader, public gRes::GeomResize, public rRes::RasterResize
	{

		class load::MyImgLoader* MyImgL = new load::MyImgLoader;

	public:
		DIPLearning();
	private:
	};
} // dip end namespace
