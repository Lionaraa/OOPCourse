#include <iostream>
#include <string>

// Процессор
struct CPU {
    std::string model;
    double fr;
public:
    CPU()
    {}
    CPU(const std::string& model, double fr) : model(model), fr(fr)
    {}
};
// Память! Если мы передаём длинный тип, то и в конструкторе стоит писать длинный тип
// чтобы не получать потом рандомное значение
struct Memory {
    std::string name;
    unsigned long long volume;
public:
    Memory()
    {}
    Memory(const std::string& name, unsigned long long volume) : name(name), volume(volume)
    {}
};

class MotherBoard {
    CPU cpu;
    Memory mems[2];
public:
    MotherBoard(const CPU& cpu, const Memory& mem_1,
        const Memory& mem_2) : cpu(cpu), mems{ mem_1, mem_2 }
    {}
    CPU& get_cpu() { return cpu; }
    Memory* get_mems() { return mems; }
};


int main() {
    CPU intel("CORE i5", 1.7);

    Memory m_1("Samsung", 4000000000);
    Memory m_2("Kingston", 8000000000);

    MotherBoard* ptr_mb = new MotherBoard(intel, m_1, m_2);
    delete ptr_mb;
}
