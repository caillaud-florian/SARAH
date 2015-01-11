#ifndef DRAWABLEOBJECT
#define DRAWABLEOBJECT

namespace Sarah
{

namespace Kernel
{

	class DrawableObject
	{
		public:
			// ici description OpenGL de l'objet
			virtual void Draw() = 0;

	};

}

}

#endif