class GamePole {
    int rows{0}, cols{0};
    char* pole {nullptr};
public:
    // Конструтро, который принимает 2 числа 
    GamePole (int rows, int cols) : rows(rows), cols(cols) {
        pole = new char[rows * cols];
    }
    // конструктор копирования, используем иего, потому что
    // мы инициализируем объект другим объектом, а не присваиваем
    // соответственно оператор переорпределять не нужно
    GamePole(const GamePole& p) : rows(p.rows), cols(p.cols)
    {   // соответственно делаем так, чтобы указатель указывал
    // хоть на какую-то ячейку и копируем туда данные
        pole = new char[rows*cols];
        for (int i = 0; i < rows * cols; ++i) {
            pole[i] = p.pole[i];
        }
    }
    // всё удалить к чертям
    ~GamePole() {
        delete[] pole;
    }


    void set_item(int row, int col, char value) {
        int index = row * cols + col;
        pole[index] = value;
    }
    char get_item(int row, int col) const {
        int index = row * cols + col;
        return pole[index];
    }
    const char* get_pole() const {
        return pole;
    }
    void get_size(int& rows, int& cols) const{
        rows = this->rows;
        cols = this->cols;
    }

};

int main(void)
{
    GamePole gp(10, 7);
    gp.set_item(3, 5, '#');
    gp.set_item(4, 2, '*');
    gp.set_item(4,4,'*');

    __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

    return 0;
}
