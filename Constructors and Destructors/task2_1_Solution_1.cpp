// Задание из 2.2 1 
// Нужно создать такие конструкторы, которые переводили бы из строки в числа
#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
// проверка
int convert_to_int(const std::string& first) {
	char c = first[0];
	// проверяем, что первый символ не буква или другой знак
	// если это -, то проверяем следующий сивол и тогда возвращаем 0 или -число
	if (std::isdigit(static_cast<unsigned char>(c)) or 
		(c == '-' and std::isdigit(static_cast<unsigned char>(first[1]))))
	{
		return stoi(first);
	}
	else {
		return 0;
	}
}

//  Для этого используем библиотеку sstream для ввода потока
// Распреедлим поток по переменным и и с помощью функции конвертируем
// либо в 0 либо в число
class Point {
	int x, y;
public:
	Point() : x(0), y(0)
	{}
	// передаём массив char (чтобы передать строку без переменной)
	// нужно передавать её через указатель
	Point(const char* str) {
		//поток
		std::stringstream ss(str);
		std::string a, b;
		// распределяем поток
		ss >> a >> b;
		// конвертируем в число
		x = convert_to_int(a);
		y = convert_to_int(b);
	}
	int get_x() { return x; }
	int get_y() { return y; }
};

int main() {
	Point p_1 = "-5.5 -2.3";
}
