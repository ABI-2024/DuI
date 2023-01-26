#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

//sf::Texture Texturen();

//eigener Branch erstellt

int main()
{
	sf::RenderWindow window(sf::VideoMode(1280, 720), "DrivingUnderTheInfluence");
	window.setFramerateLimit(30);
	sf::Font font;
	font.loadFromFile("TangoSans.ttf");

	double speedx = 0;
	double speedy = 0;

	sf::Texture Gas;
	Gas.loadFromFile("ressources/Gas.png");

	sf::Texture Logo;
	Logo.loadFromFile("ressources/Logo.png");

	sf::Texture Coin;
	Coin.loadFromFile("ressources/coin.png");

	sf::Texture Car;
	Car.loadFromFile("ressources/Car1.png");

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

	sf::RectangleShape Start;
	Start.setFillColor(sf::Color(69, 69, 69, 220));
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

	sf::RectangleShape player;
	player.setTexture(&Car);
	player.setSize(sf::Vector2f(36, 36));
	player.setPosition(480, 404);

	sf::RectangleShape GasIcon;
	GasIcon.setTexture(&Gas);
	GasIcon.setSize(sf::Vector2f(50, 50));
	GasIcon.setPosition(20, 15);

	sf::RectangleShape CoinIcon;
	CoinIcon.setTexture(&Coin);
	CoinIcon.setSize(sf::Vector2f(50, 50));
	CoinIcon.setPosition(1200, 15);

	sf::RectangleShape GameIsOver;
	GameIsOver.setTexture(&GameOver);
	GameIsOver.setSize(sf::Vector2f(500, 200));
	GameIsOver.setPosition(382, 60);

	int info = 0;
	int wobinich = 5;
	sf::Vector2f temppos;

	int a = 0, b = 0, c = 0, d = 0;
	float gas = 100;

	int richt = 0;

	double speedx2 = 0;
	double speedy2 = 0;

	int a2 = 0, b2 = 0, c2 = 0, d2 = 0;

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
					info = 1;
					while (info == 1)
					{
						if (gas <= 0) {
							int gameover = 1;
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
											info = 0;
											gameover = 0;
											gas = 100;
											player.setPosition(480, 404);
											richt = 1;
											Car.loadFromFile("ressources/car" + std::to_string(richt) + ".png");
											player.setTexture(&Car);
											Boden.setTexture(&Map);
											wobinich = 5;

										}
									}
								}

								window.draw(Boden);
								window.draw(player);
								window.draw(GasIcon);
								window.draw(CoinIcon);
								GasVisRot.setSize(sf::Vector2f((gas), 15));
								window.draw(GasVisRot2);
								window.draw(GasVisRot);
								window.draw(Start);
								window.draw(backtomenu);
								window.draw(GameIsOver);
								window.display();
							}
						}

						if (wobinich == 1)
						{
							temppos = player.getPosition();
							if (temppos.x >= 1280)
							{
								player.setPosition(temppos.x - 1280, temppos.y);
								wobinich = 2;
								Map.loadFromFile("ressources/map" + std::to_string(wobinich) + ".png");
								Boden.setTexture(&Map);
							}
							if (temppos.x <= 0)
							{
								player.setPosition(temppos.x + 5, temppos.y);
							}
							if (temppos.y >= 686)
							{
								player.setPosition(temppos.x, temppos.y - 5);
							}
							if (temppos.y <= -24)
							{
								player.setPosition(temppos.x, temppos.y + 744);
								wobinich = 4;
								Map.loadFromFile("ressources/map" + std::to_string(wobinich) + ".png");
								Boden.setTexture(&Map);
							}
						}
						if (wobinich == 2)
						{
							temppos = player.getPosition();
							if (temppos.x >= 1280)
							{
								player.setPosition(temppos.x - 1304, temppos.y);
								wobinich = 3;
								Map.loadFromFile("ressources/map" + std::to_string(wobinich) + ".png");
								Boden.setTexture(&Map);
							}
							if (temppos.x <= -24)
							{
								player.setPosition(temppos.x + 1304, temppos.y);
								wobinich = 1;
								Map.loadFromFile("ressources/map" + std::to_string(wobinich) + ".png");
								Boden.setTexture(&Map);
							}
							if (temppos.y >= 686)
							{
								player.setPosition(temppos.x, temppos.y - 5);
							}
							if (temppos.y <= -24)
							{
								player.setPosition(temppos.x, temppos.y + 744);
								wobinich = 5;
								Map.loadFromFile("ressources/map" + std::to_string(wobinich) + ".png");
								Boden.setTexture(&Map);
							}
						}
						if (wobinich == 3)
						{
							temppos = player.getPosition();
							if (temppos.x >= 1246)
							{
								player.setPosition(temppos.x - 5, temppos.y);
							}
							if (temppos.x <= -24)
							{
								player.setPosition(temppos.x + 1304, temppos.y);
								wobinich = 2;
								Map.loadFromFile("ressources/map" + std::to_string(wobinich) + ".png");
								Boden.setTexture(&Map);
							}
							if (temppos.y >= 686)
							{
								player.setPosition(temppos.x, temppos.y - 5);
							}
							if (temppos.y <= -24)
							{
								player.setPosition(temppos.x, temppos.y + 744);
								wobinich = 6;
								Map.loadFromFile("ressources/map" + std::to_string(wobinich) + ".png");
								Boden.setTexture(&Map);
							}
						}
						if (wobinich == 4)
						{
							temppos = player.getPosition();
							if (temppos.x >= 1280)
							{
								player.setPosition(temppos.x - 1304, temppos.y);
								wobinich = 5;
								Map.loadFromFile("ressources/map" + std::to_string(wobinich) + ".png");
								Boden.setTexture(&Map);
							}
							if (temppos.x <= 0)
							{
								player.setPosition(temppos.x + 5, temppos.y);
							}
							if (temppos.y >= 720)
							{
								player.setPosition(temppos.x, temppos.y - 744);
								wobinich = 1;
								Map.loadFromFile("ressources/map" + std::to_string(wobinich) + ".png");
								Boden.setTexture(&Map);
							}
							if (temppos.y <= -24)
							{
								player.setPosition(temppos.x, temppos.y + 744);
								wobinich = 7;
								Map.loadFromFile("ressources/map" + std::to_string(wobinich) + ".png");
								Boden.setTexture(&Map);
							}
						}
						if (wobinich == 5)
						{
							temppos = player.getPosition();
							if (temppos.x >= 1280)
							{
								player.setPosition(temppos.x - 1304, temppos.y);
								wobinich = 6;
								Map.loadFromFile("ressources/map" + std::to_string(wobinich) + ".png");
								Boden.setTexture(&Map);
							}
							if (temppos.x <= -24)
							{
								player.setPosition(temppos.x + 1304, temppos.y);
								wobinich = 4;
								Map.loadFromFile("ressources/map" + std::to_string(wobinich) + ".png");
								Boden.setTexture(&Map);
							}
							if (temppos.y >= 720)
							{
								player.setPosition(temppos.x, temppos.y - 744);
								wobinich = 2;
								Map.loadFromFile("ressources/map" + std::to_string(wobinich) + ".png");
								Boden.setTexture(&Map);
							}
							if (temppos.y <= -24)
							{
								player.setPosition(temppos.x, temppos.y + 744);
								wobinich = 8;
								Map.loadFromFile("ressources/map" + std::to_string(wobinich) + ".png");
								Boden.setTexture(&Map);
							}
						}
						if (wobinich == 6)
						{
							temppos = player.getPosition();
							if (temppos.x >= 1246)
							{
								player.setPosition(temppos.x - 5, temppos.y);
							}
							if (temppos.x <= -24)
							{
								player.setPosition(temppos.x + 1304, temppos.y);
								wobinich = 5;
								Map.loadFromFile("ressources/map" + std::to_string(wobinich) + ".png");
								Boden.setTexture(&Map);
							}
							if (temppos.y >= 720)
							{
								player.setPosition(temppos.x, temppos.y - 744);
								wobinich = 3;
								Map.loadFromFile("ressources/map" + std::to_string(wobinich) + ".png");
								Boden.setTexture(&Map);
							}
							if (temppos.y <= -24)
							{
								player.setPosition(temppos.x, temppos.y + 744);
								wobinich = 9;
								Map.loadFromFile("ressources/map" + std::to_string(wobinich) + ".png");
								Boden.setTexture(&Map);
							}
						}
						if (wobinich == 7)
						{
							temppos = player.getPosition();
							if (temppos.x >= 1280)
							{
								player.setPosition(temppos.x - 1304, temppos.y);
								wobinich = 8;
								Map.loadFromFile("ressources/map" + std::to_string(wobinich) + ".png");
								Boden.setTexture(&Map);
							}
							if (temppos.x <= 0)
							{
								player.setPosition(temppos.x + 5, temppos.y);
							}
							if (temppos.y >= 720)
							{
								player.setPosition(temppos.x, temppos.y - 744);
								wobinich = 4;
								Map.loadFromFile("ressources/map" + std::to_string(wobinich) + ".png");
								Boden.setTexture(&Map);
							}
							if (temppos.y <= 0)
							{
								player.setPosition(temppos.x, temppos.y + 5);
							}
						}
						if (wobinich == 8)
						{
							temppos = player.getPosition();
							if (temppos.x >= 1280)
							{
								player.setPosition(temppos.x - 1304, temppos.y);
								wobinich = 9;
								Map.loadFromFile("ressources/map" + std::to_string(wobinich) + ".png");
								Boden.setTexture(&Map);
							}
							if (temppos.x <= -24)
							{
								player.setPosition(temppos.x + 1304, temppos.y);
								wobinich = 7;
								Map.loadFromFile("ressources/map" + std::to_string(wobinich) + ".png");
								Boden.setTexture(&Map);
							}
							if (temppos.y >= 720)
							{
								player.setPosition(temppos.x, temppos.y - 744);
								wobinich = 5;
								Map.loadFromFile("ressources/map" + std::to_string(wobinich) + ".png");
								Boden.setTexture(&Map);
							}
							if (temppos.y <= 0)
							{
								player.setPosition(temppos.x, temppos.y + 5);
							}
						}
						if (wobinich == 9)
						{
							temppos = player.getPosition();
							if (temppos.x >= 1246)
							{
								player.setPosition(temppos.x - 5, temppos.y);
							}
							if (temppos.x <= -24)
							{
								player.setPosition(temppos.x + 1304, temppos.y);
								wobinich = 8;
								Map.loadFromFile("ressources/map" + std::to_string(wobinich) + ".png");
								Boden.setTexture(&Map);
							}
							if (temppos.y >= 720)
							{
								player.setPosition(temppos.x, temppos.y - 744);
								wobinich = 6;
								Map.loadFromFile("ressources/map" + std::to_string(wobinich) + ".png");
								Boden.setTexture(&Map);
							}
							if (temppos.y <= 0)
							{
								player.setPosition(temppos.x, temppos.y + 5);
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
											info = 0;
											escmenu = 0;
											gas = 100;
											player.setPosition(480, 404);
											richt = 1;
											Car.loadFromFile("ressources/car" + std::to_string(richt) + ".png");
											player.setTexture(&Car);
											Boden.setTexture(&Map);
											wobinich = 5;

										}

										sf::Vector2i mousePos5 = sf::Mouse::getPosition(window);
										if (backtogame.getGlobalBounds().contains(mousePos5.x, mousePos5.y))
										{
											escmenu = 0;
										}
									}
								}

								window.draw(Boden);
								window.draw(player);
								window.draw(GasIcon);
								window.draw(CoinIcon);
								GasVisRot.setSize(sf::Vector2f((gas), 15));
								window.draw(GasVisRot2);
								window.draw(GasVisRot);
								window.draw(Start);
								window.draw(backtomenu);
								window.draw(backtogame);
								window.display();
							}
						}

						player.move(speedx, speedy);
						window.clear();
						window.draw(Boden);
						window.draw(player);
						window.draw(GasIcon);
						window.draw(CoinIcon);
						GasVisRot.setSize(sf::Vector2f((gas), 15));
						window.draw(GasVisRot2);
						window.draw(GasVisRot);


						window.display();
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



		window.clear();
		window.draw(Boden);
		window.draw(player);
		window.draw(GasIcon);
		window.draw(CoinIcon);
		GasVisRot.setSize(sf::Vector2f((gas), 15));
		window.draw(GasVisRot2);
		window.draw(GasVisRot);
		window.draw(Start);


		window.draw(button);
		window.draw(button2);
		window.draw(button3);

		window.draw(LogoMenu);

		window.display();
	}
}
