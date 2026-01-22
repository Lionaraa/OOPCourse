#include <iostream>
// Класс - точка
struct Point
{
	short x, y;
};
// Класс - полилиния
class PolyLine 
{
// приватные переменные
private:
	enum {max_coords = 10};
	Point coords[max_coords]{0};
	int total{ 0 };

public:
// конструктор по умолчанию
	PolyLine()
	{}
// передача массива коориднат, НО: массив передаём через цикл
	PolyLine(Point *ar, int size_ar) 
	{
		if (size_ar > max_coords) {
			size_ar = max_coords;
		}

		for (int i = 0; i < size_ar; ++i) {
			coords[i] = ar[i];
		}
		total = size_ar;
	
	}



// Присваиваем новые значения тоже через цикл
	void set_coords(const Point* ar, int size) {
		if (size > max_coords) {
			size = max_coords;
		}

		for (int i = 0; i < size; ++i) {
			coords[i] = ar[i];
		}
		total = size;
	}
// Добавляем новые координаты, сдвигаем total
	void append_coord(Point pt) {
		if (total <= max_coords) {
			coords[total] = pt;
			total++;
		}
	}
// Получаем координаты
	const Point* get_coords() {
		return  coords ;
	}

	int get_total() {
		return total;
	}
};


int main()
{
	Point coords[20];
	for (int i = 0; i < 20; ++i) {
		coords[i].x = i + 1;
		coords[i].y = i + 2;
	}

	PolyLine poly(coords, 20);
	PolyLine pl;
	pl.append_coord(coords[19]);
}
