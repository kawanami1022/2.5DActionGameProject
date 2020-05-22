#pragma once
#include <memory>
#include <map>
#include <vector>
#include "Vector2.h"
#include <string>

using VecInt = std::vector<int>;

#define lpImageMng ImageMng::GetInstance()
#define IMAGE_ID(KEY) (ImageMng::GetInstance().GetID(KEY))

class ImageMng
{
public:
	static ImageMng& GetInstance(void)
	{
		return *sInstance;
	}

	const VecInt& GetID(const std::string& key); // �Q�Ɠn��
	const VecInt& GetID(const std::string& key, const std::string& fileName);
	const VecInt& GetID(const std::string& key, const std::string& fileName, const Vector2& divSize, const Vector2& divCnt);

private:
	struct ImageMngDeleter
	{
		void operator()(ImageMng* ImageMng) const // ��ځ@�I�[�o�[���[�h�������@��ځ@�E�ӎ�������ذĂ����������E���ɏ���
		{
			delete ImageMng;
		}
	};

	static std::unique_ptr<ImageMng, ImageMngDeleter> sInstance;

	ImageMng();
	~ImageMng();

	//�f�t�H���g��ذ���~imageMng();
	//������ذ���@�������������ذ��

	std::map<std::string, VecInt> ImgMap;
};

