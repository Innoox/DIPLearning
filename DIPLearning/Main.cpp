#include "DIPLearning.h"
#include <iostream>

int main(int argc, char** argv)
{
	dip::DIPLearning* MyMonoProccessing = new dip::DIPLearning;
	dip::DIPLearning* MyColorProcessing = new dip::DIPLearning;

	// Geometrical image resizing
	MyMonoProccessing->imgGeomResize(&MyMonoProccessing->getMonoImgs());
	MyColorProcessing->imgGeomResize(&MyColorProcessing->getColorImgs());

	// Raster image resize
	MyMonoProccessing->imgRastResize(&MyMonoProccessing->getMonoImgs());
	MyColorProcessing->imgRastResize(&MyColorProcessing->getColorImgs());

	// Uncoment to Show Result
	MyMonoProccessing->myShowImgs(&MyMonoProccessing->getGeomResizedImages());
	MyColorProcessing->myShowImgs(&MyColorProcessing->getGeomResizedImages());
	MyMonoProccessing->myShowImgs(&MyMonoProccessing->getRastResizedImages());
	MyColorProcessing->myShowImgs(&MyColorProcessing->getRastResizedImages());


	cv::waitKey(0);

	MyMonoProccessing = nullptr;
	MyColorProcessing = nullptr;
	delete MyMonoProccessing, MyColorProcessing;

	return 0;
}