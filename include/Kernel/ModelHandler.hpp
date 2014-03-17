#ifndef MODELHANDLER
#define MODELHANDLER

#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>

#include "Kernel/GeneralConfig.hpp"
#include "Kernel/Observable.hpp"

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
	 * \class 	Classe ModelHandler permettant de gérer tous les modules de la plateforme.
	 */
	class ModelHandler
	{
		template<class S, class T> friend class ControlerHandler;

		public:

			/*
			 * \fn 		Constructeur par défaut
			 */
			ModelHandler();

			/*
			 * \fn 		Constructeur paramétré
			 * \detail 	Construction à partir d'une configuration générale.
			 * \param 	p_generalConfig 	Objet représentant une configuration générale 
			 *			et avec lequel on initialise le controleur.
			 */
			ModelHandler(GeneralConfig &);

			/**
			 * \fn 		Destructeur
			 */
			~ModelHandler();

			/**
			 * \fn 		Initialisation de la partie modèle de la plateforme SARAH
			 * \return 	true si l'initialisation s'est bien passée, false sinon.
			 */
			virtual bool Init();

			virtual bool Load(GLfloat *);

		public:

			/**
			 * \brief 	Configuration générale de la partie modèle de la plateforme
			 * \detail 	Mise à disposition de l'utilisateur (public) pour consultation 
			 * 			ou changement (alors ne pas oublier de faire un GeneralConfigUpdate).
			 */
			GeneralConfig gConfig;

		protected:

			/**
			 * \brief 	Pointeur vers le maillage chargé dans la plateforme.
			 */
			GLfloat * m_loadedMesh;
			/**
			 * \brief 	Horloge permettant un contexte temporel principal (de type SFML Clock).
			 */
			sf::Clock m_generalClock;

	};

}
}

#endif
