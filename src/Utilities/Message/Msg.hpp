/**
 * \file		Msg.hpp
 * \author		fcaillaud
 * \version 	1.0
 * \date     	2 Avril 2014
 * \brief     	Fichier décrivant la classe Msg.
 * \details		Classe utilisée comme utilitaire d'affichage de message.
 * \todo 		Revoir le concepte en entier. Peut être amélioré et simplifié pour l'utilisation.
 */

#ifndef MESSAGE_MSG
#define MESSAGE_MSG

#include <iostream>
#include <string>

/**
 * \namespace 	msg
 * \brief 		Nom de domaine tertiaire, partie utilitaire.
 * \todo 		Migrer vers gu.
 */
namespace msg
{

	/**
	 * \enum 	MSG_FLAG_ENUM
	 * \brief	Type de message à envoyer.
	 */
	enum class MSG_FLAG_ENUM : char
	{
		STANDARD 	= 0,	/*!< Affichage avec std::cout. */	
		LOG			= 2,	/*!< Affichage avec std::clog. */	
		TAB			= 1,	/*!< Affichage séparant les paramètres d'une tabulation, avec std::cout. */	
		ERROR 		= 3,	/*!< Affichage avec std::cerr. */	
		EVERY_JUMP 	= 4, 	/*!< Affichage séparant les paramètres d'un saut de ligne, avec std::cout. */	
		NO_JUMP 	= 5,	/*!< Affichage ne sautant pas de ligne à la fin, avec std::cout. */	
		CONCAT 		= 6,	/*!< Affichage n'inserant pas d'espace entre les paramètres, avec std::cout. */	
		RED			= 7,	/*!< Affichage rouge, avec std::cout. */	
		GREEN		= 8,	/*!< Affichage vert, avec std::cout. */	
		BLUE		= 9		/*!< Affichage bleu, avec std::cout. */	
	};
	
	/**
	 * \class 	Msg
	 * \brief 	Classe d'affichage d'un message simple.
	 */
	class Msg
	{

		public:

			/**
			 * Constructeur par défaut.
			 * \details Saute une ligne.
			 */
			Msg()
			{
				std::cout << std::endl;
			}

			/**
			 * Constructeur paramétré.
			 * \param 	pHead 	Le premier paramètre de la liste variable de paramètres.
			 * \param 	pTail 	Le reste des paramètres de la liste variable de paramètres.
			 * \details	Pour afficher un message il faut utiliser ce constructeur. Il utilise 
			 * 			les variadic template afin de permettre d'ajouter autant de paramètre 
			 *			que l'on veut à l'affichage. L'affichage est récursif sur le nombre de 
			 *			paramètres.
			 */
			template <typename H, typename ...T>
			Msg(H pHead, T... pTail)
			{
				std::cout << pHead << ' ';
				if (sizeof...(pTail))
					Msg(pTail);
				else
					Msg();
			}

	};

	/**
	 * \class 	Msg_Spe
	 * \brief 	Classe d'affichage d'un message spécifique.
	 */
	class Msg_Spe
	{

		public:

			/**
			 * Constructeur par défaut.
			 * \details Saute une ligne.
			 */
			Msg_Spe(): mFlag(MSG_FLAG_ENUM::STANDARD)
			{
				std::cout << std::endl;
			}

			/**
			 * Constructeur paramétré.
			 * \param 	pFlag 	Le type de message à afficher.
			 * \param 	pHead 	La valeur à afficher.
			 */
			template <typename F, typename H>
			Msg_Spe(F pFlag, H pHead): mFlag(pFlag) 
			{
				switch(pFlag)
				{
					case MSG_FLAG_ENUM::STANDARD:
						std::cout << pHead << std::endl;
						break;
					case MSG_FLAG_ENUM::TAB:
						std::cout << pHead << std::endl;
						break;
					case MSG_FLAG_ENUM::LOG:
						std::clog << pHead << std::endl;
						break;
					case MSG_FLAG_ENUM::ERROR:
						std::cerr << pHead << std::endl;
						break;
					case MSG_FLAG_ENUM::EVERY_JUMP:
						std::cout << pHead << std::endl;
						break;
					case MSG_FLAG_ENUM::NO_JUMP:
						std::cout << pHead << ' ';
						break;
					case MSG_FLAG_ENUM::CONCAT:
						std::cout << pHead << ' ';
						break;
					case MSG_FLAG_ENUM::RED:
						std::cout << "\033[31m" << pHead << "\033[0m" << std::endl;
						break;
					case MSG_FLAG_ENUM::GREEN:
						std::cout << "\033[32m" << pHead << "\033[0m" << std::endl;
						break;
					case MSG_FLAG_ENUM::BLUE:
						std::cout << "\033[34m" << pHead << "\033[0m" << std::endl;
						break;
					default:
						break;
				}
			}

			/**
			 * Constructeur paramétré.
			 * \param 	pFlag 	Le type de message à afficher.
			 * \param 	pHead 	La premières des valeurs à afficher.
			 * \param 	pTail 	Les autres valeurs à afficher.
			 * \details	Pour afficher un message il faut utiliser ce constructeur. Il utilise 
			 * 			les variadic template afin de permettre d'ajouter autant de paramètre 
			 *			que l'on veut à l'affichage. L'affichage est récursif sur le nombre de 
			 *			paramètres.
			 */
			template <typename F, typename H, typename ...T>
			Msg_Spe(F pFlag, H pHead, T... pTail): mFlag(pFlag)
			{
				switch(pFlag)
				{
					case MSG_FLAG_ENUM::STANDARD:
						std::cout << pHead << ' ';
						break;
					case MSG_FLAG_ENUM::TAB:
						std::cout << pHead << '\t';
						break;
					case MSG_FLAG_ENUM::LOG:
						std::clog << pHead << ' ';
						break;
					case MSG_FLAG_ENUM::ERROR:
						std::cerr << pHead << ' ';
						break;
					case MSG_FLAG_ENUM::EVERY_JUMP:
						std::cout << pHead << std::endl;
						break;
					case MSG_FLAG_ENUM::NO_JUMP:
						std::cout << pHead << ' ';
						break;
					case MSG_FLAG_ENUM::CONCAT:
						std::cout << pHead;
						break;
					case MSG_FLAG_ENUM::RED:
						std::cout << "\033[31m" << pHead << "\033[0m ";
						break;
					case MSG_FLAG_ENUM::GREEN:
						std::cout << "\033[32m" << pHead << "\033[0m ";
						break;
					case MSG_FLAG_ENUM::BLUE:
						std::cout << "\033[34m" << pHead << "\033[0m ";
						break;
					default:
						break;
				}	

				if (sizeof...(pTail))
					Msg_Spe(pFlag, pTail...);
				else
					Msg_Spe(pFlag, pHead);
			}

		private:

			/**
			 * \brief 	Type du message à afficher.
			 */
			const MSG_FLAG_ENUM mFlag;

	};

}

#endif
