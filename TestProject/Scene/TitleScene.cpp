#include "TitleScene.h"
#include <Dxlib.h>
#include "SceneMng.h"
#include "../common/ImageMng.h"


TitleScene::TitleScene()
{
}


TitleScene::~TitleScene()
{
}

unique_Base TitleScene::Update(unique_Base own)
{
	lpSceneMng.AddDrawQueT({ IMAGE_ID("bg")[0],lpSceneMng.ScreenCenter.x,lpSceneMng.ScreenCenter.y,0 });
	lpSceneMng.AddDrawQueT({ IMAGE_ID("character")[0],lpSceneMng.ScreenCenter.x,lpSceneMng.ScreenCenter.y,0 });
	lpSceneMng.AddDrawQueT({ IMAGE_ID("jail")[0],lpSceneMng.ScreenCenter.x,lpSceneMng.ScreenCenter.y,0 });
	lpSceneMng.AddDrawQueT({ IMAGE_ID("lock")[0],lpSceneMng.ScreenCenter.x-10,lpSceneMng.ScreenCenter.y+250,0 });
	lpSceneMng.AddDrawQueT({ IMAGE_ID("button")[0],lpSceneMng.ScreenCenter.x-10,lpSceneMng.ScreenCenter.y+250,0 });

	if (CheckHitKey(KEY_INPUT_SPACE))
	{
		//return std::make_unique<GameScene>();
	}

	return std::move(own);
}
