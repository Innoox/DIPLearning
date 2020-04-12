#pragma once

#include "MyImgLoader.h"
#include "GeomResize.h"

namespace dip {

	class DIPLearning : public MyImgLoader, public GeomResize
	{

		class dip::MyImgLoader* MyImgL = new dip::MyImgLoader;

	public:
		DIPLearning();
	private:
	};
} // dip end namespace
