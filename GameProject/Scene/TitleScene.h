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

    void input()override;
    activeScene update(activeScene)override;      // タイトル中の処理、入力を待ってゲーム画面へ遷移する.
    void draw()override;        // タイトル中の処理、入力を待ってゲーム画面へ遷移する.

    void switchScene();
private:

    // タイトルシーン画像ハンドル
    int backGroundImage;        // 背景
    int characterImage;         // キャラクター
    int jailImage;              // 檻
    int lockImage;              // 鍵


    Vector2<int> characterImageSize;        // キャラクター画像サイズ保存用
    Vector2<int> characterImagePos;         // キャラクター画像座標

    Texture* jailImg;           // 檻の画像情報
    Texture* lockImg;           // 鍵の画像情報

};