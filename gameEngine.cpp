#include <fstream>
#include <math.h>       /* sqrt */

#include <iostream>
using namespace std;

///////////////////////////////////////////////////// Math

class Vector
{
public:

	float x,y,z;

	// Constructors
	Vector(){x=y=z=0;}
	Vector(float a, float b, float c){x=a, y=b, z=c;}
	//Vector(float a, float b, float c): x(a), y(b), z(c) {}
	Vector(const Vector& v){x=v.x, y=v.y, z=v.z;}
	
	// Vector-vector ops
	Vector operator+(const Vector& v)const {return Vector(x+v.x, y+v.y, z+v.z);}
	Vector operator-(const Vector& v)const {return Vector(x-v.x, y-v.y, z-v.z);}
	float  operator*(const Vector& v)const {return x*v.x + v.y*y + v.z*z;}                         // Dot product
	Vector operator%(const Vector& v)const {return Vector(y*v.z-z*v.y, z*v.x-x*v.z, x*v.y-y*v.x);} // Cross product

	// Vector-number ops
	Vector operator*(const float n)const {return Vector(x*n, y*n, z*n);}
	Vector operator/(const float n)const {return Vector(x/n, y/n, z/n);}

	float length()const                  {return sqrt(x*x + y*y + z*z);}
	float distance(const Vector& v)const {return (*this-v).length();}

	void print(){cout << "(" << x << ", " << y << ", " << z << ")\n";}
};


class Color: public Vector
{
	void clamp(Vector& col)
	{
		col.x = (col.x > 255) ? 255 : (col.x < 0) ? 0 : col.x;
		col.y = (col.y > 255) ? 255 : (col.y < 0) ? 0 : col.y;
		col.z = (col.z > 255) ? 255 : (col.z < 0) ? 0 : col.z;
	}
};

int main()
{
	Vector a = Vector(1,2,3);
	Vector b = Vector(3,3,3);
	float c = a.distance(b);
	cout << a.distance(b);
}

/*

///////////////////////////////////////////////////// Rendering

class Ray
{
	Vector orig;
	Vector direc;
	Ray(const Vector& o, const Vector& d) : o(o), d(d) {}
};

Vector camera_position = Vector(0, 0, 0);

Struct viewport
{
	float width;
	float height;
	float distance;
}

///////////////////////////////////////////////////// Scene

class Sphere
{
	Vector center;
	float radius;
	Color color;
	Sphere(Vector c, Vector r, Color co){center=c, radius=r, color=co;}

	bool instersect(Ray ray, sphere)
	{
		Vector oc = Subtract(ray.origin, this.center);
		var k1 = DotProduct(direction, direction);
		var k2 = 2*DotProduct(oc, direction);
		var k3 = DotProduct(oc, oc) - sphere.radius*sphere.radius;
		var discriminant = k2*k2 - 4*k1*k3;
		if (discriminant < 0) {
		return [Infinity, Infinity];
		}
		var t1 = (-k2 + Math.sqrt(discriminant)) / (2*k1);
		var t2 = (-k2 - Math.sqrt(discriminant)) / (2*k1);
		return [t1, t2];
	}
};

class Light
{
	float intensity;
}

class AmbientLight:     public Light{};
class PointLight:       public Light{Vector position;};
class DirectionalLight: public Light{Vector direction;};


const Color WHITE(255, 255, 255);
const Color BLACK(0, 0, 0);
const Color RED(255, 0, 0);
const Color GREEN(0, 255, 0);
const Color BLUE(0, 0, 255);

int main()
{
	const int W = 500;
	const int H = 500;

	for (int y=0; y<H; ++y)
	{
		for (int x=0; x<W; ++x)
		{

		}
	}
}


*/

