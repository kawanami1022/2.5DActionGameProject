//-------------------------------------------------
//--------------Project by ------------------------
//----------------------koshiro kawanami-----------
//-------------------------------------------------
#pragma once
//#include "../Input/InputManager.h"
//#include "../Input/PadInput.h"
// �V�[�����ł̏������s�����N���X.
class BaseScene {
public:
    BaseScene();
    ~BaseScene();

    // �p����Ŏ��������֐�.
    virtual void update() = 0;
    virtual void draw() = 0;
};
