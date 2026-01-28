class GamePole {
    int rows{ 0 }, cols{ 0 };
    char* pole;
    //Напоминание указатель должен быть типа класса
    static GamePole* ptr;
    // конструторы
    GamePole() = default;
    GamePole(const GamePole&) = default;
public:
// инициалиация с помощью функции, она не позволяет создать больше
// одного объекта

// сам метод статический, так как не зависит от конкретного объекта
    static GamePole* init(int a, int b) {
        if (ptr == nullptr) {
            ptr = new GamePole;
            ptr->rows = a;
            ptr->cols = b;
            ptr->pole = new char[a*b] {0};
        }
        return ptr;
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
    void get_size(int& rows, int& cols) const {
        rows = this->rows;
        cols = this->cols;
    }

};
// ОБЯЗАТЕЛЬНО удаляем
GamePole* GamePole::ptr {nullptr};

int main(void)
{
    GamePole* p =  GamePole::init(5,10);

    p->set_item(1,1, '@');
    p->set_item(4,9, '#');
    p->set_item(3,2, '*');
    delete p;
    return 0;
}
