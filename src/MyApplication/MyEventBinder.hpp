#ifndef MYEVENT_BINDER
#define MYEVENT_BINDER

#include "../Kernel/EventBinder.hpp"

/**
 * \namespace 	Nom de domaine principal.
 */
namespace Sarah
{

	class MyEventBinder : public Kernel::EventBinder
	{

		public:

			MyEventBinder(Kernel::GraphicHandler &, Kernel::ModelHandler &);

		protected:

			virtual void BindClosedEvent();

			virtual void BindResizedEvent(int, int);

			virtual void BindTextEnteredEvent(sf::Uint32);

			virtual void BindKeyPressedEvent(sf::Keyboard::Key, bool, bool, bool, bool);

			virtual void BindMouseButtonPressedEvent(sf::Mouse::Button, int, int);

	};

}

#endif
