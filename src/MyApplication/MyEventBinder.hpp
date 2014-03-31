/**
 * \file		GraphicHandler.hpp
 * \author		fcaillaud
 * \version 	1.0
 * \date     	31 Mars 2014
 * \brief     	Fichier décrivant la classe GraphicHandler.
 * \details		Classe utilisée pour personnaliser la gestion d'évènement de la plateforme.
 */

#ifndef MYEVENT_BINDER
#define MYEVENT_BINDER

#include "../Kernel/EventBinder.hpp"

/**
 * \namespace 	Sarah
 * \brief 		Nom de domaine principal.
 */
namespace Sarah
{

	/**
	 * \class 	MyEventBinder
	 * \brief 	Personnalisation de la classe EventBinder.
	 */
	class MyEventBinder : public Kernel::EventBinder
	{

		public:

			/**
			 * Constructeur paramétré.
			 * \param 	p_graphicHandler 	Gestionnaire des fenêtres d'où viennent les actions.
			 * \param 	p_modelHandler 		Gestionnaire des structures de données et classes de traitement
			 *								vers où vont aller les réactions.
			 */
			MyEventBinder(Kernel::GraphicHandler &, Kernel::ModelHandler &);

		protected:

			/**
			 * Réaction à l'action de fermeture de la fenêtre.
			 */
			void BindClosedEvent();

			/**
			 * Réaction à l'action de redimensionnement de la fenêtre.
			 */
			void BindResizedEvent(int, int);

			/**
			 * Réaction à l'action de frappe de texte complexe.
			 */
			void BindTextEnteredEvent(sf::Uint32);

			/**
			 * Réaction à l'action de pression d'une touche de clavier.
			 */
			void BindKeyPressedEvent(sf::Keyboard::Key, bool, bool, bool, bool);

			/**
			 * Réaction à l'action de pression d'un bouton de la souris.
			 */
			void BindMouseButtonPressedEvent(sf::Mouse::Button, int, int);

	};

}

#endif
