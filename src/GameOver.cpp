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

    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_SPACE)) {

        s_restartPlay();

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
    if (!TheTextureManager::Instance()->load("Assets/Re.png", "Retry", TheGame::Instance()->getRenderer()))
    {
        return false; 
    }


    
    GameObject* title = new Title(new LoaderParams(0, 0, 1024, 540, "Retry"));


    m_gameObjects.push_back(title);


    
    return true;
}

bool GameOverState::onExit()
{
    for (int i = 0; i < m_gameObjects.size(); i++)
    {
        m_gameObjects[i]->clean();
    }
    m_gameObjects.clear();
    TheTextureManager::Instance()->clearTextureMap("Retry");


    
    return true;
}

string GameOverState::getStateID() const
{
    return s_gameOverID;
}