#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

int randomZahl();
sf::Vector2f zweiRandomZahl();
float motor(sf::Vector2f, int, sf::RenderWindow&, float);
bool Tanken(sf::RectangleShape, sf::RenderWindow&);
int SamCoin(sf::RectangleShape*, sf::Vector2f, sf::RenderWindow&, int);
int PossitionMap(sf::RenderWindow&, sf::RectangleShape*, sf::RectangleShape*, int*, sf::Texture*);

int main()
{
	sf::RenderWindow window(sf::VideoMode(1280, 720), "DrivingUnderTheInfluence");
	window.setFramerateLimit(30);
	sf::Font font;
	font.loadFromFile("upheavtt.ttf");

	double speedx = 0; //Movement
	double speedy = 0;
	int counter = 0; //Um die Zeit von Tanken bis nächst möglichem Tanken timen zu können

	int Menugenerell = 1; //Wenn Menugenerell 1 ist, wird das Startmenü angezeigt

	int wobinich = 5; //Position (Welche Karte geladen ist (1-9))

	sf::Vector2f temppos; //Ist für die Position im Normal-Mode (also auf welcher Karte man sich befindet da)

	float gas = 100; //Treibstoff einstellbar (Je höher deste mehr Tank hat man)

	float damage = 100;

	int richt = 3; //Ist für die Richtung wie die Textur des Autos ist da.

	int Coins = 100;  //Erstmal zum testen ist der Wert für Coins immer 10 solang es noch keine Coins gibt.
  
	int coinsetzen = 1; //Wenn dies 1 ist werden neue Coins gespawn bei 0 wird eine IF Funktion geskippt.

	sf::Texture Gas;
	Gas.loadFromFile("ressources/Gas.png");

	sf::Texture Logo;
	Logo.loadFromFile("ressources/Logo.png");

	sf::Texture Coin;
	Coin.loadFromFile("ressources/coin.png");

	sf::Texture Car;
	Car.loadFromFile("ressources/Car3.png");

	sf::Texture ComingSoon;
	ComingSoon.loadFromFile("ressources/ComingSoon.png");

	sf::Texture Map;
	Map.loadFromFile("ressources/map5.png");

	sf::Texture ButtonNor;
	ButtonNor.loadFromFile("ressources/NormalButton.png");
	sf::Texture ButtonEx;
	ButtonEx.loadFromFile("ressources/ExitButton.png");
	sf::Texture ButtonHard;
	ButtonHard.loadFromFile("ressources/HardButton.png");
	sf::Texture ButtonBackGame;
	ButtonBackGame.loadFromFile("ressources/BackToGameButton.png");
	sf::Texture ButtonBackMenu;
	ButtonBackMenu.loadFromFile("ressources/BackToMenuButton.png");
	sf::Texture GameOver;
	GameOver.loadFromFile("ressources/gameover.png");

	sf::Text CoinAnzahl; //Anzeige der Coins (die Text anzeige)
	CoinAnzahl.setFont(font);
	CoinAnzahl.setFillColor(sf::Color(252, 228, 13));
	CoinAnzahl.setOutlineThickness(2);
	CoinAnzahl.setOutlineColor(sf::Color(237, 167, 2));
	CoinAnzahl.setCharacterSize(35);
	CoinAnzahl.setPosition(1145, 15);
	CoinAnzahl.setString(std::to_string(Coins));

	sf::RectangleShape button(sf::Vector2f(200, 50));
	button.setPosition(sf::Vector2f(490, 250));
	button.setTexture(&ButtonNor);
	button.setSize(sf::Vector2f(300, 50));
	button.setFillColor(sf::Color(143, 143, 143));
	button.setOutlineThickness(2);
	button.setOutlineColor(sf::Color::Black);

	sf::RectangleShape button2(sf::Vector2f(200, 50));
	button2.setPosition(sf::Vector2f(490, 320));
	button2.setTexture(&ButtonHard);
	button2.setSize(sf::Vector2f(300, 50));
	button2.setFillColor(sf::Color(143, 143, 143));
	button2.setOutlineThickness(2);
	button2.setOutlineColor(sf::Color::Black);

	sf::RectangleShape button3(sf::Vector2f(200, 50));
	button3.setPosition(sf::Vector2f(490, 390));
	button3.setTexture(&ButtonEx);
	button3.setSize(sf::Vector2f(300, 50));
	button3.setFillColor(sf::Color(143, 143, 143));
	button3.setOutlineThickness(2);
	button3.setOutlineColor(sf::Color::Black);

	sf::RectangleShape backtomenu(sf::Vector2f(200, 50));
	backtomenu.setPosition(sf::Vector2f(490, 285));
	backtomenu.setTexture(&ButtonBackMenu);
	backtomenu.setSize(sf::Vector2f(300, 50));
	backtomenu.setFillColor(sf::Color(143, 143, 143));
	backtomenu.setOutlineThickness(2);
	backtomenu.setOutlineColor(sf::Color::Black);

	sf::RectangleShape backtogame(sf::Vector2f(200, 50));
	backtogame.setPosition(sf::Vector2f(490, 355));
	backtogame.setTexture(&ButtonBackGame);
	backtogame.setSize(sf::Vector2f(300, 50));
	backtogame.setFillColor(sf::Color(143, 143, 143));
	backtogame.setOutlineThickness(2);
	backtogame.setOutlineColor(sf::Color::Black);

	sf::RectangleShape Boden;
	Boden.setTexture(&Map);
	Boden.setSize(sf::Vector2f(1280, 720));

	sf::RectangleShape LogoMenu;
	LogoMenu.setTexture(&Logo);
	LogoMenu.setSize(sf::Vector2f(300, 300));
	LogoMenu.setPosition(sf::Vector2f(490, 0));

	sf::RectangleShape HintenGrau;
	HintenGrau.setFillColor(sf::Color(69, 69, 69, 220)); //Hier kann mit der letzten Zahl die Opacity geändert werden.
	HintenGrau.setPosition(0, 0);
	HintenGrau.setSize(sf::Vector2f(1280, 720));

	sf::RectangleShape GasAnzeigeVoll;
	GasAnzeigeVoll.setFillColor(sf::Color(255, 0, 0));
	GasAnzeigeVoll.setOutlineThickness(1);
	GasAnzeigeVoll.setOutlineColor(sf::Color::White);
	GasAnzeigeVoll.setPosition(60, 40);

	sf::RectangleShape GasVisRot2;
	GasVisRot2.setFillColor(sf::Color(69, 69, 69));
	GasVisRot2.setOutlineThickness(1);
	GasVisRot2.setOutlineColor(sf::Color::White);
	GasVisRot2.setSize(sf::Vector2f(100, 15));
	GasVisRot2.setPosition(60, 40);

	sf::RectangleShape player;
	player.setTexture(&Car);
	player.setSize(sf::Vector2f(36, 36));
	player.setPosition(643, 554);

	sf::RectangleShape GasIcon;
	GasIcon.setTexture(&Gas);
	GasIcon.setSize(sf::Vector2f(50, 50));
	GasIcon.setPosition(20, 15);

	sf::RectangleShape CoinIcon;
	CoinIcon.setTexture(&Coin);
	CoinIcon.setSize(sf::Vector2f(45, 50));
	CoinIcon.setPosition(1200, 15);

	sf::RectangleShape Coin1;
	Coin1.setTexture(&Coin);
	Coin1.setSize(sf::Vector2f(25, 30));

	sf::RectangleShape Coin2;
	Coin2.setTexture(&Coin);
	Coin2.setSize(sf::Vector2f(25, 30));

	sf::RectangleShape Coin3;
	Coin3.setTexture(&Coin);
	Coin3.setSize(sf::Vector2f(25, 30));

	sf::RectangleShape GameIsOver;
	GameIsOver.setTexture(&GameOver);
	GameIsOver.setSize(sf::Vector2f(500, 200));
	GameIsOver.setPosition(382, 60);

	int gameover = 1;

	while (window.isOpen())
	{
		sf::Event eventnormal;
		while (window.pollEvent(eventnormal))
		{
			if (eventnormal.type == sf::Event::Closed)
				window.close();

			if (eventnormal.type == sf::Event::MouseButtonPressed &&
				eventnormal.mouseButton.button == sf::Mouse::Left)
			{
				sf::Vector2i mousePos = sf::Mouse::getPosition(window);
				if (button.getGlobalBounds().contains(mousePos.x, mousePos.y))
				{
					Menugenerell = 1;
					while (Menugenerell == 1)
					{
						if (gas <= 0 || damage <= 0) {
							while (gameover == 1)
							{
								sf::Event eventgameover;
								while (window.pollEvent(eventgameover))
								{
									if (eventgameover.type == sf::Event::Closed)
										window.close();

									if (eventgameover.type == sf::Event::MouseButtonPressed &&
										eventgameover.mouseButton.button == sf::Mouse::Left)
									{
										sf::Vector2i mousePos7 = sf::Mouse::getPosition(window);
										if (backtomenu.getGlobalBounds().contains(mousePos7.x, mousePos7.y))
										{
											Menugenerell = 0;
											gameover = 0;
											coinsetzen = 1;
											gas = 100;

											damage = 100;
                      
											player.setPosition(643, 554);
											richt = 3;
											Car.loadFromFile("ressources/car" + std::to_string(richt) + ".png");
											player.setTexture(&Car);
											wobinich = 5;
											Map.loadFromFile("ressources/map" + std::to_string(wobinich) + ".png");
											Boden.setTexture(&Map);

										}
									}
								}

								//GameOver Screen (hier wird alles gedrawt was man sieht, wenn einem der Tank ausgeht)

								window.draw(Boden);
								window.draw(player);
								window.draw(GasIcon);
								window.draw(CoinIcon);
								GasAnzeigeVoll.setSize(sf::Vector2f((gas), 15));
								window.draw(GasVisRot2);
								window.draw(GasAnzeigeVoll);
								window.draw(HintenGrau);
								window.draw(backtomenu);
								window.draw(GameIsOver);
								window.display();
							}
						}

						speedx = 0;
						speedy = 0;
						if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
						{
							richt = 1;
							speedx -= 5;
							Car.loadFromFile("ressources/car" + std::to_string(richt) + ".png");
							player.setTexture(&Car);
							gas -= 0.04;
						}
						if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
						{
							richt = 2;
							speedx += 5;
							Car.loadFromFile("ressources/car" + std::to_string(richt) + ".png");
							player.setTexture(&Car);
							gas -= 0.04;
						}


						if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W))
						{
							richt = 3;
							speedy -= 5;
							Car.loadFromFile("ressources/car" + std::to_string(richt) + ".png");
							player.setTexture(&Car);
							gas -= 0.04;
						}
						if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
						{
							richt = 4;
							speedy += 5;
							Car.loadFromFile("ressources/car" + std::to_string(richt) + ".png");
							player.setTexture(&Car);
							gas -= 0.04;
						}

						if (speedx != 0 && speedy != 0) {
							speedx = (speedx / 5) * 3;
							speedy = (speedy / 5) * 3;
						}

						if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
						{
							int escmenu = 1;

							while (escmenu == 1)
							{
								sf::Event eventnormal;
								while (window.pollEvent(eventnormal))
								{
									if (eventnormal.type == sf::Event::Closed)
										window.close();

									if (eventnormal.type == sf::Event::MouseButtonPressed &&
										eventnormal.mouseButton.button == sf::Mouse::Left)
									{
										sf::Vector2i mousePos4 = sf::Mouse::getPosition(window);
										if (backtomenu.getGlobalBounds().contains(mousePos4.x, mousePos4.y))
										{
											Menugenerell = 0;

											coinsetzen = 1;
											escmenu = 0;
											gas = 100;
											damage = 100;

											escmenu = 0;
											gas = 100;

											player.setPosition(643, 554);
											richt = 3;
											Car.loadFromFile("ressources/car" + std::to_string(richt) + ".png"); //Hier werden die Texturen zurückgesetzt auf Standart
											player.setTexture(&Car);
											wobinich = 5;
											Map.loadFromFile("ressources/map" + std::to_string(wobinich) + ".png");
											Boden.setTexture(&Map);

										}

										sf::Vector2i mousePos5 = sf::Mouse::getPosition(window);
										if (backtogame.getGlobalBounds().contains(mousePos5.x, mousePos5.y))
										{
											escmenu = 0;
										}
									}
								}

								//Esc-Menue (hier wird alles gedrawt was wärend dem Menü zusehen ist wenn man ESC drückt)

								window.draw(Boden);
								window.draw(player);
								window.draw(GasIcon);
								window.draw(CoinIcon);
								window.draw(CoinAnzahl);
								GasAnzeigeVoll.setSize(sf::Vector2f((gas), 15));
								window.draw(GasVisRot2);
								window.draw(GasAnzeigeVoll);
								window.draw(HintenGrau);
								window.draw(backtomenu);
								window.draw(backtogame);
								window.display();
							}
						}

						//Das ist der Draw-Bereich wärend des Spiels

						player.move(speedx, speedy);
						window.clear();

						window.draw(Coin1);
						window.draw(Coin2);
						window.draw(Coin3);
						//window.draw(player);

						temppos = player.getPosition();

						wobinich = PossitionMap(window, &player, &Boden, &wobinich, &Map);
						if (wobinich == 5 && counter >= 350)
						{
							if (Tanken(player, window) == true) {
								gas = 100;
								counter = 0;
							}
						}

						Coins = Coins + SamCoin(&player, temppos, window, coinsetzen);

						if (temppos.x > 18 && temppos.x < 1262)
						{
							if (temppos.y > 20 && temppos.y < 700)
							{
								damage = motor(temppos, wobinich, window, damage);
							}
						}
						window.draw(GasIcon);
						window.draw(CoinIcon);
						window.draw(CoinAnzahl);
						GasAnzeigeVoll.setSize(sf::Vector2f((gas), 15));
						window.draw(GasVisRot2);
						window.draw(GasAnzeigeVoll);


						window.display();
						counter++;
					}
				}
			}

			if (eventnormal.type == sf::Event::MouseButtonPressed &&
				eventnormal.mouseButton.button == sf::Mouse::Left)
			{
				sf::Vector2i mousePos2 = sf::Mouse::getPosition(window);
				if (button2.getGlobalBounds().contains(mousePos2.x, mousePos2.y))
				{
					button2.setFillColor(sf::Color(145, 0, 0));
					button2.setTexture(&ComingSoon);
				}
			}

			if (eventnormal.type == sf::Event::MouseButtonPressed &&
				eventnormal.mouseButton.button == sf::Mouse::Left)
			{
				sf::Vector2i mousePos3 = sf::Mouse::getPosition(window);
				if (button3.getGlobalBounds().contains(mousePos3.x, mousePos3.y))
				{
					window.close();
				}
			}
		}

		// Hier ist der Startbirldschirm(Wo man den Mode oder Exit auswählt und das Logo zu sehen ist)

		window.clear();
		window.draw(Boden); //Bosen ist das Rechteck wo die Map drauf geladen wird.
		window.draw(HintenGrau);


		window.draw(button); //(Normal-Mode Button)
		window.draw(button2);
		window.draw(button3);

		window.draw(LogoMenu);

		window.display();
	}
}
