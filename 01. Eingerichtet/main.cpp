#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Screen");
    window.setFramerateLimit(30);
    sf::Font font;
    font.loadFromFile("TangoSans.ttf");

    double speedx = 0;
    double speedy = 0;

    int a = 0, b = 0, c = 0, d = 0;
    int gas1 = 0;
    int gas2 = 0;

    double speedx2 = 0;
    double speedy2 = 0;

    int a2 = 0, b2 = 0, c2 = 0, d2 = 0;

    sf::Texture Gas;
    Gas.loadFromFile("Gas2.png");
    sf::Texture Gas20;
    Gas20.loadFromFile("Gas.png");

    sf::Texture CarUp;
    CarUp.loadFromFile("CarUp.png");
    sf::Texture CarDown;
    CarDown.loadFromFile("CarDown.png");
    sf::Texture CarLeft;
    CarLeft.loadFromFile("CarLeft.png");
    sf::Texture CarRight;
    CarRight.loadFromFile("CarRight.png");

    sf::Texture CarUp2;
    CarUp2.loadFromFile("CarUp2.png");
    sf::Texture CarDown2;
    CarDown2.loadFromFile("CarDown2.png");
    sf::Texture CarLeft2;
    CarLeft2.loadFromFile("CarLeft2.png");
    sf::Texture CarRight2;
    CarRight2.loadFromFile("CarRight2.png");

    sf::Texture Bod;
    Bod.loadFromFile("boden.png");

    sf::RectangleShape Boden;
    Boden.setTexture(&Bod);
    Boden.setSize(sf::Vector2f(1280, 720));

	sf::RectangleShape Start;
	Start.setFillColor(sf::Color(69, 69, 69, 0));
	Start.setPosition(0, 0);
	Start.setSize(sf::Vector2f(1280, 720));

	sf::RectangleShape GasVisRot;
	GasVisRot.setFillColor(sf::Color(255, 0, 0));
	GasVisRot.setOutlineThickness(1);
	GasVisRot.setOutlineColor(sf::Color::White);
	GasVisRot.setPosition(60, 40);

	sf::RectangleShape GasVisRot2;
	GasVisRot2.setFillColor(sf::Color(69, 69, 69));
	GasVisRot2.setOutlineThickness(1);
	GasVisRot2.setOutlineColor(sf::Color::White);
	GasVisRot2.setSize(sf::Vector2f(100, 15));
	GasVisRot2.setPosition(60, 40);

	sf::RectangleShape GasVisBlau;
	GasVisBlau.setFillColor(sf::Color::Blue);
	GasVisBlau.setOutlineThickness(1);
	GasVisBlau.setOutlineColor(sf::Color::White);
	GasVisBlau.setPosition(1208, 55);
	GasVisBlau.setRotation(180);

	sf::RectangleShape GasVisBlau2;
	GasVisBlau2.setFillColor(sf::Color(69, 69, 69));
	GasVisBlau2.setOutlineThickness(1);
	GasVisBlau2.setOutlineColor(sf::Color::White);
	GasVisBlau2.setSize(sf::Vector2f(100, 15));
	GasVisBlau2.setPosition(1208, 55);
	GasVisBlau2.setRotation(180);

    sf::RectangleShape player;
    player.setTexture(&CarRight);
    player.setSize(sf::Vector2f(36, 36));
    player.setPosition(100, 400);

    sf::RectangleShape player2;
    player2.setTexture(&CarLeft2);
    player2.setSize(sf::Vector2f(36, 36));
    player2.setPosition(400, 400);

    sf::RectangleShape GasIcon;
    GasIcon.setTexture(&Gas);
    GasIcon.setSize(sf::Vector2f(50, 50));
    GasIcon.setPosition(1200, 15);

    sf::RectangleShape GasIcon2;
    GasIcon2.setTexture(&Gas20);
    GasIcon2.setSize(sf::Vector2f(50, 50));
    GasIcon2.setPosition(20, 15);

    GasStation.setTexture(&Gas);
    sf::RectangleShape GasStation;

    int gas = 10000;
    int gass = 10000;

    while (window.isOpen())
    {

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            speedx = -5;
            player.setTexture(&CarLeft);
            gas = gas - 0.001;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            speedx = 5;
            player.setTexture(&CarRight);
            gas = gas - 0.001;
        }
        else
        {
            speedx = 0;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            speedy = -5;
            player.setTexture(&CarUp);
            gas = gas - 0.001;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            speedy = 5;
            player.setTexture(&CarDown);
            gas = gas - 0.001;
        }
        else
        {
            speedy = 0;
        }








        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            speedx2 = -5;
            player2.setTexture(&CarLeft2);
            gass = gass - 0.001;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            speedx2 = 5;
            player2.setTexture(&CarRight2);
            gass = gass - 0.001;
        }
        else
        {
            speedx2 = 0;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            speedy2 = -5;
            player2.setTexture(&CarUp2);
            gass = gass - 0.001;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            speedy2 = 5;
            player2.setTexture(&CarDown2);
            gass = gass - 0.001;
        }
        else
        {
            speedy2 = 0;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {

            window.close();
        }

        gas1 = gas / 100;
        gas2 = gass / 100;

        player.move(speedx, speedy);
        player2.move(speedx2, speedy2);
        window.clear();
        window.draw(Boden);
        window.draw(player);
        window.draw(player2);
        window.draw(GasIcon);
		GasVisRot.setSize(sf::Vector2f((gas2), 15));
		window.draw(GasVisRot2);
		window.draw(GasVisRot);
        window.draw(GasIcon2);
		GasVisBlau.setSize(sf::Vector2f((gas1), 15));
		window.draw(GasVisBlau2);
		window.draw(GasVisBlau);
		window.draw(Start);

        window.display();
    }
    return 0;
}