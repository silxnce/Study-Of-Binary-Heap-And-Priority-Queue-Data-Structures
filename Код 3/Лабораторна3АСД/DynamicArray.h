#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

struct Data   // ��������� ���������� ��������
{
    Data();   // �����������
    char task[36];   // ����� ��������
    int utility, diff, urgency, interest;   // ���������, ���������, ����������, ��������

    bool operator<(const Data& second) const;   // ��������� ������������� ���������
    bool operator==(const Data& second) const;
    bool operator<=(const Data& second) const;
};

struct DynamicArray // ��������� ���������� ������
{
    DynamicArray(); // �����������
    ~DynamicArray(); // ����������

    Data* array;
    int currSize, size;

    void relocMem(); // ������������ ���'��
    void push_back(Data obj); // ��������� �������� � �����
    void pop_back();   // ��������� ���������� ��������
    Data get(int id);   // ��������� �������� �� ��������
    void clear();   // �������� ������
};
#endif