/*
A financial analytics company is working on a system that processes large volumes of Sorted numerical
data from different sources. The challenge is to efficiently combine two independently Sorted datasets
into a single, fully Sorted dataset while ensuring optimal memory management. Since the size of the
datasets varies dynamically based on incoming data streams, the solution must be flexible and manage
memory efficiently without relying on built-in container libraries.
To achieve this, the development team needs to implement a mechanism that accepts two Sorted
arrays of different sizes and Merges them into a new dynamically allocated array while maintaining
the Sorted order. The system should read Input values specifying the sizes of both datasets, followed
by the elements of each array. After merging, the final Sorted array should be displayed as output.
Efficient memory handling is crucial in this implementation, requiring the use of new and delete
operators for dynamic allocation and deallocation of memory.
*/

#include <iostream>
using namespace std;

class ArrrayManager {
private:
    int* arr1;
    int* arr2;
    int* Merged;
    int size1, size2;

public:
    ArrrayManager() {
        arr1 = 0;
        arr2 = 0;
        Merged = 0;
        size1 = size2 = 0;

        cout << "Enter the size of the first array: ";
        cin >> size1;
        cout << "Enter the size of the second array: ";
        cin >> size2;

        arr1 = new int[size1];
        arr2 = new int[size2];
        Merged = new int[size1 + size2];
    }

    ~ArrrayManager() {
        delete[] arr1;
        delete[] arr2;
        delete[] Merged;
    }

    void InputArrays() {
        cout << "Enter elements of the first array: ";
        for (int i = 0; i < size1; i++) {
            cin >> arr1[i];
        }

        cout << "Enter elements of the second array: ";
        for (int i = 0; i < size2; i++) {
            cin >> arr2[i];
        }

        SortArray(arr1, size1);
        SortArray(arr2, size2);
    }

    void SortArray(int* arr, int size) {
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    // Swap
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }

    void MergeArrays() {
        int i = 0, j = 0, k = 0;
        while (i < size1 && j < size2) {
            if (arr1[i] < arr2[j]) {
                Merged[k++] = arr1[i++];
            } else {
                Merged[k++] = arr2[j++];
            }
        }
        while (i < size1) {
            Merged[k++] = arr1[i++];
        }
        while (j < size2) {
            Merged[k++] = arr2[j++];
        }
    }

    void Display() {
        cout <<"\nMade by 24ce012 Tirth Bhatt" << "Merged and Sorted array: ";
        for (int i = 0; i < size1 + size2; i++) {
            cout << Merged[i] << " ";
        }
        cout << endl;
    }
};//Made by 24ce012 Tirth Bhatt

int main() {
    ArrrayManager Arrays;
    Arrays.InputArrays();
    Arrays.MergeArrays();
    Arrays.Display();
    return 0;
}
