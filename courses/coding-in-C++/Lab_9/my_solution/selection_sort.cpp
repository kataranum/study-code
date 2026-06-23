// generated completely by ChatGPT, i did not modify any of this

#include <iostream>

void printArray(const int* arr, int length)
{
    for (int i = 0; i < length; ++i)
    {
        std::cout << arr[i] << ' ';
    }
    std::cout << '\n';
}

void selectionSort(int* arr, int length)
{
    for (int i = 0; i < length - 1; ++i)
    {
        int minIndex = i;

        // Find the smallest element in the remaining unsorted part
        for (int j = i + 1; j < length; ++j)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }

        // Swap into place
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;

        std::cout << "After iteration " << (i + 1) << ": ";
        printArray(arr, length);
    }
}

int main()
{
    int data[] = {64, 25, 12, 22, 11};
    int length = sizeof(data) / sizeof(data[0]);

    std::cout << "Initial array: ";
    printArray(data, length);

    selectionSort(data, length);

    std::cout << "Sorted array: ";
    printArray(data, length);

    return 0;
}
