#include "DxLib.h"
//#include "InputManager.h"
#include "PadInput.h"

Pad::Pad()
{
	this->input[STATE_ID_NOW] = { 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0, 0,0,0,0 };
	this->input[STATE_ID_LAST] = { 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0, 0,0,0,0 };
	vec2 = new Vector2;
}

Pad::~Pad()
{
	delete vec2;
}

void Pad::update()
{
	// ì¸óÕèÛë‘ÇéÊìæ
	GetJoypadXInputState(DX_INPUT_PAD1, &input[STATE_ID_NOW]);
}

bool Pad::HoldDown(BUTTON_ID buttonID)
{
	if (input[STATE_ID_NOW].Buttons[buttonID] == 1 && input[STATE_ID_LAST].Buttons[buttonID] == 1) { return true; }
	return false;
}

bool Pad::HoldUp(BUTTON_ID buttonID)
{
	if (input[STATE_ID_NOW].Buttons[buttonID] == 0 && input[STATE_ID_LAST].Buttons[buttonID] == 0){return true;}
	return false;
}

bool Pad::Push(BUTTON_ID buttonID)
{
	if (input[STATE_ID_NOW].Buttons[buttonID] == 1 && input[STATE_ID_LAST].Buttons[buttonID] == 0){return true;}
	return false;
}

bool Pad::Release(BUTTON_ID buttonID)
{
	if (input[STATE_ID_NOW].Buttons[buttonID] == 0 && input[STATE_ID_LAST].Buttons[buttonID] == 1){return true;}
	return false;
}

XINPUT_STATE Pad::getXInput(STATE_ID stateID)
{
	return { input[stateID] };
}

bool Pad::checkStickDeadzone(short posX, short posY, int padNum, double deadZone)
{
	//double deadZoneMax=vec;
	int analogPosDef[2] = { 0,0 };
	int analogPosNow[2] = { posX,posY };
	;
	
	// xyÇÃçáê¨
	if (deadZone < vec2->calcTwoPtDisComp(analogPosDef, analogPosNow) / SHRT_MAX)
	{
		return true;
	}
	return false;
}

