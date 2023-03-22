#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

int PossitionMap(sf::RenderWindow& fenster, sf::RectangleShape* player, sf::RectangleShape* Boden, int* wobinich, sf::Texture *map, int* coinsetzen) {
	
	sf::Vector2f temppos = player->getPosition();

	if (*wobinich == 1)
	{
		temppos = player->getPosition();
		if (temppos.x >= 1280)
		{
			player->setPosition(temppos.x - 1280, temppos.y);
			*wobinich = 2;
			*coinsetzen = 1;
			map->loadFromFile("ressources/map" + std::to_string(*wobinich) + ".png");
			Boden->setTexture(&*map);
		}
		if (temppos.x <= 0)
		{
			player->setPosition(temppos.x + 5, temppos.y);
		}
		if (temppos.y >= 686)
		{
			player->setPosition(temppos.x, temppos.y - 5);
		}
		if (temppos.y <= -24)
		{
			player->setPosition(temppos.x, temppos.y + 744);
			*wobinich = 4;
			*coinsetzen = 1;
			map->loadFromFile("ressources/map" + std::to_string(*wobinich) + ".png");
			Boden->setTexture(&*map);
		}
	}
	if (*wobinich == 2)
	{
		temppos = player->getPosition();
		if (temppos.x >= 1280)
		{
			player->setPosition(temppos.x - 1304, temppos.y);
			*wobinich = 3;
			*coinsetzen = 1;
			map->loadFromFile("ressources/map" + std::to_string(*wobinich) + ".png");
			Boden->setTexture(&*map);
		}
		if (temppos.x <= -24)
		{
			player->setPosition(temppos.x + 1304, temppos.y);
			*wobinich = 1;
			*coinsetzen = 1;
			map->loadFromFile("ressources/map" + std::to_string(*wobinich) + ".png");
			Boden->setTexture(&*map);
		}
		if (temppos.y >= 686)
		{
			player->setPosition(temppos.x, temppos.y - 5);
		}
		if (temppos.y <= -24)
		{
			player->setPosition(temppos.x, temppos.y + 744);
			*wobinich = 5;
			*coinsetzen = 1;
			map->loadFromFile("ressources/map" + std::to_string(*wobinich) + ".png");
			Boden->setTexture(&*map);
		}
	}
	if (*wobinich == 3)
	{
		temppos = player->getPosition();
		if (temppos.x >= 1246)
		{
			player->setPosition(temppos.x - 5, temppos.y);
		}
		if (temppos.x <= -24)
		{
			player->setPosition(temppos.x + 1304, temppos.y);
			*wobinich = 2;
			*coinsetzen = 1;
			map->loadFromFile("ressources/map" + std::to_string(*wobinich) + ".png");
			Boden->setTexture(&*map);
		}
		if (temppos.y >= 686)
		{
			player->setPosition(temppos.x, temppos.y - 5);
		}
		if (temppos.y <= -24)
		{
			player->setPosition(temppos.x, temppos.y + 744);
			*wobinich = 6;
			*coinsetzen = 1;
			map->loadFromFile("ressources/map" + std::to_string(*wobinich) + ".png");
			Boden->setTexture(&*map);
		}
	}
	if (*wobinich == 4)
	{
		temppos = player->getPosition();
		if (temppos.x >= 1280)
		{
			player->setPosition(temppos.x - 1304, temppos.y);
			*wobinich = 5;
			*coinsetzen = 1;
			map->loadFromFile("ressources/map" + std::to_string(*wobinich) + ".png");
			Boden->setTexture(&*map);
		}
		if (temppos.x <= 0)
		{
			player->setPosition(temppos.x + 5, temppos.y);
		}
		if (temppos.y >= 720)
		{
			player->setPosition(temppos.x, temppos.y - 744);
			*wobinich = 1;
			*coinsetzen = 1;
			map->loadFromFile("ressources/map" + std::to_string(*wobinich) + ".png");
			Boden->setTexture(&*map);
		}
		if (temppos.y <= -24)
		{
			player->setPosition(temppos.x, temppos.y + 744);
			*wobinich = 7;
			*coinsetzen = 1;
			map->loadFromFile("ressources/map" + std::to_string(*wobinich) + ".png");
			Boden->setTexture(&*map);
		}
	}
	if (*wobinich == 5)
	{
		temppos = player->getPosition();
		if (temppos.x >= 1280)
		{
			player->setPosition(temppos.x - 1304, temppos.y);
			*wobinich = 6;
			*coinsetzen = 1;
			map->loadFromFile("ressources/map" + std::to_string(*wobinich) + ".png");
			Boden->setTexture(&*map);
		}
		if (temppos.x <= -24)
		{
			player->setPosition(temppos.x + 1304, temppos.y);
			*wobinich = 4;
			*coinsetzen = 1;
			map->loadFromFile("ressources/map" + std::to_string(*wobinich) + ".png");
			Boden->setTexture(&*map);
		}
		if (temppos.y >= 720)
		{
			player->setPosition(temppos.x, temppos.y - 744);
			*wobinich = 2;
			*coinsetzen = 1;
			map->loadFromFile("ressources/map" + std::to_string(*wobinich) + ".png");
			Boden->setTexture(&*map);
		}
		if (temppos.y <= -24)
		{
			player->setPosition(temppos.x, temppos.y + 744);
			*wobinich = 8;
			*coinsetzen = 1;
			map->loadFromFile("ressources/map" + std::to_string(*wobinich) + ".png");
			Boden->setTexture(&*map);
		}
	}
	if (*wobinich == 6)
	{
		temppos = player->getPosition();
		if (temppos.x >= 1246)
		{
			player->setPosition(temppos.x - 5, temppos.y);
		}
		if (temppos.x <= -24)
		{
			player->setPosition(temppos.x + 1304, temppos.y);
			*wobinich = 5;
			*coinsetzen = 1;
			map->loadFromFile("ressources/map" + std::to_string(*wobinich) + ".png");
			Boden->setTexture(&*map);
		}
		if (temppos.y >= 720)
		{
			player->setPosition(temppos.x, temppos.y - 744);
			*wobinich = 3;
			*coinsetzen = 1;
			map->loadFromFile("ressources/map" + std::to_string(*wobinich) + ".png");
			Boden->setTexture(&*map);
		}
		if (temppos.y <= -24)
		{
			player->setPosition(temppos.x, temppos.y + 744);
			*wobinich = 9;
			*coinsetzen = 1;
			map->loadFromFile("ressources/map" + std::to_string(*wobinich) + ".png");
			Boden->setTexture(&*map);
		}
	}
	if (*wobinich == 7)
	{
		temppos = player->getPosition();
		if (temppos.x >= 1280)
		{
			player->setPosition(temppos.x - 1304, temppos.y);
			*wobinich = 8;
			*coinsetzen = 1;
			map->loadFromFile("ressources/map" + std::to_string(*wobinich) + ".png");
			Boden->setTexture(&*map);
		}
		if (temppos.x <= 0)
		{
			player->setPosition(temppos.x + 5, temppos.y);
		}
		if (temppos.y >= 720)
		{
			player->setPosition(temppos.x, temppos.y - 744);
			*wobinich = 4;
			*coinsetzen = 1;
			map->loadFromFile("ressources/map" + std::to_string(*wobinich) + ".png");
			Boden->setTexture(&*map);
		}
		if (temppos.y <= 0)
		{
			player->setPosition(temppos.x, temppos.y + 5);
		}
	}
	if (*wobinich == 8)
	{
		temppos = player->getPosition();
		if (temppos.x >= 1280)
		{
			player->setPosition(temppos.x - 1304, temppos.y);
			*wobinich = 9;
			*coinsetzen = 1;
			map->loadFromFile("ressources/map" + std::to_string(*wobinich) + ".png");
			Boden->setTexture(&*map);
		}
		if (temppos.x <= -24)
		{
			player->setPosition(temppos.x + 1304, temppos.y);
			*wobinich = 7;
			*coinsetzen = 1;
			map->loadFromFile("ressources/map" + std::to_string(*wobinich) + ".png");
			Boden->setTexture(&*map);
		}
		if (temppos.y >= 720)
		{
			player->setPosition(temppos.x, temppos.y - 744);
			*wobinich = 5;
			*coinsetzen = 1;
			map->loadFromFile("ressources/map" + std::to_string(*wobinich) + ".png");
			Boden->setTexture(&*map);
		}
		if (temppos.y <= 0)
		{
			player->setPosition(temppos.x, temppos.y + 5);
		}
	}
	if (*wobinich == 9)
	{
		temppos = player->getPosition();
		if (temppos.x >= 1246)
		{
			player->setPosition(temppos.x - 5, temppos.y);
		}
		if (temppos.x <= -24)
		{
			player->setPosition(temppos.x + 1304, temppos.y);
			*wobinich = 8;
			*coinsetzen = 1;
			map->loadFromFile("ressources/map" + std::to_string(*wobinich) + ".png");
			Boden->setTexture(&*map);
		}
		if (temppos.y >= 720)
		{
			player->setPosition(temppos.x, temppos.y - 744);
			*wobinich = 6;
			*coinsetzen = 1;
			map->loadFromFile("ressources/map" + std::to_string(*wobinich) + ".png");
			Boden->setTexture(&*map);
		}
		if (temppos.y <= 0)
		{
			player->setPosition(temppos.x, temppos.y + 5);
		}
	}

	fenster.draw(*Boden);
	fenster.draw(*player);

	return *wobinich;
}