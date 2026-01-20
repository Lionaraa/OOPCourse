#include <iostream>
#include <string>

class TravelBlog {
private:
    std::string country;
    short days;
/* здесь была ошибка связанная с &days в функции и выдавало ошибку из-за
несоответствия типов, поэтому
Невозможно создать ссылку на временное значение (rvalue) - число 10 является
 временным значением типа int, а функция ожидает short&.

 Вывод: используем обычную переменную
*/
public:
    void set_info(const std::string &country, short days) {
        this->country = country;
        this->days = days;
    }
// Передача данных из объекта в другой объект
    void set_info(const TravelBlog& blog) {
        *this = blog;
    }
    const std::string& get_country() {
        return country;
    }
    const short get_days() {
        return days;
    }

};

int main() {
    TravelBlog blog1, blog2;

    blog1.set_info("ОАЭ", 10);
    blog2.set_info(blog1);

}
