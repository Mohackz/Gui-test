#ifndef GUI_HPP_INCLUDED
#define GUI_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include <vector>

namespace gui
{

class Widget;

class Gui
{
    public:
        Gui();
        ~Gui();
        void handleEvents(sf::Event& event);
        void update();
        void display(sf::RenderWindow& window);
        void add(Widget* widget = nullptr);
    private:
        std::vector<Widget*> _allWidgets;
};

class Widget : public sf::Transformable
{
protected:
    virtual void handleEvents(sf::Event& event);
    virtual void update();
    virtual void show(sf::RenderTarget& target);
    sf::RectangleShape _rectWidget;
    friend Gui;
};

class Button : public Widget
{
public:
    enum class State
    {
        DEFAULT,
        HOVER,
        CLICKED
    };
    Button();
    Button(const sf::String& text);
private:
    sf::String _text {"Button"};
    State _currentState {State::DEFAULT};
    sf::Texture _texture;
    sf::RenderStates _renderStates;
protected:
    void handleEvents(sf::Event& event);
    void update();
    void show(sf::RenderTarget& target);
};


}

#endif // GUI_HPP_INCLUDED
