#ifndef MATH_PHYSICS_H
#define MATH_PHYSICS_H

#include "rectangle.h"
#include <cmath>

#define MP_MIN(X, Y) ((X) < (Y) ? (X) : (Y))
#define MP_MAX(X, Y) ((X) > (Y) ? (X) : (Y))
#define MP_ABS(X) ((X) < 0 ? -(X) : (X))
#define MP_SIGN(X) ((X) / MP_ABS(X))


struct physics
{
	vec2 position;
	vec2 velocity;
	vec2 forces;
};

inline rect rectCreate(float x, float y, float w, float h)
{
	rect r = { { x, y }, {x + w, y + h} };
	return r;
}

inline rect rectCreate(const vec2 &min, const vec2 &max)
{
	rect r = { min, max };
	return r;
}



inline vec2 vec2Add(const vec2 &v1, const vec2 &v2)
{
	vec2 v;
	v.x = v1.x + v2.x;
	v.y = v1.y + v2.y;
	return v;
}

inline vec2 vec2Sub(const vec2 &v1, const vec2 &v2)
{
	vec2 v;
	v.x = v1.x - v2.x;
	v.y = v1.y - v2.y;
	return v;	
}

inline vec2 vec2Mul(const vec2 &v1, float scalar)
{
	vec2 v;
	v.x = v1.x * scalar;
	v.y = v1.y * scalar;
	return v;
}

inline vec2 vec2Div(const vec2 &v1, float scalar)
{
	return vec2Mul(v1, 1.0f / scalar);
}

inline float vec2Dot(const vec2 &v1, const vec2 &v2)
{
	return v1.x * v2.x + v1.y * v2.y;
}

inline vec2 vec2Perpendicular(const vec2 &v1)
{
	vec2 v;
	v.x = v1.y;
	v.y = -v1.x;
	return v;
}

inline float vec2Angle(const vec2 &v)
{
	float r = atan(v.x / v.y);

	if (v.x < 0)
	{
		r += 3.141592f;
	}

	return r;
}

inline float vec2Length(const vec2 &v)
{
	return sqrt(v.x * v.x + v.y * v.y); // PYTAGORAS REGERAR
}

inline float vec2LengthSquared(const vec2 &v)
{
	return v.x * v.x + v.y * v.y;
}

inline void vec2Reset(vec2 *v)
{
	v->x = 0.0f;
	v->y = 0.0f;
}

inline void integrate(physics *ph, float delta)
{
	static const vec2 GRAVITY = { 0.0f, -1.0f };

	ph->forces = vec2Add(ph->forces, GRAVITY);

	ph->velocity = vec2Add(vec2Mul(ph->forces, delta * delta / 2.0f), ph->velocity);
	ph->position = vec2Add(ph->position, vec2Mul(ph->velocity, delta));

	vec2Reset(&ph->forces);
}

inline void applyForce(physics *ph, const vec2 &force)
{
	ph->forces = vec2Add(ph->forces, force);
}

#endif // !MATH_PHYSICS_H