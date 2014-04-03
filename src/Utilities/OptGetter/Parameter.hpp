/**
 * \file		Parameter.hpp
 * \author		fcaillaud
 * \version 	1.0
 * \date     	2 Avril 2014
 * \brief     	Fichier décrivant la classe Parameter.
 * \details		Classe représentant un paramètre au sein de l'Opt(ion)Getter.
 */

#ifndef OPTGETTER_PARAMETER
#define OPTGETTER_PARAMETER

#include <string>
#include "../BasicTypeOperations/BasicTypeConverter.hpp"

/**
 * \namespace 	optg
 * \brief 		Nom de domaine tertiaire, partie utilitaire.
 * \todo 		Migrer vers le namespace gu.
 */
namespace optg
{

	/**
	 * \enum 	PType
	 * \brief 	Type du paramètre.
	 */
	enum PType{
		VOID,			/*!< Paramètre de type void. */
		CHAR,			/*!< Paramètre de type char. */
		PCHAR,			/*!< Paramètre de type pointeur sur char. */
		STRING,			/*!< Paramètre de type std::string. */
		BOOL,			/*!< Paramètre de type bool. */
		INT,			/*!< Paramètre de type int. */
		UINT,			/*!< Paramètre de type unsigned int. */
		SINT,			/*!< Paramètre de type short int. */
		LINT,			/*!< Paramètre de type long int. */
		LLINT,			/*!< Paramètre de type long long int. */
		DOUBLE,			/*!< Paramètre de type double. */
		LDOUBLE,		/*!< Paramètre de type long double. */
		FLOAT			/*!< Paramètre de type float. */
	};

	/**
	 * \class 	Parameter
	 * \brief 	Classe représentant un paramètre au sein de l'Opt(ion)Getter.
	 */
	class Parameter
	{

		public:

			/**
			 * Constructeur paramétré (pas de constructeur par défaut).
			 * \param 	pValue 	La valeur du paramètre (en chaîne de caractères).
			 * \param 	pType 	Le type du paramètre (PType).
			 * \details	Stocke la valeur du paramètre sous forme de char * mais avec 
			 *			la vrai valeur de celui-ci en fonction de son type.
			 */
			Parameter(const char *, PType);

			/**
			 * Destructeur.
			 */
			~Parameter();

			/**
			 * Récupération de la valeur du paramètre.
			 * \return 	La valeur du paramètre.
			 * \details	Fonction template sur le type de retour, donc restitution 
			 *			de la vrai valeur du paramètre en fonction de son type.
			 */
			template<typename ParamType>
			ParamType GetValue() const
			{
				return *((ParamType *)mValue);
			}

			/**
			 * Récupération de la valeur du paramètre sous forme de chaîne de caractères.
			 * \return 	La valeur du paramètre sous forme de std::string.
			 */
			std::string GetStrValue();

			/**
			 * Récupération du type du paramètre.
			 * \return 	Le type du paramètre.
			 */
			PType GetType();

			/**
			 * Remplissage d'une variable avec la valeur du paramètre.
			 * \param 	pValue 	La variable à remplir.
			 * \details	Simplification de la fonction GetValue().
			 */
			template<typename ParamType>
			void operator >> (ParamType & pValue)
			{
				pValue = *((ParamType *)mValue);
			}

		protected:

			/**
			 * \brief	 Valeur du paramètre.
			 */
			void * mValue;

			/**
			 * \brief 	Valeur du paramètre au format std::string.
			 */
			std::string mStrValue;

			/**
			 * \brief 	Type du paramètre.
			 */
			PType mType;

	};

	/**
	 * Récupération du nom d'un type.
	 * \param 	pType 	Le type voulu.
	 * \return 	Le nom du type voulu sous forme de std::string.
	 */
	std::string GetTypeName(PType pType);

}

#endif
