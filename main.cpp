#include <SFML/Graphics.hpp>

using namespace sf; // statt std, hat zur Folge, dass bei String etc. std:: vor gesetzt werden muss

int main()
{
    int highscore = 0;
    int movex = 0;
    int movey = 0;
    int geschwind = 3;

    // Windows-Fenster einrichten
    RenderWindow window(VideoMode(410, 510), "Pong in Cool");
    window.setFramerateLimit(30);

    // Form: Kreis
    CircleShape kreis(8.f);
    kreis.setFillColor(Color::Yellow);
    kreis.setPosition(195, 400);

    // Form: Wand
    RectangleShape wall(Vector2f(10, 500));
    wall.setFillColor(Color::Cyan);
    wall.setPosition(300, 0);

    RectangleShape wall2(Vector2f(10, 500));
    wall2.setFillColor(Color::Cyan);
    wall2.setPosition(0, 0);

    RectangleShape wall3(Vector2f(310, 10));
    wall3.setFillColor(Color::Cyan);
    wall3.setPosition(0, 500);

    RectangleShape wall4(Vector2f(300, 10));
    wall4.setFillColor(Color::Cyan);
    wall4.setPosition(0, 0);
    //

    RectangleShape spieler(Vector2f(30, 10));
    spieler.setFillColor(Color::White);
    spieler.setPosition(150, 450);


    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        Vector2f ballPos = kreis.getPosition();
        Vector2f SpielerPos = spieler.getPosition();

        if (ballPos.x <= 10)
        {
            movex = geschwind;
        }
        else if (ballPos.x >= 300 - 12)
        {
            movex = -geschwind;
        }

        if (ballPos.y <= 10)
        {
            movey = geschwind;
        }
        else if (ballPos.y >= 500 - 8)
        {
            movey = 0;
            movex = 0;
        }

        if (ballPos.x >= SpielerPos.x && ballPos.x <= SpielerPos.x + 30)
        {
            if (ballPos.y >= SpielerPos.y - 4)
            {
                highscore++;
                movey = -geschwind;
            }

        }

        kreis.move(movex, movey);

        if (movex == 0 && movey == 0) {

            if (Keyboard::isKeyPressed(Keyboard::Space))
            {
                movex = -geschwind;
                movey = -geschwind;
            }

        }

        window.clear();
        window.draw(kreis);
        window.draw(wall);
        window.draw(wall2);
        window.draw(wall3);
        window.draw(wall4);
        window.draw(spieler);
        window.display();
    }

    return 0;
}
