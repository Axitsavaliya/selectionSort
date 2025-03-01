#include <iostream>
#include <vector>

using namespace std;

// Function to perform Selection Sort
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

// Function to perform Merge Sort
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Function to perform Linear Search
int linearSearch(const vector<int>& arr, int target) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == target) {
            return i; // Return the index of the found element
        }
    }
    return -1; // Return -1 if not found
}

// Function to perform Binary Search
int binarySearch(const vector<int>& arr, int target, int left, int right) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid; // Return the index of the found element
        }
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1; // Return -1 if not found
}

// Main function to drive the program
int main() {
    int choice;
    vector<int> arr;
    int n, target;

    do {
        cout << "\nMenu:\n";
        cout << "1. Input Array\n";
        cout << "2. Selection Sort\n";
        cout << "3. Merge Sort\n";
        cout << "4. Linear Search\n";
        cout << "5. Binary Search\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the number of elements: ";
                cin >> n;
                arr.resize(n);
                cout << "Enter the elements:\n";
                for (int i = 0; i < n; i++) {
                    cin >> arr[i];
                }
                break;

            case 2:
                selectionSort(arr);
                cout << "Array sorted using Selection Sort:\n";
                for (int num : arr) {
                    cout << num << " ";
                }
                cout << endl;
                break;

            case 3:
                mergeSort(arr, 0, arr.size() - 1);
                cout << "Array sorted using Merge Sort:\n";
                for (int num : arr) {
                    cout << num << " ";
                }
                cout << endl;
                break;

            case 4:
                cout << "Enter the element to search: ";
                cin >> target;
                int linearIndex;
                linearIndex = linearSearch(arr, target);
                if (linearIndex != -1) {
                    cout << "Element found at index: " << linearIndex << endl;
                } else {
                    cout << "Element not found."
                }
                break;
            }
        }
    }
                        


