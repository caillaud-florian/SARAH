#include "Vector.hpp"

namespace geo
{

	/*============ Vector2D ============*/

	Vect2D::Vect2D():
		x(0),
		y(0)
	{
		//EMPTY
	}

	Vect2D::Vect2D(double pX, double pY):
		x(pX),
		y(pY)
	{
		//EMPTY
	}

	Vect2D::Vect2D(VECTOR_TYPE pVectType)
	{
		switch(pVectType)
		{
			case VR_ZERO:
				x = 0.0;
				y = 0.0;
				break;
			case VR_IDENT:
				x = 1.0;
				y = 1.0;
				break;
			default:
				x = 0.0;
				y = 0.0;
				break;
		}
	}

	Vect2D::Vect2D(Vertex2D pVertexA, Vertex2D pVertexB):
		x(pVertexB.GetX() - pVertexA.GetX()),
		y(pVertexB.GetY() - pVertexA.GetY())
	{
		//EMPTY
	}

	Vect2D::~Vect2D()
	{
		//EMPTY
	}

	double Vect2D::GetX()
	{
		return x;
	}

	double Vect2D::GetY()
	{
		return y;
	}

	void Vect2D::SetX(double pX)
	{
		x = pX;
	}

	void Vect2D::SetY(double pY)
	{
		y = pY;
	}

	double& Vect2D::operator [](int pInd)
	{
		switch(pInd)
		{
			case 0:
				return x;
				break;
			case 1:
				return y;
				break;
			default:
				std::cerr << "Vect2D struct doesn't have any member at index '" << pInd << "'" << std::endl;
				exit(1);
		}
	}

	double& Vect2D::operator ()(char pCoord)
	{
		switch(pCoord)
		{
			case 'x':
				return x;
				break;
			case 'y':
				return y;
				break;
			default:
				std::cerr << "Vect2D struct doesn't have any member called '" << pCoord << "'" << std::endl;
				exit(1);
		}
	}

	bool Vect2D::operator <(Vect2D pVect)
	{
		return (this->SqLength() < pVect.SqLength());
	}

	bool Vect2D::operator >(Vect2D pVect)
	{
		return (this->SqLength() > pVect.SqLength());
	}

	bool Vect2D::operator <=(Vect2D pVect)
	{
		return (this->SqLength() <= pVect.SqLength());
	}

	bool Vect2D::operator >=(Vect2D pVect)
	{
		return (this->SqLength() >= pVect.SqLength());
	}

	bool Vect2D::operator ==(Vect2D pVect)
	{
		return (this->x == pVect.x && this->y == pVect.y);
	}

	bool Vect2D::operator !=(Vect2D pVect)
	{
		return !(this->x == pVect.x && this->y == pVect.y);
	}

	Vect2D Vect2D::operator +(Vect2D pVect2D)
	{
		return Vect2D(this->x + pVect2D.x, this->y + pVect2D.y);
	}

	Vect2D Vect2D::operator -(Vect2D pVect2D)
	{
		return Vect2D(this->x - pVect2D.x, this->y - pVect2D.y);
	}

	double Vect2D::operator *(Vect2D pVect2D)
	{
		return (this->x * pVect2D.x + this->y * pVect2D.y);
	}

	double * Vect2D::SData()
	{
		double* vScratchData = &(this->x);
		return vScratchData;
	}

	double Vect2D::Length()
	{
		return sqrt(x * x + y * y);
	}

	double Vect2D::SqLength()
	{
		return x * x + y * y;
	}

	Vect2D operator *(Vect2D pVect2D, double pFactor)
	{
		return Vect2D(pVect2D.GetX() * pFactor, pVect2D.GetY() * pFactor);
	}

	Vect2D operator *(double pFactor, Vect2D pVect2D)
	{
		return Vect2D(pVect2D.GetX() * pFactor, pVect2D.GetY() * pFactor);
	}

	Vect2D operator /(Vect2D pVect2D, double pFactor)
	{
		return Vect2D(pVect2D.GetX() / pFactor, pVect2D.GetY() / pFactor);
	}

	double Power(Vect2D pVec2DA, Vect2D pVec2DB)
	{
		return pVec2DA.y * pVec2DB.x - pVec2DA.x * pVec2DB.y;
	}

	double UnPower(Vect2D pVec2DA, Vect2D pVec2DB)
	{
		return fabs(pVec2DA.y * pVec2DB.x - pVec2DA.x * pVec2DB.y);
	}

	double Power(Vect2D pVec2D, Vertex2D pVertex2D)
	{
		return pVec2D.y * pVertex2D.GetX() - pVec2D.x * pVertex2D.GetY();
	}

	double UnPower(Vect2D pVec2D, Vertex2D pVertex2D)
	{
		return fabs(pVec2D.y * pVertex2D.GetX() - pVec2D.x * pVertex2D.GetY());
	}

