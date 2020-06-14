//-------------------------------------------------
//--------------Project by ------------------------
//----------------------koshiro kawanami-----------
//-------------------------------------------------
#include "DxLib.h"
#include "InputManager.h"
#include "../Vector2D/Vector2.h"

enum BUTTON_ID
{
	BUTTON_ID_DPAD_UP,
	BUTTON_ID_DPAD_DOWN,
	BUTTON_ID_DPAD_LEFT,
	BUTTON_ID_DPAD_RIGHT,
	BUTTON_ID_START,
	BUTTON_ID_BACK,
	BUTTON_ID_LEFT_THUMB,
	BUTTON_ID_RIGHT_THUMB,
	BUTTON_ID_LEFT_SHOULDER,
	BUTTON_ID_RIGHT_SHOULDER,
	BUTTON_ID_A = 12,
	BUTTON_ID_B = 13,
	BUTTON_ID_X = 14,
	BUTTON_ID_Y = 15,
	BUTTON_ID_MAX
};


class Pad
{
public:

	Pad();
	~Pad();

	// static class pointerを取る関数定義
	static Pad& GetInstance(void)
	{
		return *sInstance;
	}

	void update();
	//int analogNumber() const;
	//int analog(int) const;		// アナログスティックの値を取得

	bool HoldDown(BUTTON_ID);						// Now 1,	Last 1
	bool HoldUp(BUTTON_ID);							// Now 0,	Last 0
	bool Push(BUTTON_ID);							// Now 1,	Last 0
	bool Release(BUTTON_ID);						// Now 0,	Last 1
	XINPUT_STATE getXInput(STATE_ID);				//トリガーの値を取得
	bool checkStickDeadzone(short posX, short posY, int, double);		// true:動かす false:動かさない
	double calcAngleLeft();
	double getAngleLeft();
	void saveInputState();
private:
	struct PadDeleter
	{
		void operator()(Pad* Pad) const // 一つ目　オーバーロードしたい　二つ目　右辺式何をﾃﾞﾘｰﾄしたいかを右側に書く
		{
			delete Pad;
		}
	};

	// static class pointer 定義
	static std::unique_ptr<Pad, PadDeleter> sInstance;

	XINPUT_STATE input[STATE_ID_MAX];
	Vector2<double> *vec2;
	double LStickAngle;
};