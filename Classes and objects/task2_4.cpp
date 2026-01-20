#include <iostream>
#include <string>
struct Person {
    public:
        void set_person_data(const std::string &fio, const std::string &job, unsigned char old) {
            this->fio = fio;
            this->job = job;
            this->old = old;
        }

        void set_person_data(const Person& p) {
            *this = p;
        }
        void get_data(std::string &fio, std::string &job, unsigned char& old) {
            fio = this->fio;
            job = this->job;
            old = this->old;
        }

    private:
        std::string fio;
        std::string job;
    unsigned char old;
};

int main() {
    Person p1, p2;
    p1.set_person_data("С.М. Балакирев", "Просветитель", 84);
    p2.set_person_data(p1);
}
