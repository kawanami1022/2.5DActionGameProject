#pragma once
class KeyInput
{
public:
	void Update();
	bool Push(int);			// �������u��
	bool Release(int);		// �������u��
	bool Hold(int);			// ���������Ă�

	char inputState[256];
	char inputStateOld[256];
	KeyInput();
	~KeyInput();
private:
};