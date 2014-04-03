/**
 * \file		Vector.hpp
 * \author		fcaillaud
 * \version 	1.0
 * \date     	2 Avril 2014
 * \brief     	Fichier décrivant la classe Vector.
 * \details		Classe représentant un vecteur géométrique.
 * \todo 		Pourquoi ne pas utiliter l'héritage ->
 *				un HVertex est un Vertex avec un coordonnée en plus et un Vertex est un 
 *				Vertex2D avec une coordonnée en plus. Plus les redéfinitions de fonction qui vont bien.
 *				ATTENTION au imprécision numérique pour les opérateurs de comparaison !!
 */

#ifndef GEOMETRY_VECTOR
#define GEOMETRY_VECTOR

#include <iostream>
#include <cmath>

#include "Vertex.hpp"

/**
 * \namespace 	geo
 * \brief 		Nom de domaine tertiaire, partie utilitaire.
 * \todo 		Migrer vers le namespace gu.
 */
namespace geo
{

	/**
	 * \enum 	VECTOR_TYPE
	 * \brief 	Type du vecteur.
	 */
	enum VECTOR_TYPE
	{
		VR_ZERO,	/*!< Vecteur nul. */
		VR_IDENT	/*!< Vecteur dont toutes les coordonnées sont à 1. */
	};

	/**
	 * \class 	Vect2D
	 * \brief 	Classe représentant un vecteur dans un espace 2D.
	 */
	class Vect2D
	{

		public:

			/**
			 * Constructeur par défaut.
			 * \details Initialise les coordonnées à 0.
			 */
			Vect2D();

			/**
			 * Constructeur paramétré.
			 * \param 	pX 	La coordonnée x du vecteur.
			 * \param 	pY 	La coordonnée y du vecteur.
			 */
			Vect2D(double, double);

			/**
			 * Constructeur paramétré.
			 * \param 	pVectType 	Le type du vecteur voulu.
			 */
			Vect2D(VECTOR_TYPE);

			/**
			 * Constructeur paramétré.
			 * \param 	pVertexA 	Le premier Vertex2D (base du vecteur).
			 * \param 	pVertexB 	Le deuxième Vertex2D (pointe du vecteur).
			 */
			Vect2D(Vertex2D, Vertex2D);

			/**
			 * Destructeur.
			 */
			~Vect2D();

			/**
			 * Récupération de la coordonnée x du vecteur.
			 * \return La coordonnée x du vecteur.
			 */
			double GetX();

			/**
			 * Récupération de la coordonnée y du vecteur.
			 * \return La coordonnée y du vecteur.
			 */
			double GetY();

			/**
			 * Changement de la coordonnée x du vecteur.
			 * \param 	pX 	 La nouvelle coordonnée x du vecteur.
			 */
			void SetX(double);

			/**
			 * Changement de la coordonnée y du vecteur.
			 * \param 	pY 	 La nouvelle coordonnée y du vecteur.
			 */
			void SetY(double);

			/**
			 * Récupération de la coordonnée du vecteur à l'indice voulu.
			 * \param 	pInd 	L'indice de la coordonnée voulue.
			 * \return La coordonnée du vecteur à l'indice pInd.
			 */
			double& operator [](int);

			/**
			 * Récupération de la coordonnée du vecteur au nom voulu.
			 * \param 	pCoord 	Le nom de la coordonnée voulue (x ou y).
			 * \return La coordonnée du vecteur au nom pCoord.
			 */
			double& operator ()(char);

			/**
			 * Vérification d'infériorité stricte entre deux Vect2D.
			 * \param 	pVect 	Le deuxième vertex à tester.
			 * \return 	true si pVect est plus grand, false sinon.
			 * \details	Le test s'effectue sur la longueur du vecteur.
			 */
			bool operator <(Vect2D);

			/**
			 * Vérification de supériorité stricte entre deux Vect2D.
			 * \param 	pVect 	Le deuxième vertex à tester.
			 * \return 	true si pVect est plus petit, false sinon.
			 * \details	Le test s'effectue sur la longueur du vecteur.
			 */
			bool operator >(Vect2D);

