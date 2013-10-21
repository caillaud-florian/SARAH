#ifndef GEOMETRY_VERTEX
#define GEOMETRY_VERTEX

#include <iostream>
#include <cmath>

namespace geo
{

	enum VERTEX_TYPE
	{
		V_ZERO,
		V_IDENT
	};

	class Vertex2D
	{

		public:

			Vertex2D();

			Vertex2D(double, double);

			Vertex2D(VERTEX_TYPE);

			~Vertex2D();

			double GetX();

			double GetY();

			void SetX(double);

			void SetY(double);

			double& operator [](int);

			double& operator ()(char);

			bool operator <(Vertex2D);

			bool operator >(Vertex2D);

			bool operator <=(Vertex2D);

			bool operator >=(Vertex2D);

			bool operator ==(Vertex2D);

			bool operator !=(Vertex2D);

			double * SData();

			friend Vertex2D Min(Vertex2D, Vertex2D);

			friend Vertex2D Max(Vertex2D, Vertex2D);

			friend double Distance(Vertex2D, Vertex2D);

			friend double SqDistance(Vertex2D, Vertex2D);

		private:

			double x, y;
			
	};

	class Vertex
	{

		public:

			Vertex();

			Vertex(double, double, double);

			Vertex(Vertex2D, double);

			Vertex(VERTEX_TYPE);

			~Vertex();

			double GetX();

			double GetY();

			double GetZ();

			void SetX(double);

			void SetY(double);

			void SetZ(double);

			double& operator [](int);

			double& operator ()(char);

			bool operator <(Vertex);

			bool operator >(Vertex);

			bool operator <=(Vertex);

			bool operator >=(Vertex);

			bool operator ==(Vertex);

			bool operator !=(Vertex);

			double * SData();

			friend Vertex Min(Vertex, Vertex);

			friend Vertex Max(Vertex, Vertex);

			friend double Distance(Vertex, Vertex);

			friend double SqDistance(Vertex, Vertex);

		private:

			double x, y, z;

	};
	
	class HVertex
	{

		public:

			HVertex();

			HVertex(double, double, double, double);

			HVertex(Vertex, double);

			HVertex(Vertex2D, double, double);

			HVertex(VERTEX_TYPE);

			~HVertex();

			double GetX();

			double GetY();

			double GetZ();

			double GetH();

			void SetX(double);

			void SetY(double);

			void SetZ(double);

			void SetH(double);

			double& operator [](int);

			double& operator ()(char);

			bool operator <(HVertex);

			bool operator >(HVertex);

			bool operator <=(HVertex);

			bool operator >=(HVertex);

			bool operator ==(HVertex);

			bool operator !=(HVertex);

			double * SData();

			Vertex GetCartesian();

			void SetCartesian();

			friend HVertex Min(HVertex, HVertex);

			friend HVertex Max(HVertex, HVertex);

			friend double Distance(HVertex, HVertex);

			friend double SqDistance(HVertex, HVertex);

		private:

			double x, y, z, h;

	};

}

#endif