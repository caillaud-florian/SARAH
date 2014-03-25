#ifndef GEOMETRY_EDGE
#define GEOMETRY_EDGE

#include <iostream>
#include <cmath>

#include "../../Point/Vertex.hpp"
#include "../../Point/Vector.hpp"

namespace geo
{

	class Edge2D
	{

		public:
		
			Edge2D();

			Edge2D(Vertex2D, Vertex2D);

			Edge2D(Vect2D);

			Edge2D(Vertex2D, Vect2D);
		
			~Edge2D();

			Vertex2D GetA();

			Vertex2D GetB();

			void SetA(Vertex2D);

			void SetB(Vertex2D);

			Vertex2D& operator [](int);

			Vertex2D& operator ()(char);

			bool operator <(Edge2D);

			bool operator >(Edge2D);

			bool operator <=(Edge2D);

			bool operator >=(Edge2D);

			bool operator ==(Edge2D);

			bool operator !=(Edge2D);

			double * SData();

			double Length();

			double SqLength();

			friend double Power(Edge2D, Vertex2D);

			friend double UnPower(Edge2D, Vertex2D);
		
		private:

			Vertex2D a, b;
	};

	class Edge
	{

		public:
		
			Edge();

			Edge(Vertex, Vertex);

			Edge(Vect);

			Edge(Vertex, Vect);
		
			~Edge();

			Vertex GetA();

			Vertex GetB();

			void SetA(Vertex);

			void SetB(Vertex);

			Vertex& operator [](int);

			Vertex& operator ()(char);

			bool operator <(Edge);

			bool operator >(Edge);

			bool operator <=(Edge);

			bool operator >=(Edge);

			bool operator ==(Edge);

			bool operator !=(Edge);

			double * SData();

			double Length();

			double SqLength();
		
		private:

			Vertex a, b;
	};

}

#endif