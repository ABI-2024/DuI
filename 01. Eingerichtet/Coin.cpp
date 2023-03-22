#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

extern sf::Vector2f zweiRandomZahl();

int SamCoin(sf::RectangleShape* player, sf::Vector2f temppos, sf::RenderWindow& fenster, int* coinsetzen, sf::RectangleShape* Coin1, sf::RectangleShape* Coin2, sf::RectangleShape* Coin3) {

	if (*coinsetzen == 1)
	{

		temppos = zweiRandomZahl();
		Coin1->setPosition(temppos);

		temppos = zweiRandomZahl();
		Coin2->setPosition(temppos);

		temppos = zweiRandomZahl();
		Coin3->setPosition(temppos);


		std::cout << Coin1->getPosition().x << " " << Coin1->getPosition().y << std::endl;
		std::cout << Coin2->getPosition().x << " " << Coin2->getPosition().y << std::endl;
		std::cout << Coin3->getPosition().x << " " << Coin3->getPosition().y << std::endl << std::endl;
		*coinsetzen = 0;
	}

	if (player->getGlobalBounds().intersects(Coin1->getGlobalBounds())) {

		return 1;
	}
	else if (player->getGlobalBounds().intersects(Coin2->getGlobalBounds())) {

		return 1;
	}
	else if (player->getGlobalBounds().intersects(Coin3->getGlobalBounds())) {

		return 1;
	}
	
	return 0;
}