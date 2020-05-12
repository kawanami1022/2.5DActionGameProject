#pragma once
#include <memory>
#include "BaseScene.h"
#define SCREEN_SIZE_X   800
#define SCREEN_SIZE_Y   800


// �Q�[���̎��������Ǘ�����.
class SceneController {
private:
    // �����ǂ̃V�[���������N���X.
    std::unique_ptr<BaseScene> nowScene;

public:
    // �R���X�g���N�^�A������ʂ��^�C�g���ɃZ�b�g����.
    SceneController();
    ~SceneController();

    int run();
};