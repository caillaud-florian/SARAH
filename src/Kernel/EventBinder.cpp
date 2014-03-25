#include "EventBinder.hpp"

namespace Sarah
{
namespace Kernel
{

EventBinder::EventBinder(GraphicHandler & p_graphicHandler, ModelHandler & p_modelHandler):
	m_graphicHandler(p_graphicHandler),
	m_modelHandler(p_modelHandler),
	m_pause(false)
{}

void EventBinder::Bind()
{
	sf::Event event;
	while (GetFocusedWindow().pollEvent(event))
	{
	    switch (event.type)
	    {
	        // fenêtre fermée
			case sf::Event::Closed :
				BindClosedEvent();
				break;
			// fenêtre redimensionnée
			case sf::Event::Resized :
				BindResizedEvent(event.size.width, event.size.height);
				break;
			// perte de focus de la fenêtre
			case sf::Event::LostFocus :
				BindLostFocusEvent();
				break;
			// gain de focus de la fenêtre
			case sf::Event::GainedFocus :
				BindGainedFocusEvent();
				break;
			// texte entré comme dans un champ texte
			case sf::Event::TextEntered :
				BindTextEnteredEvent(event.text.unicode);
				break;
			// touche du clavier pressée
			case sf::Event::KeyPressed :
				BindKeyPressedEvent(event.key.code, event.key.control, event.key.alt, event.key.shift, event.key.system);
				break;
			// touche du clavier relachée
			case sf::Event::KeyReleased :
				BindKeyReleasedEvent(event.key.code, event.key.control, event.key.alt, event.key.shift, event.key.system);
				break;
			// mouvement de la molette de la souris
			case sf::Event::MouseWheelMoved :
				BindMouseWheelMovedEvent(event.mouseWheel.delta, event.mouseWheel.x, event.mouseWheel.y);
				break;
			// pression d'un bouton de la souris
			case sf::Event::MouseButtonPressed :
				BindMouseButtonPressedEvent(event.mouseButton.button, event.mouseButton.x, event.mouseButton.y);
				break;
			// relachement d'un bouton de la souris
			case sf::Event::MouseButtonReleased :
				BindMouseButtonReleasedEvent(event.mouseButton.button, event.mouseButton.x, event.mouseButton.y);
				break;
			// mouvement de la souris
			case sf::Event::MouseMoved :
				BindMouseMovedEvent(event.mouseMove.x, event.mouseMove.y);
				break;
			// entrée de la souris dans la fenêtre
			case sf::Event::MouseEntered :
				BindMouseEnteredEvent();
				break;
			// sortie de la souris hors de la fenêtre
			case sf::Event::MouseLeft :
				BindMouseLeftEvent();
				break;
			// autres actions liées aux joysticks (pas encore gérées)
			case sf::Event::JoystickButtonPressed :
				BindJoystickButtonPressedEvent();
				break;
			case sf::Event::JoystickButtonReleased :
				BindJoystickButtonReleasedEvent();
				break;
			case sf::Event::JoystickMoved :
				BindJoystickMovedEvent();
				break;
			case sf::Event::JoystickConnected :
				BindJoystickConnectedEvent();
				break;
			case sf::Event::JoystickDisconnected :
				BindJoystickDisconnectedEvent();
				break;
	        default:
	            break;
	    }
	}
}

bool EventBinder::IsPaused()
{
	return m_pause;
}

sf::Window & EventBinder::GetFocusedWindow()
{
	return m_graphicHandler.m_focusedWindow;
}

void EventBinder::BindClosedEvent()
{
	GetFocusedWindow().close();
}

void EventBinder::BindResizedEvent(int p_width, int p_height)
{}

void EventBinder::BindLostFocusEvent()
{
	m_pause = true;
}

void EventBinder::BindGainedFocusEvent()
{
	m_pause = false;
}

void EventBinder::BindTextEnteredEvent(sf::Uint32)
{}

void EventBinder::BindKeyPressedEvent(sf::Keyboard::Key, bool, bool, bool, bool)
{}

void EventBinder::BindKeyReleasedEvent(sf::Keyboard::Key, bool, bool, bool, bool)
{}

void EventBinder::BindMouseWheelMovedEvent(int, int, int)
{}

void EventBinder::BindMouseButtonPressedEvent(sf::Mouse::Button, int, int)
{}

void EventBinder::BindMouseButtonReleasedEvent(sf::Mouse::Button, int, int)
{}

void EventBinder::BindMouseMovedEvent(int, int)
{}

void EventBinder::BindMouseEnteredEvent()
{}

void EventBinder::BindMouseLeftEvent()
{}

void EventBinder::BindJoystickButtonPressedEvent()
{}

void EventBinder::BindJoystickButtonReleasedEvent()
{}

void EventBinder::BindJoystickMovedEvent()
{}

void EventBinder::BindJoystickConnectedEvent()
{}

void EventBinder::BindJoystickDisconnectedEvent()
{}

}
}
