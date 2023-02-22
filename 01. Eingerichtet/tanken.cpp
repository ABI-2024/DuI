#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

bool Tanken(sf::Vector2f playerPos, sf::RectangleShape player, sf::RenderWindow& fenster, int currentGas) {
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