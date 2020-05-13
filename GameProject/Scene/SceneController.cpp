//-------------------------------------------------
//--------------Project by ------------------------
//----------------------koshiro kawanami-----------
//-------------------------------------------------
#include <memory>
#include "DxLib.h"
#include "BaseScene.h"
#include "SceneController.h"
#include "TitleScene.h"
#include "GameScene.h"


SceneController::SceneController()
{
    nowScene = std::make_unique<GameScene>();
}

SceneController::~SceneController()
{

}

int SceneController::run() {

    ChangeWindowMode(true);
    SetGraphMode(800, 800, 32);
    // ＤＸライブラリ初期化処理
    if (DxLib_Init() == -1)
    {
        return -1;        // エラーが起きたら直ちに終了
    }
    // メインループ.
    while (!CheckHitKey(KEY_INPUT_ESCAPE) && !ProcessMessage()) 
    {
        ClsDrawScreen();
        // シーンに応じた処理を行う.
        nowScene->update();
        nowScene->draw();
        ScreenFlip();
    }

    DxLib_End();
    return 0;
};