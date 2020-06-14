//-------------------------------------------------
//--------------Project by ------------------------
//----------------------koshiro kawanami-----------
//-------------------------------------------------

#pragma once
//#include "../Input/InputManager.h"
//#include "../Input/PadInput.h"
//#include "../Obj/Player/Player.h"
//#include "../Obj/Obj.h"
//#include "../Obj/map/Map.h"

class Obj;
class Player;
class Map;

class GameScene :public BaseScene
{
public:
	GameScene();		
	~GameScene();

	void input();
	activeScene update(activeScene);			// �X�V����
	void draw();			// �`�揈��
	void move();			// �ړ�����
	bool checkMoveObj(int*, int*, int, int, int);	// true: �}�b�v�ړ� false:�v���[���[�ړ�
private:
	Player *player;			// �v���[���[
	Map* map;				// �}�b�v
	
};