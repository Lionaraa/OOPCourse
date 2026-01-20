#include <iostream>

class Table {
    unsigned width, height, depth;
public:
    void set_dims(unsigned width, unsigned height, unsigned depth) {
        this->width = width;
        this->height = height;
        this->depth = depth;
}


    int get_width() {
        return width;
    }

    int get_height() {
        return height;
    }

    int get_depth() {
        return depth;
    }

};           

int main() {
    Table t1;
    t1.set_dims(10, 10, 5);

    Table t2;
    t2.set_dims(7,20,7);

    Table t3;
    t3.set_dims(12,40, 6);

}
