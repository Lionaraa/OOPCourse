#include <iostream>
#include <cstring>
//Создание класса
class CartData {
public:
  void get_data(unsigned long &id, unsigned &price, double &weight){
    id = this->id;
    price = this->price;
    weight = this->weight;
  }  

  char* get_name() {
    return name;
  }
// Передаём данные в объект
  void set_data(unsigned long id, const char* name, unsigned price, double weight){
    this->id = id;
    this->price = price;
    this->weight = weight;
// чтобы перенести строку в объект, используем strncpy, мы копируем c-подобную строку
    // можно перебрать через цикл
    strncpy(this->name, name, sizeof(this->name));

  }


private:
    unsigned long id;
    char name[100];
    unsigned price;
    double weight;    
};

int main() {
    CartData obj;
    obj.set_data(10,"Toy", 2000, 5.45);
}
