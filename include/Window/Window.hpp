/**
 * \file		Window.hpp
 * \author		fcaillaud
 * \version 	0.1
 * \date     	28 Octobre 2013
 * \brief     	Fichier implémentant la surcouche d'une fenêtre SFML.
 *
 * \todo 	  	ContextSettings à enlever, déjà géré dans WindowConfig.
 *				Voir pour mettre d'autre fonctionnalité dans cette classe qui sera surement utile !!
 */

#ifndef WINDOW
#define WINDOW

#include <SFML/Window.hpp>

/**
 * \namespace 	Nom de domaine principal.
 */	
namespace Sarah
{
/**
 * \namespace 	Nom de domaine secondaire, partie graphique.
 */	
namespace Window
{
	/**
	 * \class : Window Window.hpp surcouche d'une SFML Window permettant plus de fonctionnalités.
	 */
	class Window : public sf::Window
	{
		public:

			/**
			 * \fn	Accesseur de l'attribut \a m_contextSettings.
			 * \return 	Les contextSettings de la fenêtre.
			 */
			sf::ContextSettings GetContext();

			/**
			 * \fn 	Mutateur de l'attribut \a m_contextSettings.
			 * \param	Les nouveaux contextSettings de la fenêtre.
			 */
			void SetContext(sf::ContextSettings);

		private:

			/**
			 * \brief	contextSettings de la fenêtre
			 */
			sf::ContextSettings m_contextSettings;
	};

}	
}

#endif