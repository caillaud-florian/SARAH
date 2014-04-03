/**
 * \file		Vertex.hpp
 * \author		fcaillaud
 * \version 	1.0
 * \date     	2 Avril 2014
 * \brief     	Fichier décrivant la classe Vertex.
 * \details		Classe représentant un sommet géométrique.
 * \todo 		Ne parle-t-on pas ici de Point ?? Et pourquoi ne pas utiliter l'héritage ->
 *				un HVertex est un Vertex avec un coordonnée en plus et un Vertex est un 
 *				Vertex2D avec une coordonnée en plus. Plus les redéfinitions de fonction qui vont bien.
 */

#ifndef GEOMETRY_VERTEX
#define GEOMETRY_VERTEX

#include <iostream>
#include <cmath>

/**
 * \namespace 	geo
 * \brief 		Nom de domaine tertiaire, partie utilitaire.
 * \todo 		Migrer vers le namespace gu.
 */
namespace geo
{

	/**
	 * \enum 	VERTEX_TYPE
	 * \brief 	Type du vertex.
	 */
	enum VERTEX_TYPE
	{
		V_ZERO,		/*!< Vertex centré sur l'origine. */
		V_IDENT		/*!< Vertex dont toutes les coordonnées sont à 1. */
	};

	/**
	 * \class 	Vertex2D
	 * \brief 	Classe représentant un vertex dans un espace 2D.
	 */
	class Vertex2D
	{

		public:

			/**
			 * Constructeur par défaut.
			 * \details Initialise les coordonnées à 0.
			 */
			Vertex2D();

			/**
			 * Constructeur paramétré.
			 * \param 	pX 	La coordonnée x du vertex.
			 * \param 	pY 	La coordonnée y du vertex.
			 */
			Vertex2D(double, double);

			/**
			 * Constructeur paramétré.
			 * \param 	pVertexType 	Le type du vertex voulu.
			 */
			Vertex2D(VERTEX_TYPE);

			/**
			 * Destructeur.
			 */
			~Vertex2D();

			/**
			 * Récupération de la coordonnée x du vertex.
			 * \return La coordonnée x du vertex.
			 */
			double GetX();

			/**
			 * Récupération de la coordonnée y du vertex.
			 * \return La coordonnée y du vertex.
			 */
			double GetY();

			/**
			 * Changement de la coordonnée x du vertex.
			 * \param 	pX 	 La nouvelle coordonnée x du vertex.
			 */
			void SetX(double);

			/**
			 * Changement de la coordonnée y du vertex.
			 * \param 	pY 	 La nouvelle coordonnée y du vertex.
			 */
			void SetY(double);

			/**
			 * Récupération de la coordonnée du vertex à l'indice voulu.
			 * \param 	pInd 	L'indice de la coordonnée voulue.
			 * \return La coordonnée du vertex à l'indice pInd.
			 */
			double& operator [](int);

			/**
			 * Récupération de la coordonnée du vertex au nom voulu.
			 * \param 	pCoord 	Le nom de la coordonnée voulue (x ou y).
			 * \return La coordonnée du vertex au nom pCoord.
			 */
			double& operator ()(char);

			/**
			 * Vérification d'infériorité stricte entre deux Vertex2D.
			 * \param 	pVertex 	Le deuxième vertex à tester.
			 * \return 	true si pVertex est plus grand, false sinon.
			 * \details	Le test s'effectue dans l'ordre lexicographique
			 *			(sur les x, puis sur les y).
			 */
			bool operator <(Vertex2D);

			/**
			 * Vérification de supériorité stricte entre deux Vertex2D.
			 * \param 	pVertex 	Le deuxième vertex à tester.
			 * \return 	true si pVertex est plus petit, false sinon.
			 * \details	Le test s'effectue dans l'ordre lexicographique
			 *			(sur les x, puis sur les y).
			 */
			bool operator >(Vertex2D);

			/**
			 * Vérification d'infériorité entre deux Vertex2D.
			 * \param 	pVertex 	Le deuxième vertex à tester.
			 * \return 	true si pVertex est plus grand ou égal, false sinon.
			 * \details	Le test s'effectue dans l'ordre lexicographique
			 *			(sur les x, puis sur les y).
			 */
			bool operator <=(Vertex2D);

			/**
			 * Vérification d'infériorité entre deux Vertex2D.
			 * \param 	pVertex 	Le deuxième vertex à tester.
			 * \return 	true si pVertex est plus petit ou égal, false sinon.
			 * \details	Le test s'effectue dans l'ordre lexicographique
			 *			(sur les x, puis sur les y).
			 */
			bool operator >=(Vertex2D);

