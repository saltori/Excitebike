#include"DxLib.h"
#include "ImageMng.h"



std::unique_ptr<ImageMng, ImageMng::ImageMngDeleter> ImageMng::s_Instance(new ImageMng());

ImageMng::ImageMng()
{
}


ImageMng::~ImageMng()
{
}

const VEC_INT & ImageMng::GetID(std::string f_name)
{
	if (imagMap.find(f_name) == imagMap.end())
	{
		imagMap[f_name].resize(1);
		imagMap[f_name][0] = LoadGraph(f_name.c_str());
	}
	return imagMap[f_name];
}

const VEC_INT & ImageMng::GetID(std::string f_name, VECTOR2 divSize, VECTOR2 divCnt, VECTOR2 chipOffset)
{
	if (imagMap.find(f_name) == imagMap.end())
	{
		imagMap[f_name].resize(divCnt.x * divCnt.y);
		imagMap[f_name][0] = LoadDivGraph(f_name.c_str(), divCnt.x*divCnt.y, divCnt.x, divCnt.y, divSize.x, divSize.y, &imagMap[f_name][0], true);
	}
	return imagMap[f_name];
}