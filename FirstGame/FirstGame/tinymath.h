#ifndef TINYMATH_H
#define TINYMATH_H

#ifdef __cplusplus
#include <cmath>
#else
#include <math.h>
#endif

#define TI_MAX(X, Y) ((X) > (Y) ? (X) : (Y))
#define TI_MIN(X, Y) ((X) < (Y) ? (X) : (Y))

#define BOOL int
#define TRUE 1
#define FALSE 0

// Change these values to play around with gravity. (simply set to zero to turn it off).
#define GRAVITY_X 0.0f
#define GRAVITY_Y 250.0f


struct tiVec2
{
	float x, y;
};

struct tiRect
{
	tiVec2 min;
	tiVec2 max;
};

struct tiPhysics
{
	tiVec2 position;
	tiVec2 velocity;
	tiVec2 forces;

	// Air resistance, decides how quickly an object stops. Ff set to 0 objects will not stop unless colliding,
	// or some external force moves them in another direction.
	// Try values between 0.1-0.001... 
	float linearDrag;
};

// Retrieve the width of a rectangle.
inline float tiRectWidth(const tiRect &r)
{
	return r.max.x - r.min.x;
}

// Retrieve the height of a rectangle.
inline float tiRectHeight(const tiRect &r)
{
	return r.max.y - r.min.y;
}

// Create a rectangle.
inline tiRect tiRectCreate(float x, float y, float width, float height)
{
	tiRect rect = { {x, y}, { x + width, y + height } };
	return rect;
}

// Set the members of a rectangle using width/height rather than min/max.
inline void tiRectSet(float x, float y, float width, float height, tiRect *out)
{
	out->min.x = x;
	out->min.y = y;
	out->max.x = x + width;
	out->max.y = y + height;
}

// Treats the vector as a point, and returns true if the rectangle contains the point.
inline BOOL tiRectContains(const tiRect &r, const tiVec2 &point)
{
	if (point.x < r.min.x) return FALSE;
	if (point.x > r.max.x) return FALSE;
	if (point.y < r.min.y) return FALSE;
	if (point.y > r.max.y) return FALSE;

	return TRUE;
}

// Returns true if r1 intersects with r2.
inline BOOL tiRectIntersects(const tiRect &r1, const tiRect &r2)
{
	 if (r1.min.x > r2.max.x) return FALSE;
	 if (r1.min.y > r2.max.y) return FALSE;
	 if (r2.min.x > r1.max.x) return FALSE;
	 if (r2.min.y > r1.max.y) return FALSE;
	 return true;
}

// Returns the rectangle of intersection between r1 and r2. - Make sure the intersect first.
inline tiRect tiRectOverlap(const tiRect &r1, const tiRect &r2)
{
	tiRect r;
	r.min.x = TI_MAX(r1.min.x, r2.min.x);
	r.min.y = TI_MAX(r1.min.y, r2.min.y);
	r.max.x = TI_MIN(r1.max.x, r2.max.x);
	r.max.y = TI_MIN(r1.max.y, r2.max.y);	
	return r;
}

