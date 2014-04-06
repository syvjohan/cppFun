#include "Game.h"
#include "IRenderer.h"
#include "Wall.h"

Game::Game()
{
	_player = new Player();
	_objects.push_back(_player);

	EventManager::RegisterListener(EVT_QUIT_GAME, this);
	EventManager::RegisterListener(EVT_MOVE, _player);

	Rect wallRect;

	for (int i = 0; i != 10; ++i)
	{
		wallRect.min = Point(rand() % 1180 + 50, rand() % 620 + 50);
		wallRect.max.x = wallRect.min.x + 50;
		wallRect.max.y = wallRect.min.y + 50;

		_objects.push_back(new Wall(wallRect));

	}
}

Game::~Game()
{
	for (IGameObject *obj : _objects)
	{
		delete obj;
	}

	_player = nullptr;
}

void Game::Update()
{
	for (IGameObject *obj : _objects)
	{
		obj->Update();
	}

	DoCollisions();
}

void Game::Render(IRenderer *renderer)
{
	renderer->Clear(Color(0.25f, 0.0f, 0.25f, 1.0f));

	// Render game objects..
	for (IGameObject *obj : _objects)
	{
		obj->Render(renderer);
	}

	renderer->Present();
}

bool Game::HandleEvent(const EventPTR &evt)
{
	switch (evt->Id())
	{
		case EVT_QUIT_GAME:
			// Stop the game here..
			break;
	}

	return false;
}

void Game::DoCollisions()
{
	for (IGameObject *obj1 : _objects)
	{
		for (IGameObject *obj2 : _objects)
		{
			// Skip collisions against self
			if (obj1 == obj2) continue;

			if (obj1->HitBox().Intersects(obj2->HitBox()))
			{
				Rect r1 = obj1->HitBox();
				Rect r2 = obj2->HitBox();

				Point p1 = { r1.min.x + (r1.max.x - r1.min.x) / 2,
					r1.min.y + (r1.max.y - r1.min.y) / 2
				};

				Point p2 = { r2.min.x + (r2.max.x - r2.min.x) / 2,
					r2.min.y + (r2.max.y - r2.min.y) / 2
				};

				Rect overlap = r1.IntersectionRect(r2);

				int w = overlap.max.x - overlap.min.x;
				int h = overlap.max.y - overlap.min.y;

				if (obj1->Type() != GO_WALL && obj2->Type() != GO_WALL)
				{
					if (w > h)
					{
						r1.min.y -= h / 2;
						r1.max.y -= h / 2;

						r2.min.y += h / 2;
						r2.max.y += h / 2;
					}
					else
					{
						r1.min.x -= w / 2;
						r1.max.x -= w / 2;

						r2.min.x += w / 2;
						r2.max.x += w / 2;
					}
				}
				else if (obj1->Type() != GO_WALL)
				{
					int d = 1;
					if (w > h)
					{
						d = p1.y > p2.y ? 1 : -1;

						r1.min.y += h * d;
						r1.max.y += h * d;
					}
					else
					{
						d = p1.x > p2.x ? 1 : -1;

						r1.min.x += w * d;
						r1.max.x += w * d;
					}
				}


				obj1->SetBox(r1);
				obj2->SetBox(r2);
			}
		}
	}
}