 //-------------------------------------------------
//--------------Project by ------------------------
//----------------------koshiro kawanami-----------
//-------------------------------------------------
//#include "InputManager.h"
#include "DxLib.h"
#include "PadInput.h"

std::unique_ptr<Pad, Pad::PadDeleter> Pad::sInstance(new Pad());		// static pointer　を作る

Pad::Pad()
{
	this->input[STATE_ID_NOW] = { 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0, 0,0,0,0 };		// NOW	0:押されてない
	this->input[STATE_ID_LAST] = { 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0, 0,0,0,0 };		// LAST	0:押されてない
	this->LStickAngle = 0;																	// 左スティックの角度
	vec2 = new Vector2<double>;
}

Pad::~Pad()
{
	delete vec2;
}

void Pad::update()
{
	// 入力状態を取得
	GetJoypadXInputState(DX_INPUT_PAD1, &input[STATE_ID_NOW]);					// パッド1の
	this->LStickAngle = this->calcAngleLeft();
}

// NOW 1 LAST 1 押し続けている
bool Pad::HoldDown(BUTTON_ID buttonID)
{
	if (input[STATE_ID_NOW].Buttons[buttonID] == 1 && input[STATE_ID_LAST].Buttons[buttonID] == 1) { return true; }
	return false;
}

// NOW 0 LAST 0 離し続けている
bool Pad::HoldUp(BUTTON_ID buttonID)
{
	if (input[STATE_ID_NOW].Buttons[buttonID] == 0 && input[STATE_ID_LAST].Buttons[buttonID] == 0){return true;}
	return false;
}

// NOW 1 LAST 0 今押した
bool Pad::Push(BUTTON_ID buttonID)
{
	if (input[STATE_ID_NOW].Buttons[buttonID] == 1 && input[STATE_ID_LAST].Buttons[buttonID] == 0){return true;}
	return false;
}

// NOW 0 LAST 1 今離した
bool Pad::Release(BUTTON_ID buttonID)
{
	if (input[STATE_ID_NOW].Buttons[buttonID] == 0 && input[STATE_ID_LAST].Buttons[buttonID] == 1){return true;}
	return false;
}

//目的	:入力状態を取得
//入力	:stateID	状態
XINPUT_STATE Pad::getXInput(STATE_ID stateID)
{
	return { input[stateID] };
}

//目的	:デッドゾーンを設ける
//入力	:posX
//		:posY
//		:padNum			
//		:deadZone		無効値
bool Pad::checkStickDeadzone(short posX, short posY, int padNum, double deadZone)
{
	//double deadZoneMax=vec;
	double analogPosDef[2] = { 0,0 };
	double analogPosNow[2] = { posX,posY };
	;
	
	// xyの合成
	if (deadZone < vec2->calcTwoPtDisComp(analogPosDef, analogPosNow) / SHRT_MAX)
	{
		return true;
	}
	return false;
}

// 目的	:LStickの角度を求める
double Pad::calcAngleLeft()
{
	double angle = vec2->calcAngle(
		(double)this->input[STATE_ID_NOW].ThumbLX,
		(double)this->input[STATE_ID_NOW].ThumbLY);
	return angle;
}

// 目的	: 左スティックの角度を取得
double Pad::getAngleLeft()
{
	return this->LStickAngle;
}

// 目的	: 現在の入力情報を保存する(これをゲームループ内に呼ぶことで入力状態によって判定することができる)
void Pad::saveInputState()
{
	this->input[STATE_ID_LAST] = this->input[STATE_ID_NOW];
}



