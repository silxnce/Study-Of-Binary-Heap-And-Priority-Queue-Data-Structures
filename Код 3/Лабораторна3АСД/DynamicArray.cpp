#include "DynamicArray.h"
#include <iostream>
#include <cstdlib>
#include <cmath>

Data::Data()   // �����������
{
    char taskArr[15][36] = { "C++ Programming Assignment", "Data Structures Project", "Algorithms Homework", "Object-Oriented Design Exercise", "Software Engineering Assignment",
        "Database Design Task", "Computer Graphics Project", "Operating Systems Lab Report", "Artificial Intelligence Programming", "Networking Assignment",
        "Web Development Project", "Mobile App Development Task", "Embedded Systems Programming", "Game Development Challenge", "Compiler Design Assignment" };
    strcpy_s(task, taskArr[rand() % 15]);   // ��������� ��������� ���������� ��� ��������
    utility = rand() % 11;
    diff = rand() % 11;
    urgency = rand() % 11;
    interest = rand() % 11;
}

bool Data::operator<(const Data& second) const
{
        if (utility != second.utility)   // 1) ���������
            return utility < second.utility;
        if (urgency != second.urgency)   // 2) ����������
            return urgency < second.urgency;
        if (diff != second.diff)   // 3) ���������
            return diff < second.diff;
        return interest < second.interest;   // 4) ֳ������
}

bool Data::operator==(const Data& second) const 
{
    return utility == second.utility && diff == second.diff && urgency == second.urgency && interest == second.interest;
}

bool Data::operator<=(const Data& second) const
{
    return *this < second || *this == second;
}

DynamicArray::DynamicArray()   // �����������
{
    size = 3;
    array = new Data[size];
    currSize = 0;
}

DynamicArray::~DynamicArray() // ����������
{
    delete[] array;
}

void DynamicArray::relocMem() // ������������ ���'��
{
    size += size + 1;   // �������� ���� �� ���������� �����
    Data* newArray = new Data[size]; // �������� ����� ������� ���'��

    memmove(newArray, array, currSize * sizeof(Data)); // ����������� ��������

    delete[] array; // ��������� ������� ������
    array = newArray; // ���� ������, � ���� ���'������ ��������
}

void DynamicArray::push_back(Data obj) // ��������� �������� � �����
{
    if (currSize == size) // ���� ����� ����������
        relocMem();
    array[currSize] = obj;
    currSize++;
}

void DynamicArray::pop_back() // ��������� �������� � ����
{
    if (currSize != 0) // ���� ����� �� ������
        currSize--;
}

Data DynamicArray::get(int id) // ���������� �������� �� ��������
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
