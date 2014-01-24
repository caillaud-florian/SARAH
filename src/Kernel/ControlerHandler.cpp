#include "Kernel/ControlerHandler.hpp"

namespace Sarah
{
namespace Kernel
{

// Constructeur et destructeur
ControlerHandler::ControlerHandler():
    gConfig(),
	m_graphicHandler(),
    m_modelHandler(),
	m_generalClock()
{

}

ControlerHandler::ControlerHandler(GeneralConfig & p_gConfig):
    gConfig(p_gConfig),
	m_graphicHandler(p_gConfig),
    m_modelHandler(p_gConfig),
	m_generalClock()
{

}

ControlerHandler::~ControlerHandler()
{

}

//Fonctions spécifiques
bool ControlerHandler::Init()
{
    return (m_graphicHandler.Init() && m_modelHandler.Init());
}

bool ControlerHandler::MainLoop()
{

	// Start the game loop
    while (GetWindow().isOpen())
    {
        // Process events
        sf::Event event;
        while (GetWindow().pollEvent(event))
        {
            // Close m_mainWindow: exit
            if (event.type == sf::Event::Closed)
                GetWindow().close();

            // Escape key: exit
            if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))
                GetWindow().close();

            // Resize event: adjust the viewport
            if (event.type == sf::Event::Resized)
                glViewport(0, 0, event.size.width, event.size.height);
        }

        // Clear the color and depth buffers
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Apply some transformations to rotate the cube
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glTranslatef(0.f, 0.f, -200.f);
        glRotatef(m_generalClock.getElapsedTime().asSeconds() * 50, 1.f, 0.f, 0.f);
        glRotatef(m_generalClock.getElapsedTime().asSeconds() * 30, 0.f, 1.f, 0.f);
        glRotatef(m_generalClock.getElapsedTime().asSeconds() * 90, 0.f, 0.f, 1.f);

        // Draw the cube
        glDrawArrays(GL_TRIANGLES, 0, 36);

        // Finally, display the rendered frame on screen
        GetWindow().display();
    }

	return true;
}

sf::Window & ControlerHandler::GetWindow()
{
    return m_graphicHandler.m_mainWindow;
}

}
}