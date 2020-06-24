#pragma once
class KeyInput
{
public:
	void Update();
	bool Push(int);			// ‰Ÿ‚µ‚½uŠÔ
	bool Release(int);		// —£‚µ‚½uŠÔ
	bool Hold(int);			// ‰Ÿ‚µ‘±‚¯‚Ä‚é

	char inputState[256];
	char inputStateOld[256];
	KeyInput();
	~KeyInput();
private:
};