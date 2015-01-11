/**
 * \file		BaseMesh.hpp
 * \author		fcaillaud
 * \version 	1.0
 * \date     	31 Mars 2014
 * \brief     	Fichier décrivant la classe BaseMesh.
 * \details		Classe mère de toutes les futures structures de maillages 
 *				en interaction avec la plateforme.
 */

#ifndef BASEMESH
#define BASEMESH

#include <string>
#include <vector>

#include <SFML/OpenGL.hpp>

#include "Utilities/Geometry/Point/Vertex.hpp"

/**
 * \namespace 	Sarah
 * \brief		Nom de domaine principal.
 */	
namespace Sarah
{
/**
 * \namespace 	Modeling
 * \brief		Nom de domaine secondaire, partie modélisation.
 */	
namespace Modeling
{

	/**
	 * \class 	BaseMesh
	 * \brief	Classe mère représentant un maillage basique.
	 * \details	Elle est constituée principalement d'un nom et de sommets.
	 */
	class BaseMesh
	{

		public:

			/**
			 * Dans BaseMesh, les faces sont représentées par des listes d'indices sur leurs sommets.
			 */
			typedef std::vector<unsigned int> 		Face;

		public:

			/**
			 * Constructeur paramétré.
			 * \param 	p_meshName 	Nom du maillage, par défaut "Standard Mesh".
			 */
			BaseMesh(std::string p_meshName = "Standard Mesh");

			~BaseMesh();

			/**
			 * Mise en forme des données du maillage (sommets et autres) pour 
			 * le chargement au sein du pipeline OpenGL.
			 * \return 	Un pointeur sur GLfloat définissant la manière dont le maillage doit être affiché.
			 */
			GLfloat * Draw();

		protected:

			/**
			 * \brief 	Nom du maillage.
			 */
			std::string 				m_name;

			/**
			 * \brief 	Liste des sommets du maillage.
			 */
			std::vector<geo::Vertex> 	m_vertices;
			
			/**
			 * \brief 	Liste des faces du maillage.
			 */
			std::vector<Face> 			m_faces;

			/**
			 * \brief 	Liste des couleurs associées aux sommets du maillage.
			 */
			std::vector<geo::Vertex> 	m_colors;

			GLfloat * 					m_glMesh;
	};
	
}
}

#endif
