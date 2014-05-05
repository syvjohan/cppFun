#ifndef RECTANGLE_H
#define RECTANGLE_H

struct vec2 
{
	int x;
	int y;
};

struct rect
{
	vec2 min;
	vec2 max;
};

#endif //!RECTANGLE_H