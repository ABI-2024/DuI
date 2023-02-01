#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <random>

using namespace std; 
void motor(sf::Vector2f poss, int mapzahl) {

	//sf::Texture Motor;
	//Motor.loadFromFile("ressources/motor.png");

	//sf::RectangleShape MotorAnzeigeVoll;
	//MotorAnzeigeVoll.setFillColor(sf::Color(107, 61, 4));
	//MotorAnzeigeVoll.setOutlineThickness(1);
	//MotorAnzeigeVoll.setOutlineColor(sf::Color::White);
	//MotorAnzeigeVoll.setPosition(60, 40);

	//sf::RectangleShape MotorVisRot2;
	//MotorVisRot2.setFillColor(sf::Color(69, 69, 69));
	//MotorVisRot2.setOutlineThickness(1);
	//MotorVisRot2.setOutlineColor(sf::Color::White);
	//MotorVisRot2.setSize(sf::Vector2f(100, 15));
	//MotorVisRot2.setPosition(60, 40);

	//sf::RectangleShape MotorIcon;
	//MotorIcon.setTexture(&Motor);
	//MotorIcon.setSize(sf::Vector2f(50, 50));
	//MotorIcon.setPosition(20, 15);

	sf::Color Black = sf::Color::Black;
	sf::Color White = sf::Color::White;
	sf::Color Grey = sf::Color(105, 106, 106);
	sf::Color DarkGrey = sf::Color(48, 45, 43);

	poss.x = poss.x / 4 + 5;
	poss.y = poss.y / 4 + 5;

	sf::Image Karte;
	Karte.loadFromFile("ressources/map" + std::to_string(mapzahl) + ".png");
	
	sf::Color pixelcolor = Karte.getPixel(poss.x, poss.y);
	if (pixelcolor != Black && pixelcolor != White && pixelcolor != Grey && pixelcolor != DarkGrey) {
		cout << "Nicht auf der Strasse!" << endl;
	}

	//if (pixelcolor != sf::Color::White && pixelcolor != sf::Color::Black)
	//{
	//	cout << "Nicht auf der Straße!";
	//}
	//else
	//{
	//	cout << "Auf der Straße";
	//}

}