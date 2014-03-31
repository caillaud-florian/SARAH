/**
 * \file		Window.hpp
 * \author		fcaillaud
 * \version 	0.1
 * \date     	28 Octobre 2013
 * \brief     	Fichier implémentant la surcouche d'une fenêtre SFML.
 * \todo 	  	ContextSettings à enlever, déjà géré dans WindowConfig.
 *				Voir pour mettre d'autre fonctionnalité dans cette classe qui sera surement utile !!
 */

#ifndef WINDOW
#define WINDOW

#include <SFML/Window.hpp>

/**
 * \namespace 	Sarah
 * \brief 		Nom de domaine principal.
 */	
namespace Sarah
{
/**
 * \namespace 	Window
 * \brief 		Nom de domaine secondaire, partie graphique.
 */	
namespace Window
{
	/**
	 * \class 	Window
	 * \brief 	Surcouche d'une SFML Window permettant plus de fonctionnalités.
	 */
	class Window : public sf::Window
	{

		public:

			/**
			 * Récupération de l'attribut m_contextSettings.
			 * \return	Les contextSettings de la fenêtre.
			 */
			sf::ContextSettings GetContext();

			/**
			 * Modification de l'attribut m_contextSettings.
			 * \param	p_contextSettings 	Les nouveaux contextSettings de la fenêtre.
			 */
			void SetContext(sf::ContextSettings);

		private:

			/**
			 * \brief	ContextSettings de la fenêtre.
			 */
			sf::ContextSettings m_contextSettings;
	};

}	
}

#endif
