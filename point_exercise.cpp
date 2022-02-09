#include "point.hpp"
#include <iostream>

using namespace geometry;

int main(){
	std::array<Point<int>, 4> parray {Point (0 ,1) , Point (1 ,2) , Point (3 ,5) , Point (8 ,13)};
	for(int i = 0; i < 4; i++){
		std::cout<<parray[i].getPoint().x<<std::endl;
	}
}
