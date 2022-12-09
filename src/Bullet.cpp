#include "Bullet.h"

Bullet::Bullet(const LoaderParams* pParams) : SDLGameObject(pParams) {

}

void Bullet::draw() {
	SDLGameObject::draw(flip, angle);
}

void Bullet::update() {

	Vector2D* vec = TheInputHandler::Instance()->getMousePosition();
	m_acceleration.setY(-10);
	m_velocity = (*vec - m_position) / 100;
	m_currentFrame = 0;
	SDLGameObject::update();
	FireBullet();
}

void Bullet::FireBullet() {


	if (m_position.getX() >= 480 || m_position.getX() <= 0 || m_position.getY() >= 640 || m_position.getY() <= 0) {

		printf(" ¤·¤· ");
	}
}