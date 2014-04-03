/**
 * \file		CommentedParameter.hpp
 * \author		fcaillaud
 * \version 	1.0
 * \date     	2 Avril 2014
 * \brief     	Fichier décrivant la classe CommentedParameter.
 * \details		Classe représentant un paramètre commenté au sein de l'Opt(ion)Getter.
 */

#ifndef OPTGETTER_COMMENTEDPARAMETER
#define OPTGETTER_COMMENTEDPARAMETER

#include "Parameter.hpp"

/**
 * \namespace 	optg
 * \brief 		Nom de domaine tertiaire, partie utilitaire.
 * \todo 		Migrer vers le namespace gu.
 */
namespace optg
{

	/**
	 * \class 	CommentedParameter
	 * \brief 	Classe représentant un paramètre commenté au sein de l'Opt(ion)Getter.
	 */
	class CommentedParameter : public Parameter
	{

		public:

			/**
			 * Constructeur paramétré (pas de constructeur par défaut).
			 * \param 	pValue 	La valeur du paramètre (en chaîne de caractères).
			 * \param 	pType 	Le type du paramètre (PType).
			 * \details	Stocke la valeur du paramètre sous forme de char * mais avec 
			 *			la vrai valeur de celui-ci en fonction de son type. Initialise 
			 *			le nom et le commentaire à "undefined".
			 */
			CommentedParameter(const char *, PType);

			/**
			 * Constructeur paramétré (pas de constructeur par défaut).
			 * \param 	pValue 		La valeur du paramètre (en chaîne de caractères).
			 * \param 	pType 		Le type du paramètre (PType).
			 * \param 	pName 		Le nom du paramètre.
			 * \param 	pComment 	Le commentaire associé au paramètre.
			 * \details	Stocke la valeur du paramètre sous forme de char * mais avec 
			 *			la vrai valeur de celui-ci en fonction de son type.
			 */
			CommentedParameter(const char *, PType, std::string, std::string);

			/**
			 * Destructeur.
			 */
			~CommentedParameter();

			/**
			 * Récupération du nom du paramètre.
			 * \return 	Le nom du paramètre.
			 */
			std::string GetName();

			/**
			 * Récupération du commentaire associé au paramètre.
			 * \return 	le commentaire associé au paramètre.
			 */
			std::string GetComment();

			/**
			 * Affichage du nom (s'il existe), de la valeur et du commentaire (s'il existe) du paramètre.
			 * \todo 	Faire la même chose avec Parameter.
			 */
			void Print();

		private:

			/**
			 * \brief 	Nom du paramètre.
			 */
			std::string mName;

			/**
			 * \brief 	Commentaire associé au paramètre.
			 */
			std::string mComment;

	};

}

#endif