			/**
			 * Vérification d'infériorité entre deux Vect2D.
			 * \param 	pVect 	Le deuxième vertex à tester.
			 * \return 	true si pVect est plus grand ou égal, false sinon.
			 * \details	Le test s'effectue sur la longueur du vecteur.
			 */
			bool operator <=(Vect2D);

			/**
			 * Vérification d'infériorité entre deux Vect2D.
			 * \param 	pVect 	Le deuxième vertex à tester.
			 * \return 	true si pVect est plus petit ou égal, false sinon.
			 * \details	Le test s'effectue sur la longueur du vecteur.
			 */
			bool operator >=(Vect2D);

			/**
			 * Vérification d'égalité entre deux Vect2D.
			 * \param 	pVect 	Le deuxième vertex à tester.
			 * \return 	true si pVect est égal, false sinon.
			 * \details	Le test s'effectue sur la longueur du vecteur.
			 */
			bool operator ==(Vect2D);

			/**
			 * Vérification d'inégalité entre deux Vect2D.
			 * \param 	pVect 	Le deuxième vertex à tester.
			 * \return 	true si pVect est inégal, false sinon.
			 * \details	Le test s'effectue sur la longueur du vecteur.
			 */
			bool operator !=(Vect2D);

			/**
			 * Addition avec un autre vecteur.
			 * \param 	pVect2D 	L'autre vecteur.
			 * \return	Le résultat de l'addition des deux vecteurs.
			 * \details	Additionne coordonnée par coordonnée.
			 */
			Vect2D operator +(Vect2D);

			/**
			 * Soustraction par un autre vecteur.
			 * \param 	pVect2D 	L'autre vecteur.
			 * \return	Le résultat de la soustraction des deux vecteurs.
			 * \details	Soustrait coordonnée par coordonnée.
			 */
			Vect2D operator -(Vect2D);

			/**
			 * Multiplication avec un autre vecteur.
			 * \param 	pVect2D 	L'autre vecteur.
			 * \return	Le résultat de la multiplication des deux vecteurs.
			 * \details	Multiplie coordonnée par coordonnée.
			 */
			double operator *(Vect2D);

			/**
			 * Récupère le pointeur sur les éléments du vecteur.
			 * \return 	Le pointeur sur les éléments du vecteur.
			 */
			double * SData();

			/**
			 * Calcul de la norme L2 entre la base et la pointe du vecteur.
			 * \return	La distance entre la base et la pointe du vecteur.
			 */
			double Length();

			/**
			 * Calcul de la norme L2 au carré entre la base et la pointe du vecteur.
			 * \return	La distance au carré entre la base et la pointe du vecteur.
			 * \details Le calcul est plus rapide car on ne calcule pas
			 *			la racine carré, au contraire de la fonction Length.
			 */
			double SqLength();

			/**
			 * Multiplication avec un scalaire.
			 * \param 	pVect2D 	Le vecteur.
			 * \param 	pFactor 	Le scalaire.
			 * \return	Le résultat de la multiplication du vecteur par le scalaire.
			 */
			friend Vect2D operator *(Vect2D, double);

			/**
			 * Multiplication avec un scalaire.
			 * \param 	pFactor 	Le scalaire.
			 * \param 	pVect2D 	Le vecteur.
			 * \return	Le résultat de la multiplication du vecteur par le scalaire.
			 */
			friend Vect2D operator *(double, Vect2D);

			/**
			 * Division par un scalaire.
			 * \param 	pVect2D 	Le vecteur.
			 * \param 	pFactor 	Le scalaire.
			 * \return	Le résultat de la division du vecteur par le scalaire.
			 */
			friend Vect2D operator /(Vect2D, double);

			/**
			 * Calcul de la puissance entre deux vecteurs.
			 * \param 	pVec2DA 	Le premier vecteur.
			 * \param 	pVec2DB 	Le deuxième vecteur.
			 * \return 	La puissance entre pVec2DA et pVec2DB.
			 * \todo 	Retrouver un sens à cette série de fonctions.
			 */
			friend double Power(Vect2D, Vect2D);

			/**
			 * Calcul de la puissance absolue entre deux vecteurs.
			 * \param 	pVec2DA 	Le premier vecteur.
			 * \param 	pVec2DB 	Le deuxième vecteur.
			 * \return 	La puissance absolue entre pVec2DA et pVec2DB.
			 */
			friend double UnPower(Vect2D, Vect2D);

