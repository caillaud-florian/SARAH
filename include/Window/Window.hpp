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

			//TODO : ContextSettings à enlever, déjà géré dans WindowConfig.
			//		Voir pour mettre d'autre fonctionnalité dans cette classe qui sera surement utile !!
	};
}	
}

#endif