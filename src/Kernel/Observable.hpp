#ifndef OBSERVABLE_HPP
#define OBSERVABLE_HPP

#include <string>
#include <set>

#include "Observer.hpp"
#include "Exception.hpp"

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
	class Observable
	{

		public:

			typedef Observer<_NotificationType> * 						ObserverType;
			typedef typename std::set<ObserverType> 					ObserverContainerType;
			typedef typename ObserverContainerType::iterator			ObserverContainerIteratorType;

		public:

			void AddObserver(ObserverType p_obs)
			{
				if( ! ( (m_observerSet.insert(p_obs)).second ) )
					throw Exception("Exception in Observer:AddObserver => Observer already present in observer set");
			}

			void RemoveObserver(ObserverType p_obs)
			{
				ObserverContainerIteratorType it = m_observerSet.find(p_obs);
				if(it != m_observerSet.end())
					m_observerSet.erase(it);
				else
					throw Exception("Exception in Observer:RemoveObserver => Observer not present in observer set");
			}

			void RemoveAllObservers()
			{
				m_observerSet.clear();
			}

			void Notify(ObserverType p_obs, _NotificationType p_notification)
			{ObserverContainerIteratorType it = m_observerSet.find(p_obs);
				if(it != m_observerSet.end())
					(*it)->Update(p_notification);
				else
					throw Exception("Exception in Observer:RemoveObserver => Observer not present in observer set");
			}

			void NotifyAll(_NotificationType p_notification)
			{
				for(ObserverContainerIteratorType it = m_observerSet.begin();
				    it != m_observerSet.end(); ++it)
				{
					(*it)->Update(p_notification);
				}
			}

		private:

			ObserverContainerType m_observerSet;

	};

}
}

#endif