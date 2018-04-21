/*
 * sfml_graphics_tutorial.cpp
 *
 *  Created on: Apr 5, 2018
 *      Author: Dave
 */
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <algorithm>

#include "Store.h"
#include "TextBox.h"
#include "Button.h"

sf::RenderWindow window(sf::VideoMode(1500, 800), "Mr. Djald's Supermarket", sf::Style::Close^sf::Style::Titlebar);
sf::Font font;

//sf::Texture produce_button;
//sf::Sprite produceButton;


std::vector<std::string> names = {"Dave" , "Dean", "Jon"};
std::string line;
int windowDepth = 0;


int main()
{
    if (!font.loadFromFile("arial.ttf"))
        return EXIT_FAILURE;

    std::cout<< std::fixed << std::setprecision(2);	//Sets cout to output numbers with 2 decimal places

    Store supermarket = Store();		//Creates object <supermarket>

    std::ifstream productDataFile;		//Initializes productDataFile as a istream object
    productDataFile.open("FOOD.txt");	//Data will be streamed from the <FOOD.txt> file

    // Saves one line of the text file into "line", until eof (end of file) is reached.
    while(std::getline(productDataFile, line))
    {

        std::vector<std::string> lineVec;			//<lineVec> is a vector that will be used to store the split strings
        //from the string "line"
        std::istringstream iss(line);				//create a string stream "iss" to operate on the string line.

        //While-loop will split "line" by the spaces it contains.  It will store the splitted strings into "lineVec"
        while( iss >> line )
        {
            replace( line.begin(), line.end(), '_', ' ' );	//remove underscores from strings
            lineVec.push_back(line);
        }
        //The following bool expressions check what sections the each entry belongs to.
        if (lineVec.at(0).compare("produce") == 0){
            supermarket.addProduce(lineVec.at(1), lineVec.at(2), stod(lineVec.at(3)), sf::Vector2f(100,30), font, lineVec.at(1));
        }

        lineVec.clear();
    }
    productDataFile.close();	//Closes the stream of productDataFile when the eof has been reached.

    ////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////

    supermarket.listFruit();

    ////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////

//	if (!produce_button.loadFromFile("produce_button.png"))
//		std::cout<<"nogo on button\n\n";//error message

//	produceButton.setTexture(produce_button);
//	produceButton.setPosition( 0.0f, 0.0f );

    TextBox nameBox = TextBox(sf::Vector2f(400,50), sf::Vector2f(window.getSize().x/2 - 400/2, 400.0f) ,5, font, "Enter Full Name");
    TextBox box = TextBox(sf::Vector2f(400,50), sf::Vector2f(window.getSize().x/2 - 400/2, 6.0f) ,5, font, "Search");

    Button produceButton = Button(sf::Vector2f(200,57), sf::Vector2f(5.0f, 5.0f) , font, "Produce");
    Button meatsButton = Button(sf::Vector2f(200,57), sf::Vector2f(5.0f, 72.0f) , font, "Meats");
    Button grainsButton = Button(sf::Vector2f(200,57), sf::Vector2f(5.0f, 139.0f) , font, "Grains");
    Button dairyButton = Button(sf::Vector2f(200,57), sf::Vector2f(5.0f, 206.0f) , font, "Dairy");
    Button drinksButton = Button(sf::Vector2f(200,57), sf::Vector2f(5.0f, 273.0f) , font, "Drinks");

    while (window.isOpen())
    {
        sf::Vector2i mousePos = sf::Mouse::getPosition( window );
        sf::Vector2f mousePosF( static_cast<float>( mousePos.x ), static_cast<float>( mousePos.y ) );

        sf::Event event0;
        sf::Event event1;

        if(windowDepth == 0)
        {
            while(window.pollEvent(event0) )
            {
                switch(event0.type)
                {
                    case(sf::Event::Closed):
                    {
                        window.close();
                        break;
                    }

                    case(sf::Event::MouseButtonPressed):
                    {

                        if ( nameBox.clicked( mousePosF) )	//detect if an object of TextBox was clicked
                        {
                            std::cout << "Clicked nameBox" << std::endl;
                            window.clear(sf::Color::White);
                            window.draw(nameBox.getTextBox());
                            window.draw(nameBox.getBoxText());
                            window.display();
                            while(window.waitEvent(event0))
                            {
                                if(event0.type == sf::Event::TextEntered)
                                {
                                    nameBox.textEntered(event0.text.unicode);
                                    window.clear(sf::Color::White);
                                    window.draw(nameBox.getTextBox());
                                    window.draw(nameBox.getBoxText());
                                    window.display();
                                    if(event0.text.unicode == 13)	//Must have a particular action be a break statement (<enter> key)
                                    {
                                        std::cout<<nameBox.getBoxTextStr()<<std::endl;
                                        windowDepth++;
                                        std::cout<<windowDepth<<std::endl;
                                        break;
                                    }
                                }
                            }
                        }
                    }

                }
                window.clear(sf::Color::White);
                window.draw(nameBox.getTextBox());
                window.draw(nameBox.getBoxText());
                window.display();
            }
            continue;
        }

        if(windowDepth == 1)
        {
            while(window.pollEvent(event1) )
            {
                switch(event1.type)
                {
                    case(sf::Event::Closed):
                    {
                        window.close();
                        break;
                    }
                    case(sf::Event::MouseButtonPressed):
                    {
                        //sf::Vector2i mousePos = sf::Mouse::getPosition( window );
                        //sf::Vector2f mousePosF( static_cast<float>( mousePos.x ), static_cast<float>( mousePos.y ) );

                        if ( box.clicked( mousePosF) )	//detect if an object of TextBox was clicked
                        {
                            std::cout << "Clicked textBox" << std::endl;
                            window.clear(sf::Color::White);
                            window.draw(box.getTextBox());
                            window.draw(box.getBoxText());
                            window.display();
                            while(window.waitEvent(event1))
                            {
                                if(event1.type == sf::Event::TextEntered)
                                {
                                    box.textEntered(event1.text.unicode);
                                    window.clear(sf::Color::White);
                                    window.draw(box.getTextBox());
                                    window.draw(box.getBoxText());
                                    window.display();
                                    if(event1.text.unicode == 13)	//Must have a particular action be a break statement (<enter> key)
                                    {
                                        std::cout<<box.getBoxTextStr()<<std::endl;
                                        for(int i = 0, max = names.size(); i<max; ++i)
                                        {
                                            if(box.getBoxTextStr().compare(names.at(i)) == 0)
                                                std::cout<<"found person" << std::endl;
                                        }
                                        break;
                                    }
                                }
                            }
                        }
                        if(produceButton.clicked(mousePosF))
                        {
                            std::cout<<"Produce Button Clicked"<<std::endl;
                            while(window.waitEvent(event1))
                            {
                                mousePos = sf::Mouse::getPosition( window );
                                sf::Vector2f mousePosF( static_cast<float>( mousePos.x ), static_cast<float>( mousePos.y ) );
                                supermarket.produceGrid();


                                window.clear(sf::Color::White);
                                window.draw(produceButton.getButton());
                                window.draw(produceButton.getButtonName());
                                window.draw(meatsButton.getButton());
                                window.draw(meatsButton.getButtonName());
                                window.draw(grainsButton.getButton());
                                window.draw(grainsButton.getButtonName());
                                window.draw(dairyButton.getButton());
                                window.draw(dairyButton.getButtonName());
                                window.draw(drinksButton.getButton());
                                window.draw(drinksButton.getButtonName());

                                for(int i = 0, max = supermarket.amountOfProduceItems(); i!=max;++i)
                                {
                                    window.draw(supermarket.getProduceItem(i).getButton());
                                    window.draw(supermarket.getProduceItem(i).getButtonName());
                                }

                                window.display();
                                if(event1.type == sf::Event::KeyPressed)
                                {
                                    if(event1.key.code == sf::Keyboard::M)
                                        break;
                                }
                                if(event1.type == sf::Event::MouseButtonPressed)
                                {
                                    std::cout<<supermarket.getProduceItem(0).getName()<<std::endl;
                                    std::cout<<mousePosF.x <<std::endl;
                                    std::cout<<mousePosF.y <<std::endl;

                                    for(int i = 0, max = supermarket.amountOfProduceItems(); i!=max;++i)
                                    {
                                        if(supermarket.getProduceItem(i).clicked(mousePosF))
                                            std::cout<<"yep"<<std::endl;
                                    }
                                }

                            }

                        }
                        break;
                    }

                }

                window.clear(sf::Color::White);
                window.draw(produceButton.getButton());
                window.draw(produceButton.getButtonName());
                window.draw(meatsButton.getButton());
                window.draw(meatsButton.getButtonName());
                window.draw(grainsButton.getButton());
                window.draw(grainsButton.getButtonName());
                window.draw(dairyButton.getButton());
                window.draw(dairyButton.getButtonName());
                window.draw(drinksButton.getButton());
                window.draw(drinksButton.getButtonName());
                window.draw(box.getTextBox());
                window.draw(box.getBoxText());
                window.display();
            }

        }


    }
    return 0;
}
