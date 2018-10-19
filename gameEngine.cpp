#include <fstream>
#include <math.h>   /* sqrt */

//#include <iostream>
//using namespace std;

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

	//void print(){std::cout << "(" << x << ", " << y << ", " << z << ")\n";}
};


/*class Color: public Vector
{
	void clamp(Vector& col)
	{
		col.x = (col.x > 255) ? 255 : (col.x < 0) ? 0 : col.x;
		col.y = (col.y > 255) ? 255 : (col.y < 0) ? 0 : col.y;
		col.z = (col.z > 255) ? 255 : (col.z < 0) ? 0 : col.z;
	}
};*/


struct Sphere
{
	Vector center;
	float radius;
	Vector color;
	
	Sphere(const Vector &ce, float r, const Vector &co): center(ce), radius(r), color(co) {}
	
	Vector getNormal(const Vector& pi) const
	{
		return (pi - center) / radius;
	}
	
	bool intersect(const Vector& origen, const Vector& direction, float &t) const
	{
		const Vector oc = origen - center;
		const float b   = 2 * (oc*direction);
		const float c   = (oc*oc) - radius*radius;
		float disc = b*b - 4 * c;
		if (disc < 1e-4) return false;
		disc = sqrt(disc);
		const float t0 = -b - disc;
		const float t1 = -b + disc;
		t = (t0 < t1) ? t0 : t1;
		return true;
	}
}sphere1(Vector(50, 50, 50), 50, Vector(255,0,0));


Vector traceRay(Vector origen, Vector direction)
{
	Vector color;
	float t;

	// TODO: For every object, get closer intersection...
	if (sphere1.intersect(origen, direction, t))
	{
		//const Vector pi = origin + direction*t;
		//const Vector L  = light.c - pi;
		//const Vector N  = sphere1.getNormal(pi);
		//const double dt = dot(L.normalize(), N.normalize());

		//pix_col = (red + white*dt) * 0.5;
		//clamp255(pix_col);
		color = Vector(255,0,0);
	}
	else
	{
		color = Vector(0,0,0);
	}

	return color;
}

int main()
{
	Vector origen = Vector(0,0,0); // camera_position

	const int W = 100;
	const int H = 100;
	const int DISTANCE = 50;
	const int halfW = W/2;
	const int halfH = H/2;

	std::ofstream out("out.ppm");
	out << "P3\n" << W << ' ' << H << ' ' << "255\n";

	// For each pixel on the screen
	for (int y=-halfH; y<halfH; ++y)
	{
		for (int x=-halfW; x<halfW; ++x)
		{
			// 1. Determine the ray this pixel
			Vector ray = Vector(x,y,DISTANCE);

			// 2. Determine the color seen through that ray
			Vector color = traceRay(origen, ray);

			// 3. Paint the pixel with that color
			out << (int)color.x << ' ' << (int)color.y << ' ' << (int)color.z << '\n';
		}
	}
}







/*
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

*/

