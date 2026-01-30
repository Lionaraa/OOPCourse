#include <iostream>

#include <iostream>
#include <cstring>
class StringChars {
    char* buffer{ nullptr };
    size_t length{ 0 };
public:
    StringChars(const char* str) {
        length = std::strlen(str);
        buffer = new char[length + 1];
        size_t i = 0;
        while (str[i] != '\0')
        {
            buffer[i] = str[i];
            i++;
        }
        buffer[length] = '\0';
    }

    StringChars(const StringChars& other) {
        length = other.length;

        buffer = new char[length + 1];
        size_t i = 0;
        while (other.buffer[i] != '\0')
        {
            buffer[i] = other.buffer[i];
            i++;
        }
        buffer[length] = '\0';
    }

    ~StringChars() {
        delete[] buffer;
    }

    StringChars operator+ (const StringChars& b) {
        size_t n_length = b.length + length;
        char* n_str = new char[n_length + 1];

        size_t i = 0;
        while (buffer[i] != '\0') {
            n_str[i] = buffer[i];
            ++i;
        }
        size_t j = 0;
        while (b.buffer[j] != '\0') {
            n_str[i + j] = b.buffer[j];
            ++j;
        }
        n_str[n_length] = '\0';
        StringChars res = StringChars(n_str);
        // инициализируем переменную и возвращаем результат
        // делаем именно так, чтобы избежать утечки памяти
        delete[] n_str;
        return res;

    }

    char* to_str() const { return buffer; }
    size_t get_length() const { return length; }



};

int main(void)
{
    StringChars* ptr_str1 = new StringChars("Language");
    StringChars* ptr_str2 = new StringChars(" C++");
    StringChars res = (*ptr_str1) + (*ptr_str2);

    __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

    delete ptr_str1;
    delete ptr_str2;
    ptr_str1 = ptr_str2 = nullptr; 

    return 0;
}
