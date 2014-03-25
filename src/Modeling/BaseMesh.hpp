#ifndef BASEMESH
#define BASEMESH

#include <string>
#include <vector>

#include <SFML/OpenGL.hpp>

#include "Utilities/Geometry/Point/Vertex.hpp"

/**
 * \namespace 	Nom de domaine principal.
 */	
namespace Sarah
{
/**
 * \namespace 	Nom de domaine secondaire, partie modélisation.
 */	
namespace Modeling
{

	class BaseMesh
	{

		public:

			typedef std::vector<unsigned int> 		Face;

		public:

			BaseMesh(std::string p_meshName = "Standard Mesh");

			GLfloat * Draw();

		private:

			

		protected:

			std::string 				m_name;

			std::vector<geo::Vertex> 	m_vertices;
			
			std::vector<Face> 			m_faces;

			std::vector<geo::Vertex> 	m_colors;
	};
	
}
}

#endif
