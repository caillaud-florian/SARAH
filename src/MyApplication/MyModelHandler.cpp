#include "MyModelHandler.hpp"

namespace Sarah
{

MyModelHandler::MyModelHandler():
	ModelHandler(),
    m_loadedMesh("test1")
{}

MyModelHandler::MyModelHandler(Kernel::GeneralConfig & p_gConfig):
	ModelHandler(p_gConfig),
    m_loadedMesh("test1")
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
