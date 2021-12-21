#include<iostream>
using namespace std;

int Partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low, j = high;

    while(i <= j) {
        while(arr[i] <= pivot)
            i++;
        while(arr[j] >= pivot)
            j--;
        if(i < j) swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);

    return j;
}

void Quick_Sort(int arr[], int low, int high) {
    if(low < high) {
        int pivot = Partition(arr, low, high);
        Quick_Sort(arr, low, pivot-1);
        Quick_Sort(arr, pivot+1, high);
    }
    return;
}

int main()
{
    int i, n;
    cout << "Enter the number of elements of array" << endl;
    cin >> n;
    cout << "Enter the elements of aray : " << endl;
    int arr[n];
    for(i = 0; i < n; i++) cin >> arr[i];
    Quick_Sort(arr, 0, n-1);
    for(i = 0; i < n; i++) cout << arr[i] << " ";
    cout << "\n";

    return 0;
}