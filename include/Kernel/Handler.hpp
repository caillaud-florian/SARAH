#ifndef HANDLER
#define HANDLER

#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>

#include "Kernel/GeneralConfig.hpp"

namespace Sarah
{
namespace Kernel
{
	typedef Kernel::GeneralConfig GeneralConfig;

	class Handler
	{
		public:

			// Constructeur et destructeur
			Handler();

			Handler(GeneralConfig);

			~Handler();

			//Fonctions spécifiques
			bool Init();

			bool Load(GLfloat *);

			bool MainLoop();

		public:

			GeneralConfig gConfig;

		private:

			sf::Window m_mainWindow;
			sf::Clock m_generalClock;

			GLfloat * m_loadedMesh;
	};

}
}

#endif