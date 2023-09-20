#include <iostream>
#include <ctime>
#include <queue>
#include "DynamicArray.h"

using namespace std;

struct BinaryHeap   // Структура бінарної купи
{
    DynamicArray arr;

    int getParent(int id)   // Знаходження індексу батьківського вузла
    {
        return (id - 1) / 2;
    }

    int getLeftChild(int id)   // Знаходження індексу лівого дочірнього вузла
    {
        return 2 * id + 1;
    }

    int getRightChild(int id)   // Правого дочірнього вузла
    {
        return 2 * id + 2;
    }

    void siftUp(int id)   // Просіювання вгору
    {
        if (id > 0 && arr.get(getParent(id)) < arr.get(id))   // Якщо досліджуваний елемент не є коренем і він є більшим за батьківським
        {
            swap(arr.array[getParent(id)], arr.array[id]);   // Зміна місцями
            siftUp(getParent(id));   // Виклик рекурсії
        }
    }

    void siftDown(int id)   // Просіювання вниз
    {
        if (id >= ceil((float)(arr.currSize - 1) / 2))   // Якщо елемент не має дочірніх вузлів
            return;
        int maxId;   // Індекс більшого дочірньго елемента
        if (getRightChild(id) == arr.currSize || arr.get(getRightChild(id)) <= arr.get(getLeftChild(id)))   // Якщо правого дочірнього елемента немає, або він менший/дорівнює лівому
            maxId = getLeftChild(id);
        else   // Якщо правий більший
            maxId = getRightChild(id);
        if (arr.get(id) < arr.get(maxId))   // Якщо досліджуваний вузол менший за дочірній
        {
            swap(arr.array[id], arr.array[maxId]);   // Зміна місцями
            siftDown(maxId);   // Виклик рекурсії
        }
    }
};

struct PriorityQueue   // Структура пріоритетної черги
{
    BinaryHeap heap;
    int *currSize = &heap.arr.currSize;   // Вказівник на значення розміру масиву, на якому базується бінарна купа

    void push(Data obj)   // Додавання елементу в чергу
    {
        heap.arr.push_back(obj);
        heap.siftUp(*currSize - 1);
    }

    Data top()   // Отримання верхнього елементу
    {
        if (!empty())
            return heap.arr.get(0);
    }

    void pop()   // Видалення верхнього елементу
    {
        if (!empty())
        {
            swap(heap.arr.array[0], heap.arr.array[*currSize - 1]);   // Зміна місцями з останнім вузлом
            heap.arr.pop_back();
            heap.siftDown(0);   // Просіювання вниз новго кореня
        }
    }

    int size()   // Кількість елементів в черзі
    {
        return *currSize;
    }

    bool empty()   // Перевірка на пустоту
    {
        if (*currSize == 0)
            return true;
        return false;
    }

    void clean()   // Очищення черги
    {
        heap.arr.clear();
    }
};

template <typename T>   // Функція тестування пріоритетної черги
float testPriorityQueueSpeed(T&& priorityQueue)
{
    const int iters = 100000;
    clock_t timeStart = clock();
    for (int i = 0; i < iters; i++)
    {
        int insertDataAmount = rand() % 6 + 5;
        for (int j = 0; j < insertDataAmount; j++)
        {
            priorityQueue.push(Data());
        }
        priorityQueue.top();
        priorityQueue.pop();
    }
    clock_t timeEnd = clock();
    float time = (float(timeEnd - timeStart)) / CLOCKS_PER_SEC;
    return time;
}
bool testPriorityQueue()
{
    srand(time(NULL));
    const int iters = 20000;
    PriorityQueue myPriorQueue;
    priority_queue<Data> stlPriorQueue;
    bool isDataEqual = true;
    for (int i = 0; i < iters; i++)
    {
        int insertDataAmount = rand() % 6 + 5;
        for (int j = 0; j < insertDataAmount; j++)
        {
            Data randData = Data();
            myPriorQueue.push(randData);
            stlPriorQueue.push(randData);
        }
        if (!(myPriorQueue.top() == stlPriorQueue.top()))
        {
            isDataEqual = false;
            cerr << "Comparing failed on iteration " << i << endl << endl;
            break;
        }
        int removeDataAmount = rand() % insertDataAmount;
        for (int j = 0; j < removeDataAmount; j++)
        {
            myPriorQueue.pop();
            stlPriorQueue.pop();
        }
    }
    int myQueueSize = myPriorQueue.size();
    int stlQueueSize = stlPriorQueue.size();
    float stlTime =
        testPriorityQueueSpeed<priority_queue<Data>>(priority_queue<Data>());
    float myTime = testPriorityQueueSpeed<PriorityQueue>(PriorityQueue());
    cout << "My PriorityQueue:" << endl;
    cout << "Time: " << myTime << ", size: " << myQueueSize << endl;
    cout << "STL priority_queue:" << endl;
    cout << "Time: " << stlTime << ", size: " << stlQueueSize << endl << endl;
    if (isDataEqual && myQueueSize == stlQueueSize)
    {
        cout << "The lab is completed" << endl << endl;
        return true;
    }
    cerr << ":(" << endl << endl;
    return false;
}

struct HeapSort   // Структура сортування купою
{
    void siftDown(int *arr, int size, int id)   // Просіювання вниз
    {
        if (id >= ceil((float)(size - 1) / 2))   // Якщо елемент не має дочірніх вузлів
            return;
        int left = 2 * id + 1;
        int right = 2 * id + 2;
        int maxId;
        if (right == size || arr[right] <= arr[left])   // Якщо правого дочірнього елемента немає, або він менший/дорівнює лівому
            maxId = left;
        else   // Якщо правий більший
            maxId = right;
        if (arr[id] < arr[maxId])   // Якщо досліджуваний вузол менший за дочірній
        {
            swap(arr[id], arr[maxId]);
            siftDown(arr, size, maxId);
        }
    }

    void buildHeap(int *arr, int size)   // Побудова купи з вхідного масиву
    {
        for (int i = ceil((float)(size - 1) / 2); i >= 0; i--)   // Просіювання вузлів, що мають хоча б один дочірній елемент
            siftDown(arr, size, i);
    }

    void heapSort(int *arr, int size)   // Метод сортування
    {
        buildHeap(arr, size);

        for (int i = size - 1; i >= 0; i--)   // Цикл, що додає найбільші елементи в кінець
        {
            swap(arr[0], arr[i]);
            siftDown(arr, i, 0);
        }
    }
};

int main()
{
    testPriorityQueue();

    int const N = 250000;   // Тестування швидкості сортування і порівняння з бібліотечним рішенням
    int testArr[N];
    HeapSort testSort;
    srand(time(NULL));

    for (int i = 0; i < N; i++)
        testArr[i] = rand();

    clock_t timeStart = clock();
    testSort.heapSort(testArr, N);
    clock_t timeEnd = clock();

    float time = (float(timeEnd - timeStart)) / CLOCKS_PER_SEC;
    cout << "Heap Sort: " << time << endl;

    for (int i = 0; i < N; i++)
        testArr[i] = rand();

    timeStart = clock();
    sort(testArr, testArr + N);
    timeEnd = clock();

    time = (float(timeEnd - timeStart)) / CLOCKS_PER_SEC;
    cout << "std::sort(): " << time << endl;
}
