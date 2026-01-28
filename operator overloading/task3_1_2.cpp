class StudentMarks
{
    enum { max_length = 100 };
    short marks[max_length]{ 0 };
    int count{ 0 };
public:
    StudentMarks(short* ms, int total)
    {
        count = (total > max_length) ? max_length : total;

        for (int i = 0; i < count; ++i) {
            marks[i] = ms[i];
        }
    }


    const short* get_marks() const { return marks; }
    int get_count() const { return count; }
    // C помощью двух методов реализовали оператор + с типом short и StudentMarks
    StudentMarks operator+ (const StudentMarks& right) {
        // Создали новый массив, перенесли туда оценки, сначала оценки левой части, затем правой
        short all_marks[max_length];
        for (int i = 0; i < this->count; ++i) {
            all_marks[i] = this->marks[i];
        }
        for (int i = 0; i < right.count; ++i) {
            all_marks[this->get_count() + i] = right.marks[i];
        }
        // передаём его в конструктор, выполнится проверка и всё равно длина, которую мы переберём будет 
        // count или max_length
        return StudentMarks(all_marks, this->count + right.count);

    }
    // то же самое, только переносим один массив и добавляем в конец массива в число
    StudentMarks operator+ (int num) {
        short all_marks[max_length];
        for (int i = 0; i < this->count; ++i) {
            all_marks[i] = this->marks[i];
        }
        all_marks[this->count] = num;
        // всё равно будет выполнена проверка на count
        return StudentMarks(all_marks, this->count + 1);
    }
};

int main() {
    short m[] = { 2, 2, 3, 2, 3 };
    short k[] = { 5, 4, 2 };
    StudentMarks marks_1(m, sizeof(m) / sizeof(*m));
    StudentMarks marks_2(k, sizeof(k) / sizeof(*k));

    StudentMarks res_1 = marks_1 + marks_2; // res_1: marks = {2, 2, 3, 2, 3, 5, 4, 2}, count = 8
    StudentMarks res_2 = marks_1 + 4; // res_2: marks = {2, 2, 3, 2, 3, 4}, count = 6

}
