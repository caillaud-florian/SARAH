#ifndef MYMODELHANDLER
#define MYMODELHANDLER

#include "Kernel/ModelHandler.hpp"

/**
 * \namespace 	Nom de domaine principal.
 */	
namespace Sarah
{

	class MyModelHandler : public Kernel::ModelHandler, public Kernel::Observable<int>
	{
		template<class T> friend class ControlerHandler;

		public:

			/*
			 * \fn 		Constructeur par défaut
			 */
			MyModelHandler();

			/*
			 * \fn 		Constructeur paramétré
			 * \detail 	Construction à partir d'une configuration générale.
			 * \param 	p_generalConfig 	Objet représentant une configuration générale 
			 *			et avec lequel on initialise le controleur.
			 */
			MyModelHandler(Kernel::GeneralConfig &);

			/**
			 * \fn 		Initialisation de la partie modèle de la plateforme SARAH
			 * \return 	true si l'initialisation s'est bien passée, false sinon.
			 */
			bool Init();

			bool Load(GLfloat *);

	};

}

#endif
