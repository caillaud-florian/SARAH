/**
 * \file		MyModelHandler.hpp
 * \author		fcaillaud
 * \version 	1.0
 * \date     	31 Mars 2014
 * \brief     	Fichier décrivant la spécialisation de la classe ModelHandler.
 * \details		Classe utilisée pour personnaliser le fonctionnement de ModelHandler.
 */

#ifndef MYMODELHANDLER
#define MYMODELHANDLER

#include "../Kernel/ModelHandler.hpp"

#include "../Modeling/BaseMesh.hpp"

/**
 * \namespace 	Sarah
 * \brief 		Nom de domaine principal.
 */	
namespace Sarah
{

	/**
	 * \class 	MyModelHandler
	 * \brief 	Personnalisation de la classe ModelHandler.
	 */
	class MyModelHandler : public Kernel::ModelHandler, public Kernel::Observable<GLfloat *>
	{

		/**
		 * \brief 	La classe ControlerHandler est en ami pour pouvoir accéder librement à MyModelHandler.
		 * \todo 	Voir comment ne plus avoir besoin de cette amitié plus ou moins anormale.
		 */
		template<class M, class G, class E> friend class ControlerHandler;

		public:

			/**
			 * Constructeur par défaut.
			 */
			MyModelHandler();

			/**
			 * Constructeur paramétré.
			 * \details	Construction à partir d'une configuration générale.
			 * \param 	p_gConfig 	Objet représentant une configuration générale 
			 *						et avec lequel on initialise le controleur.
			 */
			MyModelHandler(Kernel::GeneralConfig &);

			/**
			 * Initialisation de la partie modèle de la plateforme SARAH
			 * \return 	true si l'initialisation s'est bien passée, false sinon.
			 */
			bool Init();

			/**
			 * Chargement des modèles 2D, 3D et autres.
			 * \todo	Réfléchir à la vraie utilité de cette fonction.
			 * \return 	true si le chargement s'est bien passée, false sinon.
			 */
			bool Load();

			/**
			 * Notification de dessin généralement adressée à la Vue.
			 */
			void Draw();

		private:

			/**
			 * \brief 	Pointeur vers le maillage chargé dans la plateforme.
			 */
			Modeling::BaseMesh	m_loadedMesh;

	};

}

#endif
