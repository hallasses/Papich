#include <iostream>
#include <vector>


class Base {
public:
	virtual void show() = 0;
};

template <class T>
class Point2D {
public:
	Point2D(T x, T y) : x(x), y(y) {}

protected:
	T x, y;
};

template <class T>
class Z {
public:
	Z(T z) : z(z) {}

protected:
	T z;
};

template <class T>
class H {
public:
	H(T h) : h(h) {}

protected:
	T h;
};

template <class T>
class Point3Dh : public Point2D<T>, public Z<T>, public H<T>, public Base {
public:
	Point3Dh(T x, T y, T z, T h) : Point2D<T>(x, y), Z<T>(z), H<T>(h) {}
	void show() {
		if (this->h != 0)
			std::cout << "(" << this->x / this->h << ", " << this->y / this->h << ", " << this->z / this->h << ")" << std::endl;
		else
			std::cout << "4 координата не должна равняться 0" << std::endl;
	}
};

int main() {
	setlocale(LC_ALL, "Russian");
	Point3Dh <int> p1(3, 4, 2, 3);
	p1.show();
	Point3Dh <short> p2(4, 2, 2, 0);
	p2.show();
	Point3Dh <float> p3(6.4, 4.7, 3.4, 3.2);
	p3.show();
	Point3Dh <double> p4(3.2, 5.1, 3.2, 2.2);
	p4.show();
	Point3Dh <long> p5(5, 2, 3, 2);
	p5.show();
	std::vector<Base*> v;
	v.push_back((Base*)&p1);
	v.push_back((Base*)&p2);
	v.push_back((Base*)&p3);
	v.push_back((Base*)&p4);
	v.push_back((Base*)&p5);
	for (int i = 0; i < v.size(); i++)
	{
		std::cout << i + 1 << " - ";
		v[i]->show();
	}
}
