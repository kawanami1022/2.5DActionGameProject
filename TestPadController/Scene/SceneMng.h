#pragma once
#include "../common/Vector2.h"
#include "BaseScene.h"
#include <tuple>
#include <vector>

enum class DRAW_QUE // enum�͌^���B�� class�������class�������O��Ԃ�����X�Ƃ������O�������ł��Ⴄ���̂ɂȂ� 
{
	IMAGE,				// �摜ID	
	X,
	Y,
	RAD
};

using DrawQueT = std::tuple<int, double, double, double>;		// 4��,��]�p

#define lpSceneMng SceneMng::GetInstance()

class SceneMng
{
public:
	static SceneMng& GetInstance(void)
	{
		Create();
		return *sInstance;
	}

	static void Create()
	{
		if (sInstance == nullptr)
		{
			sInstance = new SceneMng();
		}
	}

	static void Destroy()
	{
		if (sInstance != nullptr)
		{
			delete sInstance;
		}
		sInstance = nullptr; // ��ذĂ��Ă��Ђ��̂��邩��null�������
	}

	void Run(void);		

	bool AddDrawQue(DrawQueT dQue);

	const Vector2 ScreenSize;
	const Vector2 ScreenCenter;
	const Vector2 GameScreenSize;
	const Vector2 GameScreenOffset;
	const int frame(void);

private:
	static SceneMng* sInstance; // �N���X�|�C���^�̐錾����

	std::vector<DrawQueT> _drawList;

	unique_Base _activeScene;

	void Draw(void);

	int _frame;

	SceneMng();
	~SceneMng();
	bool SysInit(void);
};

