#include <iostream>
using namespace std;
void selectionSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[min])
                min = j;
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}
int binarySearch(int arr[], int size, int key)
{
    int low = 0;
    int high = size - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == key)
            return mid;
        if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}
int main()
{
    int arr[8];
    int key;
    char choice;
    cout << "Enter 8 numbers: ";
    for (int i = 0; i < 8; i++)
        cin >> arr[i];
    selectionSort(arr, 8);
    cout << "Sorted: ";
    for (int i = 0; i < 8; i++)
        cout << arr[i] << " ";
    do
    {
        cout << "\nEnter value to search: ";
        cin >> key;
        int result = binarySearch(arr, 8, key);
        if (result == -1)
            cout << key << " not found";
        else
            cout << key << " found at index " << result;
        cout << "\nSearch again? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');
    return 0;
}
