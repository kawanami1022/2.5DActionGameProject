//-------------------------------------------------
//--------------Project by ------------------------
//----------------------koshiro kawanami-----------
//-------------------------------------------------
#pragma once
// シーン内での処理を行う基底クラス.
class BaseScene {
public:
    BaseScene();
    ~BaseScene();

    // 継承先で実装される関数.
    virtual void update() = 0;
    virtual void draw() = 0;
};
