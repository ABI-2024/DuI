#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <iostream>


void soundOnOff(sf::RenderWindow& fenster,sf::Sound* ton,sf::Music* musik,bool* soundOn) {
	

	sf::Texture ButtonOff;
	ButtonOff.loadFromFile("ressources/soundaus.png");
	sf::RectangleShape soundOff;
	soundOff.setTexture(&ButtonOff);
	soundOff.setSize(sf::Vector2f(45, 50));
	soundOff.setPosition(1200, 640);
				
	if (soundOn)
	{
		ton->pause();
		*soundOn = false;
	}
	else
	{
		ton->play();
		*soundOn = true;
	}
				
		
}