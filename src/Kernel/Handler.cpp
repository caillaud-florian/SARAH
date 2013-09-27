#include "Kernel/Handler.hpp"

namespace Sarah
{
namespace Kernel
{

// Constructeur et destructeur
Handler::Handler():
	m_mainWindow(),
	m_generalClock()
{

}

Handler::Handler(sf::ContextSettings p_contextSettings):
	m_mainWindow(sf::VideoMode(640, 480), "SFML window with OpenGL", sf::Style::Default, p_contextSettings),
	m_generalClock()
{

}

Handler::~Handler()
{

}

//Fonctions spécifiques
bool Handler::Init()
{
    // Make it the active window for OpenGL calls
    m_mainWindow.setActive();


    //------------------------OPENGL--------------------------------------


    // Set the color and depth clear values
    glClearDepth(1.f);
    glClearColor(0.f, 0.f, 0.f, 1.f);

    // Enable Z-buffer read and write
    glEnable(GL_DEPTH_TEST);
    glDepthMask(GL_TRUE);

    // Disable lighting and texturing
    glDisable(GL_LIGHTING);
    glDisable(GL_TEXTURE_2D);

    // Configure the viewport (the same size as the window)
    glViewport(0, 0, m_mainWindow.getSize().x, m_mainWindow.getSize().y);

    // Setup a perspective projection
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    GLfloat ratio = static_cast<float>(m_mainWindow.getSize().x) / m_mainWindow.getSize().y;
    glFrustum(-ratio, ratio, -1.f, 1.f, 1.f, 500.f);

	return true;
}

bool Handler::Load(GLfloat * p_toLoadMesh)
{
	m_loadedMesh = p_toLoadMesh;

	// Enable position and color vertex components
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    glVertexPointer(3, GL_FLOAT, 7 * sizeof(GLfloat), m_loadedMesh);
    glColorPointer(4, GL_FLOAT, 7 * sizeof(GLfloat), m_loadedMesh + 3);

    // Disable normal and texture coordinates vertex components
    glDisableClientState(GL_NORMAL_ARRAY);
    glDisableClientState(GL_TEXTURE_COORD_ARRAY);

	return true;
}

bool Handler::MainLoop()
{
	// Start the game loop
    while (m_mainWindow.isOpen())
    {
        // Process events
        sf::Event event;
        while (m_mainWindow.pollEvent(event))
        {
            // Close m_mainWindow: exit
            if (event.type == sf::Event::Closed)
                m_mainWindow.close();

            // Escape key: exit
            if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))
                m_mainWindow.close();

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
        m_mainWindow.display();
    }

	return true;
}

}
}