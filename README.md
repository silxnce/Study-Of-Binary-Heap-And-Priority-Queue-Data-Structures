# Study-Of-Binary-Heap-And-Priority-Queue-Data-Structures
Computer Science. Year 1. Algorithms and Data structures. Lab 7

# Task
Translated via ChatGPT

Throughout the week, a student receives many homework assignments. Each assignment is characterized by its interest level, the usefulness of the subject, the difficulty of completion, the deadline, and so on. According to a certain criterion, the student should quickly choose the most optimal assignment and start working on it. New assignments with higher priority will appear during the week.  

1. Create a "Data" structure for storing objects with characteristics according to your chosen task:  
  Choose a specific criterion for determining the more prioritized object based on all its characteristics.  
  Overload the "less than" operator (operator<).  
  Overload the "equals" operator (operator==).  

2. Implement a non-decreasing max-heap (binary heap):  
2.1 Create a "BinaryHeap" structure, which represents a binary tree for working with a binary heap. You can use your own dynamic array that has been implemented in previous tasks to store the binary tree.  
2.2 Implement basic methods for navigating the binary tree:  
  getParent(index) – find the index of the parent node.  
  getLeftChild(index) – find the index of the left child node.  
  getRightChild(index) – find the index of the right child node.  
2.3 Implement internal methods for heap ordering:  
  siftUp(index) – sift an element up the tree.  
  siftDown(index) – sift an element down the tree.  

3. Implement a priority queue based on the binary heap.  
3.1 Create a "PriorityQueue" structure that contains the "BinaryHeap."  
3.2 Implement basic methods for working with the priority queue:  
  push(object) – add a new element to the queue.  
  top() – get the top element from the queue.  
  pop() – remove the top element from the queue.  
  size() – find the number of elements in the queue.  
  empty() – check if the queue is empty.  
  clean() – clear the queue.  

4. Perform testing using the provided testPriorityQueue() function. Verify correctness and measure the speed of operation, comparing it with the ready-made STL priority_queue library solution.  

5. Implement heap sort based on the binary heap.  
5.1 Create a "HeapSort" structure based on the binary heap that works with the data type int. Implement the necessary methods:  
  buildHeap(int* array, int arraySize) – build a heap from the input array.  
  heapSort(int* array, int arraySize) – sort the array, calling buildHeap inside.  
5.2 Compare it with the ready-made STL std::sort() library solution or other sorting algorithms implemented in previous tasks. Conduct testing with time measurements on different input data (different array lengths, best/average/worst-case scenarios for sorting).  

Also GitHub has some issues with Cyrillic symbols, therefore, some comments and lines of code may not be displayed correctly.
