#include "Player.h"
#include "IRenderer.h"

#define SIGN(X) (X / (X < 0 ? -X : X))

Player::Player()
{
	_box.max.x = 40;
	_box.max.y = 40;
}

Player::~Player()
{

}

void Player::Update()
{
	_box.min.x += _direction.x;
	_box.max.x += _direction.x;

	_box.min.y += _direction.y;
	_box.max.y += _direction.y;
}

void Player::Render(IRenderer *renderer)
{
	renderer->DrawRectangle(_box, Color(1.0f, 1.0f, 0, 1));
}

bool Player::HandleEvent(const EventPTR &evt)
{
	switch (evt->Id())
	{
		case EVT_MOVE:
			{
				Point nDirection = ((MoveEvent*)evt.get())->GetDirection();

				_direction.x += nDirection.x;
				_direction.y += nDirection.y;
			}
			break;
	}

	return false;
}