#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

int main()
{
	RenderWindow window({ 800,600 }, "SFML Test");
	Event ev;

	while (true)
	{
		window.pollEvent(ev);
		if (ev.type == Event::Closed)
		{
			window.close();
			break;
		}
		window.clear(Color(0,0,0));

		window.display();
	}
}