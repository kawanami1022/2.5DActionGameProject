#pragma once
#include <vector>
#include "InputState.h"
#include <DxLib.h>

class PlayerInputHandler;

class XPadState :
	public InputState
{
	friend PlayerInputHandler;
public:
	XPadState(int& padNum);
	~XPadState();
	void Update(void);
private:

	void RefPadData(void);				// ���̷݂��ް���������
	void SetPadConfig(void);			// �����̏�������
	void (XPadState::* func)(void);

	DxLib::XINPUT_STATE buf_;
	std::vector<int> keyCon_;			// Using keys variable
	std::vector<int> keyConDef_;		// Default keys variable

	int& padNum_;						// XPad Number

	XPAD_INPUT_ID confID_;

};

