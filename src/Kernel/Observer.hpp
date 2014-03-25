#ifndef OBSERVER_HPP
#define OBSERVER_HPP

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

	template <typename _NotificationType = std::string>
	class Observer
	{
		public:

			virtual void Update(_NotificationType p_notification) = 0;
		
	};

}
}

#endif