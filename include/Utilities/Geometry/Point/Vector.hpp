#ifndef GEOMETRY_VECTOR
#define GEOMETRY_VECTOR

#include <iostream>
#include <cmath>

#include "Vertex.hpp"

namespace geo
{

	enum VECTOR_TYPE
	{
		VR_ZERO,
		VR_IDENT
	};

	class Vect2D
	{

		public:

			Vect2D();

			Vect2D(double, double);

			Vect2D(VECTOR_TYPE);

			Vect2D(Vertex2D, Vertex2D);

			~Vect2D();

			double GetX();

			double GetY();

			void SetX(double);

			void SetY(double);

			double& operator [](int);

			double& operator ()(char);

			bool operator <(Vect2D);

			bool operator >(Vect2D);

			bool operator <=(Vect2D);

			bool operator >=(Vect2D);

			bool operator ==(Vect2D);

			bool operator !=(Vect2D);

			Vect2D operator +(Vect2D);

			Vect2D operator -(Vect2D);

			double operator *(Vect2D);

			double * SData();

			double Length();

			double SqLength();

			friend Vect2D operator *(Vect2D, double);

			friend Vect2D operator *(double, Vect2D);

			friend Vect2D operator /(Vect2D, double);

			friend double Power(Vect2D, Vect2D);

			friend double UnPower(Vect2D, Vect2D);

			friend double Power(Vect2D, Vertex2D);

			friend double UnPower(Vect2D, Vertex2D);

		private:

			double x, y;
			
	};

	class Vect
	{

		public:

			Vect();

			Vect(double, double, double);

			Vect(Vect2D, double);

			Vect(VECTOR_TYPE);

			Vect(Vertex, Vertex);

			~Vect();

			double GetX();

			double GetY();

			double GetZ();

			void SetX(double);

			void SetY(double);

			void SetZ(double);

			double& operator [](int);

			double& operator ()(char);

			bool operator <(Vect);

			bool operator >(Vect);

			bool operator <=(Vect);

			bool operator >=(Vect);

			bool operator ==(Vect);

			bool operator !=(Vect);

			Vect operator +(Vect);

			Vect operator -(Vect);

			double operator *(Vect);

			Vect operator ^(Vect);

			double * SData();

			double Length();

			double SqLength();

			friend Vect operator *(Vect, double);

			friend Vect operator *(double, Vect);

			friend Vect operator /(Vect, double);

		private:

			double x, y, z;

	};

}

#endif