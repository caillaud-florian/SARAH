#ifndef CONFIG
#define CONFIG

#include <string>
#include <iostream>

#include <SFML/Window.hpp>

namespace Sarah
{
namespace Kernel
{
	
	class Config
	{

		public:

			virtual std::string GetName() const = 0;
			virtual void Print() const = 0;

	};

	class WindowConfig : public Config
	{

		public:

			WindowConfig():
				title("default window"),
				videoMode(sf::VideoMode(640, 480)),
				style(sf::Style::Default),
				contextSettings()
			{

			}

			WindowConfig(std::string p_title, sf::VideoMode p_videoMode, int p_style, sf::ContextSettings p_context):
				title(p_title),
				videoMode(p_videoMode),
				style(p_style),
				contextSettings(p_context)
			{
				
			}

			std::string GetName() const
			{
				return "WindowConfig";
			}

			void Print() const
			{
				std::cout << "------------------------------" << std::endl 
							<< GetName() << std::endl
							<< "------------------------------" << std::endl
							<< "title \t\t-> " << title << std::endl
							<< "videoMode \t-> " << "à implémenter" << std::endl
							<< "style \t\t-> " << "à implémenter" << std::endl
							<< "contextSettings -> " << "à implémenter" << std::endl;
			}

		public:

			std::string 			title;
			sf::VideoMode 			videoMode;
			int 					style;
			sf::ContextSettings 	contextSettings;


	};

}
}

#endif