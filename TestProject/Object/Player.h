#pragma once
#include "Obj.h"
#include <memory>
#include "../Input/InputState.h"

class Player :
	public Obj
{
public:
	Player();
	Player(Vector2Dbl pos, Vector2Dbl size);
	void Update(void) override;
	~Player();
private:
	void Draw(void) override;
	void Init(void);
	std::shared_ptr<InputState> _input;
};

