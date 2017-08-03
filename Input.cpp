#include "Input.h"

Input::Input()
{
	for (int i = 0; i <= SIZE_OF_KEYS_PRESSED_ENUM; i++)
	{
		m_keysPressed[i] = false;
	}

}

Input::~Input()
{

}

void Input::Update()
{
	// loop through all the events in the event list
	// Check for key down/up
	// update keys

	/*while (SDL_PollEvent(&m_event) != NULL)
	{
		if (m_event.type == SDL_KEYDOWN)
		{
			SDL_Keycode keyPressed = m_event.key.keysym.sym;

			switch (keyPressed)
			{
			case SDLK_ESCAPE:
				m_keysPressed[KEY_ESCAPE] = true;
				break;
			case SDLK_a:
				m_keysPressed[KEY_A] = true;
				break;
			case SDLK_v:
				m_keysPressed[KEY_V] = true;
				break;
			case SDLK_f:
				m_keysPressed[KEY_F] = true;
				break;
			case SDLK_u:
				m_keysPressed[KEY_U] = true;
				break;
			case SDLK_d:
				m_keysPressed[KEY_D] = true;
				break;
			case SDLK_g:
				m_keysPressed[KEY_G] = true;
				break;
			case SDLK_c:
				m_keysPressed[KEY_C] = true;
				break;
			case SDLK_t:
				m_keysPressed[KEY_T] = true;
				break;
			case SDLK_b:
				m_keysPressed[KEY_B] = true;
				break;
			}
		}
		else if (m_event.type == SDL_KEYUP)
		{
			SDL_Keycode keyPressed = m_event.key.keysym.sym;

			switch (keyPressed)
			{
			case SDLK_a:
				m_keysPressed[KEY_A] = false;
				break;
			case SDLK_v:
				m_keysPressed[KEY_V] = false;
				break;
			case SDLK_f:
				m_keysPressed[KEY_F] = false;
				break;
			case SDLK_u:
				m_keysPressed[KEY_U] = false;
				break;
			case SDLK_d:
				m_keysPressed[KEY_D] = false;
				break;
			case SDLK_g:
				m_keysPressed[KEY_G] = false;
				break;
			case SDLK_c:
				m_keysPressed[KEY_C] = false;
				break;
			case SDLK_t:
				m_keysPressed[KEY_T] = false;
				break;
			case SDLK_b:
				m_keysPressed[KEY_B] = false;
				break;
			}
		}
	}*/
}

bool Input::KeyIsPressed(KEYS_PRESSED_LIST key)
{
	return m_keysPressed[key];
}