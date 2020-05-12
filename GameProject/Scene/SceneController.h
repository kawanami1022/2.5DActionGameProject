#pragma once
#include <memory>
#include "BaseScene.h"
#define SCREEN_SIZE_X   800
#define SCREEN_SIZE_Y   800


// ゲームの実処理を管理する.
class SceneController {
private:
    // 今がどのシーンか示すクラス.
    std::unique_ptr<BaseScene> nowScene;

public:
    // コンストラクタ、初期画面をタイトルにセットする.
    SceneController();
    ~SceneController();

    int run();
};