			/**
			 * Calcul de la puissance entre un vecteur et un vertex.
			 * \param 	pVec2D 		Le vecteur.
			 * \param 	pVertex2D 	Le vertex.
			 * \return 	La puissance entre pVec2D et pVertex2D.
			 */
			friend double Power(Vect2D, Vertex2D);

			/**
			 * Calcul de la puissance absolue entre un vecteur et un vertex.
			 * \param 	pVec2D 		Le vecteur.
			 * \param 	pVertex2D 	Le vertex.
			 * \return 	La puissance absolue entre pVec2D et pVertex2D.
			 */
			friend double UnPower(Vect2D, Vertex2D);

		private:

			/**
			 * \brief 	Coordonnée x du vecteur.
			 */
			double x;

			/**
			 * \brief 	Coordonnée y du vecteur.
			 */
			double y;
			
	};

	/**
	 * \class 	Vect
	 * \brief 	Classe représentant un vecteur dans un espace 3D.
	 */
	class Vect
	{

		public:

			/**
			 * Constructeur par défaut.
			 * \details Initialise les coordonnées à 0.
			 */
			Vect();

			/**
			 * Constructeur paramétré.
			 * \param 	pX 	La coordonnée x du vecteur.
			 * \param 	pY 	La coordonnée y du vecteur.
			 * \param 	pZ 	La coordonnée z du vecteur.
			 */
			Vect(double, double, double);

			/**
			 * Constructeur paramétré.
			 * \param 	pV2D 	Le vecteur correspondant aux coordonnées x et y du vecteur.
			 * \param 	pZ 		La coordonnée z du vecteur.
			 */
			Vect(Vect2D, double);

			/**
			 * Constructeur paramétré.
			 * \param 	pVectType 	Le type du vecteur voulu.
			 */
			Vect(VECTOR_TYPE);

			/**
			 * Constructeur paramétré.
			 * \param 	pVertexA 	Le premier Vertex (base du vecteur).
			 * \param 	pVertexB 	Le deuxième Vertex (pointe du vecteur).
			 */
			Vect(Vertex, Vertex);

			/**
			 * Destructeur.
			 */
			~Vect();

			/**
			 * Récupération de la coordonnée x du vecteur.
			 * \return La coordonnée x du vecteur.
			 */
			double GetX();

			/**
			 * Récupération de la coordonnée y du vecteur.
			 * \return La coordonnée y du vecteur.
			 */
			double GetY();

			/**
			 * Récupération de la coordonnée z du vecteur.
			 * \return La coordonnée z du vecteur.
			 */
			double GetZ();

			/**
			 * Changement de la coordonnée x du vecteur.
			 * \param 	pX 	 La nouvelle coordonnée x du vecteur.
			 */
			void SetX(double);

			/**
			 * Changement de la coordonnée y du vecteur.
			 * \param 	pY 	 La nouvelle coordonnée y du vecteur.
			 */
			void SetY(double);

			/**
			 * Changement de la coordonnée z du vecteur.
			 * \param 	pZ 	 La nouvelle coordonnée z du vecteur.
			 */
			void SetZ(double);

			/**
			 * Récupération de la coordonnée du vecteur à l'indice voulu.
			 * \param 	pInd 	L'indice de la coordonnée voulue.
			 * \return La coordonnée du vecteur à l'indice pInd.
			 */
			double& operator [](int);

			/**
			 * Récupération de la coordonnée du vecteur au nom voulu.
			 * \param 	pCoord 	Le nom de la coordonnée voulue (x, y ou z).
			 * \return La coordonnée du vecteur au nom pCoord.
			 */
			double& operator ()(char);

			/**
			 * Vérification d'infériorité stricte entre deux Vect.
			 * \param 	pVect 	Le deuxième vertex à tester.
			 * \return 	true si pVect est plus grand, false sinon.
			 * \details	Le test s'effectue sur la longueur du vecteur.
			 */
			bool operator <(Vect);

			/**
			 * Vérification de supériorité stricte entre deux Vect.
			 * \param 	pVect 	Le deuxième vertex à tester.
			 * \return 	true si pVect est plus petit, false sinon.
			 * \details	Le test s'effectue sur la longueur du vecteur.
			 */
			bool operator >(Vect);

