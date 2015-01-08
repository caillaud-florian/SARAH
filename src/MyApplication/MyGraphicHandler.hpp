/**
 * \file		MyGraphicHandler.hpp
 * \author		fcaillaud
 * \version 	1.0
 * \date     	31 Mars 2014
 * \brief     	Fichier décrivant la spécialisation de la classe GraphicHandler.
 * \details		Classe utilisée pour personnaliser le fonctionnement de GraphicHandler.
 */

#ifndef MYGRAPHICHANDLER
#define MYGRAPHICHANDLER

#include "../Kernel/GraphicHandler.hpp"
#include "../Kernel/Observer.hpp"

/**
 * \namespace 	Sarah
 * \brief 		Nom de domaine principal.
 */	
namespace Sarah
{

	/**
	 * \class 	MyGraphicHandler
	 * \brief 	Personnalisation de la classe GraphicHandler.
	 */
	class MyGraphicHandler : public Kernel::GraphicHandler, public Kernel::Observer<GLfloat *>
	{

		public:

			/**
			 * Constructeur par défaut.
			 */
			MyGraphicHandler();

			/**
			 * Constructeur paramétré.
			 * \details	Construction à partir d'une configuration générale.
			 * \param 	p_gConfig 	Objet représentant une configuration générale 
			 *						et avec lequel on initialise le handler.
			 */
			MyGraphicHandler(Kernel::GeneralConfig &);

			/**
			 * Destructeur.
			 */
			~MyGraphicHandler();

			/**
			 * Redéfinition de la fonction Init de GraphicHandler.
			 * \return 	true si l'initialisation s'est bien passée, false sinon.
			 */
			bool Init();

			/**
			 * Implémentation de la fonction Update de l'interface Observer.
			 * \param 	glMesh 	Données du maillage à afficher (sommets et autres) formaté pour le pipeline OpenGL.
			 */
			void Update(GLfloat *);

	};

}

#endif
