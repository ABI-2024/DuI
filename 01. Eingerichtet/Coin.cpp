#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

extern sf::Vector2f zweiRandomZahl();

int SamCoin(sf::RectangleShape* player, sf::Vector2f temppos, sf::RenderWindow& fenster, int* coinsetzen, sf::RectangleShape* Coin1, sf::RectangleShape* Coin2, sf::RectangleShape* Coin3, int* m�nze) {

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

	if (*m�nze == 1)
	{
		*m�nze = 0;
		temppos = zweiRandomZahl();
		Coin1->setPosition(temppos);
	}
	if (*m�nze == 2)
	{
		*m�nze = 0;
		temppos = zweiRandomZahl();
		Coin2->setPosition(temppos);
	}
	if (*m�nze == 3)
	{
		*m�nze = 0;
		temppos = zweiRandomZahl();
		Coin3->setPosition(temppos);
	}

	if (player->getGlobalBounds().intersects(Coin1->getGlobalBounds())) {

		*m�nze = 1;
		return 1;
	}
	else if (player->getGlobalBounds().intersects(Coin2->getGlobalBounds())) {

		*m�nze = 2;
		return 1;
	}
	else if (player->getGlobalBounds().intersects(Coin3->getGlobalBounds())) {

		*m�nze = 3;
		return 1;
	}
	
	return 0;
}