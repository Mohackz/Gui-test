#include <SFML/Graphics.hpp>
#include "gui.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800,600),"Vincent tu vas perir !");

    gui::Gui maGui;

    gui::Button button;
    button.setPosition(100,150);

    maGui.add(&button);

    while(window.isOpen())
    {
        sf::Event even;
        while(window.pollEvent(even))
        {
            maGui.handleEvents(even);
            if(even.type == sf::Event::Closed)
                window.close();
        }

        maGui.update();

        maGui.display(window);
        window.display();
        window.clear();
    }

    return EXIT_SUCCESS;
}
