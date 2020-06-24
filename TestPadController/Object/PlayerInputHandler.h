#pragma once
#include "../common/Vector2.h"
#include <memory>

class XPadState;

namespace
{
	constexpr int speed = 5;
}

class PlayerInputHandler
{
private:
	// Reference to player position
	Vector2Dbl& pos_;
	
	// XPad Input variable
	std::shared_ptr<XPadState> input_;

	// Handle player movement
	void MovePlayer(void);

	// Reference to player's Xpad number
	int& padNum_;
public:
	PlayerInputHandler(Vector2Dbl& pos, int& padNum);

	// Update current process
	void Update();

	~PlayerInputHandler();
};

