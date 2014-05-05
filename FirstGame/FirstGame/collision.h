#ifndef COLLISION_H
#define COLLISION_H

#include "player.h"
#include "bullet.h"
#include "enemy.h"

#define BOOL int
#define TRUE 1
#define FALSE 0

const int screenWidth = 1280;
const int screenHeight = 720;

void wallCollision() {
	if (player.min.x < 0) {
		player.min.x = 0;
		player.max.x = playerSize;
	}
	if (player.min.y < 0) {
		player.min.y = 0;
		player.max.y = playerSize;
	}
	if (player.max.x > screenWidth) {
		player.max.x = screenWidth;
		player.min.x = screenWidth - playerSize;
	}
	if (player.max.y > screenHeight) {
		player.max.y = screenHeight;
		player.min.y = screenHeight - playerSize;
	}
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

#endif //"COLLISION_H