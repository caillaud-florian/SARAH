#ifndef MYDRAWABLEOBJECT
#define MYDRAWABLEOBJECT

#include "SFML/OpenGL.hpp"

#include "Kernel/DrawableObject.hpp"

namespace Sarah
{

	class MyDrawableObject : public Kernel::DrawableObject
	{

		public:

			void SetObject(GLfloat * p_float)
			{
				m_float = p_float;
			}

			void Draw()
			{
				if(m_float)
				{
					glVertexPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), m_float);
		    		glColorPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), m_float + 3);
				}
			}

		private:

			GLfloat *	m_float;
	};

}

#endif