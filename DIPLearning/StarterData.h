#pragma once

#include <string>

/*
	This class is simple container for the
	basic data input like:
	- source images path
	- reade write images path
	Created to simplify using of the data
*/

namespace mySTD
{
	class StarterData
	{
	public:
		StarterData();

		std::string getColorImagesSourceFolder();
		std::string getMonoImageSourceFolder();
	private:
		// Folder with source images for the program
		std::string __ColorImagesSourceFolder;
		std::string __MonoImageSourceFolder;
		// Folder to cover the result images
		// Geometric image resizing
		std::string __GeometricResizingMonoImagesOutputFolder;
		std::string __GeometricResizingColorImagesOutputFolder;
	};
} // mySTD namespace end