#include "GameScene.h"
#include <Dxlib.h>
#include "SceneMng.h"
#include "../common/ImageMng.h"
#include "TitleScene.h"
#include "../_debug/_DebugConOut.h"
#include "../Object/Player.h"

GameScene::GameScene()
{
	TRACE("DISPLAY GAME SCENE \n");
	lpImageMng.GetID("ｷｬﾗ", "image/BossEnemy_Idle(39x56).png", { 39,56 }, { 4,1 });		// LoadDivGraph Player Image
	lpImageMng.GetID("Char Front Walk", "image/BossEnemy_FrontWalk(39x56).png", { 39,56 }, { 4,1 });
	lpImageMng.GetID("Char Back Walk", "image/BossEnemy_BackWalk(39x56).png", { 39,56 }, { 4,1 });
	lpImageMng.GetID("Char Left Walk", "image/BossEnemy_LeftWalk(39x56).png", { 39,56 }, { 4,1 });
	lpImageMng.GetID("Char Right Walk", "image/BossEnemy_RightWalk(39x56).png", { 39,56 }, { 4,1 });

	// Create player object and push to _objList
	_objList.emplace_back(
		new Player({ lpSceneMng.GameScreenSize.x / 2.0 - 64 ,lpSceneMng.GameScreenSize.y /2.0  }, { 30,32 },DX_INPUT_PAD1)
	);
	_objList.emplace_back(
		new Player({ lpSceneMng.GameScreenSize.x / 2.0 ,lpSceneMng.GameScreenSize.y / 2.0 }, { 30,32 }, DX_INPUT_PAD2)
	);
	_objList.emplace_back(
		new Player({ lpSceneMng.GameScreenSize.x / 2.0 + 64 ,lpSceneMng.GameScreenSize.y / 2.0 }, { 30,32 }, DX_INPUT_PAD3)
	);

}

GameScene::~GameScene()
{
}

unique_Base GameScene::Update(unique_Base own)
{
	// プレイヤーオブジェクトポインタを検索
	auto plObj = std::find_if(_objList.begin(), _objList.end(), 
		[&](sharedObj obj) {return (*obj).unitID() == UNIT_ID::PLAYER; });	

	if ((*plObj)->isDead())				// プレイヤーが死亡した場合、タイトルシーンに戻る
	{
		_objList.clear();
		return std::make_unique<TitleScene>();

	}

	// Update information each object in _objList in each frame
	for (auto data : _objList)
	{
		(*data).Update(*plObj);
	}

	// Draw each object in _objLists
	for (auto data : _objList)
	{
		(*data).Draw();
	}

	// Purpose : Change to TitleScene when player is dead
	if ((*plObj)->isDead())
	{
		return std::make_unique<TitleScene>();
	}

	// itr 消したい要素の先頭アドレス
	auto itr = std::remove_if(
		_objList.begin(),	// ﾁｪｯｸ範囲の開始
		_objList.end(),		// ﾁｪｯｸ範囲の終了
		[](sharedObj& obj) {return(*obj).isDead(); } 	// 死んでるやつを除外 ここは真偽を必ず返す(プレディケート)
	);
	_objList.erase(itr, _objList.end());



	return std::move(own);
}
