#pragma once

//#include "SDL.h"

enum KEYS_PRESSED_LIST
{
	KEY_ESCAPE, KEY_A, KEY_V, KEY_F, KEY_U, KEY_D, KEY_G, KEY_C, KEY_T, KEY_B, SIZE_OF_KEYS_PRESSED_ENUM			// Add, View, Feedback (add), Update, Cancel, or Go Back a page
};

class Input
{
public:
	void Update(void);
	bool KeyIsPressed(KEYS_PRESSED_LIST key);

	Input();
	~Input();

private:
	//SDL_Event m_event;
	bool m_keysPressed[SIZE_OF_KEYS_PRESSED_ENUM];

};