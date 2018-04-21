/*
 * Button.h
 *  Created on: Apr 20, 2018
 *      Author: Dave
 */

#ifndef BUTTON_H_
#define BUTTON_H_


#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>

class Button
{
	private:
		sf::RectangleShape button;
		sf::Text nameText;
		//Produce &object;

	public:
		Button(sf::Vector2f dimensions, sf::Vector2f location,  sf::Font &font, std::string initText);
		void changePosition(float x, float y);
		std::string getButtonNameStr();
		sf::RectangleShape getButton();
		sf::Text getButtonName();
		bool clicked(sf::Vector2f mousePosF);

};

Button::Button(sf::Vector2f dimensions, sf::Vector2f location, sf::Font &font,std::string initText)
{
	button.setSize(dimensions);
	button.setPosition(location);
	button.setOutlineThickness(5);
	button.setOutlineColor(sf::Color::Black);

	nameText.setPosition(location.x + 8, location.y + 8);
	nameText.setFont(font);
	nameText.setString(initText);
	nameText.setCharacterSize(25);
	nameText.setColor(sf::Color::Black);
}

void Button::changePosition(float x, float y)
{
	button.setPosition(x, y);
}

std::string Button::getButtonNameStr()
{
	return this -> nameText.getString().toAnsiString();
}

sf::RectangleShape Button::getButton()
{
	return this -> button;
}

sf::Text Button::getButtonName()
{
	return this -> nameText;
}

bool Button::clicked(sf::Vector2f mousePosF)
{
	if(button.getGlobalBounds().contains(mousePosF))
	{
		return true;
	}else{
		return false;
	}
}



#endif /* BUTTON_H_ */
