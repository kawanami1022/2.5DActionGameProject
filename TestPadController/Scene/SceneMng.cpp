#include <Dxlib.h>
#include "SceneMng.h"
#include "TitleScene.h"
#include "../common/ImageMng.h"

SceneMng* SceneMng::sInstance = nullptr;


SceneMng::SceneMng() :  ScreenSize{ 1366, 768 },
						ScreenCenter{ ScreenSize / 2 },
						GameScreenSize{ 1366, 768 },
						GameScreenOffset{ ScreenCenter - GameScreenSize / 2 } // �ݽ�׸����������u�ԁAۯ���������B
{
	_frame = 0;
}


SceneMng::~SceneMng()
{
}

void SceneMng::Draw(void)
{
	SetDrawScreen(DX_SCREEN_BACK);
	ClsDrawScreen();

	// �����ɂ��܂��Ă���QUE��`�悷��
	for (auto dQue : _drawList)
	{
		double x, y, rad;
		int id;

		std::tie(id, x, y, rad) = dQue;

		// Que�̓��e��`�悷��
		DrawRotaGraph(
			x,
			y,
			1.0,
			rad,
			id,
			true);
	}

	/*SetDrawScreen(DX_SCREEN_BACK);*/
	ScreenFlip();

}


void SceneMng::Run(void)
{
	SysInit();
	_activeScene = std::make_unique<TitleScene>();


	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		_drawList.clear();
		_activeScene = (*_activeScene).Update(std::move(_activeScene));	// move���g�����ƂŃR�s�[����炸�ɏ��L���̏��n���ł���
		// �X�}�[�g�|�C���^�Ƃ��Ă킩��₷���̂���@_activeScene->Update();
		Draw();
		_frame++;
	}

	DxLib_End();
}

bool SceneMng::AddDrawQue(DrawQueT dQue)
{
	if (std::get<static_cast<int>(DRAW_QUE::IMAGE)>(dQue) <= 0) 	// std::get<���Ԗ�>�Ŏ��o��
	{
		// �摜ID���s���Ȃ̂ŁA�ǉ����Ȃ�
		return false;
	}
	// Que��ǉ�
	// _drawList.push_back(); �v�f��ǉ�����Ƃ��Ɏg��

	_drawList.emplace_back(dQue);
	return true;
}

const int SceneMng::frame(void)
{
	return _frame;
}


bool SceneMng::SysInit(void)
{
	//���я���
	SetWindowText("TestProject");
	SetGraphMode(ScreenSize.x, ScreenSize.y, 16);				// 800*600�ޯāA65536�FӰ�ނɐݒ�
	ChangeWindowMode(true);										// true:window  false:�ٽ�ذ�

	// DirectX11�����悤����悤�ɂ���
	SetUseDirect3DVersion(DX_DIRECT3D_11);



	if (DxLib_Init() == -1)										// DXײ���؂̏�����
	{
		return false;												// DxLibײ���؏���������
	}
	

	// �t���X�N���[���E�C���h�̐؂�ւ��Ń��\�[�X��������̂�h��
	SetChangeScreenModeGraphicsSystemResetFlag(FALSE);

	SetDrawScreen(DX_SCREEN_BACK);	// �`�����ޯ��ޯ̧�ɐݒ�

	// LoadDivGraph all background images
	lpImageMng.GetID("bg", "image/background.png");
	lpImageMng.GetID("button", "image/button.png");
	lpImageMng.GetID("bg char", "image/character.png");
	lpImageMng.GetID("jail", "image/jail.png");
	lpImageMng.GetID("lock", "image/lock.png");


	return false;
}