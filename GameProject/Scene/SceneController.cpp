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
    if (std::get<static_cast<int>(DRAW_QUE::IMAGE)>(dQue) <= 0) 	// std::get<���Ԗ�>�Ŏ��o��
    {
        // �摜ID���s���Ȃ̂ŁA�ǉ����Ȃ�
        return false;
    }
    // Que��ǉ�
    // _drawList.push_back(); �v�f��ǉ�����Ƃ��Ɏg��

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
    // �c�w���C�u��������������
    if (DxLib_Init() == 0)
    {
        //nowScene = std::make_unique<TitleScene>();
        //nowScene.reset(new TitleScene);

    }
     
    SetDrawScreen(DX_SCREEN_BACK);

    // �G���[���N�����璼���ɏI��
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
    // ���C�����[�v.
    while (!CheckHitKey(KEY_INPUT_ESCAPE) && !ProcessMessage()) 
    {

        _drawList.clear();
        // �V�[���ɉ������������s��.
        
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

    // �����ɂ��܂��Ă���QUE��`�悷��
    for (auto dQue : _drawList)
    {
        double x, y, rad;
        int id;

        std::tie(id, x, y, rad) = dQue;

        // Que�̓��e��`�悷��
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