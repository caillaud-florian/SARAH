#include "BaseMesh.hpp"

namespace Sarah
{
	
namespace Modeling
{

	BaseMesh::BaseMesh(std::string p_meshName):
		m_name(p_meshName),
		m_vertices(),
		m_faces(),
		m_colors(),
		m_glMesh()
	{
		m_vertices.push_back(geo::Vertex(-50, -50, -50));
		m_colors.push_back(geo::Vertex(1, 0, 0));

		m_vertices.push_back(geo::Vertex(-50, 50, -50));
		m_colors.push_back(geo::Vertex(0, 1, 0));

		m_vertices.push_back(geo::Vertex(-50, -50, 50));
		m_colors.push_back(geo::Vertex(0, 0, 1));

		Face face; face.push_back(0); face.push_back(1); face.push_back(2);
		m_faces.push_back(face);

		m_glMesh = new GLfloat[(m_vertices.size() + m_colors.size()) * 3];
	}

	BaseMesh::~BaseMesh()
	{
		delete m_glMesh;
	}

	GLfloat * BaseMesh::Draw()
	{
	    glEnableClientState(GL_VERTEX_ARRAY);
	    glEnableClientState(GL_COLOR_ARRAY);

	    glDisableClientState(GL_NORMAL_ARRAY);
	    glDisableClientState(GL_TEXTURE_COORD_ARRAY);

		for(unsigned int i = 0; i < m_vertices.size(); ++i)
		{
			m_glMesh[(i*6)] = m_vertices[i].GetX();
			m_glMesh[(i*6) + 1] = m_vertices[i].GetY();
			m_glMesh[(i*6) + 2] = m_vertices[i].GetZ();

			m_glMesh[(i*6) + 3] = m_colors[i].GetX();
			m_glMesh[(i*6) + 4] = m_colors[i].GetY();
			m_glMesh[(i*6) + 5] = m_colors[i].GetZ();
		}
		    
		return m_glMesh;
	}
	
}
}
