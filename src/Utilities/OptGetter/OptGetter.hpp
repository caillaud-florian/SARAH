/**
 * \file		OptGetter.hpp
 * \author		fcaillaud
 * \version 	1.0
 * \date     	2 Avril 2014
 * \brief     	Fichier décrivant la classe OptGetter.
 * \details		Classe représentant la classe mère de tous gestionnaires d'options.
 */

#ifndef OPTGETTER_OPTGETTER
#define OPTGETTER_OPTGETTER

#include "CommentedParameter.hpp"

//Pour afficher les commentaires récupérés
//#define VERBOSE_OPT

/**
 * \namespace 	optg
 * \brief 		Nom de domaine tertiaire, partie utilitaire.
 * \todo 		Migrer vers le namespace gu.
 */
namespace optg
{

	/**
	 * \struct 	ParameterLabel
	 * \brief 	Structure définissant un tuple nom, type et commentaire pour les traitements.
	 */
	struct ParameterLabel
	{

		/**
		 * \brief 	Nom du paramètre.
		 */
		std::string mName;

		/**
		 * \brief 	Type du paramètre.
		 */
		PType 		mPType;

		/**
		 * \brief 	Commentaire associé au paramètre.
		 */
		std::string mComment;

	};

	/**
	 * \struct 	TaggedParameterLabel
	 * \brief 	Structure définissant un tuple nom, libellé, type, nécessité et commentaire pour les traitements.
	 */
	struct TaggedParameterLabel
	{

		/**
		 * \brief 	Nom du paramètre.
		 */
		std::string mName;

		/**
		 * \brief 	Libellé associé au paramètre.
		 */
		std::string mTag;

		/**
		 * \brief 	Type du paramètre.
		 */
		PType 		mPType;

		/**
		 * \brief 	Nécessité du paramètre.
		 */
		bool		mRequire;

		/**
		 * \brief 	Commentaire associé au paramètre.
		 */
		std::string mComment;

	};

	/**
	 * \class 	OptGetter
	 * \brief 	Classe mère pour tous les gestionnaires d'options.
	 */
	class OptGetter
	{

		public:

			/**
			 * Récupération du paramètre à l'indice voulu (virtuelle pure).
			 * \param 	pInd 	L'indice du paramètre voulu.
			 * \return 	Le paramètre commenté d'indice pInd.
			 */
			virtual CommentedParameter GetParameter(int pInd) = 0;

			/**
			 * Récupération du paramètre à l'indice voulu (virtuelle pure).
			 * \param 	pInd 	L'indice du paramètre voulu.
			 * \return 	Le paramètre commenté d'indice pInd.
			 */
			virtual CommentedParameter operator [](int pInd) = 0;

			/**
			 * Affichage de la liste des paramètres (virtuelle pure).
			 */
			virtual void Print() = 0;

	};

}

#endif
