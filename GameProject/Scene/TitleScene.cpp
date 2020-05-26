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
	// �摜��ǂݍ���
	backGroundImage = LoadGraph("Graphic/Title Scene Image/background.png", true);		// �w�i
	characterImage= LoadGraph("Graphic/Title Scene Image/character.png", true);			// �L�����N�^�[
	jailImage = LoadGraph("Graphic/Title Scene Image/jail.png", true);					// �B
	lockImage = LoadGraph("Graphic/Title Scene Image/lock.png", true);					// ��

	// �摜����ۑ�
	GetGraphSize(characterImage, &characterImageSize.x, &characterImageSize.y);			// �L�����N�^�[�T�C�Y�擾
	characterImagePos = { (SCREEN_SIZE_X - characterImageSize.x) / 2,SCREEN_SIZE_Y - characterImageSize.y }; 

	jailImg = new Texture(jailImage, 0, 0);												// �B
	lockImg = new Texture(lockImage, SCREEN_SIZE_X / 2, SCREEN_SIZE_Y / 2+200);			// ��
}

TitleScene::~TitleScene()
{
	// �摜�폜
	DeleteGraph(jailImage, true);			// �w�i
	DeleteGraph(jailImage, true);			// �L�����N�^�[
	DeleteGraph(characterImage, true);		// �B
	DeleteGraph(backGroundImage, true);		// ��
}

void TitleScene::update()
{

}

void TitleScene::draw()
{
	// �摜�`��
	DrawGraph(0, 0, backGroundImage, true);												// �w�i
	DrawGraph(characterImagePos.x, characterImagePos.y,characterImage, true);			// �L�����N�^�[
	jailImg->drawTextureNomal();														// �B
	lockImg->drawTextureCenter();														// ��(�摜���S�ʒu�ɕ`��)
}
