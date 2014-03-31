/**
 * \file		GraphicHandlerBuilder.hpp
 * \author		fcaillaud
 * \version 	1.0
 * \date     	28 Mars 2014
 * \brief     	Fichier décrivant la classe GraphicHandlerBuilder.
 * \details		Classe utilisée pour la construction d'un object GraphicHandler
 *				à partir d'un ensemble de propriétés (typedef GeneralConfigMap)
 * 				selon le design pattern Builder.
 */

#ifndef GRAPHICHANDLERBUILDER
#define GRAPHICHANDLERBUILDER

#include <string>

#include <SFML/Window.hpp>

#include "Utilities/BasicTypeOperations/BasicTypeConverter.hpp"
#include "Utilities/BasicTypeOperations/StringOperation.hpp"

#include "GraphicHandler.hpp"
#include "GeneralConfig.hpp"
/**
 * Définition du nom usuel de la configuration traitée par cette classe.
 */
#define graphicHandlerBuilderConfigName "WindowConfig"

/**
 * \namespace 	Sarah 	
 * \brief 		Nom de domaine principal.
 */
namespace Sarah
{

/**
 * \namespace 	Kernel	
 * \brief 		Nom de domaine secondaire, partie coeur.
 */
namespace Kernel
{

	/**
	 * \class 	GraphicHandlerBuilder
	 * \brief 	Classe GraphicHandlerBuilder permettant de construire une instance de GraphicHandler à partir d'un ensemble de propriétés.
	 */
	class GraphicHandlerBuilder
	{
		template<class M, class G, class E> friend class ControlerHandler;

		public:

			/**
			 * Un dictionnaire de noms associés à des valeur est une ConfigMap.
			 */
			typedef std::map<std::string, std::string> 	ConfigMap;
			/**
			 * Un dictionnaire de noms associés à une ConfigMap est une GeneralConfigMap.
			 */
			typedef std::map<std::string, ConfigMap>  	GeneralConfigMap;

		public:

			/**
			 * Opération de construction d'un GraphicHandler à l'aide d'un ensemble de propriétés.
			 * \param 	generalConfigMap 	Ensemble d'informations regroupé sous forme de dictionnaire de propriétés
			 *								(typedef GeneralConfigMap).
			 * \param 	graphHandler 		L'instance de GraphicHandler à construire.
			 * \todo 	Permettre de REbuilder sans avoir a relire la config (conservation de la derniere config).
			 */
			virtual void operator()(const GeneralConfigMap & generalConfigMap, GraphicHandler & graphHandler)
			{
				GeneralConfig generalConfig;
				WindowConfig * windowConfig = new WindowConfig();
				generalConfig.AddConfig(windowConfig);

				GeneralConfigMap::const_iterator itGConfig;
				ConfigMap::iterator itConfig;
				std::string tempString;
				std::vector<std::string> tempVecString;

				//si il n'y a pas de section WindowConfig -> config par défaut
				//sinon, les propriétés spécifiées sont gérées, les autres sont mises par défaut
				if((itGConfig = generalConfigMap.find(graphicHandlerBuilderConfigName)) != generalConfigMap.end())
				{
					ConfigMap windowConfigMap = itGConfig->second;

					//Récupération du titre s'il existe
					if((itConfig = windowConfigMap.find("title")) != windowConfigMap.end())
						windowConfig->title = itConfig->second;

					//Récupération du mode video, s'il existe (largeur hauteur et bit par pixel + fullscreen)
					if((itConfig = windowConfigMap.find("videomode")) != windowConfigMap.end()){
						sf::VideoMode persoVideoMode(640, 480, 32);
						tempString = itConfig->second;

						if(tempString.compare("fullscreen") == 0)
						{
							//TODO : implémenter la creation d'un videomode en fullscreen
							msg::Msg_Spe(msg::MSG_FLAG_ENUM::BLUE, "In GraphicHandlerBuilder() : The fullscreen property isn't yet implemented, ... Sorry !");
						}else{
							tempVecString = gu::Split(tempString, ':');

							for(unsigned int i = 0; i < tempVecString.size(); ++i)
							{
								switch(i)
								{
									case 0:
										persoVideoMode.width = gu::AtoInt(tempVecString[i].c_str());
										break;
									case 1:
										persoVideoMode.height = gu::AtoInt(tempVecString[i].c_str());
										break;
									case 2:
										if(tempVecString[i].compare("desktop") == 0)
											persoVideoMode.bitsPerPixel = sf::VideoMode::getDesktopMode().bitsPerPixel;
										else
											persoVideoMode.bitsPerPixel = gu::AtoInt(tempVecString[i].c_str());
										break;
									default:
										msg::Msg_Spe(msg::MSG_FLAG_ENUM::ERROR, "Error in GraphicHandlerBuilder() : Wrong Syntax in WindowConfig.VideoMode property, check in the INI file. Should be \"width:height or width:height:bpp or width:height:desktop or fullscreen\"");
										exit(-1);
										break;
								}
							}
						}
						windowConfig->videoMode = persoVideoMode;
					}

					//Récupération du style de la fenêtre
					if((itConfig = windowConfigMap.find("style")) != windowConfigMap.end()){
						tempString = itConfig->second;

						if(tempString.compare("default") == 0)
							windowConfig->style = sf::Style::Default;
						else{
							int persoStyle = sf::Style::None;
							tempVecString = gu::Split(tempString, '|');

							for(unsigned int i = 0; i < tempVecString.size(); ++i)
							{
								if(tempVecString[i].compare("none") == 0){
									//Rien à faire
								}else if(tempVecString[i].compare("default") == 0){
									persoStyle |= sf::Style::Default;
								}else if(tempVecString[i].compare("titlebar") == 0){
									persoStyle |= sf::Style::Titlebar;
								}else if(tempVecString[i].compare("resize") == 0){
									persoStyle |= sf::Style::Resize;
								}else if(tempVecString[i].compare("close") == 0){
									persoStyle |= sf::Style::Close;
								}else if(tempVecString[i].compare("fullscreen") == 0){
									persoStyle |= sf::Style::Fullscreen;
								}else{
									msg::Msg_Spe(msg::MSG_FLAG_ENUM::ERROR, "Error in GraphicHandlerBuilder() : Wrong Syntax in WindowConfig.Style property, check in the INI file. Should be \"none, default, titlebar, resize, close and/or fullscreen\"");
									exit(-1);
								}
							}
							windowConfig->style = persoStyle;
						}
					}
				}
				windowConfig->Print();
				graphHandler.gConfig = generalConfig;
			}

	};

}
}

#endif
