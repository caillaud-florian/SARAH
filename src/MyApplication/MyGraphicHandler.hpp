#ifndef MYGRAPHICHANDLER
#define MYGRAPHICHANDLER

#include "../Kernel/GraphicHandler.hpp"
#include "../Kernel/Observer.hpp"

/**
 * \namespace 	Nom de domaine principal.
 */	
namespace Sarah
{

	class MyGraphicHandler : public Kernel::GraphicHandler, public Kernel::Observer<GLfloat *>
	{
		friend class EventBinder;
		template<class M, class G, class E> friend class ControlerHandler;
		friend class GraphicHandlerBuilder;

		public:

			MyGraphicHandler();

			MyGraphicHandler(Kernel::GeneralConfig &);

			~MyGraphicHandler();

			bool Init();

			void Update(GLfloat *);

	};

}

#endif
