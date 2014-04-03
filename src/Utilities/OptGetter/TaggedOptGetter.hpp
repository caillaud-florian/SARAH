/**
 * \file		TaggedOptGetter.hpp
 * \author		fcaillaud
 * \version 	1.0
 * \date     	2 Avril 2014
 * \brief     	Fichier décrivant la classe TaggedOptGetter.
 * \details		Classe représentant un gestionnaires d'options avec tag.
 */

#ifndef OPTGETTER_TAGGEDOPTGETTER
#define OPTGETTER_TAGGEDOPTGETTER

#include <map>
#include <vector>
#include <utility>

#include "OptGetter.hpp"

/**
 * \namespace 	optg
 * \brief 		Nom de domaine tertiaire, partie utilitaire.
 * \todo 		Migrer vers le namespace gu.
 */
namespace optg
{

	/**
	 * \class 	TaggedOptGetter
	 * \brief 	Classe représentant un gestionnaires d'options avec tag (e.g. -I "ouioui" -o -D).
	 */
	class TaggedOptGetter : public OptGetter
	{

		public:

			/**
			 * Constructeur paramétré.
			 * \param 	argc				argc de la fonction Main.
			 * \param 	argv				argv de la fonction Main.
			 * \param 	pVectType			La liste des tuples attendus.
			 * \details	Il n'y a pas d'ordre imposé pour les tuples.
			 */
			TaggedOptGetter(int, char **, std::vector<std::pair<std::string, PType> >);

			/**
			 * Constructeur paramétré.
			 * \param 	argc				argc de la fonction Main.
			 * \param 	argv				argv de la fonction Main.
			 * \param 	pVectType			La liste des tuples attendus.
			 * \details	Il n'y a pas d'ordre imposé pour les tuples.
			 */
			TaggedOptGetter(int, char **, std::vector<TaggedParameterLabel>);

			/**
			 * Destructeur.
			 */
			~TaggedOptGetter();

			/**
			 * Redéfinition de la fonction GetParameter de OptGetter.
			 * \param 	pInd 	L'indice du paramètre voulu.
			 * \return 	Le paramètre commenté d'indice pInd.
			 */
			CommentedParameter GetParameter(int);

			/**
			 * Récupération du paramètre au nom voulu.
			 * \param 	pKey 	Le nom du paramètre voulu.
			 * \return 	Le paramètre commenté d'indice pInd.
			 */
			CommentedParameter GetParameter(std::string);

			/**
			 * Redéfinition de la fonction operator [] de OptGetter.
			 * \param 	pInd 	L'indice du paramètre voulu.
			 * \return 	Le paramètre commenté d'indice pInd.
			 */
			CommentedParameter operator [](int);

			/**
			 * Récupération du paramètre au nom voulu.
			 * \param 	pKey 	Le nom du paramètre voulu.
			 * \return 	Le paramètre commenté d'indice pInd.
			 */
			CommentedParameter operator [](std::string);			

			/**
			 * Redéfinition de la fonction Print de OptGetter.
			 */
			void Print();

		protected:

			/**
			 * \brief 	Dictionnaire des paramètres récupérés.
			 */
			std::map<std::string, CommentedParameter *> mParameters;

	};

}

#endif
