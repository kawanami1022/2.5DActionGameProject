//-------------------------------------------------
//--------------Project by ------------------------
//----------------------koshiro kawanami-----------
//-------------------------------------------------
#pragma once
// タイトルシーン内での処理を行うクラス.
class TitleScene : public BaseScene {
public:
    TitleScene();
    ~TitleScene();

    void update()override;      // タイトル中の処理、入力を待ってゲーム画面へ遷移する.
    void draw()override;      // タイトル中の処理、入力を待ってゲーム画面へ遷移する.
};