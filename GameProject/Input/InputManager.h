//-------------------------------------------------
//--------------Project by ------------------------
//----------------------koshiro kawanami-----------
//-------------------------------------------------
#ifndef INPUT_MANAGER_H_
#define INPUT_MANAGER_H_

//--------入力用ライブラリ

enum STATE_ID
{
	STATE_ID_NOW,		// 現在の状態
	STATE_ID_LAST,		// 1フレーム前
	STATE_ID_MAX
};

namespace Input
{
	class Keyboard;
	class Mouse;
	class Pad;

	class Manager {
	public:
		Manager();
		~Manager();
		static Manager instance();

		Keyboard Keyboard() const;
		Mouse mouse() const;

		static void create(void* windowHandle);
		static void destroy();

	};
}

#endif INPUT_MANAGER_H_