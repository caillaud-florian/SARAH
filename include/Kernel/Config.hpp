/**
 * \file		Config.hpp
 * \author		fcaillaud
 * \version 	0.1
 * \date     	28 Octobre 2013
 * \brief     	Fichier implémentant un modèle BaseConfig et ses dérivés.
 * \detail 		Une configuration permet de regrouper plusieurs données communes à un objet.
 *				Ces attributs sont public afin de permettre à l'utilisateur de les consulter
 *				et de les changer simplement (un ConfigUpdate est nécessaire).
 * \todo		Créer une classe mère Configured, ayant une fonction purement virtuelle
 *				ConfigUpdate mettant à jour l'objet héritant en fonction des changements faits 
 *				sur la configuration.
 *				Utiliser l'utilitaire MSG pour les messages.
 */

#ifndef CONFIG
#define CONFIG

#include <string>
#include <iostream>

#include <SFML/Window.hpp>

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
	 * \class 	Classe mère de toutes les configurations
	 */
	class BaseConfig
	{

		public:

			/**
			 * \fn 		Fonction purement virtuelle renvoyant le nom de la configuration.
			 * \return 	Le nom de la configuration.
			 */
			virtual std::string GetName() const = 0;
			/**
			 * \fn 		Fonction purement virtuelle imprimant sur la sortie standard 
			 *			les données de la configuration.
			 */
			virtual void Print() const = 0;

	};

	/**
	 * \class Class dérivée de BaseConfig et représentant la configuration d'une Sarah::Window::Window
	 */
	class WindowConfig : public BaseConfig
	{

		public:

			/**
			 * \fn 		Constructeur par défaut
			 */
			WindowConfig():
				title("default window"),
				videoMode(sf::VideoMode(640, 480)),
				style(sf::Style::Default),
				contextSettings()
			{

			}

			/**
			 * \fn 		Constructeur paramétré
			 * \param 	p_title 	Titre de la fenêtre
			 * \param 	p_videoMode	Mode vidéo utilisé (taille, etc.)
			 * \param 	p_style 	Style de la fenêtre (FullScreen, etc.)
			 * \param 	p_context 	ContextSettings de la fenêtre
			 */
			WindowConfig(std::string p_title, sf::VideoMode p_videoMode, int p_style, sf::ContextSettings p_context):
				title(p_title),
				videoMode(p_videoMode),
				style(p_style),
				contextSettings(p_context)
			{
				
			}

			/**
			 * \fn 		Redefinition de fonction GetName de BaseConfig
			 * \return 	WindowConfig
			 */
			std::string GetName() const
			{
				return "WindowConfig";
			}

			/**
			 * \fn 		Redefinition de la fonction Print de BaseConfig
			 * \detail 	Imprime sur la sortie standard les attributs suivant un certain format
			 */
			void Print() const
			{
				std::cout << "------------------------------" << std::endl 
							<< GetName() << std::endl
							<< "------------------------------" << std::endl
							<< "title \t\t-> " << title << std::endl
							<< "videoMode \t-> " << "à implémenter" << std::endl
							<< "style \t\t-> " << "à implémenter" << std::endl
							<< "contextSettings -> " << "à implémenter" << std::endl;
			}

		public:

			/**
			 * \brief 	Le titre de la fenêtre
			 */
			std::string 			title;
			/**
			 * \brief 	La taille de la fenêtre et le format des pixels (de type SFML VideoMode)
			 */
			sf::VideoMode 			videoMode;
			/**
			 * \brief 	Le style de la fenêtre (FullScreen, TitleBar, None, etc.)(enum SFML)
			 */
			int 					style;
			/**
			 * \brief 	Les informations de contexte de la fenêtre (de type SFML ContextSettings)
			 */
			sf::ContextSettings 	contextSettings;


	};

}
}

#endif