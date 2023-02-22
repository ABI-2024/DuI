#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

bool Tanken(sf::RectangleShape player, sf::RenderWindow& fenster) {
	sf::Texture Gas;
	Gas.loadFromFile("ressources/Gas.png");
	sf::RectangleShape GasStation;
	
	GasStation.setTexture(&Gas);
	GasStation.setSize(sf::Vector2f(30, 30));
	GasStation.setPosition(890, 285);

	if (player.getGlobalBounds().intersects(GasStation.getGlobalBounds())) {
		
		return 1;
	}
	
	fenster.draw(GasStation);
	
}