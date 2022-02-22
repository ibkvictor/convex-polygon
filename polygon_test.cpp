#include "polygon.hpp"
#include <iostream>

using namespace geometry;

template <typename T,  typename std::enable_if<std::is_arithmetic<T>::value>::type* = nullptr>
void printAttributes(Polygon<T>* poly){
        std::cout<<poly->area()<<std::endl;
        for(int i = 0; i < poly->getNumSides(); i++){
                std::cout<<"point: "<<i+1;
                std::cout<<" "<<(poly->getPoints() + i)->getPoint().x;
                std::cout<<" "<<(poly->getPoints() + i)->getPoint().y;
        }
}

int main(){
	/// create a rectangle
	Point<int>* rect_points[2];
	for(int i = 0; i < 2; i++){
		int x;
		int y;
		std::cin>> x >> y;
                rect_points[i] = new Point<int> (x, y);
	}
	Rectangle<int> r {rect_points};
	/// create a triangle
        Point<int>* trig_points[3];
        for(int i = 0; i < 3; i++){
		int x;
		int y;
		std::cin>> x >> y;
                rect_points[i] = new Point<int> (x, y);
        }
	Triangle<int> t {trig_points};

	printAttributes(&r);
	printAttributes(&t);
}
