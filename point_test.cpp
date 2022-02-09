#include <array>
#include <iostream>

const int* jeff(){
	int* b = new int[] {5,6,7,8};
	int* temp = b;
	b = new int[5];
	for(int i = 0; i < 4; i++){
		*(b + i) = *(temp + i);
	}
	delete temp;
	std::cout<<t[1]<<std::endl;
	return b;
}

int main(){
	int a[3] {1, 2, 3};
	std::array<int, 3>* a_ptr = new std::array<int, 3>;
	std::cout<<&(*a_ptr)[1]<<std::endl;
	std::cout<<&a[1]<<std::endl;
	delete a_ptr;
	a_ptr = new std::array<int, 3>;
	std::cout<<a[1]<<std::endl;
	std::cout<<jeff()<<std::endl;
	
	int p[4] {1,2,4,5};
	int* ptr = p;
	*(ptr + 3) = 3;
	std::cout<<p[3]<<std::endl;
}



