#include <iostream>
using namespace std;

void marge(int arr[], int low, int mid, int high) {
    int i, j, n1 = mid - low + 1;
    int n2 = high - mid;
    int left[n1], right[n2];

    for(i = 0; i < n1; i++) left[i] = arr[low + i ];
    for(i = 0; i < n2; i++) right[i] = arr[mid + i + 1 ];

    i = 0, j = 0;
    int k = low;

    while(i < n1 && j < n2) {
        if(left[i] <= right[j]) {
            arr[k++] = left[i];
            i ++;
        }
        else {
            arr[k++] = right[j];
            j ++;
        }
    }
    while(i < n1) {
        arr[k++] = left[i];
        i++;
    }
    while(j < n2) {
        arr[k++] = right[j];
        j++;
    }
}

void marge_Sort(int arr[], int low, int high)
{
     if(low < high) {
         int mid = low + (high - low) / 2;
         marge_Sort(arr, low, mid);
         marge_Sort(arr, mid+1, high);
         marge(arr, low, mid, high);
     }
}

int main()
{
    int n = 5, i, j;
    cout << "Enter the size of the array" << endl;
    cin >> n;
    cout << "Enter element of the array" << endl;
    int arr[n];
    for(i = 0; i < n; i++) cin >> arr[i];
    marge_Sort(arr, 0, n-1);

    cout << "After sorting the array" << endl;
    for(i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    return 0;
}