#include "gui.hpp"
#include <iostream>

using namespace std;

namespace gui
{

void Widget::handleEvents(sf::Event& event){}
void Widget::update(){}
void Widget::show(sf::RenderTarget& target){}


Gui::Gui()
{
    //ctor
}

Gui::~Gui()
{
    //dtor
}

void Gui::add(Widget* widget)
{
    _allWidgets.push_back(widget);
}

void Gui::handleEvents(sf::Event& event)
{
    if(!_allWidgets.empty())
    {
        for(unsigned int i=0;i<_allWidgets.size();i++)
            _allWidgets[i]->handleEvents(event);
    }
}

void Gui::update()
{
    if(!_allWidgets.empty())
    {
        for(unsigned int i=0;i<_allWidgets.size();i++)
            _allWidgets[i]->update();
    }
}

void Gui::display(sf::RenderWindow& window)
{
    if(!_allWidgets.empty())
    {
        for(unsigned int i=0;i<_allWidgets.size();i++)
            _allWidgets[i]->show(window);
    }
}

Button::Button()
{
    if(!_texture.loadFromFile("res/button.png"))
        cerr << "Failed to load button texture !" << endl;
    _rectWidget.setTexture(&_texture);
    _rectWidget.setSize(sf::Vector2f(90,28));
}

Button::Button(const sf::String& text)
{
    _text = text;
    if(!_texture.loadFromFile("res/button.png"))
        cerr << "Failed to load button texture !" << endl;
    _rectWidget.setTexture(&_texture);
    _rectWidget.setSize(sf::Vector2f(90,28));
}

void Button::handleEvents(sf::Event& event)
{
    switch(event.type)
    {
    case sf::Event::MouseButtonPressed:
        if(event.mouseButton.button == sf::Mouse::Left)
        {
            if(_rectWidget.getGlobalBounds().contains(event.mouseButton.x,event.mouseButton.y))
                _currentState = State::CLICKED;
        }
        break;
    case sf::Event::MouseButtonReleased:
        if(event.mouseButton.button == sf::Mouse::Left)
        {
            if(_rectWidget.getGlobalBounds().contains(event.mouseButton.x,event.mouseButton.y))
                _currentState = State::HOVER;
        }
        break;
    case sf::Event::MouseMoved:
        if(_rectWidget.getGlobalBounds().contains(event.mouseMove.x,event.mouseMove.y))
        {
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
                _currentState = State::CLICKED;
            else _currentState = State::HOVER;
        } else _currentState = State::DEFAULT;
        break;
    default:
        break;
    }
}

void Button::update()
{
}

void Button::show(sf::RenderTarget& target)
{
    _renderStates.transform = getTransform();
    switch(_currentState)
    {
    case State::DEFAULT:
        _rectWidget.setTextureRect(sf::IntRect(0,0,90,28));
        target.draw(_rectWidget,_renderStates);
        break;
    case State::HOVER:
        _rectWidget.setTextureRect(sf::IntRect(0,28,90,28));
        target.draw(_rectWidget,_renderStates);
        break;
    case State::CLICKED:
        _rectWidget.setTextureRect(sf::IntRect(0,28*2,90,28));
        target.draw(_rectWidget,_renderStates);
        break;
    }
}

















}
