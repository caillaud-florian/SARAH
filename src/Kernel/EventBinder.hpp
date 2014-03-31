/**
 * \file		EventBinder.hpp
 * \author		fcaillaud
 * \version 	1.0
 * \date     	28 Mars 2014
 * \brief     	Fichier décrivant la classe EventBinder.
 * \details		Classe utilisée comme base de la gestion d'évènements au sein de SARAH. Elle permet
 *				de gérer l'ensemble des actions engendrées par l'utilisateur. Il est conseillé 
 *				d'hériter de cette classe pour personnalisé son fonctionnement tout	en usant de la 
 *				structure qu'il forme au sein de ControlerHandler.
 */

#ifndef EVENTBINDER
#define EVENTBINDER

#include <SFML/Window.hpp>

#include "GraphicHandler.hpp"
#include "ModelHandler.hpp"

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
	 * \class 	EventBinder
	 * \brief	Classe donnant une base à la gestion d'évènement pour la plateforme SARAH.
	 */
	class EventBinder
	{

		public:

			/**
			 * Constructeur paramétré.
			 * \param 	p_graphicHandler 	Gestionnaire des fenêtres d'où viennent les actions.
			 * \param 	p_modelHandler 		Gestionnaire des structures de données et classes de traitement
			 *								vers où vont aller les réactions.
			 */
			EventBinder(GraphicHandler &, ModelHandler &);

			/**
			 * Choix de la fonction Bind... en fonction de l'action courante reçue.
			 */
			virtual void Bind();

			/**
			 * Test sur l'état de pause de la fenêtre sélectionnée du GraphicHandler.
			 * \return 	true si elle est en pause, false sinon.
			 * \todo 	Voir si c'est bien compatible avec plusieurs fenêtres (peut être un EventBinder par fenêtre).
			 */
			bool IsPaused();

		protected:

			/**
			 * Récupération de la fenêtre sélectionnée du GraphicHandler.
			 * \return	La fenêtre sélectionnée du GraphicHandler (de type SFML::Window).
			 * \todo 	Cette fonction devrait être dans GraphicHandler ce qui éviterait une relation d'ami. 
			 */
			sf::Window & GetFocusedWindow();

			/**
			 * Réaction à l'action de fermeture de la fenêtre (virtuelle).
			 * \details	Si nécessaire il est possible de redefinir cette fonction dans une classe dérivée de 
			 *			EventBinder	afin de personnaliser son fonctionnement.
			 */
			virtual void BindClosedEvent();

			/**
			 * Réaction à l'action de redimensionnement de la fenêtre (virtuelle).
			 * \details	Si nécessaire il est possible de redefinir cette fonction dans une classe dérivée de 
			 *			EventBinder	afin de personnaliser son fonctionnement.
			 */
			virtual void BindResizedEvent(int, int);

			/**
			 * Réaction à l'action de perte de sélection de la fenêtre (virtuelle).
			 * \details	Si nécessaire il est possible de redefinir cette fonction dans une classe dérivée de 
			 *			EventBinder	afin de personnaliser son fonctionnement.
			 */
			virtual void BindLostFocusEvent();

			/**
			 * Réaction à l'action de gain de sélection de la fenêtre (virtuelle).
			 * \details	Si nécessaire il est possible de redefinir cette fonction dans une classe dérivée de 
			 *			EventBinder	afin de personnaliser son fonctionnement.
			 */
			virtual void BindGainedFocusEvent();

			/**
			 * Réaction à l'action de frappe de texte complexe (virtuelle).
			 * \details	Si nécessaire il est possible de redefinir cette fonction dans une classe dérivée de 
			 *			EventBinder	afin de personnaliser son fonctionnement.
			 */
			virtual void BindTextEnteredEvent(sf::Uint32);

			/**
			 * Réaction à l'action de pression d'une touche de clavier (virtuelle).
			 * \details	Si nécessaire il est possible de redefinir cette fonction dans une classe dérivée de 
			 *			EventBinder	afin de personnaliser son fonctionnement.
			 */
			virtual void BindKeyPressedEvent(sf::Keyboard::Key, bool, bool, bool, bool);

			/**
			 * Réaction à l'action de relâchement d'une touche de clavier (virtuelle).
			 * \details	Si nécessaire il est possible de redefinir cette fonction dans une classe dérivée de 
			 *			EventBinder	afin de personnaliser son fonctionnement.
			 */
			virtual void BindKeyReleasedEvent(sf::Keyboard::Key, bool, bool, bool, bool);

			/**
			 * Réaction à l'action de roulement de la molette de souris (virtuelle).
			 * \details	Si nécessaire il est possible de redefinir cette fonction dans une classe dérivée de 
			 *			EventBinder	afin de personnaliser son fonctionnement.
			 */
			virtual void BindMouseWheelMovedEvent(int, int, int);

			/**
			 * Réaction à l'action de pression d'un bouton de la souris (virtuelle).
			 * \details	Si nécessaire il est possible de redefinir cette fonction dans une classe dérivée de 
			 *			EventBinder	afin de personnaliser son fonctionnement.
			 */
			virtual void BindMouseButtonPressedEvent(sf::Mouse::Button, int, int);

			/**
			 * Réaction à l'action de relâchement d'un bouton de la souris (virtuelle).
			 * \details	Si nécessaire il est possible de redefinir cette fonction dans une classe dérivée de 
			 *			EventBinder	afin de personnaliser son fonctionnement.
			 */
			virtual void BindMouseButtonReleasedEvent(sf::Mouse::Button, int, int);

			/**
			 * Réaction à l'action de mouvement de la souris (virtuelle).
			 * \details	Si nécessaire il est possible de redefinir cette fonction dans une classe dérivée de 
			 *			EventBinder	afin de personnaliser son fonctionnement.
			 */
			virtual void BindMouseMovedEvent(int, int);

			/**
			 * Réaction à l'action de la souris d'entrée dans la fenêtre (virtuelle).
			 * \details	Si nécessaire il est possible de redefinir cette fonction dans une classe dérivée de 
			 *			EventBinder	afin de personnaliser son fonctionnement.
			 */
			virtual void BindMouseEnteredEvent();

			/**
			 * Réaction à l'action de la souris de sortir de la fenêtre (virtuelle).
			 * \details	Si nécessaire il est possible de redefinir cette fonction dans une classe dérivée de 
			 *			EventBinder	afin de personnaliser son fonctionnement.
			 */
			virtual void BindMouseLeftEvent();

			/**
			 * Réaction à l'action de pression d'un bouton sur un joystick (virtuelle).
			 * \details	Si nécessaire il est possible de redefinir cette fonction dans une classe dérivée de 
			 *			EventBinder	afin de personnaliser son fonctionnement.
			 * \todo 	Fonction pas finie d'implémenter. Il manque des attributs fournis par la SFML.
			 */
			virtual void BindJoystickButtonPressedEvent();

			/**
			 * Réaction à l'action de relâchement d'un bouton sur un joystick (virtuelle).
			 * \details	Si nécessaire il est possible de redefinir cette fonction dans une classe dérivée de 
			 *			EventBinder	afin de personnaliser son fonctionnement.
			 * \todo 	Fonction pas finie d'implémenter. Il manque des attributs fournis par la SFML.
			 */
			virtual void BindJoystickButtonReleasedEvent();

			/**
			 * Réaction à l'action de mouvement d'un joystick (virtuelle).
			 * \details	Si nécessaire il est possible de redefinir cette fonction dans une classe dérivée de 
			 *			EventBinder	afin de personnaliser son fonctionnement.
			 * \todo 	Fonction pas finie d'implémenter. Il manque des attributs fournis par la SFML.
			 */
			virtual void BindJoystickMovedEvent();

			/**
			 * Réaction à l'action de connection d'un joystick (virtuelle).
			 * \details	Si nécessaire il est possible de redefinir cette fonction dans une classe dérivée de 
			 *			EventBinder	afin de personnaliser son fonctionnement.
			 * \todo 	Fonction pas finie d'implémenter. Il manque des attributs fournis par la SFML.
			 */
			virtual void BindJoystickConnectedEvent();

			/**
			 * Réaction à l'action de déconnection d'un joystick (virtuelle).
			 * \details	Si nécessaire il est possible de redefinir cette fonction dans une classe dérivée de 
			 *			EventBinder	afin de personnaliser son fonctionnement.
			 * \todo 	Fonction pas finie d'implémenter. Il manque des attributs fournis par la SFML.
			 */
			virtual void BindJoystickDisconnectedEvent();

		protected:

			/**
			 * \brief 	Gestionnaire de la Vue.
			 */
			GraphicHandler & m_graphicHandler;

			/**
			 * \brief 	Gestionnaire du Modèle.
			 */
			ModelHandler & m_modelHandler;

			/**
			 * \brief 	État de pause ou non de la fenêtre sélectionnée.
			 * \details	Attribut utile pour mettre en pause l'exécution de la fenêtre lors d'une perte de sélection.
			 */
			bool m_pause;

	};

}
}

#endif
