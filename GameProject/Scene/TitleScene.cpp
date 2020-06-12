//-------------------------------------------------
//--------------Project by ------------------------
//----------------------koshiro kawanami-----------
//-------------------------------------------------
#include <DxLib.h>
#include <iostream>
#include "SceneController.h"
#include "BaseScene.h"
#include "TitleScene.h"
#include "GameScene.h"
#include "../ImageMng/ImageMng.h"
#include "../Scene/SceneController.h"
#include "../Input/PadInput.h"

TitleScene::TitleScene()
{
	//// 画像を読み込む
	//backGroundImage = LoadGraph("Graphic/Title Scene Image/background.png", true);		// 背景
	//characterImage= LoadGraph("Graphic/Title Scene Image/character.png", true);			// キャラクター
	//jailImage = LoadGraph("Graphic/Title Scene Image/jail.png", true);					// 檻
	//lockImage = LoadGraph("Graphic/Title Scene Image/lock.png", true);					// 鍵

	// Use Image Manager to load image ID
	// 画像を読み込む
	lpImageMng.GetID("背景", "Graphic/Title Scene Image/background.png");
	lpImageMng.GetID("キャラクター", "Graphic/Title Scene Image/character.png");
	lpImageMng.GetID("檻", "Graphic/Title Scene Image/jail.png");
	lpImageMng.GetID("鍵", "Graphic/Title Scene Image/lock.png");

	// 画像情報を保存
	//GetGraphSize(characterImage, &characterImageSize.x, &characterImageSize.y);			// キャラクターサイズ取得
	//characterImagePos = { (SCREEN_SIZE_X - characterImageSize.x) / 2,SCREEN_SIZE_Y - characterImageSize.y }; 

	//jailImg = new Texture(jailImage, 0, 0);												// 檻
	//lockImg = new Texture(lockImage, SCREEN_SIZE_X / 2, SCREEN_SIZE_Y / 2+200);			// 鍵
}

TitleScene::~TitleScene()
{
	// 画像削除
	//DeleteGraph(jailImage, true);			// 背景
	//DeleteGraph(jailImage, true);			// キャラクター
	//DeleteGraph(characterImage, true);		// 檻
	//DeleteGraph(backGroundImage, true);		// 鍵
}

void TitleScene::input()
{
}

activeScene TitleScene::update(activeScene scene)
{
	Pad::GetInstance().update();
	//switchScene();


	// Add images' information to _drawList
	lpSceneMng.AddDrawQue({ IMAGE_ID("背景")[0],SCREEN_SIZE_X / 2,SCREEN_SIZE_Y / 2,0 });
	lpSceneMng.AddDrawQue({ IMAGE_ID("キャラクター")[0],SCREEN_SIZE_X / 2,SCREEN_SIZE_Y / 2,0 });
	lpSceneMng.AddDrawQue({ IMAGE_ID("檻")[0],SCREEN_SIZE_X / 2,SCREEN_SIZE_Y / 2,0 });
	lpSceneMng.AddDrawQue({ IMAGE_ID("鍵")[0],SCREEN_SIZE_X / 2,SCREEN_SIZE_Y / 2 + 200,0 });

	if (Pad::GetInstance().Push(BUTTON_ID_A))
	{
		std::cout << "BUTTON_ID_A" << std::endl;
		return std::make_unique<GameScene>();
	}
	Pad::GetInstance().saveInputState();
	return std::move(scene);
}

void TitleScene::draw()
{
	//// 画像描画
	//DrawGraph(0, 0, backGroundImage, true);												// 背景
	//DrawGraph(characterImagePos.x, characterImagePos.y,characterImage, true);			// キャラクター
	//jailImg->drawTextureNomal();														// 檻
	//lockImg->drawTextureCenter();														// 鍵(画像中心位置に描画)

}

void TitleScene::switchScene()
{


}