	/*============ Vector3D ============*/

	Vect::Vect():
		x(0),
		y(0),
		z(0)
	{
		//EMPTY
	}

	Vect::Vect(double pX, double pY, double pZ):
		x(pX),
		y(pY),
		z(pZ)
	{
		//EMPTY
	}

	Vect::Vect(Vect2D pV2D, double pZ):
		x(pV2D.GetX()),
		y(pV2D.GetY()),
		z(pZ)
	{
		//EMPTY
	}

	Vect::Vect(VECTOR_TYPE pVectType)
	{
		switch(pVectType)
		{
			case VR_ZERO:
				x = 0.0;
				y = 0.0;
				z = 0.0;
				break;
			case VR_IDENT:
				x = 1.0;
				y = 1.0;
				z = 1.0;
				break;
			default:
				x = 0.0;
				y = 0.0;
				z = 0.0;
				break;
		}
	}

	Vect::Vect(Vertex pVertexA, Vertex pVertexB):
		x(pVertexB.GetX() - pVertexA.GetX()),
		y(pVertexB.GetY() - pVertexA.GetY()),
		z(pVertexB.GetZ() - pVertexA.GetZ())
	{
		//EMPTY
	}

	Vect::~Vect()
	{
		//EMPTY
	}

	double Vect::GetX()
	{
		return x;
	}

	double Vect::GetY()
	{
		return y;
	}

	double Vect::GetZ()
	{
		return z;
	}

	void Vect::SetX(double pX)
	{
		x = pX;
	}

	void Vect::SetY(double pY)
	{
		y = pY;
	}

	void Vect::SetZ(double pZ)
	{
		z = pZ;
	}

	double& Vect::operator [](int pInd)
	{
		switch(pInd)
		{
			case 0:
				return x;
				break;
			case 1:
				return y;
				break;
			case 2:
				return z;
				break;
			default:
				std::cerr << "Vect struct doesn't have any member at index '" << pInd << "'" << std::endl;
				exit(1);
		}
	}

	double& Vect::operator ()(char pCoord)
	{
		switch(pCoord)
		{
			case 'x':
				return x;
				break;
			case 'y':
				return y;
				break;
			case 'z':
				return z;
				break;
			default:
				std::cerr << "Vect struct doesn't have any member called '" << pCoord << "'" << std::endl;
				exit(1);
		}
	}

	bool Vect::operator <(Vect pVect)
	{
		return (this->SqLength() < pVect.SqLength());
	}

	bool Vect::operator >(Vect pVect)
	{
		return (this->SqLength() > pVect.SqLength());
	}

	bool Vect::operator <=(Vect pVect)
	{
		return (this->SqLength() <= pVect.SqLength());
	}

	bool Vect::operator >=(Vect pVect)
	{
		return (this->SqLength() >= pVect.SqLength());
	}

	bool Vect::operator ==(Vect pVect)
	{
		return (this->x == pVect.x && this->y == pVect.y && this->z == pVect.z);
	}

	bool Vect::operator !=(Vect pVect)
	{
		return !(this->x == pVect.x && this->y == pVect.y && this->z == pVect.z);
	}

	Vect Vect::operator +(Vect pVect)
	{
		return Vect(this->x + pVect.x, this->y + pVect.y, this->z + pVect.z);
	}

	Vect Vect::operator -(Vect pVect)
	{
		return Vect(this->x - pVect.x, this->y - pVect.y, this->z - pVect.z);
	}

	double Vect::operator *(Vect pVect)
	{
		return (this->x * pVect.x + this->y * pVect.y + this->z * pVect.z);
	}

	Vect Vect::operator ^(Vect pVect)
	{
		return Vect(this->y * pVect.z - this->z * pVect.y, this->z * pVect.x - this->x * pVect.z, this->x * pVect.y - this->y * pVect.x);
	}

	double * Vect::SData()
	{
		double* vScratchData = &(this->x);
		return vScratchData;
	}

	double Vect::Length()
	{
		return sqrt(x * x + y * y + z * z);
	}

	double Vect::SqLength()
	{
		return x * x + y * y + z * z;
	}

	Vect operator *(Vect pVect, double pFactor)
	{
		return Vect(pVect.GetX() * pFactor, pVect.GetY() * pFactor, pVect.GetZ() * pFactor);
	}

	Vect operator *(double pFactor, Vect pVect)
	{
		return Vect(pVect.GetX() * pFactor, pVect.GetY() * pFactor, pVect.GetZ() * pFactor);
	}

	Vect operator /(Vect pVect, double pFactor)
	{
		return Vect(pVect.GetX() / pFactor, pVect.GetY() / pFactor, pVect.GetZ() / pFactor);
	}
	
}