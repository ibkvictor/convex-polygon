#include "polygon.hpp"

using namespace geometry;

printAtributes(Polygon* poly){
        std::cout<<poly->area()<<std::endl;
        for(int i = 0; i < poly->getNumSides(); i++){
                std::cout<<"point: "<<i+1;
                std::cout<<" "<<p.get(i)->getPoint().x;
                std::cout<<" "<<p.get(i)->getPoint().y;
        }
}

int main(){
	/// create a rectangle
	Point<int> rect_points[2];
	for(int i = 0; i < 2; i++){
		int x;
		int y;
		cin>> x >> y;
		rect_points[i].setX(x);
		rect_points[i].setY(y);
	}
	Rectangle<int> r{rect_points};
	/// create a triangle
        Point<int> trig_points[3];
        for(int i = 0; i < 3; i++){
                int x;
                int y;
                cin>> x >> y;
                rect_points[i].setX(x);
                rect_points[i].setY(y);
        }
	Triangle<int> t{trig_points};

	printAttributes(&r);
	printAttributes(&t);
}
