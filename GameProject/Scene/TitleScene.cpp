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
	//// �摜��ǂݍ���
	//backGroundImage = LoadGraph("Graphic/Title Scene Image/background.png", true);		// �w�i
	//characterImage= LoadGraph("Graphic/Title Scene Image/character.png", true);			// �L�����N�^�[
	//jailImage = LoadGraph("Graphic/Title Scene Image/jail.png", true);					// �B
	//lockImage = LoadGraph("Graphic/Title Scene Image/lock.png", true);					// ��

	// Use Image Manager to load image ID
	// �摜��ǂݍ���
	lpImageMng.GetID("�w�i", "Graphic/Title Scene Image/background.png");
	lpImageMng.GetID("�L�����N�^�[", "Graphic/Title Scene Image/character.png");
	lpImageMng.GetID("�B", "Graphic/Title Scene Image/jail.png");
	lpImageMng.GetID("��", "Graphic/Title Scene Image/lock.png");

	// �摜����ۑ�
	//GetGraphSize(characterImage, &characterImageSize.x, &characterImageSize.y);			// �L�����N�^�[�T�C�Y�擾
	//characterImagePos = { (SCREEN_SIZE_X - characterImageSize.x) / 2,SCREEN_SIZE_Y - characterImageSize.y }; 

	//jailImg = new Texture(jailImage, 0, 0);												// �B
	//lockImg = new Texture(lockImage, SCREEN_SIZE_X / 2, SCREEN_SIZE_Y / 2+200);			// ��
}

TitleScene::~TitleScene()
{
	// �摜�폜
	//DeleteGraph(jailImage, true);			// �w�i
	//DeleteGraph(jailImage, true);			// �L�����N�^�[
	//DeleteGraph(characterImage, true);		// �B
	//DeleteGraph(backGroundImage, true);		// ��
}

void TitleScene::input()
{
}

activeScene TitleScene::update(activeScene scene)
{
	Pad::GetInstance().update();
	//switchScene();


	// Add images' information to _drawList
	lpSceneMng.AddDrawQue({ IMAGE_ID("�w�i")[0],SCREEN_SIZE_X / 2,SCREEN_SIZE_Y / 2,0 });
	lpSceneMng.AddDrawQue({ IMAGE_ID("�L�����N�^�[")[0],SCREEN_SIZE_X / 2,SCREEN_SIZE_Y / 2,0 });
	lpSceneMng.AddDrawQue({ IMAGE_ID("�B")[0],SCREEN_SIZE_X / 2,SCREEN_SIZE_Y / 2,0 });
	lpSceneMng.AddDrawQue({ IMAGE_ID("��")[0],SCREEN_SIZE_X / 2,SCREEN_SIZE_Y / 2 + 200,0 });

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
	//// �摜�`��
	//DrawGraph(0, 0, backGroundImage, true);												// �w�i
	//DrawGraph(characterImagePos.x, characterImagePos.y,characterImage, true);			// �L�����N�^�[
	//jailImg->drawTextureNomal();														// �B
	//lockImg->drawTextureCenter();														// ��(�摜���S�ʒu�ɕ`��)

}

void TitleScene::switchScene()
{


}
