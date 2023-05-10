#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <iostream>
bool onOff = 0;//0=an 1=aus

int soundOnOff(sf::RenderWindow& fenster) {
	

	sf::Texture ButtonOff;
	ButtonOff.loadFromFile("ressources/soundaus.png");
	sf::RectangleShape soundOff;
	soundOff.setTexture(&ButtonOff);
	soundOff.setSize(sf::Vector2f(45, 50));
	soundOff.setPosition(1200, 640);

	
	
	
	
	if (onOff == 1) {
		fenster.draw(soundOff);
		onOff = 0;
		return 0;
	}
}