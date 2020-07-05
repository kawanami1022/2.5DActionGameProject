#include <Dxlib.h>
#include "SceneMng.h"
#include "TitleScene.h"
#include "../common/ImageMng.h"

SceneMng* SceneMng::sInstance = nullptr;


SceneMng::SceneMng() :  ScreenSize{ 1366, 768 },
						ScreenCenter{ ScreenSize / 2 },
						GameScreenSize{ 1366, 768 },
						GameScreenOffset{ ScreenCenter - GameScreenSize / 2 } // ｺﾝｽﾄﾗｸﾀが走った瞬間、ﾛｯｸがかかる。
{
	_frame = 0;
}


SceneMng::~SceneMng()
{
}

void SceneMng::Draw(void)
{
	SetDrawScreen(DX_SCREEN_BACK);
	ClsDrawScreen();

	// ｽﾀｯｸにたまっているQUEを描画する
	for (auto dQue : _drawList)
	{
		double x, y, rad;
		int id;

		std::tie(id, x, y, rad) = dQue;

		// Queの内容を描画する
		DrawRotaGraph(
			x,
			y,
			1.0,
			rad,
			id,
			true);
	}

	/*SetDrawScreen(DX_SCREEN_BACK);*/
	ScreenFlip();

}


void SceneMng::Run(void)
{
	SysInit();
	_activeScene = std::make_unique<TitleScene>();


	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		_drawList.clear();
		_activeScene = (*_activeScene).Update(std::move(_activeScene));	// moveを使うことでコピーを作らずに所有権の譲渡ができる
		// スマートポインタとしてわかりやすいのが上　_activeScene->Update();
		Draw();
		_frame++;
	}

	DxLib_End();
}

bool SceneMng::AddDrawQue(DrawQueT dQue)
{
	if (std::get<static_cast<int>(DRAW_QUE::IMAGE)>(dQue) <= 0) 	// std::get<何番目>で取り出す
	{
		// 画像IDが不正なので、追加しない
		return false;
	}
	// Queを追加
	// _drawList.push_back(); 要素を追加するときに使う

	_drawList.emplace_back(dQue);
	return true;
}

const int SceneMng::frame(void)
{
	return _frame;
}


bool SceneMng::SysInit(void)
{
	//ｼｽﾃﾑ処理
	SetWindowText("TestProject");
	SetGraphMode(ScreenSize.x, ScreenSize.y, 16);				// 800*600ﾄﾞｯﾄ、65536色ﾓｰﾄﾞに設定
	ChangeWindowMode(true);										// true:window  false:ﾌﾙｽｸﾘｰﾝ

	// DirectX11をしようするようにする
	SetUseDirect3DVersion(DX_DIRECT3D_11);



	if (DxLib_Init() == -1)										// DXﾗｲﾌﾞﾗﾘの初期化
	{
		return false;												// DxLibﾗｲﾌﾞﾗﾘ初期化処理
	}
	

	// フルスクリーンウインドの切り替えでリソースが消えるのを防ぐ
	SetChangeScreenModeGraphicsSystemResetFlag(FALSE);

	SetDrawScreen(DX_SCREEN_BACK);	// 描画先をﾊﾞｯｸﾊﾞｯﾌｧに設定

	// LoadDivGraph all background images
	lpImageMng.GetID("bg", "image/background.png");
	lpImageMng.GetID("button", "image/button.png");
	lpImageMng.GetID("bg char", "image/character.png");
	lpImageMng.GetID("jail", "image/jail.png");
	lpImageMng.GetID("lock", "image/lock.png");


	return false;
}