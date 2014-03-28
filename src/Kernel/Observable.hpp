/**
 * \file		Observable.hpp
 * \author		fcaillaud
 * \version 	1.0
 * \date     	28 Mars 2014
 * \brief     	Fichier décrivant la classe abstraite Observer.
 * \detail 		Classe utilisée dans l'élaboration du design pattern Observer/Observable
 *				et plus largement dans le design pattern MVC.
 */

#ifndef OBSERVABLE
#define OBSERVABLE

#include <string>
#include <set>

#include "Observer.hpp"
#include "Exception.hpp"

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
	 * \class 	Observable
	 * \brief	Classe Observable servant pour l'élaboration du design pattern Observer/Observable.
	 *			Le type de notification est un template.
	 */
	template <typename _NotificationType = std::string>
	class Observable
	{

		public:

			/**
			 * \typedef 	Pointeur sur le type construit d'Observer.
			 */
			typedef Observer<_NotificationType> * 						ObserverType;
			/**
			 * \typedef 	Container de pointeur sur Observer de type std::set.
			 */
			typedef typename std::set<ObserverType> 					ObserverContainerType;
			/**
			 * \typedef 	Iterateur sur le container de pointeur sur Observer.
			 */
			typedef typename ObserverContainerType::iterator			ObserverContainerIteratorType;

		public:

			/**
			 * \fn 		Ajout d'un pointeur sur Observer dans le container m_observerSet.
			 * \param 	p_obs		Pointeur sur un objet héritant du type Observer.
			 */
			void AddObserver(ObserverType p_obs)
			{
				if( ! ( (m_observerSet.insert(p_obs)).second ) )
					throw Exception("Exception in Observer:AddObserver => Observer already present in observer set");
			}

			/**
			 * \fn 		Suppression d'un pointeur sur Observer au sein du container m_observerSet.
			 * \param 	p_obs		Pointeur sur un objet héritant du type Observer.
			 */
			void RemoveObserver(ObserverType p_obs)
			{
				ObserverContainerIteratorType it = m_observerSet.find(p_obs);
				if(it != m_observerSet.end())
					m_observerSet.erase(it);
				else
					throw Exception("Exception in Observer:RemoveObserver => Observer not present in observer set");
			}

			/**
			 * \fn 		Suppression de tous les pointeurs sur Observer au sein du container m_observerSet.
			 */
			void RemoveAllObservers()
			{
				m_observerSet.clear();
			}

			/**
			 * \fn 		Notification à un observateur.
			 * \param 	p_obs			Pointeur sur l'objet héritant du type Observer à notifier.
			 * \param 	p_notification	Notification à transmettre à l'observateur p_obs (type template).
			 */
			void Notify(ObserverType p_obs, _NotificationType p_notification)
			{ObserverContainerIteratorType it = m_observerSet.find(p_obs);
				if(it != m_observerSet.end())
					(*it)->Update(p_notification);
				else
					throw Exception("Exception in Observer:RemoveObserver => Observer not present in observer set");
			}

			/**
			 * \fn 		Notification à tous les observateurs.
			 * \param 	p_notification	Notification à transmettre à tous les observateurs (type template).
			 */
			void NotifyAll(_NotificationType p_notification)
			{
				for(ObserverContainerIteratorType it = m_observerSet.begin();
				    it != m_observerSet.end(); ++it)
				{
					(*it)->Update(p_notification);
				}
			}

		private:

			/**
			 * \brief 	Le container de pointeurs sur Observer (de type std::set<ObserverType>).
			 */
			ObserverContainerType m_observerSet;

	};

}
}

#endif
