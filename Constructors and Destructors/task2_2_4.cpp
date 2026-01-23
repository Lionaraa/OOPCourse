#include <iostream>

class VectorN 
{
private:
	int dims{ 0 };
	short* coords{ nullptr };
public:
	VectorN(int a) : dims{ a } 
	{
		coords = new short[dims];
		for (size_t i = 0; i < dims; ++i) {
			coords[i] = 0;
		}
	}

	explicit VectorN(int a = 0, int b = 0) : dims{ 2 } 
	{
		coords = new short[dims];
		coords[0] = a;
		coords[1] = b;
	}
	VectorN(short* data, int n) : dims{n} 
	{
		coords = new short[dims];
		for (size_t i = 0; i < dims; ++i) {
			coords[i] = data[i];
		}

	}
	~VectorN() {
		std::cout << "delete coords:";
		for (size_t i = 0; i < dims; ++i) {
			std::cout << ' ' << coords[i];
		}
		std::cout << std::endl;
		delete[] coords;
		coords = nullptr;
	}

	const short* get_coords() {
		return coords;
	}
	
	int get_dims() {
		return dims;
	}


};

int main() {
	short data[] = { 4, 2, 10, 0, -5 };
	VectorN v1 = 5;
	VectorN v2(1, 2); // формирование вектора с двумя координатами: 1 2
	VectorN v3(data, std::size(data)); // формирование вектора с переданными координатами data
}
