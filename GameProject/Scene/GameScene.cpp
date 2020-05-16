//-------------------------------------------------
//--------------Project by ------------------------
//----------------------koshiro kawanami-----------
//-------------------------------------------------
#include "DxLib.h"
//#include "../Input/InputManager.h"
//#include "../Input/PadInput.h"
#include "../Collision2D/collision.h"
#include "SceneController.h"
#include "BaseScene.h"
#include "GameScene.h"


GameScene::GameScene()
{
	pad = new Pad();
	player = new Player();
	map = new Map();
}

GameScene::~GameScene()
{
	delete pad;
	delete player;
	delete map;
}

void GameScene::update()
{
	pad->update();
	player->setAngle(pad->getAngleLeft());
	move();
	player->setPos();
	map->setPos();

}

void GameScene::draw()
{
	map->draw();
	player->draw();
}

// �ړI: �I�u�W�F�N�g�ړ�
void GameScene::move()
{
	// �A�i���O�X�e�B�b�N��
	short LStickPos[2] = { pad->getXInput(STATE_ID_NOW).ThumbLX ,pad->getXInput(STATE_ID_NOW).ThumbLY };
	player->calcVelocity(LStickPos);
	// �v���[���[���W
	int plPos[2] = { (int)player->getPos().x, (int)player->getPos().y};
	int mpPosChX[2] = { 0,CHIP_CNT_X * CHIP_SIZE_X - SCREEN_SIZE_X };		// �}�b�v���W�̍��E��
	int mpPosChY[2] = { 0,CHIP_CNT_Y * CHIP_SIZE_Y - SCREEN_SIZE_Y };		// �}�b�v���W�̏㉺��
	int scrPosChX[2] = { 100,SCREEN_SIZE_X - 100 };
	int scrPosChY[2] = { 100,SCREEN_SIZE_Y - 100 };
	
	if(pad->checkStickDeadzone(pad->getXInput(STATE_ID_NOW).ThumbLX,
								pad->getXInput(STATE_ID_NOW).ThumbLY,
								PAD_INPUT_1,0.2))
	{
		//Player movement range		true:player move	false:map move
		if (checkMoveObj(mpPosChX, scrPosChX,
			player->getVelocity().x,
			player->getPos().x,
			map->getPos().x))
		{
			player->moveX();
		}
		else
		{
			map->moveX(player->getVelocity(), mpPosChX);
		}

		if (checkMoveObj(mpPosChY, scrPosChY,
			player->getVelocity().y,
			player->getPos().y,
			map->getPos().y))
		{
			player->moveY();
		}
		else
		{
			map->moveY(player->getVelocity(), mpPosChY);
		}
	}
}

//�ړI	:true �v���[���[�𓮂���	false �}�b�v�𓮂���
//����	:mapPosLU				map����ذ݂̉E�[�̍��W
//		:mapPosRD				map����ذ݂̍��[�̍��W
//		:screenPosLU			�}�b�v���ړ�������W
//		:screenPosRD			�}�b�v���ړ��E�����W
bool GameScene::checkMoveObj(int* mpPosCh, int* scrPosCh,int plVel,int plPos,int mpPos)
{
	// 0:����@1:�E��
	// �ړ���(-)
	if ( plVel< 0)
	{	
		// 
		if (scrPosCh[0] < plPos)
		{
			return true;
		}
		// �}�b�v����ذ݂̍��[
		if (mpPos <= mpPosCh[0])
		{
			return true;
		}
		else{
			return false;
		}
	}
	// �ړ���(+)
	else if(0 < plVel)
	{
		if (plPos < scrPosCh[1])
		{
			return true;
		}
		// �}�b�v����ذ݂̉E�[
		if (mpPosCh[1] <= mpPos)
		{
			return true;
		}
		else {
			return false;
		}
	}

	
	return false;
}


