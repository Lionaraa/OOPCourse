#include <iostream>
#include <string>

class Notes {
    private:
        std::string title;
        std::string author;
        int pages;
    // Передаём данные на основе внешних переменных
    public:
        void set_data(const std::string& title, const std::string& author, int pages) {
            this->title = title;
            this->author = author;
            this->pages = pages;
        } 
        // Устанавливаем данные на основе другого объекта
        void set_data(const Notes& note){
            this->title = note.title;
            this->author = note.author;
            this->pages = note.pages;
        }

        const std::string& get_title() {
            return title;
        }
        const std::string& get_author() {
            return author;
        }
        int get_pages() {
            return pages;
        }

};

int main() {

    Notes* ptr_note1 = new Notes;
    ptr_note1->set_data("Фантазия экспромт",  "Ф. Шопен", 5);

    Notes* ptr_note2 = new Notes;
    // Чтобы связать объект и другое название, мы разыменовываем указатель
    // потому что на том месте, куда указывает указатель, наш объект и находится
    ptr_note2->set_data(*ptr_note1);

    // удаляем 
    delete ptr_note1;
    delete ptr_note2;
}
