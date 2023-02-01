#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <random>

using namespace std;

int randomZahl() {

    constexpr int MIN = 1;
    constexpr int MAX = 1260;

    constexpr int RAND_NUMS_TO_GENERATE = 1;

    random_device rd;
    default_random_engine eng(rd());
    uniform_int_distribution<int> distr(MIN, MAX);

    return distr(eng);

}

sf::Vector2f zweiRandomZahl() {

    constexpr int MIN = 30;
    constexpr int MAX = 1240;

    constexpr int RAND_NUMS_TO_GENERATE = 1;

    sf::Vector2f temp = { 0,0 };

    random_device rd;
    default_random_engine eng(rd());
    uniform_int_distribution<int> distr(MIN, MAX);

    temp.x = distr(eng);

    random_device rd2;
    default_random_engine engg(rd2());
    uniform_int_distribution<int> distrr(MIN, MAX);

    temp.y = distrr(engg);

    return temp;

}
