#include <DxLib.h>
#include "ImageMng.h"

std::unique_ptr<ImageMng, ImageMng::ImageMngDeleter> ImageMng::sInstance(new ImageMng());

const VecInt& ImageMng::GetID(const std::string& key)
{
	return GetID(key, key);
}

const VecInt& ImageMng::GetID(const std::string& key, const std::string& fileName)
{
	if (ImgMap.find(key) == ImgMap.end())
	{
		ImgMap[key].resize(1);
		ImgMap[key][0] = LoadGraph(fileName.c_str());
	}
	return ImgMap[key];
}

const VecInt& ImageMng::GetID(const std::string& key, const std::string& fileName, const Vector2<int>& divSize, const Vector2<int>& divCnt)
{
	if (ImgMap.find(key) == ImgMap.end())
	{
		/*VecInt tmpData;
		tmpData.resize(divCnt.x * divCnt.y);
		if (LoadDivGraph(fileName.c_str(), divCnt.x * divCnt.y, divCnt.x, divCnt.y, divSize.x, divSize.y, &tmpData[0]) == 0)
		{
			imgMap[key] = std::move(tmpData);
		}*/
		/*else
		{
			 return std::move(tmpData);
		}*/
		//return imgMap[key];
		ImgMap[key].resize(divCnt.x * divCnt.y);
		LoadDivGraph(fileName.c_str(), divCnt.x * divCnt.y, divCnt.x, divCnt.y, divSize.x, divSize.y, &ImgMap[key][0]);
	}
	return ImgMap[key];
}

ImageMng::ImageMng()
{
}


ImageMng::~ImageMng()
{
}