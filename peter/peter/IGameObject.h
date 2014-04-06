#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

enum GameObjectType
{
	GO_UNDEFINED = 0,

	GO_PLAYER,
	GO_WALL,
};


class IRenderer;

class IGameObject
{
public:
	virtual ~IGameObject() { }


	virtual GameObjectType Type() const = 0;
	virtual void Update() = 0;
	virtual void Render(IRenderer *renderer) = 0;

	virtual Rect HitBox() const = 0;
	virtual void SetBox(const Rect &box) = 0;

private:
};

#endif // !GAMEOBJECT_h