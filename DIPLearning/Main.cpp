#include "DIPLearning.h"
#include <iostream>

int main(int argc, char** argv)
{
	dip::DIPLearning* MyMonoProccessing = new dip::DIPLearning;
	dip::DIPLearning* MyColorProcessing = new dip::DIPLearning;

	MyMonoProccessing->imgResize(&MyMonoProccessing->getMonoImgs());

	MyMonoProccessing->myShowImgs(&MyMonoProccessing->getResizedImages());

	// Uncomment to show current images
	//MyMonoProccessing->myShowImgs(&MyMonoProccessing->getMonoImgs());
	//MyColorProcessing->myShowImgs(&MyColorProcessing->getColorImgs());

	// Have to be changed to run Aim img resize
	//MyMonoProccessing->setImgs(&MyMonoProccessing->getMonoImgs());
	//MyColorProcessing->setImgs(&MyColorProcessing->getColorImgs());

	// Uncoment to check largest img size
	//std::cout << "The largest Mono img size is: " 
	//	<< MyMonoProccessing->getImgWidth()
	//	<< " x " 
	//	<< MyMonoProccessing->getImgHeight()
	//	<< "\nThe largest Color img size is: "
	//	<< MyColorProcessing->getImgWidth()
	//	<< " x " 
	//	<< MyColorProcessing->getImgHeight()
	//	<< std::endl;

	cv::waitKey(0);

	MyMonoProccessing = nullptr;
	delete MyMonoProccessing;

	return 0;
}