#include <iostream>
#include <vector>

using std::vector;

class ArrayList {
private:
    static const int MAX_SIZE = 100;
    int items[MAX_SIZE];
    size_t length;
    bool (*compareFunc)(int, int) = &ascendingCompare;
protected:
    void buildMaxOrMinHeap();
    void heapify(int length, int i);
public:
    ArrayList() : length(0) {}
    ArrayList(int item) : length(1) { items[1] = item; }
    ArrayList(vector<int> numbers) : length(numbers.size()) { for (int i = 1; i <= numbers.size(); i++) items[i] = numbers[i - 1]; }
    bool isEmpty() const { return length == 0; }
    bool isFull() const { return length == MAX_SIZE; }
    void add(int item);
    int indexOf(int item) const;
    void remove(int item);
    static bool ascendingCompare(int a, int b);
    static bool descendingCompare(int a, int b);
    void heapsort(bool isAscending);
    void buildHeap();
    void printList() const;
    size_t size() const { return length; }
};