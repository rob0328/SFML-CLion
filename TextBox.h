/*
 * TextBox.h
 *
 *  Created on: Apr 20, 2018
 *      Author: Dave
 */

#ifndef TEXTBOX_H_
#define TEXTBOX_H_

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>

class TextBox
{
	private:
		sf::String boxInput;
		sf::Text boxText;
		std::string boxTextStr;
        sf::RectangleShape textBox;

	public:
		TextBox(sf::Vector2f dimensions, sf::Vector2f location,int outlineThickness, sf::Font &font, std::string initText);
		void changePosition(float x, float y);
		bool clicked(sf::Vector2f mousePosF);
		void textEntered(sf::Uint32 unicode);

		sf::RectangleShape getTextBox();
		sf::Text getBoxText();
		std::string getBoxTextStr();
};

TextBox::TextBox(sf::Vector2f dimensions, sf::Vector2f location, int outlineThickness, sf::Font &font,std::string initText )
{
	textBox.setSize(dimensions);
	textBox.setPosition(location);
	textBox.setOutlineThickness(outlineThickness);
	textBox.setOutlineColor(sf::Color::Black);

	boxText.setPosition(location.x + 2, location.y + 8);
	boxText.setFont(font);
	boxText.setString(initText);
	boxText.setCharacterSize(25);
	boxText.setColor(sf::Color::Red);
}

void TextBox::changePosition(float x, float y)
{
	textBox.setPosition(x, y);
}

sf::RectangleShape TextBox::getTextBox()
{
	return this->textBox;
}

sf::Text TextBox::getBoxText()
{

	return this -> boxText;
}


std::string TextBox::getBoxTextStr()
{
	return this -> boxText.getString().toAnsiString();
}



bool TextBox::clicked(sf::Vector2f mousePosF)
{
	if(textBox.getGlobalBounds().contains(mousePosF ))
	{
		boxInput.clear();
		boxText.setString(boxInput);
		return true;
	}else{
	return false;
	}
}

void TextBox::textEntered(sf::Uint32 unicode)
{
	if(unicode<123 && unicode > 31 && (boxText.getLocalBounds().width < textBox.getLocalBounds().width - 15))	//Take in characters
	{
		boxInput += unicode;
		boxText.setString(boxInput);
		boxTextStr = boxText.getString().toAnsiString();
	}
	if(unicode == 8)
	{
		if(boxTextStr.size() > 0)
		 {

		boxTextStr = boxText.getString().toAnsiString();
		boxTextStr.pop_back();
		boxText.setString(boxTextStr);
		boxInput.erase(boxInput.getSize()-1, 1);
		 }
	}
	if(unicode == 13)
	{
		boxTextStr = boxText.getString().toAnsiString();
	}

}
#endif /* TEXTBOX_H_ */
