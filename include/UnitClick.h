#pragma once
#include "SDLGameObject.h"

class UnitClick : public SDLGameObject {

public:
    UnitClick(const LoaderParams* pParams);
    virtual void draw();
    virtual void update();
    //virtual void clean();
protected:
private:

    enum button_state 
    {
        MOUSE_OUT = 0,
        MOUSE_OVER = 1,
        CLICKED = 2
    };

    void (*m_callback)(); 
    bool m_bReleased; 
    static bool Clicked;

    static void s_Selected();
    static void s_Unselected();

};