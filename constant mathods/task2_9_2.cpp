#include <iostream>

class BoxDims {
    unsigned short dimension{ 0 };
    unsigned* dims{ nullptr };
public:
    BoxDims(unsigned dim_1) : dimension(1)
    {
        dims = new unsigned {dim_1};
    }
    BoxDims(unsigned dim_1, unsigned dim_2) : dimension(2)
    {
        dims = new unsigned[2] {dim_1, dim_2};
    }
    BoxDims(unsigned dim_1, unsigned dim_2, unsigned dim_3) : dimension(3)
    {
       dims = new unsigned[3] {dim_1, dim_2, dim_3};
    }
    BoxDims(unsigned* d_arr, unsigned short size_d_arr) : dimension(size_d_arr)
    {
        dims = new unsigned[dimension];
        for (size_t i = 0; i < dimension; ++i) {
            dims[i] = d_arr[i];
        }
    }

    ~BoxDims()
    {
        delete[] dims;
    }

    // не константный метод, так как меняет объект, к которому принадлежит
    void set_dims(unsigned* ds);
    unsigned short get_dimension() const { return dimension; }
    const unsigned* get_dims() const { return dims; }
    unsigned get_volume() const;

};
// подразумевается, что массив не меньше длины массива dims 
void BoxDims::set_dims(unsigned* ds) {
    for (int i = 0; i < dimension; ++i) 
        dims[i] = ds[i];
}

unsigned BoxDims::get_volume() const {
    unsigned volume = 1;
    for (size_t i = 0; i < this->dimension; ++i) {
        volume *= dims[i];
    }
    return volume;
}
int main(void)
{
    BoxDims box(3, 10, 5);

    __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

    return 0;
}
