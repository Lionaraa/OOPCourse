#include <iostream>

class CellItem {
private:
    int row{ 0 }, col{ 0 };
    double data{ 0.0 };
public:
    CellItem(int n_row, int n_col) : row(n_row), col(n_col)
        {}
    CellItem(int n_row, int n_cl, double d) : CellItem(n_row, n_cl) {data = d;}

    int get_row() const { return row; }
    int get_col() const { return col; }

    double get_data() const { return data; }
    void set_data(double d) { data = d; }
};

int main(void)
{
       CellItem cell(5, 7, 0.79);

    __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

    return 0;
}
