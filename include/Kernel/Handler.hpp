/**
 * \file		Handler.hpp
 * \author		fcaillaud
 * \version 	0.1
 * \date     	28 Octobre 2013
 * \brief     	Fichier implémentant le controleur de la plateforme SARAH.
 * \detail		Cet objet, unique (pour le moment) au sein de la plateforme lors de l'execution
 *				sert à gérer les différents modules de la plateforme.
 */

#ifndef HANDLER
#define HANDLER

#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>

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
	 * \typedef	\a Kernel::GeneralConfig devient \a GeneralConfig pour plus de simplicité pour l'utilisateur.
	 */
	typedef Kernel::GeneralConfig GeneralConfig;

	/**
	 * \class 	Classe Handler permettant de gérer tous les module de la plateforme.
	 */
	class Handler
	{
		public:

			/*
			 * \fn 		Constructeur par défaut
			 */
			Handler();

			/*
			 * \fn 		Constructeur paramétré
			 * \detail 	Construction à partir d'une configuration générale.
			 * \param 	p_generalConfig 	Objet représentant une configuration générale 
			 *			et avec lequel on initialise le controleur.
			 */
			Handler(GeneralConfig);

			/**
			 * \fn 		Destructeur
			 */
			~Handler();

			/**
			 * \fn 		Initialisation de la plateforme SARAH
			 * \return 	true si l'initialisation s'est bien passée, false sinon.
			 */
			bool Init();

			/**
			 * \fn		Chargement d'un objet dans la plateforme
			 * \param 	p_mesh	Liste de points formés en triangles.
			 * \return 	true si le chargement s'est bien passé, false sinon.
			 */
			bool Load(GLfloat *);

			/**
			 * \fn 		Boucle principale d'évènements
			 * \return 	true si la boucle a été quittée correctement, false sinon.
			 */
			bool MainLoop();

		public:

			/**
			 * \brief 	Configuration générale de la plateforme
			 * \detail 	Mise à disposition de l'utilisateur (public) pour consultation 
			 * 			ou changement (alors ne pas oublier de faire un GeneralConfigUpdate).
			 */
			GeneralConfig gConfig;

		private:

			/**
			 * \brief 	Fenêtre principale (de type SFML Window).
			 */
			sf::Window m_mainWindow;
			/**
			 * \brief 	Horloge permettant un contexte temporel principal (de type SFML Clock).
			 */
			sf::Clock m_generalClock;
			/**
			 * \brief 	Pointeur vers le maillage chargé dans la plateforme.
			 */
			GLfloat * m_loadedMesh;
	};

}
}

#endif