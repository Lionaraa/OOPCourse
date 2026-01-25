#include <iostream>
#include <string>
class Notebook 
{
private:
    std::string model; // модель ноутбука
    std::string cpu_model; // модель процессора
    unsigned memory{0}; // объём оп в Мб
    unsigned disk_volume {0}; // объём дискового пространства ГГб
public:
    Notebook() 
    {}
    //передаём указатель, так как при неявном вызове подаётся C строка
    Notebook(const char* name) : model(name)
    {}
    Notebook(const char* name, const char* name_model)
        : Notebook(name)
    {
        cpu_model = name_model;
    }
    Notebook(const char* name, const char* name_model, unsigned memory_size)
        : Notebook(name, name_model)
    {
        memory = memory_size;
    }
    Notebook(const char* name, const char* name_model, unsigned memory_size, unsigned disk_v)
        : Notebook(name, name_model, memory_size)
    {
        disk_volume = disk_v;
    }
    
    void set_data(const std::string& model,
                const std::string& cpu,
                unsigned memory,
                unsigned disk) {
        this->model = model;
        this->cpu_model = cpu;
        this->memory = memory;
        this->disk_volume = disk;
    }

    std::string& get_model() {
        return model;
    }
    std::string& get_cpu() {
        return cpu_model;
    }
    void get_info(unsigned& memory, unsigned& disk_volume) {
        memory = this->memory;
        disk_volume = this->disk_volume;
    }

};


int main() {
    Notebook note= "HP";
    note.set_data("HP", "Intel core i5", 1000, 2);
}
