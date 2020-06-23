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

	// Set pad state
	bool state(XPAD_INPUT_ID, int data);

	// ¡‚Ü‚³‚É‰Ÿ‚³‚ê‚Ü‚µ‚½
	bool isTriggered(XPAD_INPUT_ID) const;

	// Œ»İ‰Ÿ‚³‚ê‚Ä‚¢‚é
	bool isPressed(XPAD_INPUT_ID) const;

	// ‰Ÿ‚µ‚Ä‚½“z‚ª¡‚Ü‚³‚É—£‚³‚ê‚½
	bool isReleased(XPAD_INPUT_ID) const;

	// Set previous state
	void SetOld(void);								

private:
	KeyMap state_;

};

