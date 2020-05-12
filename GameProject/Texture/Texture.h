#pragma once

// 画像クラス、画像の幅や高さも知りたいのでクラス化
class Texture {
private:
	// 画像ハンドル
	int handle;
	// 画像の幅
	int width;
	// 画像の高さ
	int height;
public:
	// コンストラクタ、読み込んだ画像ハンドルを設定する
	// またハンドルから、画像の幅と高さを設定する
	Texture(int handle);
};