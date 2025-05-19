#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdio.h>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;
double gx=810., gy=810.;
RenderWindow window(VideoMode(gx, gy), "Fractals by deepness.");
ContextSettings settings;
Vertex line[] =
{
	Vertex(Vector2f(0, gy)),
	Vertex(Vector2f(gx, gy))
};

void SeTri_SFML(double sx, double sy, double x, double y, double d)
{
	if (d<=0)
	{
		return;
	}
	double l = (x - sx) * 0.75 + sx - (((x - sx) * 0.25) + sx);
	line[0] = Vertex(Vector2f(((x - sx) * 0.25) + sx,(y - sy) * 0.5 + sy));
	line[1] = Vertex(Vector2f((x - sx) * 0.75 + sx,(y - sy) * 0.5 + sy));
	window.draw(line, 2, Lines);
	line[1] = Vertex(Vector2f((x - sx) * 0.5 + sx,(y - sy) + sy));
	window.draw(line, 2, Lines);
	line[0] = Vertex(Vector2f((x - sx) * 0.75 + sx,(y - sy) * 0.5 + sy));
	window.draw(line, 2, Lines);
	d -= 2;
	SeTri_SFML(sx, sy + l, x-l, y, d);
	SeTri_SFML(sx + l, sy + l, x, y, d);
	SeTri_SFML(sx + l * 0.5, sy, sx + l * 1.5, y - l, d);
}

void SeCarp_SFML(double sx, double sy, double x, double y, double d)
{
	if (d <= 0)
	{
		return;
	}
	double l = (x-sx)/3;
	line[0] = Vertex(Vector2f(l + sx, l + sy));
	line[1] = Vertex(Vector2f(l * 2 + sx, l + sy));
	window.draw(line, 2, Lines);
	line[1] = Vertex(Vector2f(l + sx, l * 2  + sy));
	window.draw(line, 2, Lines);
	line[0] = Vertex(Vector2f(l + sx, l * 2 + sy));
	line[1] = Vertex(Vector2f(l * 2 + sx, l * 2 + sy));
	window.draw(line, 2, Lines);
	line[0] = Vertex(Vector2f(l * 2 + sx, l * 2 + sy));
	line[1] = Vertex(Vector2f(l * 2 + sx, l + sy));
	window.draw(line, 2, Lines);
	d -= 2;
	SeCarp_SFML(sx, sy, l + sx, l + sy, d);
	SeCarp_SFML(sx + l, sy, l * 2 + sx, l + sy, d);
	SeCarp_SFML(l * 2 + sx, sy, l * 3 + sx, l + sy, d);
	SeCarp_SFML(l * 2 + sx, l + sy, l * 3 + sx, l * 2 + sy, d);
	SeCarp_SFML(l * 2 + sx, l * 2 + sy, l * 3 + sx, l * 3 + sy, d);
	SeCarp_SFML(l + sx, l * 2 + sy, l * 2 + sx, l * 3 + sy, d);
	SeCarp_SFML(sx, l * 2 + sy, l + sx, l * 3 + sy, d);
	SeCarp_SFML(sx, l + sy, l + sx, l * 2 + sy, d);
}

int main()
{
	int c = 0;
	double d=0, x=gx, y=gy;
	settings.antialiasingLevel = 8;
	while (window.isOpen())
	{
		window.clear(Color::Black);
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
			}
			if ((event.key.code == Keyboard::Add || event.key.code == Keyboard::Equal) && d < 20)
			{
				d++;
			}
			else if ((event.key.code == Keyboard::Subtract || event.key.code == Keyboard::Dash) && d>0)
			{
				d--;
			}
			switch (event.key.code)
			{
				case Keyboard::Num0:
				{
					c = 0;
					break;
				}
				case Keyboard::Num1:
				{
					c = 1;
					break;
				}
				default:
					break;
			}
		}
		line->color = Color::White;
		switch (c)
		{
			case 0:
			{
				line[0] = Vertex(Vector2f(0, y-0.5));
				line[1] = Vertex(Vector2f(x-0.5, y-0.5));
				window.draw(line, 2, Lines);
				line[1] = Vertex(Vector2f(x/2, 0));
				window.draw(line, 2, Lines);
				line[0] = Vertex(Vector2f(x, y));
				window.draw(line, 2, Lines);
				SeTri_SFML(0, 0, x, y, d);
				break;
			}
			case 1:
			{
				line[0] = Vertex(Vector2f(0.5, 0.5));
				line[1] = Vertex(Vector2f(0.5, y));
				window.draw(line, 2, Lines);
				line[1] = Vertex(Vector2f(x, 0.5));
				window.draw(line, 2, Lines);
				line[0] = Vertex(Vector2f(x, y));
				line[1] = Vertex(Vector2f(0, y - 0.5));
				window.draw(line, 2, Lines);
				line[1] = Vertex(Vector2f(x, 0.5));
				window.draw(line, 2, Lines);
				SeCarp_SFML(0, 0, x, y, d);
				break;
			}
			default:
				break;
		}
		window.display();
	}
}