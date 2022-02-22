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
        //definition of static variable


	/// create a rectangle
        int a; int b; int c; int d;
	for(int i = 0; i < 4; i++){
		std::cin>> a >> b >> c >> d;
                //rect_points[i] = new Point<int> (x, y);
	}
	Rectangle<int> r (a, b, c, d);
	/// create a triangle
        Point<int>* trig_points[3];
        for(int i = 0; i < 3; i++){
		int x;
		int y;
		std::cin>> x >> y;
                trig_points[i] = new Point<int> (x, y);
        }
	Triangle<int> t (*trig_points);

	printAttributes<int>(&r);
	printAttributes<int>(&t);
}
