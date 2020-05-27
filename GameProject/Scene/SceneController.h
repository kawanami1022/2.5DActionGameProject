//-------------------------------------------------
//--------------Project by ------------------------
//----------------------koshiro kawanami-----------
//-------------------------------------------------
#pragma once
#include <memory>
#include "BaseScene.h"
#define SCREEN_SIZE_X   1336
#define SCREEN_SIZE_Y   768


// �Q�[���̎��������Ǘ�����.
class SceneController {
private:
    // �����ǂ̃V�[���������N���X.
    std::unique_ptr<BaseScene> nowScene;

public:
    // �R���X�g���N�^�A������ʂ��^�C�g���ɃZ�b�g����.
    SceneController();
    ~SceneController();

    void changeScene(BaseScene* scene);
    int run();
};