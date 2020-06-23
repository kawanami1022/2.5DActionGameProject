#pragma once
#include "Obj.h"
#include <memory>

class XPadState;

class Player :
	public Obj
{
public:
	Player();
	Player(Vector2Dbl pos, Vector2Dbl size);
	void Update(sharedObj) override;
	~Player();
private:
	void Draw(void) override;
	void Init(void);
	std::shared_ptr<XPadState> input_;
};

