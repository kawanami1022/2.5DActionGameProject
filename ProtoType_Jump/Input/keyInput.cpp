#include <iostream>
#include <string.h>
#include <DxLib.h>
#include "keyInput.h"
void KeyInput::Update()
{
	// “ü—Íó‘Ô‚ğ•ÏX
	memcpy(inputStateOld, inputState, sizeof(inputState));
	GetHitKeyStateAll(inputState);
}

bool KeyInput::Push(int keyId)
{
	return (inputState[keyId]&&(!inputStateOld[keyId]));
}

bool KeyInput::Release(int keyId)
{
	return (!inputState[keyId] && (inputStateOld[keyId]));
}

bool KeyInput::Hold(int keyId)
{
	return (inputState[keyId] && (inputStateOld[keyId]));
}

KeyInput::KeyInput()
{
	for (int i = 0; i < 256; i++)
	{
		inputState[i] = 0;
		inputStateOld[i] = 0;
	}
}

KeyInput::~KeyInput()
{

}
