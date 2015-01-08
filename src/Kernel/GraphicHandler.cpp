#include "GraphicHandler.hpp"

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
    WindowUpdate();
}

GraphicHandler::~GraphicHandler()
{

}

//Fonctions spécifiques
bool GraphicHandler::Init()
{
	return true;
}

void GraphicHandler::WindowUpdate()
{
    WindowConfig * vWConf;
    if((vWConf = (WindowConfig *)gConfig.GetConfig("WindowConfig")) != nullptr){
        m_focusedWindow.create(vWConf->videoMode, vWConf->title, vWConf->style, vWConf->contextSettings);
        delete vWConf;
    }
}

sf::Window & GraphicHandler::GetFocusedWindow()
{
    return m_focusedWindow;
}

}
}
