#include <iostream>
using namespace std;


int findMinIndex(int *arr,int i,int n)
{
    int minInd = i;
    for(int j=i+1;j<n;j++)
    {
        if(arr[j] < arr[minInd])
        {
            minInd = j;
        }
    }
    return minInd;
}

void selectionSort(int *arr,int n)
{
    for(int i=0;i<n;i++)
    {
        int minInd = findMinIndex(arr,i,n);

        if(minInd != i)
        {
            int temp = arr[i];
            arr[i] = arr[minInd];
            arr[minInd] = temp;
        }
    }
}

void printArray(int * arr,int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<' ';
    }
}

int main()
{
    int n;
    cout<<"Enter no of elements: ";
    cin>>n;

    int *arr = new int[n];
    cout<<"\nEnter array elements: ";
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }

    cout<<"Before sorting: "<<endl;
    printArray(arr,n);

    selectionSort(arr,n);

    cout<<"Sorted array: "<<endl;
    printArray(arr,n);


    return 0;
}