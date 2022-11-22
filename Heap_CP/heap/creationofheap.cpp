#include <iostream>
using namespace std;

class heap
{
public:
    int arr[100];
    int size;

    // create constructor
    heap()
    {
        arr[0] = -1;
        size = 0;
    }
    void insert(int value)
    {
        size = size + 1;
        int index = size;
        arr[index] = value;
        while (index > 1)
        {
            int parent = index / 2;
            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }
    void deletenode()
    {
        if (size == 0)
        {
            cout << "nothing to delete" << endl;
            return;
        }

        arr[1] = arr[size];
        size--;
        int i = 1;
        while (i < size)
        {
            int leftindex = 2 * i;
            int rightindex = 2 * i + 1;
            if (leftindex < size && arr[leftindex] > arr[i])
            {
                swap(arr[leftindex], arr[i]);
                i = leftindex;
            }
            else if (rightindex < size && arr[rightindex] > arr[i])
            {
                swap(arr[rightindex], arr[i]);
                i = rightindex;
            }
            else
            {
                return;
            }
        }
    }
    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // heapify
    // ek node ko uski sahi jagah par leke jana heapify function ka kaam hai
    // TC-O(logn)
    void heapify(int arr[], int n, int i)
    {
        int largest = i;
        int left = 2 * i;
        int right = 2 * i + 1;
        if (left < n && arr[largest] < arr[left])
        {
            largest = left;
        }
        if (right < n && arr[largest] < arr[right])
        {
            largest = right;
        }

        if (largest != i)
        {
            swap(arr[right], arr[i]);
            heapify(arr, n, largest);
        }
    }

    // build min-heap
    void minheap(int arr[], int n, int i)
    {
        int smallest = i;
        int left = 2 * i;
        int right = 2 * i + 1;
        if (left < n && arr[smallest] < arr[left])
        {
            smallest = left;
        }
        if (right < n && arr[smallest] < arr[right])
        {
            smallest = right;
        }

        if (smallest != i)
        {
            swap(arr[right], arr[i]);
            minheap(arr, n, smallest);
        }
    }

    // heap sort
    // step1-swap(arr[1],arr[n])
    // size--
    void heapsort(int arr[], int n)
    {
        int size = n;
        while (size > 1)
        {
            swap(arr[1], arr[size]);
            size--;
            minheapify(arr, size, 1);
        }
    }
};

int main()
{
    heap h;
    h.insert(10);
    h.insert(20);
    h.insert(15);
    h.insert(12);
    h.insert(25);
    h.print();
    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;
    // for (int i = n / 2; i > 0; i--)
    // {
    //     h.heapify(arr, n, i);
    // }
    h.heapsort(arr, 5);
    cout << "\nprinting the array now" << endl;
    for (int i = 1; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}