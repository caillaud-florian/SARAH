#include "Kernel/GraphicHandler.hpp"

namespace Sarah
{
namespace Kernel
{

// Constructeur et destructeur
GraphicHandler::GraphicHandler():
    gConfig(),
	m_mainWindow(),
	m_generalClock()
{
    
}

GraphicHandler::GraphicHandler(GeneralConfig & p_gConfig):
    gConfig(p_gConfig),
	m_mainWindow(),
	m_generalClock()
{
    WindowConfig * vWConf;
    if((vWConf = (WindowConfig *)p_gConfig.GetConfig("WindowConfig")) != nullptr){
        m_mainWindow.create(vWConf->videoMode, vWConf->title, 
                            vWConf->style, vWConf->contextSettings);
    }
}

GraphicHandler::~GraphicHandler()
{

}

//Fonctions spécifiques
bool GraphicHandler::Init()
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

}
}