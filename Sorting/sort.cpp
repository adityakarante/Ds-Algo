#include<bits/stdc++.h>
using namespace std;
//All sorting algorithms

//_________________Bubble sort_____________________
/*
Sorting In Place: Yes
Stable: Yes
*/
void BubbleSort(int a[],int n)
{
//repeatedly swapping the adjacent elements if they are in wrong order.
    int pos;
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
                std::swap(a[j],a[j+1]);
        }

    }
}
/*
The above function always runs O(n^2) time even if the array is sorted.
It can be optimized by stopping the algorithm if inner loop didn’t cause any swap.
*/
void Modified_BubbleSort(int a[],int n)
{
    bool swapped=false;
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
                std::swap(a[j],a[j+1]),swapped=true;
        }
        if(swapped==false)//if flag is still 1 means no swapping so array sorted
            break;

    }
}
void Recursive_BubbleSort(int a[],int n)
{
    //base case
    if(n==1)
        return;

    //for one pass largest element moved to end
    for(int i=0;i<n-1;i++)
        if(a[i]>a[i+1])
            std::swap(a[i],a[i+1]);

    //do recursive procedure for all other
    Recursive_BubbleSort(a,n-1);
}
//_________________Selection Sort____________
void SelectionSort(int a[],int n)
{
/*
In every iteration of selection sort, the minimum element
(considering ascending order) from the unsorted subarray is picked and moved to the sorted subarray.
In Place : Yes, it does not require extra space.
*/
    int min_index;
    for(int i=0;i<n-1;i++)
    {
        min_index=i;
        for(int j=i+1;j<n;j++)
        {
            if(a[j]<a[min_index])
                min_index=j;
        }
        std::swap(a[min_index],a[i]);
    }
}
//_________________Insertion Sort________________
/*
Sorting In Place: Yes
Stable: Yes
*/
void InsertionSort(int a[],int n)
{
    int val,j;
    for(int i=1;i<n;i++)
    {
        val=a[i];
        j=i-1;
        while(j>=0 && a[j]>val)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=val;
    }
}
void Recusive_InsertionSort(int a[],int n)
{
    if(n<=1)
        return;

}

//__________Quick Sort__________
int partitionIndex(int *a,int l,int r)
{
    int par_index=l;//partition index at start initially
    int pivot=a[r];//use pivot element as end
    int i;
    for(i=l;i<r;i++)
    {
        if(a[i]<=pivot)
        {
            swap(a[i],a[par_index]);//swap if element is less than pivot
            par_index++;
        }
    }
    std::swap(a[par_index],a[r]);
    return par_index;
}
void QuickSort(int a[],int l,int r)
{
    if(l<r)
    {
        int pindex=partitionIndex(a,l,r);
        QuickSort(a,l,pindex-1);
        QuickSort(a,pindex+1,r);
    }
}

//_______________Merge Sort_____________
void merge_parts(int a[],int l,int mid,int r)
{
    int n1=mid-l+1;
    int n2=r-mid;

    int L[n1],R[n2];//create temp array

    //copy data to temp array
    for(int i=0;i<n1;i++)
        L[i]=a[l+i];
    for(int i=0;i<n2;i++)
        R[i]=a[mid+1+i];

    int i=0,j=0,k=l;

    while(i<n1 && j<n2)
    {
        if(L[i]<=R[j])
        {
            a[k]=L[i];
            i++;
        }
        else
        {
            a[k]=R[j];
            j++;
        }
        k++;
    }
    while(i<n1)
    {
        a[k]=L[i];
        i++;k++;
    }
    while(j<n2)
    {
        a[k]=R[j];
        j++;k++;
    }


}
void MergeSort(int a[],int l,int r)
{
    if(l<r)
    {
        int mid=l+(r-l)/2;
        MergeSort(a,l,mid);
        MergeSort(a,mid+1,r);
        merge_parts(a,l,mid,r);
    }

}
//_____________Counting Sort___________
void CountingSort(int a[],int n)
{
    int MAX=a[0];
    //finding max from array
    for(int i=1;i<n;i++)
        if(a[i]>MAX)
            MAX=a[i];
    //create array of max size
    int count_arry[MAX+1]={0};
    //find count of each element inside array and store inside count array
    for(int i=0;i<n;i++)
        count_arry[a[i]]++;

    int j=0;
    //if count > 0 print that element and repeat process
    for(int i=0;i<MAX+1;i++)
    {
        while(count_arry[i]>0)
        {
            a[j]=i;
            j++;
            count_arry[i]--;
        }
    }
}
//_____________Radix Sort___________
void RadixSort(int a[],int n)
{

}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
            cin>>a[i];
    cout<<"\nBefore sorting\n";
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<"\nAfter sorting\n";
    MergeSort(a,0,n-1);
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";

}
