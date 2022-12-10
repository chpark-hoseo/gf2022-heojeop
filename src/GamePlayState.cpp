#include "GamePlayState.h"
#include "TextureManager.h"
#include "Game.h"
#include "InputHandler.h"
#include "GameOver.h"
#include "GameClear.h"
#include <iostream>


const std::string PlayState::s_playID = "PLAY";



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

    if (checkCollision(dynamic_cast<SDLGameObject*>(m_gameObjects[14]), dynamic_cast<SDLGameObject*>(m_gameObjects[0])))
    {
        TheGame::Instance()->getStateMachine()->pushState(new GameOverState());
        
    }
    if (checkCollision(dynamic_cast<SDLGameObject*>(m_gameObjects[14]), dynamic_cast<SDLGameObject*>(m_gameObjects[1])))
    {
        TheGame::Instance()->getStateMachine()->pushState(new GameOverState());
        
    }
    if (checkCollision(dynamic_cast<SDLGameObject*>(m_gameObjects[14]), dynamic_cast<SDLGameObject*>(m_gameObjects[2])))
    {
        
        TheGame::Instance()->getStateMachine()->pushState(new GameOverState());
    }
    if (checkCollision(dynamic_cast<SDLGameObject*>(m_gameObjects[14]), dynamic_cast<SDLGameObject*>(m_gameObjects[3])))
    {
        TheGame::Instance()->getStateMachine()->pushState(new GameOverState());
       
    }
    if (checkCollision(dynamic_cast<SDLGameObject*>(m_gameObjects[14]), dynamic_cast<SDLGameObject*>(m_gameObjects[4])))
    {
       
        TheGame::Instance()->getStateMachine()->pushState(new GameOverState());
    }
    if (checkCollision(dynamic_cast<SDLGameObject*>(m_gameObjects[14]), dynamic_cast<SDLGameObject*>(m_gameObjects[5])))
    {

        TheGame::Instance()->getStateMachine()->pushState(new GameOverState());
    }
    if (checkCollision(dynamic_cast<SDLGameObject*>(m_gameObjects[14]), dynamic_cast<SDLGameObject*>(m_gameObjects[6])))
    {
        TheGame::Instance()->getStateMachine()->pushState(new GameOverState());
        
    }
    if (checkCollision(dynamic_cast<SDLGameObject*>(m_gameObjects[14]), dynamic_cast<SDLGameObject*>(m_gameObjects[7])))
    {

        TheGame::Instance()->getStateMachine()->pushState(new GameOverState());
    }
    if (checkCollision(dynamic_cast<SDLGameObject*>(m_gameObjects[14]), dynamic_cast<SDLGameObject*>(m_gameObjects[8])))
    {
        TheGame::Instance()->getStateMachine()->pushState(new GameOverState());

    }
    if (checkCollision(dynamic_cast<SDLGameObject*>(m_gameObjects[14]), dynamic_cast<SDLGameObject*>(m_gameObjects[9])))
    {
        if (FirstFlag == false) {
            FirstFlag = true;
            cout << " First Flag " << endl;
        }
    }
    if (checkCollision(dynamic_cast<SDLGameObject*>(m_gameObjects[14]), dynamic_cast<SDLGameObject*>(m_gameObjects[10])))
    {

        if (FirstFlag == true && SecondFlag == false) {
            SecondFlag = true;
            cout << " Second Flag " << endl;
        }
    }
    if (checkCollision(dynamic_cast<SDLGameObject*>(m_gameObjects[14]), dynamic_cast<SDLGameObject*>(m_gameObjects[11])))
    {

        if (FirstFlag == true && SecondFlag == true && ThirdFlag == false) {
            ThirdFlag = true;
            cout << " Third Flag " << endl;
        }


    }

    if (checkCollision(dynamic_cast<SDLGameObject*>(m_gameObjects[14]), dynamic_cast<SDLGameObject*>(m_gameObjects[12])))
    {

        if (FirstFlag == true && SecondFlag == true && ThirdFlag == true) {
            TheGame::Instance()->getStateMachine()->pushState(new GameClear());
        }


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
    if (!TheTextureManager::Instance()->load("Assets/Car.png", "Charactor", TheGame::Instance()->getRenderer())) 
    {
        return false;
    }
    if (!TheTextureManager::Instance()->load("Assets/RaceTrack2.png", "Background", TheGame::Instance()->getRenderer()))
    {
        return false;
    }
    if (!TheTextureManager::Instance()->load("Assets/1.png", "TrackCollider 1", TheGame::Instance()->getRenderer()))
    {
        return false;
    }
    if (!TheTextureManager::Instance()->load("Assets/2.png", "TrackCollider 2", TheGame::Instance()->getRenderer()))
    {
        return false;
    }
    if (!TheTextureManager::Instance()->load("Assets/3.png", "TrackCollider 3", TheGame::Instance()->getRenderer()))
    {
        return false;
    }
    if (!TheTextureManager::Instance()->load("Assets/4.png", "TrackCollider 4", TheGame::Instance()->getRenderer()))
    {
        return false;
    }
    if (!TheTextureManager::Instance()->load("Assets/5.png", "TrackCollider 5", TheGame::Instance()->getRenderer()))
    {
        return false;
    }
    if (!TheTextureManager::Instance()->load("Assets/6.png", "TrackCollider 6", TheGame::Instance()->getRenderer()))
    {
        return false;
    }
    if (!TheTextureManager::Instance()->load("Assets/7.png", "TrackCollider 7", TheGame::Instance()->getRenderer()))
    {
        return false;
    }
    if (!TheTextureManager::Instance()->load("Assets/8.png", "TrackCollider 8", TheGame::Instance()->getRenderer()))
    {
        return false;
    }
    if (!TheTextureManager::Instance()->load("Assets/9.png", "TrackCollider 9", TheGame::Instance()->getRenderer()))
    {
        return false;
    }
    if (!TheTextureManager::Instance()->load("Assets/10.png", "Goal", TheGame::Instance()->getRenderer()))
    {
        return false;
    }
    if (!TheTextureManager::Instance()->load("Assets/Collider.png", "Flag", TheGame::Instance()->getRenderer()))
    {
        return false;
    }

    GameObject* Collider1 = new Background(new LoaderParams(0, 0, 1024, 41, "TrackCollider 1"));
    GameObject* Collider2 = new Background(new LoaderParams(0, 41, 40, 500, "TrackCollider 2"));
    GameObject* Collider3 = new Background(new LoaderParams(40, 494, 984, 46, "TrackCollider 3"));
    GameObject* Collider4 = new Background(new LoaderParams(1002, 42, 21, 452, "TrackCollider 4"));
    GameObject* Collider5 = new Background(new LoaderParams(166, 143, 700, 33, "TrackCollider 5"));
    GameObject* Collider6 = new Background(new LoaderParams(652, 264, 350, 40, "TrackCollider 6"));
    GameObject* Collider7 = new Background(new LoaderParams(166, 176, 346, 168, "TrackCollider 7"));
    GameObject* Collider8 = new Background(new LoaderParams(280, 344, 232, 74, "TrackCollider 8"));
    GameObject* Collider9 = new Background(new LoaderParams(512, 384, 383, 34, "TrackCollider 9"));
    GameObject* Goal = new Background(new LoaderParams(632, 416, 16, 77, "Goal"));

    GameObject* FirstFlag = new Background(new LoaderParams(60, 215, 77, 16, "Flag"));
    GameObject* SecondFlag = new Background(new LoaderParams(880, 131, 77, 16, "Flag"));
    GameObject* ThirdFlag = new Background(new LoaderParams(910, 385, 77, 16, "Flag"));
    GameObject* BackgroundImage = new Background(new LoaderParams(0, 0, 1024, 540, "Background"));

    GameObject* player = new Player(new LoaderParams(635, 443, 22, 40, "Charactor"));

    

    
    m_gameObjects.push_back(Collider1);
    m_gameObjects.push_back(Collider2);
    m_gameObjects.push_back(Collider3);
    m_gameObjects.push_back(Collider4);
    m_gameObjects.push_back(Collider5);
    m_gameObjects.push_back(Collider6);
    m_gameObjects.push_back(Collider7);
    m_gameObjects.push_back(Collider8);
    m_gameObjects.push_back(Collider9); 
    m_gameObjects.push_back(FirstFlag);
    m_gameObjects.push_back(SecondFlag);
    m_gameObjects.push_back(ThirdFlag);
    m_gameObjects.push_back(Goal);
    m_gameObjects.push_back(BackgroundImage);
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

    TheTextureManager::Instance()->clearTextureMap("TrackCollider 1");
    TheTextureManager::Instance()->clearTextureMap("TrackCollider 2");
    TheTextureManager::Instance()->clearTextureMap("TrackCollider 3");
    TheTextureManager::Instance()->clearTextureMap("TrackCollider 4");
    TheTextureManager::Instance()->clearTextureMap("TrackCollider 5");
    TheTextureManager::Instance()->clearTextureMap("TrackCollider 6");
    TheTextureManager::Instance()->clearTextureMap("TrackCollider 7");
    TheTextureManager::Instance()->clearTextureMap("TrackCollider 8");
    TheTextureManager::Instance()->clearTextureMap("TrackCollider 9");
    TheTextureManager::Instance()->clearTextureMap("Goal");
    TheTextureManager::Instance()->clearTextureMap("Flag");
    TheTextureManager::Instance()->clearTextureMap("Background");
    TheTextureManager::Instance()->clearTextureMap("Charactor");
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