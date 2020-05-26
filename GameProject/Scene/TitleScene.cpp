//-------------------------------------------------
//--------------Project by ------------------------
//----------------------koshiro kawanami-----------
//-------------------------------------------------
#include <DxLib.h>
#include "SceneController.h"
#include "BaseScene.h"
#include "TitleScene.h"

TitleScene::TitleScene()
{
	// GrHandle
	backGroundImage = LoadGraph("Graphic/Title Scene Image/background.png", true);
	characterImage= LoadGraph("Graphic/Title Scene Image/character.png", true);
	jailImage = LoadGraph("Graphic/Title Scene Image/jail.png", true);
	lockImage = LoadGraph("Graphic/Title Scene Image/lock.png", true);

	// �摜����ۑ�
	GetGraphSize(characterImage, &characterImageSize.x, &characterImageSize.y);
	characterImagePos = { (SCREEN_SIZE_X - characterImageSize.x) / 2,SCREEN_SIZE_Y - characterImageSize.y }; 

	jailImg = new Texture(jailImage, 0, 0);
	lockImg = new Texture(lockImage, SCREEN_SIZE_X / 2, SCREEN_SIZE_Y / 2+200);
}

TitleScene::~TitleScene()
{
	DeleteGraph(jailImage, true);
	DeleteGraph(jailImage, true);
	DeleteGraph(characterImage, true);
	DeleteGraph(backGroundImage, true);
}

void TitleScene::update()
{

}

void TitleScene::draw()
{

	DrawGraph(0, 0, backGroundImage, true);
	DrawGraph(characterImagePos.x, characterImagePos.y,characterImage, true);
	jailImg->drawTextureNomal();
	lockImg->drawTextureCenter();
}
