#include <math.h>
#include <iostream>

struct Vector2
{
	float Len()
	{
		return sqrt(x*x+y*y);
	}
	float x, y;
};

int main()
{
	Vector2 v;
	v.x = 1;
	v.y = 1;
	std::cout << v.Len() << "\n";
}
