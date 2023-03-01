#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

extern sf::Vector2f zweiRandomZahl();

int SamCoin(sf::RectangleShape* player, sf::Vector2f temppos, sf::RenderWindow& fenster, int coinsetzen) {

	sf::Texture CoinTex;
	CoinTex.loadFromFile("ressources/coin.png");

	sf::RectangleShape Coin1;
	Coin1.setTexture(&CoinTex);
	Coin1.setSize(sf::Vector2f(25, 30));

	sf::RectangleShape Coin2;
	Coin2.setTexture(&CoinTex);
	Coin2.setSize(sf::Vector2f(25, 30));

	sf::RectangleShape Coin3;
	Coin3.setTexture(&CoinTex);
	Coin3.setSize(sf::Vector2f(25, 30));

	if (coinsetzen == 1)
	{

		temppos = zweiRandomZahl();
		Coin1.setPosition(temppos);

		temppos = zweiRandomZahl();
		Coin2.setPosition(temppos);

		temppos = zweiRandomZahl();
		Coin3.setPosition(temppos);

		coinsetzen = 0;
	}

	if (player->getGlobalBounds().intersects(Coin1.getGlobalBounds())) {

		return 1;
	}
	if (player->getGlobalBounds().intersects(Coin2.getGlobalBounds())) {

		return 1;
	}
	if (player->getGlobalBounds().intersects(Coin3.getGlobalBounds())) {

		return 1;
	}

	fenster.draw(Coin1);
	fenster.draw(Coin2);
	fenster.draw(Coin3);

	return 0;
}