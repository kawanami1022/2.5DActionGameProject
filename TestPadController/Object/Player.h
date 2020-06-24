#pragma once
#include "Obj.h"
#include <memory>
#include "PlayerInputHandler.h"

class PlayerInputHandler;
class XPadState;

class Player :
	public Obj
{
public:
	Player();
	Player(Vector2Dbl pos, Vector2Dbl size, int padNum);
	void Update(sharedObj) override;
	~Player();
private:
	void Draw(void) override;
	void Init(void);

	int _padNum;

	// Handle player input variable
	PlayerInputHandler inputHandler_;

	
};