			/**
			 * Vérification d'égalité entre deux Vertex2D.
			 * \param 	pVertex 	Le deuxième vertex à tester.
			 * \return 	true si pVertex est égal, false sinon.
			 * \details	Le test s'effectue dans l'ordre lexicographique
			 *			(sur les x, puis sur les y).
			 */
			bool operator ==(Vertex2D);

			/**
			 * Vérification d'inégalité entre deux Vertex2D.
			 * \param 	pVertex 	Le deuxième vertex à tester.
			 * \return 	true si pVertex est inégal, false sinon.
			 * \details	Le test s'effectue dans l'ordre lexicographique
			 *			(sur les x, puis sur les y).
			 */
			bool operator !=(Vertex2D);

			/**
			 * Récupère le pointeur sur les éléments du vertex.
			 * \return 	Le pointeur sur les éléments du vertex.
			 */
			double * SData();

			/**
			 * Détermination du minimum entre deux Vertex2D.
			 * \param 	pVertexA 	Le premier vertex.
			 * \param 	pVertexB 	Le deuxième vertex.
			 * \return	Le minimum entre pVertexA et pVertexB.
			 * \details	Le test s'effectue dans l'ordre lexicographique
			 *			(sur les x, puis sur les y).
			 */
			friend Vertex2D Min(Vertex2D, Vertex2D);

			/**
			 * Détermination du maximum entre deux Vertex2D.
			 * \param 	pVertexA 	Le premier vertex.
			 * \param 	pVertexB 	Le deuxième vertex.
			 * \return	Le maximum entre pVertexA et pVertexB.
			 * \details	Le test s'effectue dans l'ordre lexicographique
			 *			(sur les x, puis sur les y).
			 */
			friend Vertex2D Max(Vertex2D, Vertex2D);

			/**
			 * Calcul de la norme L2 entre deux Vertex2D.
			 * \param 	pVertexA 	Le premier vertex.
			 * \param 	pVertexB 	Le deuxième vertex.
			 * \return	La distance entre pVertexA et pVertexB.
			 */
			friend double Distance(Vertex2D, Vertex2D);

			/**
			 * Calcul de la norme L2 au carré entre deux Vertex2D.
			 * \param 	pVertexA 	Le premier vertex.
			 * \param 	pVertexB 	Le deuxième vertex.
			 * \return	La distance au carré entre pVertexA et pVertexB.
			 * \details Le calcul est plus rapide car on ne calcule pas
			 *			la racine carré, au contraire de la fonction Distance.
			 */
			friend double SqDistance(Vertex2D, Vertex2D);

		private:

			/**
			 * \brief 	Coordonnnée x du vertex.
			 */
			double x;

			/**
			 * \brief 	Coordonnnée y du vertex.
			 */
			double y;
			
	};

	/**
	 * \class 	Vertex
	 * \brief 	Classe représentant un vertex dans un espace 3D.
	 */
	class Vertex
	{

		public:

			/**
			 * Constructeur par défaut.
			 * \details Initialise les coordonnées à 0.
			 */
			Vertex();

			/**
			 * Constructeur paramétré.
			 * \param 	pX 	La coordonnée x du vertex.
			 * \param 	pY 	La coordonnée y du vertex.
			 * \param 	pZ 	La coordonnée z du vertex.
			 */
			Vertex(double, double, double);

			/**
			 * Constructeur paramétré.
			 * \param 	pV2D 	Le Vertex2D représentant les coordonnées x et y du vertex.
			 * \param 	pZ 		La coordonnée z du vertex.
			 */
			Vertex(Vertex2D, double);

			/**
			 * Constructeur paramétré.
			 * \param 	pVertexType 	Le type du vertex voulu.
			 */
			Vertex(VERTEX_TYPE);

			/**
			 * Destructeur.
			 */
			~Vertex();

			/**
			 * Récupération de la coordonnée x du vertex.
			 * \return La coordonnée x du vertex.
			 */
			double GetX();

			/**
			 * Récupération de la coordonnée y du vertex.
			 * \return La coordonnée y du vertex.
			 */
			double GetY();

			/**
			 * Récupération de la coordonnée z du vertex.
			 * \return La coordonnée z du vertex.
			 */
			double GetZ();

			/**
			 * Changement de la coordonnée x du vertex.
			 * \param 	pX 	 La nouvelle coordonnée x du vertex.
			 */
			void SetX(double);

			/**
			 * Changement de la coordonnée y du vertex.
			 * \param 	pY 	 La nouvelle coordonnée y du vertex.
			 */
			void SetY(double);

