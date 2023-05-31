#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <random>

using namespace std; 
float motor(sf::Vector2f poss, int mapzahl, sf::RenderWindow& fenster, float damage) {

	sf::Texture Motor;
	Motor.loadFromFile("ressources/motor.png");

	sf::RectangleShape MotorAnzeigeVoll;
	MotorAnzeigeVoll.setFillColor(sf::Color(107, 61, 4));
	MotorAnzeigeVoll.setOutlineThickness(1);
	MotorAnzeigeVoll.setOutlineColor(sf::Color::White);
	MotorAnzeigeVoll.setPosition(60, 75);

	sf::RectangleShape MotorVisBraun2;
	MotorVisBraun2.setFillColor(sf::Color(69, 69, 69));
	MotorVisBraun2.setOutlineThickness(1);
	MotorVisBraun2.setOutlineColor(sf::Color::White);
	MotorVisBraun2.setSize(sf::Vector2f(100, 15));
	MotorVisBraun2.setPosition(60, 75);

	sf::RectangleShape MotorIcon;
	MotorIcon.setTexture(&Motor);
	MotorIcon.setSize(sf::Vector2f(40, 40));
	MotorIcon.setPosition(17, 62);

	static sf::Color Black = sf::Color::Black;
	static sf::Color White = sf::Color::White;
	static sf::Color Grey = sf::Color(105, 106, 106);
	static sf::Color Red = sf::Color(172, 50, 50);
	static sf::Color DarkGrey = sf::Color(48, 45, 43);

	static sf::Color Blau = sf::Color(91, 110, 225);
	static sf::Color Blau2 = sf::Color(52, 69, 174);
	static sf::Color Blau3 = sf::Color(2, 22, 139);
	static sf::Color Blau4 = sf::Color(31, 31, 228);
	static sf::Color Blau5 = sf::Color(73, 73, 228);
	static sf::Color Blau6 = sf::Color(85, 85, 228);

	poss.x = poss.x / 4 + 5;
	poss.y = poss.y / 4 + 5;

	sf::Image Karte;
	Karte.loadFromFile("ressources/map" + std::to_string(mapzahl) + ".png");
	
	sf::Color pixelcolor = Karte.getPixel(poss.x, poss.y);
	if (pixelcolor == Blau || pixelcolor == Blau2 || pixelcolor == Blau3 || pixelcolor == Blau4 || pixelcolor == Blau5 || pixelcolor == Blau6) {
		damage -= 4;
	}
	else if (pixelcolor != Black && pixelcolor != White && pixelcolor != Grey && pixelcolor != DarkGrey && pixelcolor != Red) {
		damage -= 0.04;
	}

	fenster.draw(MotorIcon);
	MotorAnzeigeVoll.setSize(sf::Vector2f((damage), 15));
	fenster.draw(MotorVisBraun2);
	fenster.draw(MotorAnzeigeVoll);
	return damage;
}