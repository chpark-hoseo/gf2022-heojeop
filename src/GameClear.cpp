#include "GameClear.h"
#include "Game.h"
#include "TextureManager.h"

const string GameClear::s_gameOverID = "CLEAR";

GameClear::GameClear()
{

}

void GameClear::s_gameOverToMain()
{
    TheGame::Instance()->getStateMachine()->changeState(new MenuState());
}

void GameClear::s_restartPlay()
{
    TheGame::Instance()->getStateMachine()->changeState(new PlayState());
}

void GameClear::update()
{
    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_A)) {

        s_gameOverToMain();

    }
    for (int i = 0; i < m_gameObjects.size(); i++)
    {
        m_gameObjects[i]->update();
    }
}

void GameClear::render()
{
    for (int i = 0; i < m_gameObjects.size(); i++)
    {
        m_gameObjects[i]->draw();
    }
}

bool GameClear::onEnter()
{
    if (!TheTextureManager::Instance()->load("Assets/gc.png", "GameClear", TheGame::Instance()->getRenderer()))
    {
        return false;
    }


    GameObject* title = new Title(new LoaderParams(0, 0, 1024, 540, "GameClear"));


    m_gameObjects.push_back(title);



    return true;
}

bool GameClear::onExit()
{
    for (int i = 0; i < m_gameObjects.size(); i++)
    {
        m_gameObjects[i]->clean();
    }
    m_gameObjects.clear();
    TheTextureManager::Instance()->clearTextureMap("GameClear");



    return true;
}

string GameClear::getStateID() const
{
    return s_gameOverID;
}