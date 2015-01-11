#include "MyModelHandler.hpp"

namespace Sarah
{

MyModelHandler::MyModelHandler():
	ModelHandler(),
    m_loadedMesh("test1"),
    m_drawObj(new MyDrawableObject())
{}

MyModelHandler::MyModelHandler(Kernel::GeneralConfig & p_gConfig):
	ModelHandler(p_gConfig),
    m_loadedMesh("test1"),
    m_drawObj(new MyDrawableObject())
{}

MyModelHandler::~MyModelHandler()
{
	delete m_drawObj;
}

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
	m_drawObj->SetObject(m_loadedMesh.Draw());
   	NotifyAll(m_drawObj);
}

}
