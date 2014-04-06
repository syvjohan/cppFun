#ifndef UTILITY_H
#define UTILITY_H


template<typename T>
inline T Min(T t1, T t2) { 
	return t1 < t2 ? t1 : t2;
}

struct Point
{
	// Default ctor
	Point() { x = 0; y = 0; }

	Point(int x, int y) : x(x), y(y) {}
	int x;
	int y;
};

struct Color
{
	// Default ctor
	Color() { r = 0; g = 0; b = 0; a = 0; }

	Color(float r, float g, float b, float a)
	{
		this->r = r;
		this->g = g;
		this->b = b;
		this->a = a;
	}

	explicit Color(int col)
	{
		b = (col & (0xFF >> 24)) / 255.0f;
		g = (col & (0xFF >> 16)) / 255.0f;
		r = (col & (0xFF >> 8)) / 255.0f;
		a = (col & (0xFF >> 0)) / 255.0f;
	}

	inline int AsInt32() const
	{
		unsigned char col[4];
		col[0] = (b * 255.0f);
		col[1] = (g * 255.0f);
		col[2] = (r * 255.0f);
		col[3] = (a * 255.0f);
		return *((int*)col);
	}

	float r, g, b, a;
};

struct Rect
{
	// Default Ctor.
	Rect() : min(0, 0), max(0, 0) { }
	Rect(int x, int y, int w, int h) : min(x, y), max(x + w, y + h) {}

	inline bool Intersects(const Rect &other)
	{
		return !(
			min.x > other.max.x ||
			min.y > other.max.y ||
			other.min.x > max.x ||
			other.min.y > max.y);
	}

	inline Rect IntersectionRect(const Rect &other)
	{
		Rect r;

		Point p1 = { min.x + (max.x - min.x) / 2,
			min.y + (max.y - min.y) / 2
		};

		Point p2 = { other.min.x + (other.max.x - other.min.x) / 2,
			other.min.y + (other.max.y - other.min.y) / 2
		};

		if (p1.x > p2.x)
		{
			r.min.x = min.x;
			r.max.x = other.max.x;
		}
		else
		{
			r.min.x = other.min.x;
			r.max.x = max.x;
		}

		if (p1.y > p2.y)
		{
			r.min.y = min.y;
			r.max.y = other.max.y;
		}
		else
		{
			r.min.y = other.min.y;
			r.max.y = max.y;
		}

		return r;
	}

	Point min;
	Point max;
};

#endif // !UTILITY_H