/**
 * \file		SimpleOptGetter.hpp
 * \author		fcaillaud
 * \version 	1.0
 * \date     	2 Avril 2014
 * \brief     	Fichier décrivant la classe SimpleOptGetter.
 * \details		Classe représentant un gestionnaires d'options simples.
 */

#ifndef OPTGETTER_SIMPLEOPTGETTER
#define OPTGETTER_SIMPLEOPTGETTER

#include <vector>

#include "OptGetter.hpp"

/**
 * \namespace 	optg
 * \brief 		Nom de domaine tertiaire, partie utilitaire.
 * \todo 		Migrer vers le namespace gu.
 */
namespace optg
{

	/**
	 * \class 	SimpleOptGetter
	 * \brief 	Classe représentant un gestionnaires d'options simples (sans tag).
	 */
	class SimpleOptGetter : public OptGetter
	{

		public:

			/**
			 * Constructeur paramétré.
			 * \param 	argc				argc de la fonction Main.
			 * \param 	argv				argv de la fonction Main.
			 * \param 	pVectType			La liste des types voulus pour chaque argument.
			 * \param 	pNbRequiredParam	Le nombre de paramètres minimum exigés.
			 * \details	Les types doivent être dans l'ordre des paramètres attendus.
			 */
			SimpleOptGetter(int, char **, std::vector<PType>, int pNbRequiredParam = -1);

			/**
			 * Constructeur paramétré.
			 * \param 	argc				argc de la fonction Main.
			 * \param 	argv				argv de la fonction Main.
			 * \param 	pVectType			La liste des tuples voulus pour chaque argument.
			 * \param 	pNbRequiredParam	Le nombre de paramètres minimum exigés.
			 * \details	Les tuples doivent être dans l'ordre des paramètres attendus.
			 */
			SimpleOptGetter(int, char **, std::vector<ParameterLabel>, int pNbRequiredParam = -1);

			/**
			 * Destructeur.
			 */
			~SimpleOptGetter();

			/**
			 * Redéfinition de la fonction GetParameter de OptGetter.
			 * \param 	pInd 	L'indice du paramètre voulu.
			 * \return 	Le paramètre commenté d'indice pInd.
			 */
			CommentedParameter GetParameter(int);

			/**
			 * Redéfinition de la fonction operator [] de OptGetter.
			 * \param 	pInd 	L'indice du paramètre voulu.
			 * \return 	Le paramètre commenté d'indice pInd.
			 */
			CommentedParameter operator [](int);

			/**
			 * Redéfinition de la fonction Print de OptGetter.
			 */
			void Print();

		protected:

			/**
			 * \brief 	Liste des paramètres récupérés.
			 */
			std::vector<CommentedParameter *> mParameters;

	};

}

#endif
