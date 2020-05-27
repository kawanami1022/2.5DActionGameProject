//-------------------------------------------------
//--------------Project by ------------------------
//----------------------koshiro kawanami-----------
//-------------------------------------------------
#pragma once
#include <memory>
#include "BaseScene.h"
#define SCREEN_SIZE_X   1336
#define SCREEN_SIZE_Y   768


// ゲームの実処理を管理する.
class SceneController {
private:
    // 今がどのシーンか示すクラス.
    std::unique_ptr<BaseScene> nowScene;

public:
    // コンストラクタ、初期画面をタイトルにセットする.
    SceneController();
    ~SceneController();

    void changeScene(BaseScene* scene);
    int run();
};