#ifndef GRAPHICHANDLERBUILDER
#define GRAPHICHANDLERBUILDER

#include <string>

#include <SFML/Window.hpp>

#include "GraphicHandler.hpp"
#include "Kernel/GeneralConfig.hpp"

/**
 * \namespace 	Nom de domaine principal.
 */	
namespace Sarah
{
/**
 * \namespace 	Nom de domaine secondaire, partie coeur.
 */	
namespace Kernel
{
	/**
	 * \class 	Classe GraphicHandlerBuilder permettant de construire une instance de GraphicHandler à partir d'une configuration générale.
	 */
	class GraphicHandlerBuilder
	{
		friend class ControlerHandler;

		public:

			//TODO : mettre cette constante et les autres variables par défaut en attribut et faire un constructeur par défaut 
			//		et un constructeur paramétré pour que le concepteur puisse prendre la main sur l'utilisateur et dire que si 
			//		la config donnée n'est pas satisfaisante, alors on prend cette définie par défaut pour certaines raisons.


		public:

			//TODO : permettre de REbuilder sans avoir a relire la config (conservation de la derniere config)
			void operator()(GeneralConfig & config, GraphicHandler & graphHandler)
			{
				BaseConfig * windowConfig;
				std::string configName = "WindowConfig";

				std::string title = "My Window";
				unsigned int width = 300, heigth = 200, bpp = 32;
				int style = sf::Style::Titlebar | sf::Style::Resize | sf::Style::Close;

				windowConfig = config.GetConfig(configName);
				//si il n'y a pas de section WindowConfig -> config par défaut
				//sinon, les propriétés spécifiées sont gérées, les autres sont mises par défaut
				if(windowConfig != nullptr)
				{
					//démerde toi !!
				}
				
				graphHandler.m_mainWindow.create(sf::VideoMode(width, heigth, bpp), title, style);
			}

	};

}
}

#endif