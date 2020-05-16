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
    ChangeWindowMode(true);
    SetGraphMode(800, 800, 32);
    // ＤＸライブラリ初期化処理
    if (DxLib_Init() == 0)
    {
        nowScene = std::make_unique<GameScene>();
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