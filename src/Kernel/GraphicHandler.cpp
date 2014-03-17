#include "Kernel/GraphicHandler.hpp"

namespace Sarah
{
namespace Kernel
{

// Constructeur et destructeur
GraphicHandler::GraphicHandler():
    gConfig(),
	m_focusedWindow(),
	m_generalClock()
{
    m_focusedWindow.setVisible(false);
}

GraphicHandler::GraphicHandler(GeneralConfig & p_gConfig):
    gConfig(p_gConfig),
	m_focusedWindow(),
	m_generalClock()
{
    Update();
}

GraphicHandler::~GraphicHandler()
{

}

//Fonctions spécifiques
bool GraphicHandler::Init()
{
    // Make it the active window for OpenGL calls
    Update(); //pour avoir la fenêtre à jour en fonction de la config avant le glMatrixMode (??)
    m_focusedWindow.setActive();

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
    glViewport(0, 0, m_focusedWindow.getSize().x, m_focusedWindow.getSize().y);

    // Setup a perspective projection
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    GLfloat ratio = static_cast<float>(m_focusedWindow.getSize().x) / m_focusedWindow.getSize().y;
    glFrustum(-ratio, ratio, -1.f, 1.f, 1.f, 500.f);

	return true;
}

void GraphicHandler::Update()
{
    WindowConfig * vWConf;
    if((vWConf = (WindowConfig *)gConfig.GetConfig("WindowConfig")) != nullptr){
        m_focusedWindow.create(vWConf->videoMode, vWConf->title, vWConf->style, vWConf->contextSettings);
    }   
}

}
}
