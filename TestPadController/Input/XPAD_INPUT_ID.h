#pragma once
enum class XPAD_INPUT_ID // ﾏｯﾌﾟのｷｰ  既定の型を指定できる
{
DPAD_UP			,	// デジタル方向ボタン上		(0)
DPAD_DOWN		,	// デジタル方向ボタン下		(1)
DPAD_LEFT		,	// デジタル方向ボタン左		(2)
DPAD_RIGHT		,	// デジタル方向ボタン右		(3)
START			,	// STARTボタン				(4)
BACK			,	// BACKボタン				(5)
LEFT_THUMB		,	// 左スティック押し込み		(6)
RIGHT_THUMB		,	// 右スティック押し込み		(7)
LEFT_SHOULDER	,	// LBボタン					(8)
RIGHT_SHOULDER	,	// RBボタン					(9)
A				,	// Aボタン					(10)
B				,	// Bボタン					(11)
X				,	// Xボタン					(12)
Y				,	// Yボタン					(13)
MAX
};

XPAD_INPUT_ID begin(XPAD_INPUT_ID);
XPAD_INPUT_ID end(XPAD_INPUT_ID);
XPAD_INPUT_ID operator*(XPAD_INPUT_ID key);
XPAD_INPUT_ID operator++(XPAD_INPUT_ID& key);

