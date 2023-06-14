#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

bool shop(sf::RectangleShape player, sf::RenderWindow& fenster) {
	sf::Texture Cart;
	Cart.loadFromFile("ressources/card.png");
	sf::RectangleShape CartShop;
	CartShop.setTexture(&Cart);
	CartShop.setSize(sf::Vector2f(30, 30));
	CartShop.setPosition(370, 285);

	if (player.getGlobalBounds().intersects(CartShop.getGlobalBounds())) {
		return 1;
	}

	fenster.draw(CartShop);

}