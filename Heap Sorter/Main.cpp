
#include <iostream>

using namespace std;

void setHeap(int a[]);
void heapSort(int a[], int l);
void largest(int a[], int loc, int n);
void display(int a[]);
int main() {
    int arr1[7], arr2[7], arr3[7], arr4[7], arr5[7];  //taking all 5 inputs at once for one output

    cout << "Enter the 7 elements for array 1. " << endl;
    for (int i = 0; i < 7; i++) {
        cin >> arr1[i];
    }
    cout << "Enter the 7 elements for array 2. " << endl;
    for (int i = 0; i < 7; i++) {
        cin >> arr2[i];
    }
    cout << "Enter the 7 elements for array 3. " << endl;
    for (int i = 0; i < 7; i++) {
        cin >> arr3[i];
    }
    cout << "Enter the 7 elements for array 4. " << endl;
    for (int i = 0; i < 7; i++) {
        cin >> arr4[i];
    }
    cout << "Enter the 7 elements for array 5. " << endl;
    for (int i = 0; i < 7; i++) {
        cin >> arr5[i];
    }
    setHeap(arr1);
    heapSort(arr1, 7);
    display(arr1);
    setHeap(arr2);
    heapSort(arr2, 7);
    display(arr2);
    setHeap(arr3);
    heapSort(arr3, 7);
    display(arr3);
    setHeap(arr4);
    heapSort(arr4, 7);
    display(arr4);
    setHeap(arr5);
    heapSort(arr5, 7);
    display(arr5);
}

void setHeap(int a[]) {
    int* b = a;
    b[0] = a[0];
    for (int i = 1; i < 7; ++i) {
        b[i] = a[i];
        for (int j = i; j > 0; --j) {
            if (b[j] > b[(j - 1) / 2])
                swap(b[j], b[(j - 1) / 2]);
        }
    }
    for (int k = 0; k < sizeof(a); ++k)
        a[k] = b[k];
}
void heapSort(int a[], int l) {  //parameters:  a[] is array, l is length of array
    for (int n = l - 1; n > 1; --n) {
        swap(a[0], a[n]);
        largest(a, 0, n - 1);
    }
    swap(a[0], a[1]);  //final swap
}
void largest(int a[], int loc, int n) {
    int curr = a[loc];
    int lc = 2 * loc + 1;   //left child location
    int rc = 2 * loc + 2;   //right child location
    if (lc <= n) {
        if (rc <= n && a[rc] > a[lc]) {
            if (a[rc] > curr) {
                swap(a[rc], a[loc]);
                largest(a, rc, n);
            }
        }
        else {
            if (a[lc] > curr) {
                swap(a[lc], a[loc]);
                largest(a, lc, n);
            }
        }
    }
}
void display(int a[]) {   //parameters:  a[] is array
    cout << "[";
    for (int i = 0; i < 6; ++i)
        cout << a[i] << ", ";
    cout << a[6] << "]";
    cout << endl;
}