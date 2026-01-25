#include <iostream>
#include <string>
class Person {
	std::string fio;
	short age{0};
	long salary{0};
public:
	Person(const std::string& fio) : fio(fio) 
	{
		std::cout << "Person(string)";
	}
// Пример делегирующего конструктора
	Person(const std::string& fio, short age, long salary) : Person(fio)
	{ 
		this->age = age;
		this->salary = salary;
	}
	
	void get_data(std::string& fio, short& age, long& salary)
	{ 
		fio = this->fio; age = this->age; salary = this->salary;
	}
};


int main() {
	Person* ptr_p = new Person("Рахманинов С.В.", 75, 13204);
	delete ptr_p;
}
