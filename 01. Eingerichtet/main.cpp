#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <fstream>
#include <iostream>

int randomZahl();
sf::Vector2f zweiRandomZahl();
float motor(sf::Vector2f, int, sf::RenderWindow&, float);
bool Tanken(sf::RectangleShape, sf::RenderWindow&);
bool shop(sf::RectangleShape, sf::RenderWindow&);
int SamCoin(sf::RectangleShape*, sf::Vector2f, sf::RenderWindow&, int*, sf::RectangleShape*, sf::RectangleShape*, sf::RectangleShape*, int*);
int PossitionMap(sf::RenderWindow&, sf::RectangleShape*, sf::RectangleShape*, int*, sf::Texture*, int*);

int main()
{
	sf::RenderWindow window(sf::VideoMode(1280, 720), "DrivingUnderTheInfluence");
	window.setFramerateLimit(30);
	sf::Font font;
	font.loadFromFile("upheavtt.ttf");

	sf::SoundBuffer coinsound;
	coinsound.loadFromFile("sounds/coin.wav"); //Sounds für Münzen
	sf::SoundBuffer fuelsound;
	fuelsound.loadFromFile("sounds/refillfuel.wav");
	sf::SoundBuffer holysound;
	holysound.loadFromFile("sounds/holy.wav");
	sf::Sound sound;
	sound.setBuffer(coinsound);
	sound.setVolume(10);
	
	sf::Music backgroundmusic; //Hintergrundmusik
	if (!backgroundmusic.openFromFile("sounds/music.wav"))
		return -1;
	backgroundmusic.setVolume(8);
	backgroundmusic.play();
	backgroundmusic.setLoop(true);

	std::ofstream inputFile; //Daten eingabe
	std::ifstream outputFile; //Daten ausgeben von Daten.csv
	std::ofstream inputFile2; 
	std::ifstream outputFile2;

	std::string eingabecoins;

	double speedx = 0; //Movement
	double speedy = 0;
	int counter = 0; //Um die Zeit von Tanken bis nächst möglichem Tanken timen zu können
	int Coincounter = 0;

	int münzen = 0; //Welche Münze neu plaziert werden soll

	int Menugenerell = 1; //Wenn Menugenerell 1 ist, wird das Startmenü angezeigt

	int carskin = 0; // Wenn 0 = standartskin bei 1 gold skin!

	int wobinich = 5; //Position (Welche Karte geladen ist (1-9))

	sf::Vector2f temppos; //Ist für die Position im Spiel (also auf welcher Karte man sich befindet) da.

	float gas = 100; //Treibstoff einstellbar (Je höher deste mehr Tank hat man)

	float damage = 100;

	outputFile.open("data.scv");
	int Coins = 0;  //Anzahl der Münzen beim ersten Start
	outputFile >> Coins;
	outputFile.close();

	outputFile2.open("dataskin.scv");
	outputFile2 >> carskin; //Speichert ob man das Goldene Auto hat oder nicht 1 = ja man hats, 0 = normales Auto
	outputFile.close();
  
	int coinsetzen = 1; //Wenn dies 1 ist werden neue Coins gespawn bei 0 wird eine IF Funktion geskippt.

	sf::Texture Gas;
	Gas.loadFromFile("ressources/Gas.png");

	sf::Texture Logo;
	Logo.loadFromFile("ressources/Logo.png");

	sf::Texture CoinTex;
	CoinTex.loadFromFile("ressources/coin.png");

	sf::Texture Car;
	Car.loadFromFile("ressources/Car.png");

	sf::Texture Map;
	Map.loadFromFile("ressources/map5.png");

	sf::Texture Übersicht;
	Übersicht.loadFromFile("ressources/AlleKarten.png");

	sf::Texture ButtonNor;
	ButtonNor.loadFromFile("ressources/NormalButton.png");
	sf::Texture ButtonEx;
	ButtonEx.loadFromFile("ressources/ExitButton.png");
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
	button.setPosition(sf::Vector2f(490, 300));
	button.setTexture(&ButtonNor);
	button.setSize(sf::Vector2f(300, 50));
	button.setFillColor(sf::Color(143, 143, 143));
	button.setOutlineThickness(2);
	button.setOutlineColor(sf::Color::Black);

	sf::RectangleShape button3(sf::Vector2f(200, 50));
	button3.setPosition(sf::Vector2f(490, 370));
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

	sf::RectangleShape Karte;
	Karte.setTexture(&Übersicht);
	Karte.setSize(sf::Vector2f(960, 540));
	Karte.setPosition(sf::Vector2f(160, 90));

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
	player.setOrigin(player.getSize() / 2.f);
	player.setPosition(643, 554);

	sf::RectangleShape GasIcon;
	GasIcon.setTexture(&Gas);
	GasIcon.setSize(sf::Vector2f(50, 50));
	GasIcon.setPosition(20, 15);

	sf::RectangleShape CoinIcon;
	CoinIcon.setTexture(&CoinTex);
	CoinIcon.setSize(sf::Vector2f(45, 50));
	CoinIcon.setPosition(1200, 15);

	sf::RectangleShape Coin1;
	Coin1.setTexture(&CoinTex);
	Coin1.setSize(sf::Vector2f(25, 30));

	sf::RectangleShape Coin2;
	Coin2.setTexture(&CoinTex);
	Coin2.setSize(sf::Vector2f(25, 30));

	sf::RectangleShape Coin3;
	Coin3.setTexture(&CoinTex);
	Coin3.setSize(sf::Vector2f(25, 30));

	sf::RectangleShape GameIsOver;
	GameIsOver.setTexture(&GameOver);
	GameIsOver.setSize(sf::Vector2f(500, 200));
	GameIsOver.setPosition(382, 60);

	int gameover = 1;

	while (window.isOpen())
	{
		if (carskin == 0)
		{
			Car.loadFromFile("ressources/car.png");
		}
		else
		{
			Car.loadFromFile("ressources/gcar.png");
		}
		player.setTexture(&Car);

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
						if (gas <= 0 || damage <= 0) { // Noch ein Fehler drin 
							gameover = 1;		//Damit das Gameover menu nicht flackert.
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
											coinsetzen = 1;
											gas = 100;
											damage = 100;
											gameover = 0;
											counter = 0;
											player.setPosition(643, 554);
											player.setRotation(0);
											if (carskin == 0)
											{
												Car.loadFromFile("ressources/car.png");
											}
											else
											{
												Car.loadFromFile("ressources/gcar.png");
											}
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
							if (carskin == 0)
							{
								speedx -= 5;
							}
							else
							{
								speedx -= 7;
							}
							player.setRotation(270);
							if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
							{
								player.setRotation(320);
							}
							if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
							{
								player.setRotation(230);
							}
							gas -= 0.04;
						}
						if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
						{
							if (carskin == 0)
							{
								speedx += 5;
							}
							else
							{
								speedx += 7;
							}
							player.setRotation(90);
							if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
							{
								player.setRotation(45);
							}
							if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
							{
								player.setRotation(135);
							}
							gas -= 0.04;
						}


						if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W))
						{
							if (carskin == 0)
							{
								speedy -= 5;
							}
							else
							{
								speedy -= 7;
							}
							player.setRotation(0);
							if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
							{
								player.setRotation(320);
							}
							if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
							{
								player.setRotation(45);
							}
							gas -= 0.04;
						}
						if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
						{
							if (carskin == 0)
							{
								speedy += 5;
							}
							else
							{
								speedy += 7;
							}
							player.setRotation(180);
							if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
							{
								player.setRotation(230);
							}
							if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
							{
								player.setRotation(135);
							}
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
											player.setRotation(0);
											if (carskin == 0)
											{
												Car.loadFromFile("ressources/car.png");	//Hier werden die Texturen zurückgesetzt auf Standart
											}
											else
											{
												Car.loadFromFile("ressources/gcar.png");	//Hier werden die Texturen zurückgesetzt auf Standart
											}							
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
								CoinAnzahl.setString(std::to_string(Coins));
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
						//window.draw(player);

						temppos = player.getPosition();

						wobinich = PossitionMap(window, &player, &Boden, &wobinich, &Map, &coinsetzen); //Sorgt für das wechseln der Kartenabschnitte, im Numpad Layout werden die Karten je nach Position gewechset
						if (wobinich == 5 && counter >= 350 && Coins >= 5)
						{
							if (Tanken(player, window) == true && Coins >= 5) { //Funktion für das Tanken, kostet 5 Münzen und hat einen Cooldown
								gas = 100;
								inputFile.open("data.scv");
								Coins = Coins - 5; //5 Münzen kostet der Tank
								inputFile << Coins;
								inputFile.close();
								sound.setBuffer(fuelsound);
								sound.setVolume(40);
								sound.play();
								counter = 0;
							}
						}
						if (wobinich == 5 && carskin == 0)
						{

							if (shop(player, window) == true && Coins >= 100) {   //Shop ist immer da, klappt aber erst wenn man 100 Münzen hat. Wenn Funktion ausgeführt, 100 Münzen werden abgezogen und neue Auto Textur wird geladen.
								Car.loadFromFile("ressources/gcar.png");
								player.setTexture(&Car);
								inputFile2.open("dataskin.scv");
								carskin = 1;
								inputFile2 << carskin;
								inputFile2.close();
								inputFile.open("data.scv");
								Coins = Coins - 100; //100 Münzen kostet der Tank
								inputFile << Coins;
								inputFile.close();
								sound.setBuffer(holysound);
								sound.setVolume(40);
								sound.play();
							}
						}

						if (SamCoin(&player, temppos, window, &coinsetzen, &Coin1, &Coin2, &Coin3, &münzen) == true && Coincounter >= 20) //Funktion zum Sammeln von Münzen, vergleicht Positionen vom Auto und den Münzen
						{
							inputFile.open("data.scv");
							Coins++;
							inputFile << Coins;
							inputFile.close();
							inputFile << eingabecoins;
							inputFile.close();
							sound.setBuffer(coinsound);
							sound.setVolume(10);
							sound.play();
							Coincounter = 0;
						}

						damage = motor(temppos, wobinich, window, damage); //Sorgt für Schaden am Auto, überprüft auf welcher Farbe das Auto fährt und sorgt für Schaden

						window.draw(Coin1);
						window.draw(Coin2);
						window.draw(Coin3);
						window.draw(GasIcon);
						window.draw(CoinIcon);
						CoinAnzahl.setString(std::to_string(Coins));
						window.draw(CoinAnzahl);
						GasAnzeigeVoll.setSize(sf::Vector2f((gas), 15));
						window.draw(GasVisRot2);
						window.draw(GasAnzeigeVoll);


						window.display();
						counter++;
						Coincounter++;
					}
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
		window.draw(button3);

		window.draw(LogoMenu);

		window.display();
	}
}