// Returns the minimum translation vector to stop r1 from intersecting with r2.
// Make sure they intersect first.
inline tiVec2 tiRectMTV(const tiRect &r1, const tiRect &r2)
{
	tiRect o = tiRectOverlap(r1, r2);

	float width = o.max.x - o.min.x;
	float height = o.max.y - o.min.y;

	tiVec2 mtv = { 0.0f, 0.0f };

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

// Sets members of a tiVec2.
inline tiVec2 tiVec2Set(float x, float y, tiVec2 *out)
{
	out->x = x;
	out->y = y;
}

// Add two vectors together and return the result.
inline tiVec2 tiVec2Add(const tiVec2 &v1, const tiVec2 &v2)
{
	tiVec2 v = { v1.x + v2.x, v1.y + v2.y };
	return v;
}

// Add two vectors and return result in out parameter.
inline void tiVec2Add(const tiVec2 &v1, const tiVec2 &v2, tiVec2 *out)
{
	out->x = v1.x + v2.x;
	out->y = v1.y + v2.y;
}

// Subtract to vectors and return result in out parameter.
inline void tiVec2Sub(const tiVec2 &v1, const tiVec2 &v2, tiVec2 *out)
{
	out->x = v1.x - v2.x;
	out->y = v1.y - v2.y;
}

// Returns the result of v1 - v2.
inline tiVec2 tiVec2Sub(const tiVec2 &v1, const tiVec2 &v2)
{
	tiVec2 v;
	tiVec2Sub(v1, v2, &v);
	return v;
}

// Multiply v by a scalar f and return result in out parameter.
inline void tiVec2ScalarMul(const tiVec2 &v, float f, tiVec2 *out)
{
	out->x = v.x * f;
	out->y = v.y * f;
}

// returns v multiplied by f;
inline tiVec2 tiVec2ScalarMul(const tiVec2 &v, float f)
{
	tiVec2 ret;
	tiVec2ScalarMul(v, f, &ret);
	return ret;
}

// returns v divided by f in the out parameter.
inline void tiVec2ScalarDiv(const tiVec2 &v, float f, tiVec2 *out)
{
	tiVec2ScalarMul(v, 1.0f / f, out);
}

// Returns v divded by f.
inline tiVec2 tiVec2ScalarDiv(const tiVec2 &v, float f)
{
	return tiVec2ScalarMul(v, 1.0f / f);
}

// Returns the dot/scalar-product of v1 and v2.
// (v1 | v2) = |v1||v2|cos(theta) where theta is the angle between v1 and v2, and (v1 | v2) means the dot product.
inline float tiVec2Dot(const tiVec2 &v1, const tiVec2 &v2)
{
	return v1.x * v2.x + v1.y * v2.y;
}

// Returns the magnitude of v.
inline float tiVec2Length(const tiVec2 &v)
{
	return sqrtf(tiVec2Dot(v, v));
}

// Returns the magnitude of v squared (faster).
inline float tiVec2LengthSquared(const tiVec2 &v)
{
	return tiVec2Dot(v, v);
}

// Set v to the zero vector.
inline void tiVec2Zero(tiVec2 *v)
{
	v->x = 0;
	v->y = 0;
}

// Creates a physics object with an initial position, velocity and drag.
inline tiPhysics tiPhysicsCreate(const tiVec2 &pos, const tiVec2 &velocity, float linearDrag)
{
	tiPhysics ph;
	ph.position = pos;
	ph.velocity = velocity;
	ph.linearDrag = linearDrag;
	tiVec2Zero(&ph.forces);
	return ph;
}

// Integrates a physics object using standard newton.
// We assume m = 1.
// f = ma = a
// v = at + v0
// p = at^2/2 + v0t + p0
inline void tiPhysicsIntegrate(tiPhysics *ph, float delta)
{
	// Gravity constant vector
	static const tiVec2 kGravity = { GRAVITY_X, GRAVITY_Y };

	// Apply gravity as a constant force.
	tiVec2Add(ph->forces, kGravity, &ph->forces);

	tiVec2Add(ph->position, tiVec2ScalarMul(kGravity, delta), &ph->position);

	// Integrate velocity over time.
	tiVec2Add(ph->velocity, tiVec2ScalarMul(ph->forces, delta), &ph->velocity);

	// Integrate position over time.
	tiVec2Add(ph->position, tiVec2ScalarMul(ph->velocity, delta), &ph->position);
	//tiVec2Add(ph->position, tiVec2ScalarMul(ph->forces, delta * delta / 2.0f), &ph->position);

	// Apply linear drag.
	tiVec2ScalarMul(ph->velocity, 1.0f - ph->linearDrag, &ph->velocity);

	// Reset forces every time.
	tiVec2Zero(&ph->forces);
}

inline void tiPhysicsApplyForce(const tiVec2 &v, tiPhysics *out) {
    tiVec2Add(out->forces, v, &out->forces);
}

// Maintains the direction of v but makes the length 1
inline void tiVec2Normalize(const tiVec2 &v, tiVec2 *out)
{
 float len = tiVec2Length( v);
 out->x /= len;
 out->y /= len;
}

// Returns the normalized vector of v.
inline tiVec2 tiVec2Normalized(const tiVec2 &v)
{
 tiVec2 o;
 tiVec2Normalize(v, &o);
 return o;
}

#endif // !TINYMATH_H