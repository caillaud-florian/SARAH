/**
 * \file		Observer.hpp
 * \author		fcaillaud
 * \version 	1.0
 * \date     	28 Mars 2014
 * \brief     	Fichier décrivant la classe abstraite Observer.
 * \detail 		Classe utilisée dans l'élaboration du design pattern Observer/Observable
 *				et plus largement dans le design pattern MVC.
 */

#ifndef OBSERVER
#define OBSERVER

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
	 * \class 	Observer
	 * \brief	Classe Observer (abstraite) servant pour l'élaboration du design pattern Observer/Observable.
	 *			Le type de notification est un template.
	 */
	template <typename _NotificationType = std::string>
	class Observer
	{

		public:

			/**
			 * \fn 		Mise à jour de l'instance Observer par une instance Observable.
			 * \param 	p_notification		Notification apportée à l'Observer (type template).
			 */
			virtual void Update(_NotificationType p_notification) = 0;
		
	};

}
}

#endif
