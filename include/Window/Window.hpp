#ifndef WINDOW
#define WINDOW

#include <SFML/Window.hpp>

namespace Sarah
{
namespace Window
{
	
	class Window : public sf::Window
	{
		public:

			//Accesseurs
			sf::ContextSettings GetContext();

			void SetContext(sf::ContextSettings);

		private:

			sf::ContextSettings m_contextSettings;
	};
}	
}

#endif