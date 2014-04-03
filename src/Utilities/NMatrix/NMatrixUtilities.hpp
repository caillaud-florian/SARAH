/**
 * \file		NMatrixUtilities.hpp
 * \author		fcaillaud
 * \version 	1.0
 * \date     	2 Avril 2014
 * \brief     	Fichier offrant des traitement usuels pour les matrices.
 */

#ifndef NMATRIX_UTILITIES
#define NMATRIX_UTILITIES

#include "NMatrix.hpp"

/**
 * \namespace 	alg
 * \brief 		Nom de domaine tertiaire, partie utilitaire.
 * \todo 		Migrer vers le namespace gu.
 */
namespace alg
{
	
	/**
	 * \enum 	InversionMethod
	 * \brief 	Type d'inversion de matrice.
	 */
	enum InversionMethod
	{
		GAUSS_JORDAN, 		/*!< Inversion de Gauss-Jordan. */
		COFACTOR 			/*!< Inversion par la méthode des cofacteurs. */
	};

	/**
	 * Calcul du déterminant d'une matrice.
	 * \param 	pMatrix 	La matrice à analyser.
	 * \return 	Le déterminant de la matrice pMatrix.
	 */
	template<typename MType>
	double Determinant(const NMatrix<MType> pMatrix)
	{
		unsigned int vWidth = pMatrix.Width(), vHeight = pMatrix.Height();
		double vDetDust, vDetPos = 0.0, vDetNeg = 0.0;

		//Avoid to compute non-square matrix which has just no sens
		if(vWidth != vHeight){
			std::cerr << "ERROR : You tried to compute the determinant of a non-square matrix !" << std::endl;
			exit(-1);
		//Special case of a 2x2 matrix
		}else if(vWidth == 2){
			return pMatrix.GetAt(0, 0) * pMatrix.GetAt(1, 1) - pMatrix.GetAt(1, 0) * pMatrix.GetAt(0, 1);
		}

		//Other cases
			//First term of determinant equation
		for(unsigned int j = 0; j < vHeight; ++j){
			vDetDust = 1.0;
			for(unsigned int i = 0; i < vWidth; ++i)
				vDetDust *= pMatrix.GetAt(i, (i + j) % vHeight);
			vDetPos += vDetDust;
		}

			//Second term of determinant equation
		for(unsigned int j = 0; j < vHeight; ++j){
			vDetDust = 1.0;
			for(int i = vWidth - 1; i >= 0; --i)
				vDetDust *= pMatrix.GetAt(i, (abs(i - 2) + j) % vHeight);
			vDetNeg += vDetDust;
		}

		return vDetPos - vDetNeg;
	}

	/**
	 * Calcul du cofacteur d'une matrice aux indices voulus.
	 * \param 	pI 			L'indice de la ligne.
	 * \param	pJ 			L'indice de la colonne.
	 * \param	pMatrix 	La matrice à analyser.
	 * \return 	Le cofacteur de pMatrix aux indices pI et pJ.
	 */
	template<typename MType>
	double Cofactor(unsigned int pI, unsigned int pJ, const NMatrix<MType> pMatrix)
	{
		//Only width cause here is square matrices
		unsigned int vWidth = pMatrix.Width(), vCount = 0;

		NMatrix<MType> vMatrix(vWidth - 1);

		for(unsigned int j = 0; j < vWidth; ++j)
		{
			for(unsigned int i = 0; i < vWidth; ++i)
			{
				if(i != pI && j != pJ)
				{
					vMatrix[vCount] = pMatrix.GetAt(i, j);
					vCount++;
				}
			}
		}

		return Determinant(vMatrix);
	}

	/**
	 * Calcul de la comatrice d'une matrice.
	 * \param 	pMatrix 	La matrice à analyser.
	 * \return 	La comatrice de pMatrix.
	 * \details Utilisation des cofacteurs.
	 */
	template<typename MType>
	NMatrix<MType> Adjugate(const NMatrix<MType> pMatrix)
	{
		//Only width cause here is square matrices
		unsigned int vWidth = pMatrix.Width();

		NMatrix<MType> vMatrix(vWidth);

		//We find, for each element, his cofactor to construct the Adjugate Matrix
		for(unsigned int j = 0; j < vWidth; ++j)
		{
			for(unsigned int i = 0; i < vWidth; ++i)
			{
				vMatrix(i, j) = (((j * vWidth + i) % 2 == 0)?1:-1) * Cofactor(i, j, pMatrix);	
			}
		}

		return vMatrix;
	}

	/**
	 * Calcul de la transposée d'une matrice.
	 * \param 	pMatrix 	La matrice à analyser.
	 * \return 	La transposée de pMatrix.
	 */
	template<typename MType>
	NMatrix<MType> Transpose(const NMatrix<MType> pMatrix)
	{
		NMatrix<MType> vMatrix(pMatrix.Height(), pMatrix.Width());

		for(unsigned int j = 0; j < pMatrix.Height(); ++j)
		{
			for(unsigned int i = 0; i < pMatrix.Width(); ++i)
			{
				vMatrix.SetAt(j, i, pMatrix.GetAt(i, j));
			}
		}

		return vMatrix;
	}	

	/**
	 * Calcul de l'inversion d'une matrice.
	 * \param 	pMatrix 	La matrice à analyser.
	 * \param 	pIMethod 	La méthode utilisée (Gauss-Jordan ou cofacteurs).
	 * \return 	La matrice inverse de pMatrix.
	 * \todo 	N'y a t'il pas des cas ou il est impossible d'inverser ??
	 */
	template<typename MType>
	NMatrix<MType> Inversion(const NMatrix<MType> pMatrix, InversionMethod pIMethod = COFACTOR)
	{
		if(pMatrix.Width() != pMatrix.Height()){
			std::cerr << "ERROR : You tried to compute the inversion of a non-square matrix !" << std::endl;
			exit(-1);
		}

		switch(pIMethod){
			case COFACTOR:
				return CofactorInversion(pMatrix);
				break;
			case GAUSS_JORDAN:
				return GaussJordanInversion(pMatrix);
				break;
			default:
				std::cerr << "ERROR : This type of inversion (" << (unsigned int)pIMethod << ") is not implemented yet !" << std::endl;
				exit(-1);
		}
	}

	/**
	 * Calcul de l'inversion d'une matrice avec la méthode des cofacteurs.
	 * \param 	pMatrix 	La matrice à analyser.
	 * \return 	La matrice inverse de pMatrix.
	 */
	template<typename MType>
	NMatrix<MType> CofactorInversion(const NMatrix<MType> pMatrix)
	{
		std::cout << "\tCofactor Inversion : " << std::endl;

		double vDeterminant = Determinant(pMatrix);

		if(vDeterminant == 0.0)
			return NMatrix<MType>(pMatrix.Width(), M_ZERO);

		return (1 / vDeterminant) * Transpose(Adjugate(pMatrix));
	}

	/**
	 * Calcul de l'inversion d'une matrice avec la méthode de Gauss-Jordan.
	 * \param 	pMatrix 	La matrice à analyser.
	 * \return 	La matrice inverse de pMatrix.
	 * \todo 	À faire.
	 */
	template<typename MType>
	NMatrix<MType> GaussJordanInversion(const NMatrix<MType> pMatrix)
	{
		NMatrix<MType> vMatrix(pMatrix.Width());

		//A FAIRE

		return vMatrix;
	}

}

#endif
