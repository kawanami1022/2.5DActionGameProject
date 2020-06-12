//-------------------------------------------------
//--------------Project by ------------------------
//----------------------koshiro kawanami-----------
//-------------------------------------------------
#pragma once
#include <memory>
//#include "../Input/PadInput.h"

class BaseScene;

using activeScene = std::unique_ptr<BaseScene>;

// シーン内での処理を行う基底クラス.
class BaseScene {
public:
    BaseScene();
    virtual ~BaseScene();

    // 継承先で実装される関数.
    virtual void input() = 0;
    virtual activeScene update(activeScene) = 0;
    virtual void draw() = 0;
protected:
    /*Pad* pad;*/

};