			/**
			 * Changement de la coordonnée z du vertex.
			 * \param 	pZ 	 La nouvelle coordonnée z du vertex.
			 */
			void SetZ(double);

			/**
			 * Récupération de la coordonnée du vertex à l'indice voulu.
			 * \param 	pInd 	L'indice de la coordonnée voulue.
			 * \return La coordonnée du vertex à l'indice pInd.
			 */
			double& operator [](int);

			/**
			 * Récupération de la coordonnée du vertex au nom voulu.
			 * \param 	pCoord 	Le nom de la coordonnée voulue (x, y ou z).
			 * \return La coordonnée du vertex au nom pCoord.
			 */
			double& operator ()(char);

			/**
			 * Vérification d'infériorité stricte entre deux Vertex.
			 * \param 	pVertex 	Le deuxième vertex à tester.
			 * \return 	true si pVertex est plus grand, false sinon.
			 * \details	Le test s'effectue dans l'ordre lexicographique
			 *			(sur les x, puis sur les y, puis sur les z).
			 */
			bool operator <(Vertex);

			/**
			 * Vérification de supériorité stricte entre deux Vertex.
			 * \param 	pVertex 	Le deuxième vertex à tester.
			 * \return 	true si pVertex est plus petit, false sinon.
			 * \details	Le test s'effectue dans l'ordre lexicographique
			 *			(sur les x, puis sur les y, puis sur les z).
			 */
			bool operator >(Vertex);

			/**
			 * Vérification d'infériorité entre deux Vertex.
			 * \param 	pVertex 	Le deuxième vertex à tester.
			 * \return 	true si pVertex est plus grand ou égal, false sinon.
			 * \details	Le test s'effectue dans l'ordre lexicographique
			 *			(sur les x, puis sur les y, puis sur les z).
			 */
			bool operator <=(Vertex);

			/**
			 * Vérification d'infériorité entre deux Vertex.
			 * \param 	pVertex 	Le deuxième vertex à tester.
			 * \return 	true si pVertex est plus petit ou égal, false sinon.
			 * \details	Le test s'effectue dans l'ordre lexicographique
			 *			(sur les x, puis sur les y, puis sur les z).
			 */
			bool operator >=(Vertex);

			/**
			 * Vérification d'égalité entre deux Vertex.
			 * \param 	pVertex 	Le deuxième vertex à tester.
			 * \return 	true si pVertex est égal, false sinon.
			 * \details	Le test s'effectue dans l'ordre lexicographique
			 *			(sur les x, puis sur les y, puis sur les z).
			 */
			bool operator ==(Vertex);

			/**
			 * Vérification d'inégalité entre deux Vertex.
			 * \param 	pVertex 	Le deuxième vertex à tester.
			 * \return 	true si pVertex est inégal, false sinon.
			 * \details	Le test s'effectue dans l'ordre lexicographique
			 *			(sur les x, puis sur les y, puis sur les z).
			 */
			bool operator !=(Vertex);

			/**
			 * Récupère le pointeur sur les éléments du vertex.
			 * \return 	Le pointeur sur les éléments du vertex.
			 */
			double * SData();

			/**
			 * Détermination du minimum entre deux Vertex.
			 * \param 	pVertexA 	Le premier vertex.
			 * \param 	pVertexB 	Le deuxième vertex.
			 * \return	Le minimum entre pVertexA et pVertexB.
			 * \details	Le test s'effectue dans l'ordre lexicographique
			 *			(sur les x, puis sur les y, puis sur les z).
			 */
			friend Vertex Min(Vertex, Vertex);

			/**
			 * Détermination du maximum entre deux Vertex.
			 * \param 	pVertexA 	Le premier vertex.
			 * \param 	pVertexB 	Le deuxième vertex.
			 * \return	Le maximum entre pVertexA et pVertexB.
			 * \details	Le test s'effectue dans l'ordre lexicographique
			 *			(sur les x, puis sur les y, puis sur les z).
			 */
			friend Vertex Max(Vertex, Vertex);

			/**
			 * Calcul de la norme L2 entre deux Vertex.
			 * \param 	pVertexA 	Le premier vertex.
			 * \param 	pVertexB 	Le deuxième vertex.
			 * \return	La distance entre pVertexA et pVertexB.
			 */
			friend double Distance(Vertex, Vertex);

			/**
			 * Calcul de la norme L2 au carré entre deux Vertex.
			 * \param 	pVertexA 	Le premier vertex.
			 * \param 	pVertexB 	Le deuxième vertex.
			 * \return	La distance au carré entre pVertexA et pVertexB.
			 * \details Le calcul est plus rapide car on ne calcule pas
			 *			la racine carré, au contraire de la fonction Distance.
			 */
			friend double SqDistance(Vertex, Vertex);

