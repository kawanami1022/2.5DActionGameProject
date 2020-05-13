//-------------------------------------------------
//--------------Project by ------------------------
//----------------------koshiro kawanami-----------
//-------------------------------------------------
#ifndef INPUT_MANAGER_H_
#define INPUT_MANAGER_H_

//--------���͗p���C�u����

enum STATE_ID
{
	STATE_ID_NOW,		// ���݂̏��
	STATE_ID_LAST,		// 1�t���[���O
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