//-------------------------------------------------
//--------------Project by ------------------------
//----------------------koshiro kawanami-----------
//-------------------------------------------------
#include "DxLib.h"

#include "../Collision2D/collision.h"
#include "SceneController.h"
#include "BaseScene.h"
#include "GameScene.h"
#include "../Input/PadInput.h"
#include "../Obj/Player/Player.h"
#include "../Obj/Obj.h"
#include "../Obj/map/Map.h"


GameScene::GameScene()
{
	player = new Player({500.0,300.0}, {32.0,32.0});
	map = new Map();
}

GameScene::~GameScene()
{
	delete player;
	delete map;
}


void GameScene::input()
{
}

activeScene GameScene::update(activeScene scene)
{
	Pad::GetInstance().update();
	move();
	player->savePos();
	map->setPos();
	draw();
	return scene;
}

void GameScene::draw()
{
	map->draw();
	player->draw();
}

// 目的: オブジェクト移動
void GameScene::move()
{
	// アナログスティック左
	short LStickPos[2] = { Pad::GetInstance().getXInput(STATE_ID_NOW).ThumbLX ,Pad::GetInstance().getXInput(STATE_ID_NOW).ThumbLY };
	player->calcVelocity(LStickPos);
	// プレーヤー座標
	int plPos[2] = { (int)player->getPos().x, (int)player->getPos().y};
	int mpPosChX[2] = { 0,CHIP_CNT_X * CHIP_SIZE_X - SCREEN_SIZE_X };		// マップ座標の左右隅
	int mpPosChY[2] = { 0,CHIP_CNT_Y * CHIP_SIZE_Y - SCREEN_SIZE_Y };		// マップ座標の上下隅
	int scrPosChX[2] = { 100,SCREEN_SIZE_X - 100 };
	int scrPosChY[2] = { 100,SCREEN_SIZE_Y - 100 };
	
	if(Pad::GetInstance().checkStickDeadzone(Pad::GetInstance().getXInput(STATE_ID_NOW).ThumbLX,
		Pad::GetInstance().getXInput(STATE_ID_NOW).ThumbLY,
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
		player->setAngle(Pad::GetInstance().getAngleLeft());

	}
}

//目的	:true プレーヤーを動かす	false マップを動かす
//入力	:mapPosLU				mapがｽｸﾘｰﾝの右端の座標
//		:mapPosRD				mapがｽｸﾘｰﾝの左端の座標
//		:screenPosLU			マップを移動左上座標
//		:screenPosRD			マップを移動右下座標
bool GameScene::checkMoveObj(int* mpPosCh, int* scrPosCh,int plVel,int plPos,int mpPos)
{
	// 0:左上　1:右下
	// 移動量(-)
	if ( plVel< 0)
	{	
		// 
		if (scrPosCh[0] < plPos)
		{
			return true;
		}
		// マップがｽｸﾘｰﾝの左端
		if (mpPos <= mpPosCh[0])
		{
			return true;
		}
		else{
			return false;
		}
	}
	// 移動量(+)
	else if(0 < plVel)
	{
		if (plPos < scrPosCh[1])
		{
			return true;
		}
		// マップがｽｸﾘｰﾝの右端
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


