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
    // �c�w���C�u��������������
    if (DxLib_Init() == 0)
    {
        nowScene = std::make_unique<TitleScene>();
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