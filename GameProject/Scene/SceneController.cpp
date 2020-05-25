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

    ChangeWindowMode(true);
    SetGraphMode(SCREEN_SIZE_X, SCREEN_SIZE_Y, 32);
    // ＤＸライブラリ初期化処理
    if (DxLib_Init() == 0)
    {
        nowScene = std::make_unique<TitleScene>();
    }
     
    // エラーが起きたら直ちに終了
}

SceneController::~SceneController()
{
    DxLib_End();

}

int SceneController::run() {


    // メインループ.
    while (!CheckHitKey(KEY_INPUT_ESCAPE) && !ProcessMessage()) 
    {
        ClsDrawScreen();
        // シーンに応じた処理を行う.
        nowScene->update();
        nowScene->draw();
        ScreenFlip();
    }

    return 0;
};