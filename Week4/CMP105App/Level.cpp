#include "Level.h"


Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects

	playerObject.setInput(input);
	cursorIcon.setInput(input);
	backround.setInput(input);

	texture.loadFromFile("gfx/Mamma.png");
	playerObject.setTexture(&texture);

	playerObject.setSize(sf::Vector2f(250, 250));
	playerObject.setPosition(100, 100);
	playerObject.setVelocity(500,500);

	

	texture2.loadFromFile("gfx/Goomba.png");
	enemyObject.setTexture(&texture2);

	enemyObject.setSize(sf::Vector2f(80, 80));
	enemyObject.setPosition(0, 0);
	enemyObject.setVelocity(500, 500);

	
	window->setMouseCursorVisible(false);

	cursorTexture.loadFromFile("gfx/Icon.png");
	cursorIcon.setTexture(&cursorTexture);
	cursorIcon.setSize(sf::Vector2f(40,40));

	backroundTexture.loadFromFile("gfx/Level1_1.png");
	backround.setTexture(&backroundTexture);
	backround.setSize(sf::Vector2f(11038, 675));

	view = window->getView();
	

	
	
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	// Close window on Escape pressed.
	if (input->isKeyDown(sf::Keyboard::Escape))
	{
		window->close();
	}
	
	playerObject.handleInput(dt);

}

// Update game objects
void Level::update(float dt)
{
	windowX= window->getSize().x;
	windowY= window->getSize().y;
	cursorIcon.changeCursor();
	enemyObject.moveEnemy(dt, windowX, windowY);
	int moveXview = backround.moveView(view.getCenter().x, view.getSize().x);
	view.move(moveXview,0);
	
}

// Render level
void Level::render()
{
	beginDraw();

	window->setView(view);
	window->draw(backround);
	window->draw(playerObject);
	window->draw(enemyObject);
	window->draw(cursorIcon);

	endDraw();
}

// clear back buffer
void Level::beginDraw()
{
	window->clear(sf::Color::White);
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}