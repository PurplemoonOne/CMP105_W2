#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/Input.h"
#include <string.h>
#include <iostream>


class Level{
public:
	Level(sf::RenderWindow* hwnd, Input* in);
	~Level();

	void handleInput();
	void update();
	void render();

private:
	// Default functions for rendering to the screen.
	void beginDraw();
	void endDraw();

	// Default variables for level class.
	sf::RenderWindow* window;
	Input* input;

	std::string str_mouseCoords;
	sf::Text txt_mouseCoords;
	sf::Text mouse_dst;
	sf::Font font;

	int CalculateDistance(sf::Vector2i& init_coord, sf::Vector2i& last_coords);
	int mouseCoordsDst;
	bool mouseDown;

	sf::Vector2i init_mouseCoordinates;
	sf::Vector2i recent_mouseCoordinates;

	sf::CircleShape circle;

	// Add your object here

};