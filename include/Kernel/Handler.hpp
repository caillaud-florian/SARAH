#ifndef HANDLER
#define HANDLER

#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>

namespace Sarah
{
namespace Kernel
{

	class Handler
	{
		public:

			// Constructeur et destructeur
			Handler();

			Handler(sf::ContextSettings);

			~Handler();

			//Fonctions spécifiques
			bool Init();

			bool Load(GLfloat *);

			bool MainLoop();

		private:

			sf::Window m_mainWindow;
			sf::Clock m_generalClock;

			GLfloat * m_loadedMesh;
	};

}
}

#endif