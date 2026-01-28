class BottleWater
{
    enum { max_volume = 320 };
    unsigned volume{ 0 };
public:
// конструктор по умолчанию
    BottleWater() : volume(0) {}
    // конструктор преобразования
    BottleWater(unsigned volume)
    { // если больше или равно максимального значения, то верни максимальное
        this->volume = volume < max_volume ? volume : max_volume;
    }
    unsigned get_volume() const { return volume; }
    // ПЕРЕОПРЕДЕЛЕНИЕ ОПЕРАТОРА СЛОЖЕНИЯ
    BottleWater operator+ (const BottleWater& right) {
        // Когда вернём число, активируется конструктор
        // можно передать как и просто число, так и перевести всё в конструктор и 
        // вернуть его сразу
        return BottleWater(this->volume + right.volume);;
    }
};

int main() {
    BottleWater b1(10), b2(100);
    BottleWater res_1 = b1 + b2;
    BottleWater res_2 = b2 + 300;
}
