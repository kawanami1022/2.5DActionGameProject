#pragma once
#include <map>
#include "XPAD_INPUT_ID.h"

using StatePair = std::pair<int, int>;
using KeyMap = std::map<XPAD_INPUT_ID, StatePair>;

class InputState
{
public:
	InputState();
	virtual ~InputState();
	virtual void Update(void) = 0;

	// Get member variable state_
	const KeyMap& state(void) const;

	// Get pad state
	const StatePair& state(XPAD_INPUT_ID) const;

	

	// 今まさに押されました
	bool isTriggered(XPAD_INPUT_ID) const;

	// 現在押されている
	bool isPressed(XPAD_INPUT_ID) const;

	// 押してた奴が今まさに離された
	bool isReleased(XPAD_INPUT_ID) const;

							

protected:
	// Set pad state
	bool SetKeyState(XPAD_INPUT_ID, int data);

	// Set previous state
	void SetOld(void);

private:

	KeyMap state_;

};

