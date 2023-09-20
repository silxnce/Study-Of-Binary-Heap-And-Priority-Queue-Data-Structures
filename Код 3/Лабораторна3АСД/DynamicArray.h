#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

struct Data   // Структура домашнього завдання
{
    Data();   // Конструктор
    char task[36];   // Назва завдання
    int utility, diff, urgency, interest;   // Корисність, складність, терміновість, цікавість

    bool operator<(const Data& second) const;   // Прототипи перевантажень операторів
    bool operator==(const Data& second) const;
    bool operator<=(const Data& second) const;
};

struct DynamicArray // Структура динамічного масиву
{
    DynamicArray(); // Конструктор
    ~DynamicArray(); // Деструктор

    Data* array;
    int currSize, size;

    void relocMem(); // Перевиділення пам'яті
    void push_back(Data obj); // Додавання елементу в кінець
    void pop_back();   // Видалення останнього елементу
    Data get(int id);   // Отримання елементу за індексом
    void clear();   // Очищення масиву
};
#endif