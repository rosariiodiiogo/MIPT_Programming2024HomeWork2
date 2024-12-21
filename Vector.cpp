// Vector.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

class Vector
{
public:
	Vector() //Default constructer
	{
		_x = 0;
		_y = 0;
		_z = 0;
	}

	Vector(int x, int y, int z)
	{
		_x = x;
		_y = y;
		_z = z;
	}

	Vector(int x, int y)
	{
		_x = x;
		_y = y;
		_z = 0;
	}

	void setX(int x)
	{
		_x = x;
	}

	int getX()
	{
		return _x;
	}

	void setY(int y)
	{
		_y = y;
	}

	int getY()
	{
		return _y;
	}

	void setZ(int z)
	{
		_z = z;
	}

	int getZ()
	{
		return _z;
	}

	double modulus()
	{
		return (double) sqrt(pow(_x, 2) + pow(_y, 2) + pow(_z, 2));
	}

	static Vector sum(Vector u, Vector v)
	{
		int x = u._x + v._x;
		int y = u._y + v._y;
		int z = u._z + v._z;

		Vector w(x, y, z);

		return w;
	}

	static Vector subtraction(Vector u, Vector v)
	{
		int x = u._x - v._x;
		int y = u._y - v._y;
		int z = u._z - v._z;

		Vector w(x, y, z);

		return w;
	}

	static Vector scalarMultiplication(int k, Vector u)
	{
		int x = k * u._x;
		int y = k * u._y;
		int z = k * u._z;

		Vector w(x, y, z);

		return w;
	}

	static int dotProduct(Vector u, Vector v)
	{
		int x = u._x * v._x;
		int y = u._y * v._y;
		int z = u._z * v._z;

		int dotProduct = x + y + z;

		return dotProduct;
	}

	static Vector crossProduct(Vector u, Vector v)
	{
		int x = u._y * v._z - v._y * u._z;
		int y = - (u._x * v._z - v._x * u._z);
		int z = u._x * v._y - v._x * u._y;

		Vector w(x, y, z);

		return w;
	}

	static int scalarTripleProduct(Vector u, Vector v, Vector w)
	{

		Vector a = crossProduct(u, v);
		int b = dotProduct(w, a);

		return b;
	}

	static bool linearDependence(Vector u, Vector v)
	{
		int determinant1 = (u._x * v._y - v._x * u._y);
		int determinant2 = (u._y * v._z - v._y * u._z);

		if (determinant1 != 0)
		{
			return false;
		}
		else if (determinant1 == determinant2)
		{
			return true;
		}
		else
			return true;
	}

	static bool linearDependence(Vector u, Vector v, Vector w)
	{
		int determinant = scalarTripleProduct(u, v, w);

		if (determinant == 0)
		{
			return true;
		}
		else
			return false;
	}

	static double angleOfTwoVector(Vector u, Vector v)
	{
		int a = dotProduct(u, v);
		double b = u.modulus() * v.modulus();
		double c = (double) a / b;

		return acos(c) * 180 / 3.141592;
	}

	void displayVector()
	{
		cout << "(" << _x << ", " << _y << ", " << _z << ")" << endl;
	}

private:
	int _x;
	int _y;
	int _z;
};

int main()
{
	Vector a(1, 0, 2);
	Vector b(2, -7, -3);
	Vector c(3, 1, 7);

	Vector u(1, 2, 4);
	Vector v(2, 5, 8);
	Vector w;
	Vector z;

	cout << "a: "; 
	a.displayVector();

	cout << "b: ";
	b.displayVector();

	cout << "c: ";
	c.displayVector();

	cout << "u: ";
	u.displayVector();

	cout << "v: ";
	v.displayVector();

	cout << "---------------------" << endl;

	cout << "Modulus |u|: " << u.modulus() << endl;
	cout << "Dot Product u.v: " << Vector::dotProduct(u, v) << endl;

	cout << "Scalar Multiplication 3 * u: ";
	z = Vector::scalarMultiplication(3, u);
	z.displayVector();

	cout << "Sum u + v: ";
	w = Vector::sum(u, v);
	w.displayVector();

	cout << "Subtraction u - v: ";
	w = Vector::subtraction(u, v);
	w.displayVector();

	cout << "Cross Product (u x v) = w: ";
	w = Vector::crossProduct(u, v);
	w.displayVector();

	int d = Vector::scalarTripleProduct(u, v, w);
	cout << "Scalar Triple Product u.(v x w): " << d << endl;

	cout << setprecision(2) << fixed << "Angle between uv: " << Vector::angleOfTwoVector(u, v) 
		<< " degrees" << endl;
	cout << boolalpha << "Linear dependence uv: " << Vector::linearDependence(u, v) << endl;
	cout << boolalpha << "Linear dependence abc: " << Vector::linearDependence(a, b, c) << endl;
}