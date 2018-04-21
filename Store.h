/*
 * Store.h
 *  Created on: Apr 20, 2018
 *      Author: User
 */

#ifndef STORE_H_
#define STORE_H_

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

#include "Button.h"

#include "Produce.h"

class Store{
	private:
		std::vector<Produce> produceItems;

	public:
		Store();
		void listFruit();
		void listMeats();
		void listVegetables();
		void listInfo();

		void addProduce(std::string name, std::string type, double pricePerLlb, sf::Vector2f dimensions,  sf::Font &font, std::string initText );
		void produceGrid();
	//	sf::RectangleShape printProduceItem(int pos);
		//sf::Text printProduceItemText(int pos);
		int amountOfProduceItems();

		void addProduce(std::string name, std::string type, double pricePerLlb, Button button );

		Produce getProduceItem(int pos);

};

Store::Store(){
}

void Store::addProduce(std::string name, std::string type, double pricePerLlb, sf::Vector2f dimensions,  sf::Font &font, std::string initText)
{
	produceItems.push_back(Produce( name,  type,  pricePerLlb,  dimensions, font,  initText));
}


void Store::produceGrid()
{
	float x = 400.0f;
	float y = 150.0f;
	int cnt = 0;
	for(int i = 0, max = produceItems.size(); i!=max; ++i )
	{
		produceItems.at(i).changeButtonPosition(x, y);
		produceItems.at(i).changeTextPosition(x+5, y+5);
		x+=120.0f;
		cnt++;

		if(i == 6)
		{
			cnt = 0;
			x = 400.0f;
			y += 50.0f;
		}
	}
}


int Store::amountOfProduceItems()
{
	return produceItems.size();
}

Produce Store::getProduceItem(int pos)
{
	return produceItems.at(pos);
}


void Store::listFruit(){
	for(int i = 0, max = produceItems.size(); i != max; ++i){
		if(produceItems.at(i).getType().compare("fruit") == 0)
			std::cout<<produceItems.at(i).getName()<<std::endl;
	}
}


void Store::listVegetables(){
	for(int i = 0, max = produceItems.size(); i != max; ++i){
		if(produceItems.at(i).getType().compare("vegetable") == 0)
			std::cout<<produceItems.at(i).getName();
	}
}


#endif /* STORE_H_ */
