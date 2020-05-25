//-------------------------------------------------
//--------------Project by ------------------------
//----------------------koshiro kawanami-----------
//-------------------------------------------------
#include <DxLib.h>
#include "SceneController.h"
#include "BaseScene.h"
#include "TitleScene.h"
#include "../Input/PadInput.h"

TitleScene::TitleScene()
{
	// GrHandle
	backGroundImage = LoadGraph("Graphic/Title Scene Image/background.png", true);
	characterImage= LoadGraph("Graphic/Title Scene Image/character.png", true);
	jailImage = LoadGraph("Graphic/Title Scene Image/jail.png", true);

	// ‰æ‘œî•ñ‚ð•Û‘¶
	GetGraphSize(characterImage, &characterImageSize.x, &characterImageSize.y);
	characterImagePos = { (SCREEN_SIZE_X - characterImageSize.x) / 2,SCREEN_SIZE_Y - characterImageSize.y }; 

	jailImg = new Texture(jailImage, 0, 0);
}

TitleScene::~TitleScene()
{
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
}
