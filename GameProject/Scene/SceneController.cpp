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
    // �c�w���C�u��������������
    if (DxLib_Init() == -1)
    {
        return -1;        // �G���[���N�����璼���ɏI��
    }
    // ���C�����[�v.
    while (!CheckHitKey(KEY_INPUT_ESCAPE) && !ProcessMessage()) 
    {
        ClsDrawScreen();
        // �V�[���ɉ������������s��.
        nowScene->update();
        nowScene->draw();
        ScreenFlip();
    }

    DxLib_End();
    return 0;
};