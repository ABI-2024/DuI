#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <iostream>

void soundOnOff(sf::RenderWindow& fenster) {
	sf::Texture ButtonOn;
	ButtonOn.loadFromFile("ressources/soundan.png");
	sf::RectangleShape soundOn;
	soundOn.setTexture(&ButtonOn);
	soundOn.setSize(sf::Vector2f(45, 50));
	soundOn.setPosition(1200, 640);

	sf::Texture ButtonOff;
	ButtonOn.loadFromFile("ressources/soundaus.png");
	sf::RectangleShape soundOff;
	soundOff.setTexture(&ButtonOff);
	soundOff.setSize(sf::Vector2f(45, 50));
	soundOff.setPosition(1200, 640);

	bool onOff = 0; //0=an 1=aus
	
	if (onOff = 0) {
		fenster.draw(soundOn);
		onOff = 1;
	}
	if (onOff = 1) {
		fenster.draw(soundOff);
		onOff = 0;
	}
}