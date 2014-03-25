#include "Vertex.hpp"

namespace geo
{

	/*============ Vertex2D ============*/

	Vertex2D::Vertex2D():
		x(0),
		y(0)
	{
		//EMPTY
	}

	Vertex2D::Vertex2D(double pX, double pY):
		x(pX),
		y(pY)
	{
		//EMPTY
	}

	Vertex2D::Vertex2D(VERTEX_TYPE pVertexType)
	{
		switch(pVertexType)
		{
			case V_ZERO:
				x = 0.0;
				y = 0.0;
				break;
			case V_IDENT:
				x = 1.0;
				y = 1.0;
				break;
			default:
				x = 0.0;
				y = 0.0;
				break;
		}
	}

	Vertex2D::~Vertex2D()
	{
		//EMPTY
	}

	double Vertex2D::GetX()
	{
		return x;
	}

	double Vertex2D::GetY()
	{
		return y;
	}

	void Vertex2D::SetX(double pX)
	{
		x = pX;
	}

	void Vertex2D::SetY(double pY)
	{
		y = pY;
	}

	double& Vertex2D::operator [](int pInd)
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
				std::cerr << "Vertex2D struct doesn't have any member at index '" << pInd << "'" << std::endl;
				exit(1);
		}
	}

	double& Vertex2D::operator ()(char pCoord)
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
				std::cerr << "Vertex2D struct doesn't have any member called '" << pCoord << "'" << std::endl;
				exit(1);
		}
	}

	bool Vertex2D::operator <(Vertex2D pVertex)
	{
		if(this->x < pVertex.x)
			return true;
		else if(this->x > pVertex.x)
			return false;
		else
			if(this->y < pVertex.y)
				return true;
			else
				return false;
	}

	bool Vertex2D::operator >(Vertex2D pVertex)
	{
		if(this->x > pVertex.x)
			return true;
		else if(this->x < pVertex.x)
			return false;
		else
			if(this->y > pVertex.y)
				return true;
			else
				return false;
	}

	bool Vertex2D::operator <=(Vertex2D pVertex)
	{
		if(this->x < pVertex.x)
			return true;
		else if(this->x > pVertex.x)
			return false;
		else
			if(this->y < pVertex.y)
				return true;
			else if (this->y > pVertex.y)
				return false;
			else
				return true;
	}

	bool Vertex2D::operator >=(Vertex2D pVertex)
	{
		if(this->x > pVertex.x)
			return true;
		else if(this->x < pVertex.x)
			return false;
		else
			if(this->y > pVertex.y)
				return true;
			else if (this->y < pVertex.y)
				return false;
			else
				return true;
	}

	bool Vertex2D::operator ==(Vertex2D pVertex)
	{
		return (this->x == pVertex.x && this->y == pVertex.y);
	}

	bool Vertex2D::operator !=(Vertex2D pVertex)
	{
		return !(this->x == pVertex.x && this->y == pVertex.y);
	}

	double * Vertex2D::SData()
	{
		double* vScratchData = &(this->x);
		return vScratchData;
	}

	Vertex2D Min(Vertex2D pVertexA, Vertex2D pVertexB)
	{
		return Vertex2D(((pVertexA.x < pVertexB.x)?pVertexA.x:pVertexB.x),
						((pVertexA.y < pVertexB.y)?pVertexA.y:pVertexB.y));
	}

	Vertex2D Max(Vertex2D pVertexA, Vertex2D pVertexB)
	{
		return Vertex2D(((pVertexA.x > pVertexB.x)?pVertexA.x:pVertexB.x),
						((pVertexA.y > pVertexB.y)?pVertexA.y:pVertexB.y));
	}

	double Distance(Vertex2D pVertexA, Vertex2D pVertexB)
	{
		return sqrt((pVertexA.x - pVertexB.x) * (pVertexA.x - pVertexB.x) + (pVertexA.y - pVertexB.y) * (pVertexA.y - pVertexB.y));
	}

	double SqDistance(Vertex2D pVertexA, Vertex2D pVertexB)
	{
		return (pVertexA.x - pVertexB.x) * (pVertexA.x - pVertexB.x) + (pVertexA.y - pVertexB.y) * (pVertexA.y - pVertexB.y);
	}

	/*============ Vertex3D ============*/

	Vertex::Vertex():
		x(0),
		y(0),
		z(0)
	{
		//EMPTY
	}

	Vertex::Vertex(double pX, double pY, double pZ):
		x(pX),
		y(pY),
		z(pZ)
	{
		//EMPTY
	}

	Vertex::Vertex(VERTEX_TYPE pVertexType)
	{
		switch(pVertexType)
		{
			case V_ZERO:
				x = 0.0;
				y = 0.0;
				z = 0.0;
				break;
			case V_IDENT:
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

	Vertex::Vertex(Vertex2D pV2D, double pZ):
		x(pV2D.GetX()),
		y(pV2D.GetY()),
		z(pZ)
	{
		//EMPTY
	}

	Vertex::~Vertex()
	{
		//EMPTY
	}

	double Vertex::GetX()
	{
		return x;
	}

	double Vertex::GetY()
	{
		return y;
	}

	double Vertex::GetZ()
	{
		return z;
	}

	void Vertex::SetX(double pX)
	{
		x = pX;
	}

	void Vertex::SetY(double pY)
	{
		y = pY;
	}

	void Vertex::SetZ(double pZ)
	{
		z = pZ;
	}

	double& Vertex::operator [](int pInd)
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
				std::cerr << "Vertex struct doesn't have any member at index '" << pInd << "'" << std::endl;
				exit(1);
		}
	}

	double& Vertex::operator ()(char pCoord)
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
				std::cerr << "Vertex struct doesn't have any member called '" << pCoord << "'" << std::endl;
				exit(1);
		}
	}

	bool Vertex::operator <(Vertex pVertex)
	{
		if(this->x < pVertex.x)
			return true;
		else if(this->x > pVertex.x)
			return false;
		else
			if(this->y < pVertex.y)
				return true;
			else if(this->y > pVertex.y)
				return false;
			else
				if(this->z < pVertex.z)
					return true;
				else 
					return false;
	}

	bool Vertex::operator >(Vertex pVertex)
	{
		if(this->x > pVertex.x)
			return true;
		else if(this->x < pVertex.x)
			return false;
		else
			if(this->y > pVertex.y)
				return true;
			else if(this->y < pVertex.y)
				return false;
			else
				if(this->z > pVertex.z)
					return true;
				else 
					return false;
	}

	bool Vertex::operator <=(Vertex pVertex)
	{
		if(this->x < pVertex.x)
			return true;
		else if(this->x > pVertex.x)
			return false;
		else
			if(this->y < pVertex.y)
				return true;
			else if(this->y > pVertex.y)
				return false;
			else
				if(this->z < pVertex.z)
					return true;
				else if(this->z > pVertex.z)
					return false;
				else
					return true;
	}

	bool Vertex::operator >=(Vertex pVertex)
	{
		if(this->x > pVertex.x)
			return true;
		else if(this->x < pVertex.x)
			return false;
		else
			if(this->y > pVertex.y)
				return true;
			else if(this->y < pVertex.y)
				return false;
			else
				if(this->z > pVertex.z)
					return true;
				else if(this->z < pVertex.z)
					return false;
				else
					return true;
	}

	bool Vertex::operator ==(Vertex pVertex)
	{
		return (this->x == pVertex.x && this->y == pVertex.y && this->z == pVertex.z);
	}

	bool Vertex::operator !=(Vertex pVertex)
	{
		return !(this->x == pVertex.x && this->y == pVertex.y && this->z == pVertex.z);
	}

	double * Vertex::SData()
	{
		double* vScratchData = &(this->x);
		return vScratchData;
	}

	Vertex Min(Vertex pVertexA, Vertex pVertexB)
	{
		return Vertex(((pVertexA.x < pVertexB.x)?pVertexA.x:pVertexB.x),
						((pVertexA.y < pVertexB.y)?pVertexA.y:pVertexB.y),
						((pVertexA.z < pVertexB.z)?pVertexA.z:pVertexB.z));
	}

	Vertex Max(Vertex pVertexA, Vertex pVertexB)
	{
		return Vertex(((pVertexA.x > pVertexB.x)?pVertexA.x:pVertexB.x),
						((pVertexA.y > pVertexB.y)?pVertexA.y:pVertexB.y),
						((pVertexA.z > pVertexB.z)?pVertexA.z:pVertexB.z));
	}

	double Distance(Vertex pVertexA, Vertex pVertexB)
	{
		return sqrt((pVertexA.x - pVertexB.x) * (pVertexA.x - pVertexB.x) 
					+ (pVertexA.y - pVertexB.y) * (pVertexA.y - pVertexB.y)
					+ (pVertexA.z - pVertexB.z) * (pVertexA.z - pVertexB.z));
	}

	double SqDistance(Vertex pVertexA, Vertex pVertexB)
	{
		return (pVertexA.x - pVertexB.x) * (pVertexA.x - pVertexB.x) 
					+ (pVertexA.y - pVertexB.y) * (pVertexA.y - pVertexB.y)
					+ (pVertexA.z - pVertexB.z) * (pVertexA.z - pVertexB.z);
	}

	/*============ HomogenVertex ============*/

	HVertex::HVertex():
		x(0),
		y(0),
		z(0),
		h(1)
	{
		//EMPTY
	}

	HVertex::HVertex(double pX, double pY, double pZ, double pH):
		x(pX),
		y(pY),
		z(pZ),
		h(pH)
	{
		//EMPTY
	}

	HVertex::HVertex(VERTEX_TYPE pVertexType)
	{
		switch(pVertexType)
		{
			case V_ZERO:
				x = 0.0;
				y = 0.0;
				z = 0.0;
				h = 0.0;
				break;
			case V_IDENT:
				x = 1.0;
				y = 1.0;
				z = 1.0;
				h = 1.0;
				break;
			default:
				x = 0.0;
				y = 0.0;
				z = 0.0;
				h = 1.0;
				break;
		}
	}

	HVertex::HVertex(Vertex pV, double pH):
		x(pV.GetX()),
		y(pV.GetY()),
		z(pV.GetZ()),
		h(pH)
	{
		//EMPTY
	}

	HVertex::HVertex(Vertex2D pV2D, double pZ, double pH):
		x(pV2D.GetX()),
		y(pV2D.GetY()),
		z(pZ),
		h(pH)
	{
		//EMPTY
	}

	HVertex::~HVertex()
	{
		//EMPTY
	}

	double HVertex::GetX()
	{
		return x;
	}

	double HVertex::GetY()
	{
		return y;
	}

	double HVertex::GetZ()
	{
		return z;
	}

	double HVertex::GetH()
	{
		return h;
	}

	void HVertex::SetX(double pX)
	{
		x = pX;
	}

	void HVertex::SetY(double pY)
	{
		y = pY;
	}

	void HVertex::SetZ(double pZ)
	{
		z = pZ;
	}

	void HVertex::SetH(double pH)
	{
		h = pH;
	}

	double& HVertex::operator [](int pInd)
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
			case 3:
				return h;
				break;
			default:
				std::cerr << "HVertex struct doesn't have any member at index '" << pInd << "'" << std::endl;
				exit(1);
		}
	}

	double& HVertex::operator ()(char pCoord)
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
			case 'h':
				return h;
				break;
			default:
				std::cerr << "HVertex struct doesn't have any member called '" << pCoord << "'" << std::endl;
				exit(1);
		}
	}

	bool HVertex::operator <(HVertex pVertex)
	{
		Vertex vVertexA = this->GetCartesian(), vVertexB = pVertex.GetCartesian();

		if(vVertexA.GetX() < vVertexB.GetX())
			return true;
		else if(vVertexA.GetX() > vVertexB.GetX())
			return false;
		else
			if(vVertexA.GetY() < vVertexB.GetY())
				return true;
			else if(vVertexA.GetY() > vVertexB.GetY())
				return false;
			else
				if(vVertexA.GetZ() < vVertexB.GetZ())
					return true;
				else 
					return false;
	}

	bool HVertex::operator >(HVertex pVertex)
	{
		Vertex vVertexA = this->GetCartesian(), vVertexB = pVertex.GetCartesian();

		if(vVertexA.GetX() > vVertexB.GetX())
			return true;
		else if(vVertexA.GetX() < vVertexB.GetX())
			return false;
		else
			if(vVertexA.GetY() > vVertexB.GetY())
				return true;
			else if(vVertexA.GetY() < vVertexB.GetY())
				return false;
			else
				if(vVertexA.GetZ() > vVertexB.GetZ())
					return true;
				else 
					return false;
	}

	bool HVertex::operator <=(HVertex pVertex)
	{
		Vertex vVertexA = this->GetCartesian(), vVertexB = pVertex.GetCartesian();

		if(vVertexA.GetX() < vVertexB.GetX())
			return true;
		else if(vVertexA.GetX() > vVertexB.GetX())
			return false;
		else
			if(vVertexA.GetY() < vVertexB.GetY())
				return true;
			else if(vVertexA.GetY() > vVertexB.GetY())
				return false;
			else
				if(vVertexA.GetZ() < vVertexB.GetZ())
					return true;
				else if(vVertexA.GetZ() > vVertexB.GetZ())
					return false;
				else
					return true;
	}

	bool HVertex::operator >=(HVertex pVertex)
	{
		Vertex vVertexA = this->GetCartesian(), vVertexB = pVertex.GetCartesian();

		if(vVertexA.GetX() > vVertexB.GetX())
			return true;
		else if(vVertexA.GetX() < vVertexB.GetX())
			return false;
		else
			if(vVertexA.GetY() > vVertexB.GetY())
				return true;
			else if(vVertexA.GetY() < vVertexB.GetY())
				return false;
			else
				if(vVertexA.GetZ() > vVertexB.GetZ())
					return true;
				else if(vVertexA.GetZ() < vVertexB.GetZ())
					return false;
				else
					return true;
	}

	bool HVertex::operator ==(HVertex pVertex)
	{
		Vertex vVertexA = this->GetCartesian(), vVertexB = pVertex.GetCartesian();

		return (vVertexA.GetX() == vVertexB.GetX() && vVertexA.GetY() == vVertexB.GetY() && vVertexA.GetZ() == vVertexB.GetZ());
	}

	bool HVertex::operator !=(HVertex pVertex)
	{
		Vertex vVertexA = this->GetCartesian(), vVertexB = pVertex.GetCartesian();

		return !(vVertexA.GetX() == vVertexB.GetX() && vVertexA.GetY() == vVertexB.GetY() && vVertexA.GetZ() == vVertexB.GetZ());
	}

	double * HVertex::SData()
	{
		double* vScratchData = &(this->x);
		return vScratchData;
	}

	Vertex HVertex::GetCartesian()
	{
		return Vertex(x / h, y / h, z / h);
	}

	void HVertex::SetCartesian()
	{
		x /= h;
		y /= h;
		z /= h;
		h = 1;
	}

	HVertex Min(HVertex pVertexA, HVertex pVertexB)
	{
		Vertex vVertexA = pVertexA.GetCartesian(), vVertexB = pVertexB.GetCartesian();

		return HVertex(((vVertexA.GetX() < vVertexB.GetX())?vVertexA.GetX():vVertexB.GetX()),
						((vVertexA.GetY() < vVertexB.GetY())?vVertexA.GetY():vVertexB.GetY()),
						((vVertexA.GetZ() < vVertexB.GetZ())?vVertexA.GetZ():vVertexB.GetZ()),
						1.0);
	}

	HVertex Max(HVertex pVertexA, HVertex pVertexB)
	{
		Vertex vVertexA = pVertexA.GetCartesian(), vVertexB = pVertexB.GetCartesian();

		return HVertex(((vVertexA.GetX() > vVertexB.GetX())?vVertexA.GetX():vVertexB.GetX()),
						((vVertexA.GetY() > vVertexB.GetY())?vVertexA.GetY():vVertexB.GetY()),
						((vVertexA.GetZ() > vVertexB.GetZ())?vVertexA.GetZ():vVertexB.GetZ()),
						1.0);
	}

	double Distance(HVertex pVertexA, HVertex pVertexB)
	{
		Vertex vVertexA = pVertexA.GetCartesian(), vVertexB = pVertexB.GetCartesian();

		return sqrt((vVertexA.GetX() - vVertexB.GetX()) * (vVertexA.GetX() - vVertexB.GetX()) 
					+ (vVertexA.GetY() - vVertexB.GetY()) * (vVertexA.GetY() - vVertexB.GetY())
					+ (vVertexA.GetZ() - vVertexB.GetZ()) * (vVertexA.GetZ() - vVertexB.GetZ()));
	}

	double SqDistance(HVertex pVertexA, HVertex pVertexB)
	{
		Vertex vVertexA = pVertexA.GetCartesian(), vVertexB = pVertexB.GetCartesian();

		return (vVertexA.GetX() - vVertexB.GetX()) * (vVertexA.GetX() - vVertexB.GetX()) 
					+ (vVertexA.GetY() - vVertexB.GetY()) * (vVertexA.GetY() - vVertexB.GetY())
					+ (vVertexA.GetZ() - vVertexB.GetZ()) * (vVertexA.GetZ() - vVertexB.GetZ());
	}
	
}