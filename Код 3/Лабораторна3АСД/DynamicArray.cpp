#include "DynamicArray.h"
#include <iostream>
#include <cstdlib>
#include <cmath>

Data::Data()   // Конструктор
{
    char taskArr[15][36] = { "C++ Programming Assignment", "Data Structures Project", "Algorithms Homework", "Object-Oriented Design Exercise", "Software Engineering Assignment",
        "Database Design Task", "Computer Graphics Project", "Operating Systems Lab Report", "Artificial Intelligence Programming", "Networking Assignment",
        "Web Development Project", "Mobile App Development Task", "Embedded Systems Programming", "Game Development Challenge", "Compiler Design Assignment" };
    strcpy_s(task, taskArr[rand() % 15]);   // Випадкова генерація інформації про завдання
    utility = rand() % 11;
    diff = rand() % 11;
    urgency = rand() % 11;
    interest = rand() % 11;
}

bool Data::operator<(const Data& second) const
{
        if (utility != second.utility)   // 1) Корисність
            return utility < second.utility;
        if (urgency != second.urgency)   // 2) Терміновість
            return urgency < second.urgency;
        if (diff != second.diff)   // 3) Складність
            return diff < second.diff;
        return interest < second.interest;   // 4) Цікавість
}

bool Data::operator==(const Data& second) const 
{
    return utility == second.utility && diff == second.diff && urgency == second.urgency && interest == second.interest;
}

bool Data::operator<=(const Data& second) const
{
    return *this < second || *this == second;
}

DynamicArray::DynamicArray()   // Конструктор
{
    size = 3;
    array = new Data[size];
    currSize = 0;
}

DynamicArray::~DynamicArray() // Деструктор
{
    delete[] array;
}

void DynamicArray::relocMem() // Перевиділення пам'яті
{
    size += size + 1;   // Виділення місця на додатковий рівень
    Data* newArray = new Data[size]; // Виділення більшої кількості пам'яті

    memmove(newArray, array, currSize * sizeof(Data)); // Перенесення елементів

    delete[] array; // Видалення старого масиву
    array = newArray; // Зміна масиву, з яким пов'язаний вказівник
}

void DynamicArray::push_back(Data obj) // Додавання елементу в кінець
{
    if (currSize == size) // Якщо масив заповнений
        relocMem();
    array[currSize] = obj;
    currSize++;
}

void DynamicArray::pop_back() // Видалення елементу з кінця
{
    if (currSize != 0) // Якщо масив не пустий
        currSize--;
}

Data DynamicArray::get(int id) // Зчитування елементу за індексом
{
    return array[id];
}

void DynamicArray::clear()
{
    delete[] array;
    size = 3;
    currSize = 0;
    array = new Data[size];
}
