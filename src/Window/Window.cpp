#include "Window/Window.hpp"

namespace Sarah
{
namespace Window
{
	//Accesseurs
	sf::ContextSettings Window::GetContext()
	{
		return m_contextSettings;
	}

	void Window::SetContext(sf::ContextSettings p_contextSettings)
	{
		m_contextSettings = p_contextSettings;
	}
}
}
