#include "MyModelHandler.hpp"

namespace Sarah
{

MyModelHandler::MyModelHandler():
	ModelHandler(),
    m_loadedMesh("test")
{}

MyModelHandler::MyModelHandler(Kernel::GeneralConfig & p_gConfig):
	ModelHandler(p_gConfig),
    m_loadedMesh("test")
{}

bool MyModelHandler::Init()
{
    return true;
}

bool MyModelHandler::Load()
{
    return true;
}

void MyModelHandler::Draw()
{
   NotifyAll(m_loadedMesh.Draw());
}

}