		private:

			/**
			 * \brief 	Coordonnée x du vertex.
			 */			
			double x;

			/**
			 * \brief 	Coordonnée y du vertex.
			 */			
			double y;

			/**
			 * \brief 	Coordonnée z du vertex.
			 */
			double z;

	};
	
	/**
	 * \class 	HVertex
	 * \brief 	Classe représentant un vertex homogène.
	 */
	class HVertex
	{

		public:

			/**
			 * Constructeur par défaut.
			 * \details Initialise les coordonnées à 0 (sauf h, à 1).
			 */
			HVertex();

			/**
			 * Constructeur paramétré.
			 * \param 	pX 	La coordonnée x du vertex.
			 * \param 	pY 	La coordonnée y du vertex.
			 * \param 	pZ 	La coordonnée z du vertex.
			 * \param 	pH 	La coordonnée h du vertex.
			 */
			HVertex(double, double, double, double);

			/**
			 * Constructeur paramétré.
			 * \param 	pV 	Le Vertex représentant les coordonnées x, y et z du vertex.
			 * \param 	pH 	La coordonnée h du vertex.
			 */
			HVertex(Vertex, double);

			/**
			 * Constructeur paramétré.
			 * \param 	pV2D 	Le Vertex2D représentant les coordonnées x et y du vertex.
			 * \param 	pZ 		La coordonnée z du vertex.
			 * \param 	pH 	La coordonnée h du vertex.
			 */
			HVertex(Vertex2D, double, double);

			/**
			 * Constructeur paramétré.
			 * \param 	pVertexType 	Le type du vertex voulu.
			 */
			HVertex(VERTEX_TYPE);

			/**
			 * Destructeur.
			 */
			~HVertex();

			/**
			 * Récupération de la coordonnée x du vertex.
			 * \return La coordonnée x du vertex.
			 */
			double GetX();

			/**
			 * Récupération de la coordonnée y du vertex.
			 * \return La coordonnée y du vertex.
			 */
			double GetY();

			/**
			 * Récupération de la coordonnée z du vertex.
			 * \return La coordonnée z du vertex.
			 */
			double GetZ();

			/**
			 * Récupération de la coordonnée h du vertex.
			 * \return La coordonnée h du vertex.
			 */
			double GetH();

			/**
			 * Changement de la coordonnée x du vertex.
			 * \param 	pX 	 La nouvelle coordonnée x du vertex.
			 */
			void SetX(double);

			/**
			 * Changement de la coordonnée y du vertex.
			 * \param 	pY 	 La nouvelle coordonnée y du vertex.
			 */
			void SetY(double);

			/**
			 * Changement de la coordonnée z du vertex.
			 * \param 	pZ 	 La nouvelle coordonnée z du vertex.
			 */
			void SetZ(double);

			/**
			 * Changement de la coordonnée h du vertex.
			 * \param 	pH 	 La nouvelle coordonnée h du vertex.
			 */
			void SetH(double);

			/**
			 * Récupération de la coordonnée du vertex à l'indice voulu.
			 * \param 	pInd 	L'indice de la coordonnée voulue.
			 * \return La coordonnée du vertex à l'indice pInd.
			 */
			double& operator [](int);

			/**
			 * Récupération de la coordonnée du vertex au nom voulu.
			 * \param 	pCoord 	Le nom de la coordonnée voulue (x, y, z ou h).
			 * \return La coordonnée du vertex au nom pCoord.
			 */
			double& operator ()(char);

			/**
			 * Vérification d'infériorité stricte entre deux Vertex.
			 * \param 	pVertex 	Le deuxième vertex à tester.
			 * \return 	true si pVertex est plus grand, false sinon.
			 * \details	Le test s'effectue dans l'ordre lexicographique
			 *			(sur les x, puis sur les y, puis sur les z).
			 */
			bool operator <(HVertex);

			/**
			 * Vérification de supériorité stricte entre deux Vertex.
			 * \param 	pVertex 	Le deuxième vertex à tester.
			 * \return 	true si pVertex est plus petit, false sinon.
			 * \details	Le test s'effectue dans l'ordre lexicographique
			 *			(sur les x, puis sur les y, puis sur les z), après
			 *			avoir passé les HVertex en coordonnées cartésiennes
			 *			(Vertex).
			 */
			bool operator >(HVertex);

