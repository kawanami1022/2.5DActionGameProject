//-------------------------------------------------
//--------------Project by ------------------------
//----------------------koshiro kawanami-----------
//-------------------------------------------------
#pragma once
#include <memory>
//#include "../Input/PadInput.h"

class BaseScene;

using activeScene = std::unique_ptr<BaseScene>;

// �V�[�����ł̏������s�����N���X.
class BaseScene {
public:
    BaseScene();
    virtual ~BaseScene();

    // �p����Ŏ��������֐�.
    virtual void input() = 0;
    virtual activeScene update(activeScene) = 0;
    virtual void draw() = 0;
protected:
    /*Pad* pad;*/

};
