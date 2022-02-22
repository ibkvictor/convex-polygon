#include <array>
#include <type_traits>
#include <cstdlib>

namespace geometry{

template <typename T, typename std::enable_if<std::is_arithmetic<T>::value>::type* = nullptr>
class Point{
	private:
		struct Data {
			T x;
			T y;
			T z;
		};
		Data coordinates_;
	public:
		Point(T x, T y, T z){
			 coordinates_ = x;
			 coordinates_.y = y;
			 coordinates_.y = z;
		}
		
		Point(T x, T y){
			coordinates_.x = x;
			coordinates_.y = y;
			coordinates_.z = 0;
		}
		
		Data getPoint() const{
			return coordinates_;
		}
		void setX(T& x){
			coordinates_.x = x;
		}
		void setY(T& y){
                        coordinates_.y = y;
                }
		void setZ(T& z){
                        coordinates_.z = z;
                }
		
};

template <typename T, typename std::enable_if<std::is_arithmetic<T>::value>::type* = nullptr>
class PointArray{
	private:
		int size_;
		const Point<T>* start;
		void resize(int n){
                        Point<T>* temp = start;
                        start = new Point<T>[n];
                        for(auto i = 0;i < size_; i++){
                                *(start + i) = *(temp + i); //iterator to items assigning values
                        }
                        size_ = n;
                }	
	public:
		PointArray(){ //default constructor (size = 0 and empty array)
			start = new Point<T>[0];
			size_ = 0;
		}
		PointArray(const Point<T> points[], const int size){
			start =  points; //points is an implicit pointer to the first item in the array
			size_ = size;
		}
		PointArray(const PointArray& pv){ //copy constructor
			start = pv.start;
			size_ = pv.size_;
		}
		~PointArray(){
			delete start;
		}
		void pushback(Point<T>& p){
			resize(size_ + 1);
			*(start + size_ - 1) = p;
		
		}
		void insert(const int position, const Point<T> &p){
			Point<T>* tmp = start;
			resize(size_ + 1);
			*(start + position) = p;
			for(int i = position + 1; i < size_; i++){
				*(start + i) = *(tmp + i - 1);
			}
			tmp = nullptr;
		}
		void remove(const int position){
			Point<T>* tmp = start;
			resize(size_ - 1);
			for(int i = position + 1; i < size_; i++){
                                *(start + i - 1) = *(tmp + i);
                        }
			tmp = nullptr;
		}
		const int getSize() const{
			return size_;
		}
		void clear(){
			resize(0);
		}
		Point<T>* get(const int position){
                        if(position >= size_){
                                return nullptr;
                        }
			return (start + position);
		}
		const Point<T>* get(const int position) const{
			if(position >= size_){
				return nullptr;
			}
			return (start + position);
		}			
};	
} //namespce geometry

