#include "Kernel/ModelHandler.hpp"

namespace Sarah
{
namespace Kernel
{

// Constructeur et destructeur
ModelHandler::ModelHandler():
    gConfig(),
	m_loadedMesh(nullptr),
	m_generalClock()
{
    
}

ModelHandler::ModelHandler(GeneralConfig & p_gConfig):
    gConfig(p_gConfig),
	m_loadedMesh(nullptr),
	m_generalClock()
{
    
}

ModelHandler::~ModelHandler()
{

}

//Fonctions spécifiques
bool ModelHandler::Init()
{

    return true;
}

bool ModelHandler::Load(GLfloat *)
{
	return true;
}

}
}
