#include "GamePlayState.h"
#include "TextureManager.h"
#include "Game.h"
#include "InputHandler.h"
#include <iostream>

const std::string PlayState::s_playID = "PLAY";

PlayState::PlayState()
{
    //ctor
}

void PlayState::update()
{
    //input behaviour
    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE))
    {
        TheGame::Instance()->getStateMachine()->pushState(new PauseState());
    }

    //update GameObjects
    for (int i = 0; i < m_gameObjects.size(); i++)
    {
        m_gameObjects[i]->update();
    }

    //Collision detection
    if (checkCollision(dynamic_cast<SDLGameObject*>(m_gameObjects[0]), dynamic_cast<SDLGameObject*>(m_gameObjects[1])))
    {
        
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

    GameObject* BackgroundImage = new Background(new LoaderParams(-100, -400, 1920, 1080, "Background"));

    GameObject* player = new Player(new LoaderParams(100, 100, 40, 60, "Charactor"));

    m_gameObjects.push_back(BackgroundImage);
    m_gameObjects.push_back(player);
    

    std::cout << "Entering PlayState" << std::endl;
    return true;
}

bool PlayState::onExit()
{
    for (int i = 0; i < m_gameObjects.size(); i++) 
    {
        m_gameObjects[i]->clean();
    }
    m_gameObjects.clear(); 

    //clean textures
    TheTextureManager::Instance()->clearTextureMap("Charactor");

    std::cout << "exiting PlayState " << std::endl;
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