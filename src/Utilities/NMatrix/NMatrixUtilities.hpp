#ifndef NMATRIX_UTILITIES
#define NMATRIX_UTILITIES

#include "NMatrix.hpp"

namespace alg
{
	
	enum InversionMethod
	{
		GAUSS_JORDAN,
		COFACTOR
	};

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

	template<typename MType>
	NMatrix<MType> CofactorInversion(const NMatrix<MType> pMatrix)
	{
		std::cout << "\tCofactor Inversion : " << std::endl;

		double vDeterminant = Determinant(pMatrix);

		if(vDeterminant == 0.0)
			return NMatrix<MType>(pMatrix.Width(), M_ZERO);

		return (1 / vDeterminant) * Transpose(Adjugate(pMatrix));
	}

	template<typename MType>
	NMatrix<MType> GaussJordanInversion(const NMatrix<MType> pMatrix)
	{
		NMatrix<MType> vMatrix(pMatrix.Width());

		//A FAIRE

		return vMatrix;
	}

}

#endif
