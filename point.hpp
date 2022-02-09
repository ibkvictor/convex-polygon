#include <array>
#include <type_traits>

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
		
};

} //namespce geometry

