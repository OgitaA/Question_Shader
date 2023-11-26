# include <Siv3D.hpp> // Siv3D v0.6.12


#include"Game.hpp"


void Main()
{
	Game game;

	game.init();

	while (System::Update())
	{

		game.update();
		game.draw();		
	}
}


