#include <iostream>
#include <algorithm>
#include <numeric>
class IntOperator
{
private:
	int* data{ nullptr };
	int size{ 0 };
public:
	IntOperator ()
	{}
	// передача массива через указатель!
	IntOperator(int* ptr, int sz) {
		size = sz;
		data = ptr;
	}
	int sum() {
		int s = std::accumulate(data, data + size, 0);
		return s;
	}
	int max() {
		return *std::max_element(data, data + size);

	}
	int min() {
		return *std::min_element(data, data + size);
	}

	double average() {
		double s = this->sum();
		return s / size;
	}
	~IntOperator() 
	{
		for (size_t i = 0; i < size; ++i) {
			data[i] = 0;
		}
	}

};


int main() {
	int dt[] = { 0, -5, 2, 10, 7, 22 };
	IntOperator op_1;
	IntOperator op2(dt, std::size(dt));
	std::cout << op2.sum();


}

/*

небольшой экскурс в STL:

импортируем следующие модули:

#include <algorithm>
#include <numeric>
из <algorithm> нам понадобятся max_element и min_element, из <numeric> accumulate.
что делают max_element и min_element понятно из названия, однако синтаксис стоит разобрать:
max_element(ptr_beginning_array, ptr_end_array), названия параметров отражают их суть. указатель на конец массива можно записать как "указатель на начало массива+длина массива".
min_element работает так же.
функции возвращают УКАЗАТЕЛЬ на нужный элемент
accumulate(ptr_beginning_array, ptr_end_array, volume_to_add)- возвращает сумму элементов массива, прибавленных к volume_to_add.
в принципе, это все что я хотел сказать, дальше думайте сами
*/
