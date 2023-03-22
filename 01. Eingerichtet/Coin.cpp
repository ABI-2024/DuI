#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

extern sf::Vector2f zweiRandomZahl();

int SamCoin(sf::RectangleShape* player, sf::Vector2f temppos, sf::RenderWindow& fenster, int* coinsetzen, sf::RectangleShape* Coin1, sf::RectangleShape* Coin2, sf::RectangleShape* Coin3, int* münze) {

	if (*coinsetzen == 1)
	{

		temppos = zweiRandomZahl();
		Coin1->setPosition(temppos);

		temppos = zweiRandomZahl();
		Coin2->setPosition(temppos);

		temppos = zweiRandomZahl();
		Coin3->setPosition(temppos);

		*coinsetzen = 0;
	}

	if (*münze == 1)
	{
		*münze = 0;
		temppos = zweiRandomZahl();
		Coin1->setPosition(temppos);
	}
	if (*münze == 2)
	{
		*münze = 0;
		temppos = zweiRandomZahl();
		Coin2->setPosition(temppos);
	}
	if (*münze == 3)
	{
		*münze = 0;
		temppos = zweiRandomZahl();
		Coin3->setPosition(temppos);
	}

	if (player->getGlobalBounds().intersects(Coin1->getGlobalBounds())) {

		*münze = 1;
		return 1;
	}
	else if (player->getGlobalBounds().intersects(Coin2->getGlobalBounds())) {

		*münze = 2;
		return 1;
	}
	else if (player->getGlobalBounds().intersects(Coin3->getGlobalBounds())) {

		*münze = 3;
		return 1;
	}
	
	return 0;
}