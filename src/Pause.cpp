#include "Pause.h"
#include "Game.h"
#include "TextureManager.h"

const std::string PauseState::s_pauseID = "PAUSE";

void PauseState::s_pauseToMain()
{
    TheGame::Instance()->getStateMachine()->changeState(new MenuState());
}

void PauseState::s_resumePlay()
{
    TheGame::Instance()->getStateMachine()->popState();
}

void PauseState::s_Option() {

}

void PauseState::s_Save() {

}

void PauseState::update()
{
    for (int i = 0; i < m_gameObjects.size(); i++)
    {
        m_gameObjects[i]->update();
    }
}

void PauseState::render()
{
    for (int i = 0; i < m_gameObjects.size(); i++)
    {
        m_gameObjects[i]->draw();
    }
}

bool PauseState::onEnter()
{
    if (!TheTextureManager::Instance()->load("Assets/EscapeButton.png", "Escape", TheGame::Instance()->getRenderer()))
    {
        return false; 
    }
    if (!TheTextureManager::Instance()->load("Assets/OptionButton.png", "Option", TheGame::Instance()->getRenderer()))
    {
        return false; 
    }
    if (!TheTextureManager::Instance()->load("Assets/BlinkButton.png", "Blink", TheGame::Instance()->getRenderer()))
    {
        return false;
    }
    if (!TheTextureManager::Instance()->load("Assets/SaveButton.png", "Save", TheGame::Instance()->getRenderer()))
    {
        return false;
    }


    GameObject* button1 = new MenuButton(new LoaderParams(300, 350, 220, 100, "Option"), s_Option);
    GameObject* button2 = new MenuButton(new LoaderParams(524, 350, 220, 100, "Save"), s_Save);
    GameObject* button3 = new MenuButton(new LoaderParams(924, 0, 100, 100, "Escape"), s_pauseToMain);
    GameObject* button4 = new MenuButton(new LoaderParams(0, 0, 100, 100, "Blink"), s_resumePlay);

    m_gameObjects.push_back(button1);
    m_gameObjects.push_back(button2);
    m_gameObjects.push_back(button3);
    m_gameObjects.push_back(button4);
    return true;
}

bool PauseState::onExit()
{
    for (int i = 0; i < m_gameObjects.size(); i++)
    {
        m_gameObjects[i]->clean();
    }
    m_gameObjects.clear();

    TheTextureManager::Instance()->clearTextureMap("Option");
    TheTextureManager::Instance()->clearTextureMap("Escape");
    TheTextureManager::Instance()->clearTextureMap("Blink");
    TheTextureManager::Instance()->clearTextureMap("Save");

    return true;
}

std::string PauseState::getStateID() const
{
    return s_pauseID;
}