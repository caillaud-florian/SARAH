#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP

#include <exception>
#include <string>

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

	class Exception : public std::exception
	{
		public:

			Exception():
				std::exception(),
				m_message("Unidentified exception !")
			{}

			Exception(std::string str):
				std::exception(),
				m_message(str)
			{}

			~Exception() throw()
			{}

			virtual const char* what() const throw()
			{
				return m_message.c_str();
			}

		protected:

			std::string m_message;

	};

}
}

#endif