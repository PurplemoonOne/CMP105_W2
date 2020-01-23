#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	font.loadFromFile("font/arial.ttf");

	txt_mouseCoords.setFont(font);
	txt_mouseCoords.setString(str_mouseCoords);
	txt_mouseCoords.setPosition(100, 100);
	txt_mouseCoords.setCharacterSize(12);
	txt_mouseCoords.setStyle(sf::Text::Style::Bold);
	txt_mouseCoords.setFillColor(sf::Color::Black);

	mouse_dst.setFont(font);
	mouse_dst.setString(std::to_string(mouseCoordsDst));
	mouse_dst.setPosition(400, 100);
	mouse_dst.setCharacterSize(12);
	mouse_dst.setStyle(sf::Text::Style::Bold);
	mouse_dst.setFillColor(sf::Color::Black);

	circle.setFillColor(sf::Color::Green);
	circle.setOutlineColor(sf::Color::Yellow);
	circle.setPosition(300, 300);
	circle.setRadius(10);

	mouseDown = false;

	init_mouseCoordinates = sf::Vector2i(0,0);
	recent_mouseCoordinates = sf::Vector2i(0, 0);
	mouseCoordsDst = 0;

}

Level::~Level()
{
	input = nullptr;
}

// handle user input
void Level::handleInput()
{

	if (input->isKeyDown(sf::Keyboard::Key::Escape))
	{
		window->close();
	}

}

// Update game objects
void Level::update()
{
	 str_mouseCoords = std::to_string(input->getMouseX()) + " , " + std::to_string(input->getMouseY());
	 txt_mouseCoords.setString(str_mouseCoords);

	 if (input->isMouseLDown())
	 {
		 
		 init_mouseCoordinates.x = input->getMouseX();
		 init_mouseCoordinates.y = input->getMouseY();
		 circle.setPosition(input->getMouseX(), input->getMouseY());

		 

		 if (!input->isMouseLDown())
		 {
			 recent_mouseCoordinates.x = input->getMouseX();
			 recent_mouseCoordinates.y = input->getMouseY();

			 mouseCoordsDst = CalculateDistance(init_mouseCoordinates, recent_mouseCoordinates);
			 
		 }
	 }
	 mouse_dst.setString("Drag Distance " + std::to_string(mouseCoordsDst));
	
}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(txt_mouseCoords);
	window->draw(mouse_dst);
	window->draw(circle);
	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}

int Level::CalculateDistance(sf::Vector2i& i_coords, sf::Vector2i& l_coords)
{
	int dst = 0;

	dst = (l_coords.x - i_coords.x) * (l_coords.x - i_coords.x) + 
		(l_coords.y - i_coords.y) * (l_coords.y - i_coords.y);

	return dst;
}

