/**
 * \file		Dart.hpp
 * \author		fcaillaud
 * \version 	1.0
 * \date     	2 Avril 2014
 * \brief     	Fichier décrivant la classe Dart.
 * \details		Classe représentant un brin de carte généralisée.
 * \todo 		opération sur les brin alphaO, alpha1, alpha2, ...
 *				PLUS la partie v['x', 'z', 'y'] .....
 */

#ifndef GEOMETRY_DART
#define GEOMETRY_DART

#include <iostream>

/**
 * \namespace 	geo
 * \brief 		Nom de domaine tertiaire, partie utilitaire.
 * \todo 		Migrer vers le namespace gu.
 */
namespace geo
{

	/**
	 * \class 	Dart
	 * \brief 	Classe représentant un brin dans une carte généralisée.
	 * \details	Classe template sur la dimension (par défaut DIM = 3) avec DIM + 1 relations.
	 */
	template<int DIM = 3>
	class Dart
	{

		public:

			/**
			 * Constructeur par défaut.
			 * \details Initialise toutes les dimensions à nullptr.
			 */
			Dart()
			{
				for(int i = 0; i < DIM + 1; ++i)
					rel[i] = nullptr;
			}

			/**
			 * Constructeur paramétré.
			 * \param 	pTail	La liste des relations attribuées au brin.
			 * \details	Pas encore implémenté.
			 */
			template <typename ...PDART >
			Dart(PDART ... pTail)
			{
				
			}

		private:

			/**
			 * \brief 	Tableau des relations avec les autres brins.
			 */
			Dart * rel[DIM + 1];
			
	};

}

#endif