			/**
			 * Vérification d'infériorité entre deux Vect.
			 * \param 	pVect 	Le deuxième vertex à tester.
			 * \return 	true si pVect est plus grand ou égal, false sinon.
			 * \details	Le test s'effectue sur la longueur du vecteur.
			 */
			bool operator <=(Vect);

			/**
			 * Vérification d'infériorité entre deux Vect.
			 * \param 	pVect 	Le deuxième vertex à tester.
			 * \return 	true si pVect est plus petit ou égal, false sinon.
			 * \details	Le test s'effectue sur la longueur du vecteur.
			 */
			bool operator >=(Vect);

			/**
			 * Vérification d'égalité entre deux Vect.
			 * \param 	pVect 	Le deuxième vertex à tester.
			 * \return 	true si pVect est égal, false sinon.
			 * \details	Le test s'effectue sur la longueur du vecteur.
			 */
			bool operator ==(Vect);

			/**
			 * Vérification d'inégalité entre deux Vect.
			 * \param 	pVect 	Le deuxième vertex à tester.
			 * \return 	true si pVect est inégal, false sinon.
			 * \details	Le test s'effectue sur la longueur du vecteur.
			 */
			bool operator !=(Vect);

			/**
			 * Addition avec un autre vecteur.
			 * \param 	pVect   	L'autre vecteur.
			 * \return	Le résultat de l'addition des deux vecteurs.
			 * \details	Additionne coordonnée par coordonnée.
			 */
			Vect operator +(Vect);

			/**
			 * Soustraction par un autre vecteur.
			 * \param 	pVect   	L'autre vecteur.
			 * \return	Le résultat de la soustraction des deux vecteurs.
			 * \details	Soustrait coordonnée par coordonnée.
			 */
			Vect operator -(Vect);

			/**
			 * Multiplication avec un autre vecteur.
			 * \param 	pVect   	L'autre vecteur.
			 * \return	Le résultat de la multiplication des deux vecteurs.
			 * \details	Multiplie coordonnée par coordonnée.
			 */
			double operator *(Vect);

			/**
			 * Multiplication vectorielle avec un autre vecteur.
			 * \param 	pVect   	L'autre vecteur.
			 * \return	Le résultat du produit vectoriel des deux vecteurs.
			 */
			Vect operator ^(Vect);

			/**
			 * Récupère le pointeur sur les éléments du vecteur.
			 * \return 	Le pointeur sur les éléments du vecteur.
			 */
			double * SData();

			/**
			 * Calcul de la norme L2 entre la base et la pointe du vecteur.
			 * \return	La distance entre la base et la pointe du vecteur.
			 */
			double Length();

			/**
			 * Calcul de la norme L2 au carré entre la base et la pointe du vecteur.
			 * \return	La distance au carré entre la base et la pointe du vecteur.
			 * \details Le calcul est plus rapide car on ne calcule pas
			 *			la racine carré, au contraire de la fonction Length.
			 */
			double SqLength();

			/**
			 * Multiplication avec un scalaire.
			 * \param 	pVect   	Le vecteur.
			 * \param 	pFactor 	Le scalaire.
			 * \return	Le résultat de la multiplication du vecteur par le scalaire.
			 */
			friend Vect operator *(Vect, double);

			/**
			 * Multiplication avec un scalaire.
			 * \param 	pFactor 	Le scalaire.
			 * \param 	pVect   	Le vecteur.
			 * \return	Le résultat de la multiplication du vecteur par le scalaire.
			 */
			friend Vect operator *(double, Vect);

			/**
			 * Division par un scalaire.
			 * \param 	pVect   	Le vecteur.
			 * \param 	pFactor 	Le scalaire.
			 * \return	Le résultat de la division du vecteur par le scalaire.
			 */
			friend Vect operator /(Vect, double);

		private:

			
			/**
			 * \brief 	Coordonnée x du vecteur.
			 */
			double x;
			
			/**
			 * \brief 	Coordonnée y du vecteur.
			 */
			double y;

			/**
			 * \brief 	Coordonnée z du vecteur.
			 */
			double z;

	};

}

#endif