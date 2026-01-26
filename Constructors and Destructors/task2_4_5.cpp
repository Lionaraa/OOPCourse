#include <iostream>
#include <string>

class Item {
    std::string name; // название программы
    unsigned short duration; // длительность в минутах
public:
    Item() 
    {}
    Item(const char* str, unsigned short time) :
        name(str), duration(time)
    {}

    std::string& get_name() {
        return name;
    }
    unsigned short get_duration() {
        return duration;
    }
};

class TVProg {
    enum { max_length = 100 };
    Item items[max_length]; // программы 
    int count{0};  // число программ
public:
    TVProg(){}
    TVProg(const Item* it, int length) {
        count = length;
        for (int i = 0; i < count; ++i) {
            items[i] = it[i];
        }
    }

    void append(const Item& it) {
        if (count < max_length) {
            items[count] = it;
            ++count;
        }
    }
    void append(const Item* lst, int length) {
        
        if (count + length < max_length) {
            for (int i = 0; i < length; ++i) {
                items[count + i] = lst[i];
            }
            count += length;
        }
    }
    Item* get_list() {
        return items;
    }
    int get_count() {
        return count;
    }
};

int main() {
Item prog("Beatles", 4);
Item lst[6] = { {"Новости", 20}, {"Модный приговор", 50}, {"Жить здорово!", 60}, {"Информационный канал", 15}, {"Новости", 15}, {"Давай поженимся!", 70} };


}
