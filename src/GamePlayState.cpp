#include "GamePlayState.h"
#include "TextureManager.h"
#include "Game.h"
#include "InputHandler.h"
#include "GameOver.h"
#include <iostream>


const std::string PlayState::s_playID = "PLAY";

PlayState::PlayState()
{

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

    if (checkCollision(dynamic_cast<SDLGameObject*>(m_gameObjects[2]), dynamic_cast<SDLGameObject*>(m_gameObjects[3])))
    {
        m_gameObjects[2]->clean();
        //TheGame::Instance()->getStateMachine()->pushState(new GameOverState());
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
    if (!TheTextureManager::Instance()->load("Assets/GPlayer.png", "Charactor", TheGame::Instance()->getRenderer())) 
    {
        return false;
    }
    if (!TheTextureManager::Instance()->load("Assets/Backgroundimg.png", "Background", TheGame::Instance()->getRenderer()))
    {
        return false;
    }
    if (!TheTextureManager::Instance()->load("Assets/EnemyWalk.png", "Enemy", TheGame::Instance()->getRenderer()))
    {
        return false;
    }
    if (!TheTextureManager::Instance()->load("Assets/Bullet.png", "Bullet", TheGame::Instance()->getRenderer()))
    {
        return false;
    }

    GameObject* BackgroundImage = new Background(new LoaderParams(0, 0, 480, 640, "Background"));

    GameObject* player = new Player(new LoaderParams(200, 500, 70, 114, "Charactor"));

    GameObject* enemy = new Enemy(new LoaderParams(200, 0, 50, 68, "Enemy"));
    
    GameObject* bullet = new Bullet(new LoaderParams(200, 500, 20, 20, "Bullet"));

    m_gameObjects.push_back(BackgroundImage);
    m_gameObjects.push_back(enemy);
    m_gameObjects.push_back(bullet);
    m_gameObjects.push_back(player);

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
    TheTextureManager::Instance()->clearTextureMap("Bullet");
    TheTextureManager::Instance()->clearTextureMap("Enemy");

    return true;
}

void PlayState::fire() {
    printf("true");
    fired = true;
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