#pragma once
#include <SDL2/SDL.h> 
#include "Vector2D.h"
#include <vector>

enum mouse_buttons {
    LEFT = 0,
    MIDDLE = 1,
    RIGHT = 2
};

class InputHandler {
public:
    ~InputHandler() {}
    static InputHandler* Instance() {
        if (s_pInstance == 0) {
            s_pInstance = new InputHandler();
        }
        return s_pInstance;
    }

    std::vector<bool> m_mouseButtonStates;
    Vector2D* m_mousePosition;

    bool getMouseButtonState(int buttonNumber);
    Vector2D* getMousePosition();


    bool isKeyDown(SDL_Scancode key);
    void update();
    void clean() {}

private:
    InputHandler();
    static InputHandler* s_pInstance;
    const Uint8* m_keystates;
};
typedef InputHandler TheInputHandler;