			/**
			 * Vérification d'infériorité entre deux Vertex.
			 * \param 	pVertex 	Le deuxième vertex à tester.
			 * \return 	true si pVertex est plus grand ou égal, false sinon.
			 * \details	Le test s'effectue dans l'ordre lexicographique
			 *			(sur les x, puis sur les y, puis sur les z), après
			 *			avoir passé les HVertex en coordonnées cartésiennes
			 *			(Vertex).
			 */
			bool operator <=(HVertex);

			/**
			 * Vérification d'infériorité entre deux Vertex.
			 * \param 	pVertex 	Le deuxième vertex à tester.
			 * \return 	true si pVertex est plus petit ou égal, false sinon.
			 * \details	Le test s'effectue dans l'ordre lexicographique
			 *			(sur les x, puis sur les y, puis sur les z), après
			 *			avoir passé les HVertex en coordonnées cartésiennes
			 *			(Vertex).
			 */
			bool operator >=(HVertex);

			/**
			 * Vérification d'égalité entre deux Vertex.
			 * \param 	pVertex 	Le deuxième vertex à tester.
			 * \return 	true si pVertex est égal, false sinon.
			 * \details	Le test s'effectue dans l'ordre lexicographique
			 *			(sur les x, puis sur les y, puis sur les z), après
			 *			avoir passé les HVertex en coordonnées cartésiennes
			 *			(Vertex).
			 */
			bool operator ==(HVertex);

			/**
			 * Vérification d'inégalité entre deux Vertex.
			 * \param 	pVertex 	Le deuxième vertex à tester.
			 * \return 	true si pVertex est inégal, false sinon.
			 * \details	Le test s'effectue dans l'ordre lexicographique
			 *			(sur les x, puis sur les y, puis sur les z), après
			 *			avoir passé les HVertex en coordonnées cartésiennes
			 *			(Vertex).
			 */
			bool operator !=(HVertex);

			/**
			 * Récupère le pointeur sur les éléments du vertex.
			 * \return 	Le pointeur sur les éléments du vertex.
			 */
			double * SData();

			/**
			 * Récupération des coordonnées cartésiennes du vertex.
			 * \return 	Un Vertex au coordonnées cartésiennes correspondant au vertex.
			 */
			Vertex GetCartesian();

			/**
			 * Mise aux coordonnées cartésiennes du vertex.
			 * \details	Les coordonnées x, y et z sont divisées par h, puis h est remis à 1.
			 */
			void SetCartesian();

			/**
			 * Détermination du maximum entre deux Vertex.
			 * \param 	pVertexA 	Le premier vertex.
			 * \param 	pVertexB 	Le deuxième vertex.
			 * \return	Le maximum entre pVertexA et pVertexB.
			 * \details	Le test s'effectue dans l'ordre lexicographique
			 *			(sur les x, puis sur les y, puis sur les z), après
			 *			avoir passé les HVertex en coordonnées cartésiennes
			 *			(Vertex).
			 */
			friend HVertex Min(HVertex, HVertex);

			/**
			 * Détermination du maximum entre deux Vertex.
			 * \param 	pVertexA 	Le premier vertex.
			 * \param 	pVertexB 	Le deuxième vertex.
			 * \return	Le maximum entre pVertexA et pVertexB.
			 * \details	Le test s'effectue dans l'ordre lexicographique
			 *			(sur les x, puis sur les y, puis sur les z), après
			 *			avoir passé les HVertex en coordonnées cartésiennes
			 *			(Vertex).
			 */
			friend HVertex Max(HVertex, HVertex);

			/**
			 * Calcul de la norme L2 entre deux Vertex.
			 * \param 	pVertexA 	Le premier vertex.
			 * \param 	pVertexB 	Le deuxième vertex.
			 * \return	La distance entre pVertexA et pVertexB.
			 * \details	Calcul sur la base des coordonnées cartésiennes.
			 */
			friend double Distance(HVertex, HVertex);

			/**
			 * Calcul de la norme L2 au carré entre deux Vertex.
			 * \param 	pVertexA 	Le premier vertex.
			 * \param 	pVertexB 	Le deuxième vertex.
			 * \return	La distance au carré entre pVertexA et pVertexB.
			 * \details Le calcul est plus rapide car on ne calcule pas
			 *			la racine carré, au contraire de la fonction Distance.
			 *			Calcul sur la base des coordonnées cartésiennes.
			 */
			friend double SqDistance(HVertex, HVertex);

		private:

			/**
			 * \brief 	Coordonnée x du vertex.
			 */
			double x;

			/**
			 * \brief 	Coordonnée y du vertex.
			 */
			double y;

			/**
			 * \brief 	Coordonnée z du vertex.
			 */
			double z;

			/**
			 * \brief 	Coordonnée h du vertex.
			 */
			double h;

	};

}

#endif