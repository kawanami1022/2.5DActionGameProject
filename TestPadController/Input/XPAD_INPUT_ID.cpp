#include "XPAD_INPUT_ID.h"


XPAD_INPUT_ID begin(XPAD_INPUT_ID)
{
	return XPAD_INPUT_ID::DPAD_UP;
}

XPAD_INPUT_ID end(XPAD_INPUT_ID)
{
	return XPAD_INPUT_ID::MAX;
}

XPAD_INPUT_ID operator*(XPAD_INPUT_ID key)
{
	return key;
}

XPAD_INPUT_ID operator++(XPAD_INPUT_ID& key)
{
	return key = static_cast<XPAD_INPUT_ID>(static_cast<int>(key)+1);
}
