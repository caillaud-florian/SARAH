#include "MyApplication/MyEventBinder.hpp"

namespace Sarah
{

MyEventBinder::MyEventBinder(Kernel::GraphicHandler & p_graphicHandler, Kernel::ModelHandler & p_modelHandler):
	Kernel::EventBinder(p_graphicHandler, p_modelHandler)
{}

void MyEventBinder::BindClosedEvent()
{
	GetFocusedWindow().close();
}

void MyEventBinder::BindResizedEvent(int p_width, int p_height)
{
	glViewport(0, 0, p_width, p_height);
}

void MyEventBinder::BindTextEnteredEvent(sf::Uint32 p_char)
{
	if(p_char < 128)
		msg::Msg_Spe(msg::MSG_FLAG_ENUM::BLUE, "You press the following key : ", (char)p_char);
	else
		msg::Msg_Spe(msg::MSG_FLAG_ENUM::BLUE, "You press a non printable character from unicode norm !");
}

void MyEventBinder::BindKeyPressedEvent(sf::Keyboard::Key p_key, bool p_ctrl, bool p_alt, bool p_shift, bool p_syst)
{
	if(p_key == sf::Keyboard::Escape)
		GetFocusedWindow().close();
	else
	{
		msg::Msg_Spe(msg::MSG_FLAG_ENUM::BLUE, "You press a the key number : ", static_cast<int>(p_key), " (ctrl : ", p_ctrl, "; alt : ", p_alt, "; shift : ", p_shift, "; syst : ", p_syst, ")");
	}
}

void MyEventBinder::BindMouseButtonPressedEvent(sf::Mouse::Button p_button, int p_x, int p_y)
{
	switch(p_button)
	{
		case sf::Mouse::Left:
			msg::Msg_Spe(msg::MSG_FLAG_ENUM::BLUE, "You press on the Left button of the mouse");
			break;
		case sf::Mouse::Right:
			msg::Msg_Spe(msg::MSG_FLAG_ENUM::BLUE, "You press on the Right button of the mouse");
			break;
		case sf::Mouse::Middle:
			msg::Msg_Spe(msg::MSG_FLAG_ENUM::BLUE, "You press on the Middle button of the mouse");
			break;
		default:
			break;
	}
}

}
