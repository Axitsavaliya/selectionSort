#include <iostream>
using namespace std;

void selectionSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[i])
            {
                swap(arr[i], arr[j]);
            }
        }
    }
}

void merge(int arr[], int left, int mid, int right)
{
    int i, j, k, temp[right - left + 1];
    for (i = left, j = mid + 1, k = 0; i <= mid && j <= right; k++)
        temp[k] = (arr[i] < arr[j]) ? arr[i++] : arr[j++];
   for (; i <= mid; i++)
        temp[k++] = arr[i];
    for (; j <= right; j++)
        temp[k++] = arr[j];

    for (i = left, k = 0; i <= right; i++, k++)
        arr[i] = temp[k];
}

void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int linearSearch(int arr[], int size, int key)
{
    for (int i = 0; i < size; i++)
        if (arr[i] == key)
            return i;
    return -1;
}

int binarySearch(int arr[], int size, int key)
{
    int left = 0, right = size - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (arr[mid] == key)
            return mid;
        (arr[mid] < key) ? left = mid + 1 : right = mid - 1;
    }
    return -1;
}

void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int arr[100], size, choice, key;

    cout << "Enter array size: ";
    cin >> size;
    cout << "Enter " << size << " elements: ";
    for (int i = 0; i < size; i++)
        cin >> arr[i];

    do
    {
        cout << "Selection Sort" << endl;
        cout << "Merge Sort" << endl;
        cout << "Linear Search" << endl;
        cout << "Binary Search" << endl;
        cout << "Display Array" << endl;
        cout << "Exit" << endl;
        cout << "Enter Your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            selectionSort(arr, size);
            break;
        case 2:
            mergeSort(arr, 0, size - 1);
            break;
        case 3:
            cout << "Enter element to search: ";
            cin >> key;
            cout << ((linearSearch(arr, size, key) != -1) ? "Element found" : "Element not found") << endl;
            break;
        case 4:
            cout << "Enter element to search: ";
            cin >> key;
            cout << ((binarySearch(arr, size, key) != -1) ? "Element found" : "Element not found") << endl;
            break;
        case 5:
           display(arr, size);
            break;
        case 0:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "invelid choice" << endl;
        }
    } while (choice != 0);

    return 0;
}
