#include "GamePlayState.h"
#include "TextureManager.h"
#include "Game.h"
#include "InputHandler.h"
#include "GameOver.h"
#include <iostream>


const std::string PlayState::s_playID = "PLAY";

PlayState::PlayState()
{
    //ctor
}

void PlayState::update()
{
    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE))
    {
        TheGame::Instance()->getStateMachine()->pushState(new PauseState());
    }

    for (int i = 0; i < m_gameObjects.size(); i++)
    {
        m_gameObjects[i]->update();
    }

    if (checkCollision(dynamic_cast<SDLGameObject*>(m_gameObjects[1]), dynamic_cast<SDLGameObject*>(m_gameObjects[2])))
    {
        //TheTextureManager::Instance()->clearTextureMap("FireBall");
        player->PlayerDeath();
        TheGame::Instance()->getStateMachine()->pushState(new GameOverState());
    }
}

void PlayState::render()
{
    for (int i = 0; i < m_gameObjects.size(); i++)
    {
        m_gameObjects[i]->draw();
    }
}

bool PlayState::onEnter()
{
    if (!TheTextureManager::Instance()->load("Assets/CharactorSprite.png", "Charactor", TheGame::Instance()->getRenderer())) 
    {
        return false;
    }
    if (!TheTextureManager::Instance()->load("Assets/Backgroundimg.png", "Background", TheGame::Instance()->getRenderer()))
    {
        return false;
    }
    if (!TheTextureManager::Instance()->load("Assets/FireBall.png", "FireBall", TheGame::Instance()->getRenderer()))
    {
        return false;
    }

    GameObject* BackgroundImage = new Background(new LoaderParams(-400, -380, 1920, 1080, "Background"));

    GameObject* player = new Player(new LoaderParams(200, 500, 40, 60, "Charactor"));

    GameObject* FireBall = new Enemy(new LoaderParams(100, 500, 50, 50, "FireBall"));
    
   
    
    m_gameObjects.push_back(BackgroundImage);
    m_gameObjects.push_back(player);
    m_gameObjects.push_back(FireBall);

    return true;
}



bool PlayState::onExit()
{
    for (int i = 0; i < m_gameObjects.size(); i++) 
    {
        m_gameObjects[i]->clean();
    }
    m_gameObjects.clear(); 

    TheTextureManager::Instance()->clearTextureMap("Background");
    TheTextureManager::Instance()->clearTextureMap("Charactor");
    TheTextureManager::Instance()->clearTextureMap("FireBall");


    return true;
}


std::string PlayState::getStateID() const
{
    return s_playID;
}

bool PlayState::checkCollision(SDLGameObject* p1, SDLGameObject* p2)
{
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    
    leftA = p1->getPosition().getX();
    rightA = p1->getPosition().getX() + p1->getWidth();
    topA = p1->getPosition().getY();
    bottomA = p1->getPosition().getY() + p1->getHeight();

    
    leftB = p2->getPosition().getX();
    rightB = p2->getPosition().getX() + p2->getWidth();
    topB = p2->getPosition().getY();
    bottomB = p2->getPosition().getY() + p2->getHeight();

    
    if (bottomA <= topB or topA >= bottomB or rightA <= leftB or leftA >= rightB) 
        return false;
    else
        return true;

}