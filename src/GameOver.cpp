#include "GameOver.h"
#include "Game.h"
#include "TextureManager.h"

const string GameOverState::s_gameOverID = "GAMEOVER";

GameOverState::GameOverState()
{

}

void GameOverState::s_gameOverToMain()
{
    TheGame::Instance()->getStateMachine()->changeState(new MenuState());
}

void GameOverState::s_restartPlay()
{
    TheGame::Instance()->getStateMachine()->changeState(new PlayState());
}

void GameOverState::update()
{
    for (int i = 0; i < m_gameObjects.size(); i++)
    {
        m_gameObjects[i]->update();
    }
}

void GameOverState::render()
{
    for (int i = 0; i < m_gameObjects.size(); i++)
    {
        m_gameObjects[i]->draw();
    }
}

bool GameOverState::onEnter()
{
    if (!TheTextureManager::Instance()->load("Assets/GameOverTitle.png", "GameOverTitle", TheGame::Instance()->getRenderer()))
    {
        return false; 
    }
    if (!TheTextureManager::Instance()->load("Assets/EscapeButton.png", "ExitButton", TheGame::Instance()->getRenderer()))
    {
        return false; 
    }
    if (!TheTextureManager::Instance()->load("Assets/BlinkButton.png", "BlinkButton", TheGame::Instance()->getRenderer()))
    {
        return false;
    }

    
    GameObject* title = new Title(new LoaderParams(50, 50, 400, 150, "GameOverTitle"));
    GameObject* button1 = new MenuButton(new LoaderParams(130, 350, 100, 100, "ExitButton"), s_gameOverToMain);
    GameObject* button2 = new MenuButton(new LoaderParams(280, 350, 100, 100, "BlinkButton"), s_restartPlay);

    m_gameObjects.push_back(title);
    m_gameObjects.push_back(button1);
    m_gameObjects.push_back(button2);

    
    return true;
}

bool GameOverState::onExit()
{
    for (int i = 0; i < m_gameObjects.size(); i++)
    {
        m_gameObjects[i]->clean();
    }
    m_gameObjects.clear();
    TheTextureManager::Instance()->clearTextureMap("GameOverTitle");
    TheTextureManager::Instance()->clearTextureMap("ExitButton");
    TheTextureManager::Instance()->clearTextureMap("BlinkButton");

    
    return true;
}

string GameOverState::getStateID() const
{
    return s_gameOverID;
}