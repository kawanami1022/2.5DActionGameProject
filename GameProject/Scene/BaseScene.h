//-------------------------------------------------
//--------------Project by ------------------------
//----------------------koshiro kawanami-----------
//-------------------------------------------------
#pragma once
#include <memory>
#include "../Input/PadInput.h"

class BaseScene;

using nowScene = std::unique_ptr<BaseScene>;

// シーン内での処理を行う基底クラス.
class BaseScene {
public:
    BaseScene();
    ~BaseScene();

    // 継承先で実装される関数.
    virtual void input() = 0;
    virtual void update() = 0;
    virtual void draw() = 0;
protected:
    Pad* pad;

};
