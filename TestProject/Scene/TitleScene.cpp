#include "TitleScene.h"
#include <Dxlib.h>
#include "SceneMng.h"
#include "../common/ImageMng.h"
#include "GameScene.h"


TitleScene::TitleScene()
{
}


TitleScene::~TitleScene()
{
}

unique_Base TitleScene::Update(unique_Base own)
{
	lpSceneMng.AddDrawQue({ IMAGE_ID("bg")[0],lpSceneMng.ScreenCenter.x,lpSceneMng.ScreenCenter.y,0 });


	if (CheckHitKey(KEY_INPUT_SPACE))
	{
		return std::make_unique<GameScene>();
	}

	return std::move(own);
}
