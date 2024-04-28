#include "GameLoop.hpp"

void GameLoop::eventHandler(sf::RenderWindow& window, Grid* grid, bool player) {
	sf::Event event;
	sf::Vector2i pixelPos;
	sf::Vector2f worldPos;
	float zoom = 1;
	sf::View view = window.getView();



	while (window.pollEvent(event))
	{
		sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
		switch (event.type) {
		case sf::Event::Closed:
			window.close();
			break;

		case sf::Event::Resized:
			// update the view to the new size of the window
			view.reset(visibleArea);
			window.setView(view);

			// get the current mouse position in the window
			pixelPos = sf::Mouse::getPosition(window);

			// convert it to world coordinates
			worldPos = window.mapPixelToCoords(pixelPos);
			break;
		case sf::Event::MouseButtonPressed:
			if (!player) {
				break;
			}
			if (event.mouseButton.button == 0) {
				sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
				sf::Vector2f worldPos = window.mapPixelToCoords(pixelPos);
				grid->switchCell(worldPos.x, worldPos.y);
			}
			break;
		case sf::Event::KeyPressed:
		{
			sf::Vector2f deltaPos;
			if (event.key.code == sf::Keyboard::Right) {
				deltaPos.x+= 10;
			}
			if (event.key.code == sf::Keyboard::Left) {
				deltaPos.x-= 10;
			}
			if (event.key.code == sf::Keyboard::Up) {
				deltaPos.y-= 10;
			}
			if (event.key.code == sf::Keyboard::Down) {
				deltaPos.y+=10;
			}
			view.move(deltaPos);
			window.setView(view);
		}
		case sf::Event::MouseWheelScrolled:

			pixelPos = sf::Mouse::getPosition(window);
			worldPos = window.mapPixelToCoords(pixelPos);

			if (event.mouseWheelScroll.delta <= -1)
				zoom = std::min(2.f, zoom + .1f);
			else if (event.mouseWheelScroll.delta >= 1)
				zoom = std::max(.5f, zoom - .1f);

			// Update our view
			view.zoom(zoom); // Apply the zoom level (this transforms the view)
			window.setView(view);
			break;
		}
	}
}

void GameLoop::eventHandler(sf::RenderWindow& window, RainbowGrid* grid, bool player) {
	sf::Event event;
	sf::Vector2i pixelPos;
	sf::Vector2f worldPos;
	float zoom = 1;
	sf::View view = window.getView();



	while (window.pollEvent(event))
	{
		sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
		switch (event.type) {
		case sf::Event::Closed:
			window.close();
			break;

		case sf::Event::Resized:
			// update the view to the new size of the window
			view.reset(visibleArea);
			window.setView(view);

			// get the current mouse position in the window
			pixelPos = sf::Mouse::getPosition(window);

			// convert it to world coordinates
			worldPos = window.mapPixelToCoords(pixelPos);
			break;
		case sf::Event::MouseButtonPressed:
			if (!player) {
				break;
			}
			if (event.mouseButton.button == 0) {
				sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
				sf::Vector2f worldPos = window.mapPixelToCoords(pixelPos);
				grid->switchCell(worldPos.x, worldPos.y);
			}
			break;
		case sf::Event::KeyPressed:
		{
			sf::Vector2f deltaPos;
			if (event.key.code == sf::Keyboard::Right) {
				deltaPos.x+= 10;
			}
			if (event.key.code == sf::Keyboard::Left) {
				deltaPos.x-= 10;
			}
			if (event.key.code == sf::Keyboard::Up) {
				deltaPos.y-= 10;
			}
			if (event.key.code == sf::Keyboard::Down) {
				deltaPos.y+=10;
			}
			view.move(deltaPos);
			window.setView(view);
		}
		case sf::Event::MouseWheelScrolled:

			pixelPos = sf::Mouse::getPosition(window);
			worldPos = window.mapPixelToCoords(pixelPos);

			if (event.mouseWheelScroll.delta <= -1)
				zoom = std::min(2.f, zoom + .1f);
			else if (event.mouseWheelScroll.delta >= 1)
				zoom = std::max(.5f, zoom - .1f);

			// Update our view
			view.zoom(zoom); // Apply the zoom level (this transforms the view)
			window.setView(view);
			break;
		}
	}
}

void GameLoop::eventHandler(sf::RenderWindow& window, HighGrid* grid, bool player) {
	sf::Event event;
	sf::Vector2i pixelPos;
	sf::Vector2f worldPos;
	float zoom = 1;
	sf::View view = window.getView();



	while (window.pollEvent(event))
	{
		sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
		switch (event.type) {
		case sf::Event::Closed:
			window.close();
			break;

		case sf::Event::Resized:
			// update the view to the new size of the window
			view.reset(visibleArea);
			window.setView(view);

			// get the current mouse position in the window
			pixelPos = sf::Mouse::getPosition(window);

			// convert it to world coordinates
			worldPos = window.mapPixelToCoords(pixelPos);
			break;
		case sf::Event::MouseButtonPressed:
			if (!player) {
				break;
			}
			if (event.mouseButton.button == 0) {
				sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
				sf::Vector2f worldPos = window.mapPixelToCoords(pixelPos);
				grid->switchCell(worldPos.x, worldPos.y);
			}
			break;
		case sf::Event::KeyPressed:
		{
			sf::Vector2f deltaPos;
			if (event.key.code == sf::Keyboard::Right) {
				deltaPos.x+= 10;
			}
			if (event.key.code == sf::Keyboard::Left) {
				deltaPos.x-= 10;
			}
			if (event.key.code == sf::Keyboard::Up) {
				deltaPos.y-= 10;
			}
			if (event.key.code == sf::Keyboard::Down) {
				deltaPos.y+=10;
			}
			view.move(deltaPos);
			window.setView(view);
		}
		case sf::Event::MouseWheelScrolled:

			pixelPos = sf::Mouse::getPosition(window);
			worldPos = window.mapPixelToCoords(pixelPos);

			if (event.mouseWheelScroll.delta <= -1)
				zoom = std::min(2.f, zoom + .1f);
			else if (event.mouseWheelScroll.delta >= 1)
				zoom = std::max(.5f, zoom - .1f);

			// Update our view
			view.zoom(zoom); // Apply the zoom level (this transforms the view)
			window.setView(view);
			break;
		}
	}
}

void GameLoop::gameLoop(std::string gameMode, bool player)
{
	srand(time(0));

	sf::RenderWindow window(sf::VideoMode(1024, 1024), "Automota");
	if (gameMode == "Conway") {
		Grid grid;

		while (window.isOpen()) {
			window.clear(sf::Color(46, 52, 64, 255));
			eventHandler(window, &grid, player);

			grid.updateConway();
			grid.draw(window);
			window.display();
		}
	}
	if (gameMode == "Rainbow") {
		RainbowGrid rainbowGrid;

		while (window.isOpen()) {
			window.clear(sf::Color(46, 52, 64, 255));
			eventHandler(window, &rainbowGrid, player);

			rainbowGrid.updateRainbow();
			rainbowGrid.draw(window);
			window.display();
		}
	}

	if (gameMode == "High") {
		HighGrid highGrid;

		while (window.isOpen()) {
			window.clear(sf::Color(46, 52, 64, 255));
			eventHandler(window, &highGrid, player);

			highGrid.updateHigh();
			highGrid.draw(window);
			window.display();
		}
	}
}