#include <iostream>
using namespace std;

int findMinIndex(int* arr, int i, int n)
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

void printArray(int* arr, int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void selectionSort(int* arr,int n)
{
    int minInd = 0;
    for(int i=0;i<n;i++)
    {
        minInd = findMinIndex(arr,i,n);
        if(minInd != i)
        {
            int temp = arr[i];
            arr[i] = arr[minInd];
            arr[minInd] = temp;
        }
        printArray(arr,n);
    }
}

int main()
{
    int *arr,n;
    cout<<"\nEnter no of elements: ";
    cin>>n;
    arr = new int[n];

    cout<<"\nEnter array elements: "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    cout<<"\nBefore Selection Sort: "<<endl;
    printArray(arr,n);

    cout<<"\nPerforming selection sort.."<<endl;
    cout<<"Steps : "<<endl;
    selectionSort(arr,n);

    cout<<"\nAfter selection sort: "<<endl;
    printArray(arr,n);

    return 0;
}





