#ifndef MYMODELHANDLER
#define MYMODELHANDLER

#include "../Kernel/ModelHandler.hpp"

#include "../Modeling/BaseMesh.hpp"

/**
 * \namespace 	Nom de domaine principal.
 */	
namespace Sarah
{

	class MyModelHandler : public Kernel::ModelHandler, public Kernel::Observable<GLfloat *>
	{
		template<class M, class G, class E> friend class ControlerHandler;

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

			bool Load();

			void Draw();

		private:

			/**
			 * \brief 	Pointeur vers le maillage chargé dans la plateforme.
			 */
			Modeling::BaseMesh	m_loadedMesh;

	};

}

#endif
