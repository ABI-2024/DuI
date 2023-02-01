#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <random>

using namespace std; 
void motor(sf::Vector2f poss, int mapzahl, sf::RenderWindow& fenster) {

	sf::Texture Motor;
	Motor.loadFromFile("ressources/motor.png");

	sf::RectangleShape MotorAnzeigeVoll;
	MotorAnzeigeVoll.setFillColor(sf::Color(107, 61, 4));
	MotorAnzeigeVoll.setOutlineThickness(1);
	MotorAnzeigeVoll.setOutlineColor(sf::Color::White);
	MotorAnzeigeVoll.setPosition(60, 60);

	sf::RectangleShape MotorVisBraun2;
	MotorVisBraun2.setFillColor(sf::Color(69, 69, 69));
	MotorVisBraun2.setOutlineThickness(1);
	MotorVisBraun2.setOutlineColor(sf::Color::White);
	MotorVisBraun2.setSize(sf::Vector2f(100, 15));
	MotorVisBraun2.setPosition(60, 60);

	sf::RectangleShape MotorIcon;
	MotorIcon.setTexture(&Motor);
	MotorIcon.setSize(sf::Vector2f(50, 50));
	MotorIcon.setPosition(20, 35);

	sf::Color Black = sf::Color::Black;
	sf::Color White = sf::Color::White;
	sf::Color Grey = sf::Color(105, 106, 106);
	sf::Color DarkGrey = sf::Color(48, 45, 43);

	poss.x = poss.x / 4 + 5;
	poss.y = poss.y / 4 + 5;

	int damage = 0;

	sf::Image Karte;
	Karte.loadFromFile("ressources/map" + std::to_string(mapzahl) + ".png");
	
	sf::Color pixelcolor = Karte.getPixel(poss.x, poss.y);
	if (pixelcolor != Black && pixelcolor != White && pixelcolor != Grey && pixelcolor != DarkGrey) {
		damage += 0.04;
	}

	fenster.clear();
	fenster.draw(MotorIcon);
	MotorAnzeigeVoll.setSize(sf::Vector2f((damage), 35));
	fenster.draw(MotorAnzeigeVoll);
	fenster.draw(MotorVisBraun2);
	fenster.display();
}