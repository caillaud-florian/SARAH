#ifndef EVENT_BINDER
#define EVENT_BINDER

#include <SFML/Window.hpp>

#include "Kernel/GraphicHandler.hpp"
#include "Kernel/ModelHandler.hpp"

/**
 * \namespace 	Nom de domaine principal.
 */
namespace Sarah
{
/**
 * \namespace 	Nom de domaine secondaire, partie coeur.
 */
namespace Kernel
{

	class EventBinder
	{

		public:

			EventBinder(GraphicHandler &, ModelHandler &);

			virtual void Bind();

			bool IsPaused();

		protected:

			sf::Window & GetFocusedWindow();

			virtual void BindClosedEvent();

			virtual void BindResizedEvent(int, int);

			virtual void BindLostFocusEvent();

			virtual void BindGainedFocusEvent();

			virtual void BindTextEnteredEvent(sf::Uint32);

			virtual void BindKeyPressedEvent(sf::Keyboard::Key, bool, bool, bool, bool);

			virtual void BindKeyReleasedEvent(sf::Keyboard::Key, bool, bool, bool, bool);

			virtual void BindMouseWheelMovedEvent(int, int, int);

			virtual void BindMouseButtonPressedEvent(sf::Mouse::Button, int, int);

			virtual void BindMouseButtonReleasedEvent(sf::Mouse::Button, int, int);

			virtual void BindMouseMovedEvent(int, int);

			virtual void BindMouseEnteredEvent();

			virtual void BindMouseLeftEvent();

			virtual void BindJoystickButtonPressedEvent();

			virtual void BindJoystickButtonReleasedEvent();

			virtual void BindJoystickMovedEvent();

			virtual void BindJoystickConnectedEvent();

			virtual void BindJoystickDisconnectedEvent();

		protected:

			GraphicHandler & m_graphicHandler;

			ModelHandler & m_modelHandler;

			bool m_pause;

	};

}
}

#endif
