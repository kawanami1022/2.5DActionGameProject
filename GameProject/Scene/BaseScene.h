//-------------------------------------------------
//--------------Project by ------------------------
//----------------------koshiro kawanami-----------
//-------------------------------------------------
#pragma once
#include <memory>
#include "../Input/PadInput.h"

class BaseScene;

using nowScene = std::unique_ptr<BaseScene>;

// �V�[�����ł̏������s�����N���X.
class BaseScene {
public:
    BaseScene();
    ~BaseScene();

    // �p����Ŏ��������֐�.
    virtual void input() = 0;
    virtual void update() = 0;
    virtual void draw() = 0;
protected:
    Pad* pad;

};
