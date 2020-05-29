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

TitleScene::TitleScene()
{
	// ‰æ‘œ‚ð“Ç‚Ýž‚Þ
	backGroundImage = LoadGraph("Graphic/Title Scene Image/background.png", true);		// ”wŒi
	characterImage= LoadGraph("Graphic/Title Scene Image/character.png", true);			// ƒLƒƒƒ‰ƒNƒ^[
	jailImage = LoadGraph("Graphic/Title Scene Image/jail.png", true);					// ŸB
	lockImage = LoadGraph("Graphic/Title Scene Image/lock.png", true);					// Œ®

	// ‰æ‘œî•ñ‚ð•Û‘¶
	GetGraphSize(characterImage, &characterImageSize.x, &characterImageSize.y);			// ƒLƒƒƒ‰ƒNƒ^[ƒTƒCƒYŽæ“¾
	characterImagePos = { (SCREEN_SIZE_X - characterImageSize.x) / 2,SCREEN_SIZE_Y - characterImageSize.y }; 

	jailImg = new Texture(jailImage, 0, 0);												// ŸB
	lockImg = new Texture(lockImage, SCREEN_SIZE_X / 2, SCREEN_SIZE_Y / 2+200);			// Œ®
}

TitleScene::~TitleScene()
{
	// ‰æ‘œíœ
	DeleteGraph(jailImage, true);			// ”wŒi
	DeleteGraph(jailImage, true);			// ƒLƒƒƒ‰ƒNƒ^[
	DeleteGraph(characterImage, true);		// ŸB
	DeleteGraph(backGroundImage, true);		// Œ®
}

void TitleScene::input()
{
}

void TitleScene::update()
{
	pad->update();
	switchScene();
	pad->saveInput();
}

void TitleScene::draw()
{
	// ‰æ‘œ•`‰æ
	DrawGraph(0, 0, backGroundImage, true);												// ”wŒi
	DrawGraph(characterImagePos.x, characterImagePos.y,characterImage, true);			// ƒLƒƒƒ‰ƒNƒ^[
	jailImg->drawTextureNomal();														// ŸB
	lockImg->drawTextureCenter();														// Œ®(‰æ‘œ’†SˆÊ’u‚É•`‰æ)
}

void TitleScene::switchScene()
{
	if (pad->Push(BUTTON_ID_A))
	{
		std::cout << "BUTTON_ID_A" << std::endl;

	}

}
