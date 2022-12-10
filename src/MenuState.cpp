#include "MenuState.h"
#include "TextureManager.h"
#include "Game.h"
#include <iostream>

const std:: string MenuState::s_menuID = "MENU";

MenuState::MenuState()
{

}

std::string MenuState::getStateID() const
{
    return s_menuID;
}

void MenuState::update()
{


    for(int i = 0; i < m_gameObjects.size(); i++)
    {
        m_gameObjects[i]->update();
    }
}

void MenuState::render()
{
    for (int i = 0; i < m_gameObjects.size(); i++)
    {
        m_gameObjects[i]->draw();
    }
}

bool MenuState::onEnter()
{
    if (!TheTextureManager::Instance()->load("Assets/Title.png", "Title", TheGame::Instance()->getRenderer()))
    {
        return false;
    }
    if(!TheTextureManager::Instance()->load("Assets/PlayButton.png","PlayButton", TheGame::Instance()->getRenderer()))
    {
        
        return false;
    }
    if(!TheTextureManager::Instance()->load("Assets/ExitButton.png","ExitButton", TheGame::Instance()->getRenderer()))
    {
        return false;
    }
    
    GameObject* button1 = new MenuButton(new LoaderParams(300, 350, 200, 100, "PlayButton"), s_menuToPlay);
    GameObject* button2 = new MenuButton(new LoaderParams(524, 350, 200, 100, "ExitButton"), s_exitFromMenu);
    GameObject* TitleBox = new Title(new LoaderParams(300, 80, 400, 150, "Title"));

    m_gameObjects.push_back(TitleBox);
    m_gameObjects.push_back(button1);
    m_gameObjects.push_back(button2);

    return true;
}

bool MenuState::onExit()
{
    for(int i = 0; i < m_gameObjects.size(); i++)
    {
        m_gameObjects[i]->clean();
    }
    m_gameObjects.clear();
    TheTextureManager::Instance()->clearTextureMap("TItle");
    TheTextureManager::Instance()->clearTextureMap("PlayButton");
    TheTextureManager::Instance()->clearTextureMap("ExitButton"); 
    
    return true;
}

void MenuState::s_menuToPlay()
{
    TheGame::Instance()->getStateMachine()->changeState(new PlayState());
}

void MenuState::s_exitFromMenu()
{
    TheGame::Instance()->quit(); 
}