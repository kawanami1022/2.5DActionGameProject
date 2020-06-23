#include "XPadState.h"

XPadState::XPadState()
{
	DxLib::GetJoypadXInputState(DX_INPUT_PAD1, &buf_);
	keyConDef_.reserve(static_cast<size_t>(end(XPAD_INPUT_ID())));

	keyConDef_.emplace_back(XINPUT_BUTTON_DPAD_UP);
	keyConDef_.emplace_back(XINPUT_BUTTON_DPAD_DOWN);
	keyConDef_.emplace_back(XINPUT_BUTTON_DPAD_LEFT);
	keyConDef_.emplace_back(XINPUT_BUTTON_DPAD_RIGHT);
	keyConDef_.emplace_back(XINPUT_BUTTON_START);
	keyConDef_.emplace_back(XINPUT_BUTTON_BACK);
	keyConDef_.emplace_back(XINPUT_BUTTON_LEFT_THUMB);
	keyConDef_.emplace_back(XINPUT_BUTTON_RIGHT_THUMB);
	keyConDef_.emplace_back(XINPUT_BUTTON_LEFT_SHOULDER);
	keyConDef_.emplace_back(XINPUT_BUTTON_RIGHT_SHOULDER);
	keyConDef_.emplace_back(XINPUT_BUTTON_A);
	keyConDef_.emplace_back(XINPUT_BUTTON_B);
	keyConDef_.emplace_back(XINPUT_BUTTON_X);
	keyConDef_.emplace_back(XINPUT_BUTTON_Y);


	keyCon_ = keyConDef_;

	//関数ﾎﾟｲﾝﾀを使うときは&を使う　今回はﾒﾝﾊﾞｰ関数ﾎﾟｲﾝﾀ クラスから辿る＝名前空間
	func = &XPadState::RefPadData;				
}

XPadState::~XPadState()
{
}

void XPadState::Update()
{
	SetOld();
	DxLib::GetJoypadXInputState(DX_INPUT_PAD1, &buf_);	// _bufはすべてのﾎﾞﾀﾝの押下状態をとる
	(this->*func)(); // 自分自身のﾎﾟｲﾝﾀｰはthis
}


void XPadState::RefPadData(void)
{
	// _bufに入っている inputIDのｷｰ(enumclass)の情報をstateのsetを使っていれる 
	// _buf　inputID分の情報をsetを使って　範囲for文を使う　_keyconを使ってsetする　
	// f1キーを押したらfuncの内容をsetConFigに変える　
	// f1keyを押した瞬間refKeyDataの呼び出しにもどす　トレースで切り替わったら変わったことを表示する
	for (auto id : XPAD_INPUT_ID())
	{
		state(id, buf_.Buttons[keyCon_[static_cast<int>(id)]]);
	}
}

void XPadState::SetPadConfig(void)
{
}
