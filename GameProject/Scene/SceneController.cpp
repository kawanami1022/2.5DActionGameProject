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
    // �c�w���C�u��������������
    if (DxLib_Init() == 0)
    {
        nowScene = std::make_unique<GameScene>();
    }
      
    // �G���[���N�����璼���ɏI��
}

SceneController::~SceneController()
{
    DxLib_End();

}

int SceneController::run() {


    // ���C�����[�v.
    while (!CheckHitKey(KEY_INPUT_ESCAPE) && !ProcessMessage()) 
    {
        ClsDrawScreen();
        // �V�[���ɉ������������s��.
        nowScene->update();
        nowScene->draw();
        ScreenFlip();
    }

    return 0;
};