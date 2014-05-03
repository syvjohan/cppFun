#ifndef MATH_PHYSICS_H
#define MATH_PHYSICS_H

#include <cmath>

#define MP_MIN(X, Y) ((X) < (Y) ? (X) : (Y))
#define MP_MAX(X, Y) ((X) > (Y) ? (X) : (Y))
#define MP_ABS(X) ((X) < 0 ? -(X) : (X))
#define MP_SIGN(X) ((X) / MP_ABS(X))

#define BOOL int
#define TRUE 1
#define FALSE 0

struct vec2 
{
	float x;
	float y;
};

struct physics
{
	vec2 position;
	vec2 velocity;
	vec2 forces;
};

struct rect
{
	vec2 min;
	vec2 max;
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

// Returns TRUE if two rectangles intersect.
inline BOOL rectIntersects(const rect &r1, const rect &r2)
{
	if (r1.min.x > r2.max.x) return FALSE;
	if (r1.min.y > r2.max.y) return FALSE;
	if (r2.min.x > r1.max.x) return FALSE;
	if (r2.min.y > r1.max.y) return FALSE;

	return TRUE;
};

// Returns the overlapping rectangle between to rectangles. MAKE SURE THEY INTERSECT FIRST!
inline rect rectOverlap(const rect &r1, const rect &r2)
{
	rect r;
	r.min.x = MP_MAX(r1.min.x, r2.min.x);
	r.min.y = MP_MAX(r1.min.y, r2.min.y);
	r.max.x = MP_MIN(r1.max.x, r2.max.x);
	r.max.y = MP_MIN(r1.max.y, r2.max.y);

	return r;
}

// Return a vector with the minimum translation to stop two rectangles from intersecting.
// The vector will assume that r1 is to stop intersecting with r2.
inline vec2 rectMTV(const rect &r1, const rect &r2)
{
	if (rectIntersects(r1, r2))
	{
		rect o = rectOverlap(r1, r2);

		float width = o.max.x - o.min.x;
		float height = o.max.y - o.min.y;

		vec2 mtv = { 0.0f, 0.0f };

		if (width > height)
		{
			float r1mid = r1.min.y + (r1.max.y - r1.min.y) / 2.0f;
			float r2mid = r2.min.y + (r2.max.y - r2.min.y) / 2.0f;

			if (r1mid > r2mid)
			{
				mtv.y = height;
			}
			else
			{
				mtv.y = -height;
			}
		}
		else
		{
			float r1mid = r1.min.x + (r1.max.x - r1.min.x) / 2.0f;
			float r2mid = r2.min.x + (r2.max.x - r2.min.x) / 2.0f;

			if (r1mid > r2mid)
			{
				mtv.x = width;
			}
			else
			{
				mtv.x = -width;
			}
		}

		return mtv;
	}

	vec2 zero = { 0.0f, 0.0f };
	return zero;
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