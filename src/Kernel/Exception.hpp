/**
 * \file		Exception.hpp
 * \author		fcaillaud
 * \version 	1.0
 * \date     	28 Mars 2014
 * \brief     	Fichier décrivant la classe Exception.
 * \details		Classe utilisée comme spécialisation d'une std::exception.
 */

#ifndef EXCEPTION
#define EXCEPTION

#include <exception>
#include <string>

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
	 * \class 	Exception
	 * \brief 	Spécialisation d'une std::exception pour fournir un message d'erreur.
	 */
	class Exception : public std::exception
	{

		public:

			/**
			 * Constructeur par défaut.
			 */
			Exception():
				std::exception(),
				m_message("Unidentified exception !")
			{}

			/**
			 * Constructeur paramétré.
			 * \param 	p_str 	Le message d'erreur caractérisant l'exception.
			 */
			Exception(std::string p_str):
				std::exception(),
				m_message(p_str)
			{}

			/**
			 * Destructeur.
			 */
			~Exception() throw()
			{}

			/**
			 * Récupération du message d'erreur m_message.
			 * \details	Surcharge de la fonction what de std::exception.
			 * \return 	Une chaîne de caractère représentant le message d'erreur.
			 */
			virtual const char* what() const throw()
			{
				return m_message.c_str();
			}

		protected:

			/**
			 * \brief 	Message d'erreur caractérisant l'exception.
			 */
			std::string m_message;

	};

}
}

#endif