#include "Utilities/Geometry/Line/Edge/Edge.hpp"

namespace geo
{

	/*============ Edge2D ============*/

	Edge2D::Edge2D():
		a(),
		b()
	{
		//EMPTY
	}

	Edge2D::Edge2D(Vertex2D pVertexA, Vertex2D pVertexB):
		a(pVertexA),
		b(pVertexB)
	{
		//EMPTY
	}

	Edge2D::Edge2D(Vect2D pVect):
		a(VERTEX_TYPE::V_ZERO),
		b(pVect[0], pVect[1])
	{
		//EMPTY
	}

	Edge2D::Edge2D(Vertex2D pVertex, Vect2D pVect):
		a(pVertex),
		b(pVertex[0] + pVect[0], pVertex[1] + pVect[1])
	{
		//EMPTY
	}

	Edge2D::~Edge2D()
	{
		//EMPTY
	}

	Vertex2D Edge2D::GetA()
	{
		return a;
	}

	Vertex2D Edge2D::GetB()
	{
		return b;
	}

	void Edge2D::SetA(Vertex2D pA)
	{
		a = pA;
	}

	void Edge2D::SetB(Vertex2D pB)
	{
		b = pB;
	}

	Vertex2D& Edge2D::operator [](int pInd)
	{
		switch(pInd)
		{
			case 0:
				return a;
				break;
			case 1:
				return b;
				break;
			default:
				std::cerr << "Edge2D struct doesn't have any member at index '" << pInd << "'" << std::endl;
				exit(1);
		}
	}

	Vertex2D& Edge2D::operator ()(char pVertex)
	{
		switch(pVertex)
		{
			case 'a':
				return a;
				break;
			case 'b':
				return b;
				break;
			default:
				std::cerr << "Edge2D struct doesn't have any member called '" << pVertex << "'" << std::endl;
				exit(1);
		}
	}

	bool Edge2D::operator <(Edge2D pEdge)
	{
		return this->SqLength() < pEdge.SqLength();
	}

	bool Edge2D::operator >(Edge2D pEdge)
	{
		return this->SqLength() > pEdge.SqLength();
	}

	bool Edge2D::operator <=(Edge2D pEdge)
	{
		return this->SqLength() <= pEdge.SqLength();
	}

	bool Edge2D::operator >=(Edge2D pEdge)
	{
		return this->SqLength() >= pEdge.SqLength();
	}

	bool Edge2D::operator ==(Edge2D pEdge)
	{
		return (this->a == pEdge.a && this->b == pEdge.b) || (this->a == pEdge.b && this->b == pEdge.a);
	}

	bool Edge2D::operator !=(Edge2D pEdge)
	{
		return !((this->a == pEdge.a && this->b == pEdge.b) || (this->a == pEdge.b && this->b == pEdge.a));
	}

	double * Edge2D::SData()
	{
		double* vScratchData = a.SData();
		return vScratchData;
	}

	double Edge2D::Length()
	{
		return sqrt((a[0] - b[0]) * (a[0] - b[0]) + (a[1] - b[1]) * (a[1] - b[1]));
	}

	double Edge2D::SqLength()
	{
		return (a[0] - b[0]) * (a[0] - b[0]) + (a[1] - b[1]) * (a[1] - b[1]);
	}

	double Power(Edge2D pEdge, Vertex2D pVertex)
	{
		return (pEdge[1][1] - pEdge[0][1]) * (pVertex.GetX() - pEdge[0][0]) - (pEdge[1][0] - pEdge[0][0]) * (pVertex.GetY() - pEdge[0][1]);
	}

	double UnPower(Edge2D pEdge, Vertex2D pVertex)
	{
		return fabs((pEdge[1][1] - pEdge[0][1]) * (pVertex.GetX() - pEdge[0][0]) - (pEdge[1][0] - pEdge[0][0]) * (pVertex.GetY() - pEdge[0][1]));
	}

	/*============ Edge3D ============*/

	Edge::Edge():
		a(),
		b()
	{
		//EMPTY
	}

	Edge::Edge(Vertex pVertexA, Vertex pVertexB):
		a(pVertexA),
		b(pVertexB)
	{
		//EMPTY
	}

	Edge::Edge(Vect pVect):
		a(VERTEX_TYPE::V_ZERO),
		b(pVect[0], pVect[1], pVect[2])
	{
		//EMPTY
	}

	Edge::Edge(Vertex pVertex, Vect pVect):
		a(pVertex),
		b(pVertex[0] + pVect[0], pVertex[1] + pVect[1], pVertex[2] + pVect[2])
	{
		//EMPTY
	}

	Edge::~Edge()
	{
		//EMPTY
	}

	Vertex Edge::GetA()
	{
		return a;
	}

	Vertex Edge::GetB()
	{
		return b;
	}

	void Edge::SetA(Vertex pA)
	{
		a = pA;
	}

	void Edge::SetB(Vertex pB)
	{
		b = pB;
	}

	Vertex& Edge::operator [](int pInd)
	{
		switch(pInd)
		{
			case 0:
				return a;
				break;
			case 1:
				return b;
				break;
			default:
				std::cerr << "Edge struct doesn't have any member at index '" << pInd << "'" << std::endl;
				exit(1);
		}
	}

	Vertex& Edge::operator ()(char pVertex)
	{
		switch(pVertex)
		{
			case 'a':
				return a;
				break;
			case 'b':
				return b;
				break;
			default:
				std::cerr << "Edge struct doesn't have any member called '" << pVertex << "'" << std::endl;
				exit(1);
		}
	}

	bool Edge::operator <(Edge pEdge)
	{
		return this->SqLength() < pEdge.SqLength();
	}

	bool Edge::operator >(Edge pEdge)
	{
		return this->SqLength() > pEdge.SqLength();
	}

	bool Edge::operator <=(Edge pEdge)
	{
		return this->SqLength() <= pEdge.SqLength();
	}

	bool Edge::operator >=(Edge pEdge)
	{
		return this->SqLength() >= pEdge.SqLength();
	}

	bool Edge::operator ==(Edge pEdge)
	{
		return (this->a == pEdge.a && this->b == pEdge.b) || (this->a == pEdge.b && this->b == pEdge.a);
	}

	bool Edge::operator !=(Edge pEdge)
	{
		return !((this->a == pEdge.a && this->b == pEdge.b) || (this->a == pEdge.b && this->b == pEdge.a));
	}

	double * Edge::SData()
	{
		double* vScratchData = a.SData();
		return vScratchData;
	}

	double Edge::Length()
	{
		return sqrt((a[0] - b[0]) * (a[0] - b[0]) + (a[1] - b[1]) * (a[1] - b[1]) + (a[2] - b[2]) * (a[2] - b[2]));
	}

	double Edge::SqLength()
	{
		return (a[0] - b[0]) * (a[0] - b[0]) + (a[1] - b[1]) * (a[1] - b[1]) + (a[2] - b[2]) * (a[2] - b[2]);
	}

}