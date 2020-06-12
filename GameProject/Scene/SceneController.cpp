//-------------------------------------------------
//--------------Project by ------------------------
//----------------------koshiro kawanami-----------
//-------------------------------------------------
#include <iostream>
#include <memory>
#include "DxLib.h"
#include "BaseScene.h"
#include "SceneController.h"
#include "TitleScene.h"
#include "GameScene.h"


FILE* File;

// Create new static pointer
std::unique_ptr<SceneController, SceneController::SceneControllerDeleter> SceneController::sInstance(new SceneController());

bool SceneController::AddDrawQue(DrawQueT dQue)
{
    if (std::get<static_cast<int>(DRAW_QUE::IMAGE)>(dQue) <= 0) 	// std::get<何番目>で取り出す
    {
        // 画像IDが不正なので、追加しない
        return false;
    }
    // Queを追加
    // _drawList.push_back(); 要素を追加するときに使う

    _drawList.emplace_back(dQue);
    return true;
	
}

SceneController::SceneController()
{
    AllocConsole();
    freopen_s(
        &File,
        "CONIN$",	// const char * _Filename
        "r",		// const char * _Mode
        stdin);		// FILE * _File
    freopen_s(
        &File,
        "CONOUT$",	// const char * _Filename
        "w",		// const char * _Mode
        stdout);	// FILE * _File

    SetWindowText("Endless Prison");
    ChangeWindowMode(true);
    SetGraphMode(SCREEN_SIZE_X, SCREEN_SIZE_Y, 32);
    // ＤＸライブラリ初期化処理
    if (DxLib_Init() == 0)
    {
        //nowScene = std::make_unique<TitleScene>();
        //nowScene.reset(new TitleScene);

    }
     
    SetDrawScreen(DX_SCREEN_BACK);

    // エラーが起きたら直ちに終了
}

SceneController::~SceneController()
{
    DxLib_End();

}

void SceneController::changeScene(BaseScene* scene)
{
    _activeScene.reset(scene);
}

int SceneController::run() {

    _activeScene = std::make_unique<TitleScene>();
    // メインループ.
    while (!CheckHitKey(KEY_INPUT_ESCAPE) && !ProcessMessage()) 
    {

        _drawList.clear();
        // シーンに応じた処理を行う.
        
        /*_activeScene->input();*/
        _activeScene = _activeScene->update(std::move(_activeScene));

        
        Draw();
    }

    return 0;
}
void SceneController::Draw()
{
    SetDrawScreen(DX_SCREEN_BACK);
    ClsDrawScreen();

    // ｽﾀｯｸにたまっているQUEを描画する
    for (auto dQue : _drawList)
    {
        double x, y, rad;
        int id;

        std::tie(id, x, y, rad) = dQue;

        // Queの内容を描画する
        DrawRotaGraph(
            x,
            y,
            1.0,
            rad,
            id,
            true);
    }

    /*SetDrawScreen(DX_SCREEN_BACK);*/
    ScreenFlip();
}
;