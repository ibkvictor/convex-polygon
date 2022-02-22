include "point.hpp"

using std::array;

namespace geometry{

template <typename T>
class Polygon{
	protected:
		PointArray<T> p;
		static int i;
	public:
		Polygon(Point<T> holder[], size){
			p{holder};
			i++;
		}
		virtual double area() const = 0;
		inline int getNumPolygons() const {
			return i;
		}
		virtual int getNumSides() const {
			return p.getSize();
		}
		const Point* getPoints() const{
			const ptr = &p;
			return ptr;
		}
		~Polygon(){
			i--;
		}
		
};

template <typename T>
class Rectangle: public Polygon{
	public:
		Rectangle(Point<T> holder[4]) : Polygon(holder, 4){
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
		Rectangle(Point<T> holder[2]) : Polygon{holder, 2}{
			length = holder[0].getPoint().y - holder[1].getPoint().y;
			breadth = holder[0].getPoint().x - holder[1].getPoint().x;
		}
		
		double area() override {
			return length * breadth;
		}

	private:
		double length;
		double breadth;
};

template <typename T>
class Triangle: public Polygon{
	public:
                Triangle(Point <T> holder[3]) : Polygon(holder, 3){
			a = distance(&holder[0], &holder[1]);
			b = distance(&holder[0], &holder[2]);
			c = distance(&holder[1], &holder[2]);
			s = (a + b + c)/3;
                }

                double area() const override {
                        return length * breadth;
                }		

        	double area() const override {
                	return std::pow((s * (s - a) * (s - b) * (s - c)), 0.5);
        	}
		int getNumSides() const {
			return 3;
		}

        private:
                double s;
		double a;
		double b;
		double c;
		static inline double distance(const Point& one, const Point& two){
			return std::pow((std::pow(one.getPoint().x - two.getPoint().x, 2) + std::pow(one.getPoint().y - two.getPoint().y), 2), 0.5);
		}
};
}// namespace geometry
