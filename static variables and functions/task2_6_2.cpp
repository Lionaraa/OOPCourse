#include <iostream>

class Window {
private:
// статическая переменная, которая считает количество созданных объектов
    static unsigned long total;
    int width, height, color;
public:
// при создании объекта увеличиваем на 1
    Window (int w, int h, int c) : width(w), height(h), color(c)
    {
        ++total;
    }

    static unsigned long get_total();
    void set_size(int w, int h) {
        width = w;
        height = h;

    }
    void get_size(int& w, int& h){
        w = width;
        h = height;
    }
    int get_color() {
        return color;
    }
};

unsigned long Window::total{0};
// возвращаем счётчи
unsigned long Window::get_total() {
    return total;
}

int main() {
    Window* ptr_wnd = new Window(200, 100, 255);
    delete ptr_wnd;
}
