#include <iostream>
#include <string>
// Подаём текущее время
class Clock {
    unsigned time_current;
public:
//ВАЖНО: формулы для расчёта времени
    void set_time(unsigned tm) {
        time_current = tm;
    }
    unsigned get_hours() {
        return time_current / 3600 % 24;
    }
    unsigned get_minutes() {
        return time_current / 60 % 60;
    }
    unsigned get_seconds() {
        return time_current % 60;
    }
};
// Вывод числа либо 02 или 21 к примеру, можно решить с помощью printf и регулярок
std::string output(int num) {
    std::string a;
    if (num < 10) {
        a = "0" + std::to_string(num);
    } else {
        a = std::to_string(num);
    }
    return a;
}


int main() {
    // Инициализируем и т.п.
    Clock* ptr_cd = new Clock;
    unsigned tm;
    std::cin >> tm;
    ptr_cd->set_time(tm);

    unsigned hours = ptr_cd->get_hours();
    unsigned minutes = ptr_cd->get_minutes();
    unsigned seconds = ptr_cd->get_seconds();
    // Вывод формала
   std::cout << output(hours) << ":" << output(minutes) << ":" << output(seconds); 
   delete ptr_cd;
}
