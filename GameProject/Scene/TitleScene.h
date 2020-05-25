//-------------------------------------------------
//--------------Project by ------------------------
//----------------------koshiro kawanami-----------
//-------------------------------------------------
#pragma once
#include "../Vector2D/Vector2.h"
#include "../Texture/Texture.h"

// タイトルシーン内での処理を行うクラス.
class TitleScene : public BaseScene {
public:
    TitleScene();
    ~TitleScene();

    void update()override;      // タイトル中の処理、入力を待ってゲーム画面へ遷移する.
    void draw()override;        // タイトル中の処理、入力を待ってゲーム画面へ遷移する.
private:

    // タイトルシーン画像用
    int backGroundImage;        // 背景
    int characterImage;         // キャラクター
    int jailImage;
    int lockImage;


    Vector2<int> characterImageSize;
    Vector2<int> characterImagePos;

    Texture* jailImg;
    Texture* lockImg;

};