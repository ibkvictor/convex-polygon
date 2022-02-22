#include "point.hpp"
#include <cmath>

using std::array;

namespace geometry{

template <typename T, typename std::enable_if<std::is_arithmetic<T>::value>::type* = nullptr>
class Polygon{
	protected:
		PointArray<T> p;
		static inline int i;
	public:
		Polygon(Point<T> holder[], int size): p(holder, size){
			i++;
		}
		Polygon(PointArray<T> &holder): p(holder){
			i++;
		}
		virtual double area() const = 0;
		inline int getNumPolygons() const {
			return i;
		}
		virtual int getNumSides() const {
			return p.getSize();
		}
		const Point<T>* getPoints() const{
			return p.get(0);
		}
		~Polygon(){
			i--;
		}
		
};

template <typename T, typename std::enable_if<std::is_arithmetic<T>::value>::type* = nullptr>
class Rectangle: public Polygon<T>{
	private:
		double length;
		double breadth;
	public:
		Rectangle(Point<T> holder[4]) : Polygon<T>(holder, 4){
			double x = holder[0].getPoint().x;
			double y = holder[0].getPoint().y;
			for(auto& ptr: holder){
				if(ptr.getPoint().x == x && ptr.getPoint().y != y){
					breadth = ptr.getPoint().x - x;
				}
				if(ptr.getPoint().y == y && ptr.getPoint(),x != x){
					length = ptr.getPoint().y - y;
				}
			}
		}
		Rectangle(int a, int b, int c, int d): Polygon<T>((Point<T>[]) {Point<T> (a, b), Point<T> (c, d)}, 2){
			length = std::abs(a - c);
			breadth = std::abs(b - d);
		}

		double area() const override {
			return length * breadth;
		}


};

template <typename T,  typename std::enable_if<std::is_arithmetic<T>::value>::type* = nullptr>
class Triangle: public Polygon<T>{
	public:
		Triangle(Point <T> holder[3]) : Polygon<T>(holder, 3){
			a = distance(holder[0], holder[1]);
			b = distance(holder[0], holder[2]);
			c = distance(holder[1], holder[2]);
			s = (a + b + c)/3;
			}

		double area() const override {
			return std::pow((s * (s - a) * (s - b) * (s - c)), 0.5);
		}
		// int getNumSides() const override {
		// 		return 3;
		// }

        private:
                double s;
		double a;
		double b;
		double c;
		static inline double distance(const Point<T>& one, const Point<T>& two){
			return std::pow(std::pow(one.getPoint().x - two.getPoint().x, 2) + std::pow((one.getPoint().y - two.getPoint().y), 2), 0.5);
		}
};
}// namespace geometry
