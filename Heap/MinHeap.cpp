#include<bits/stdc++.h>
using namespace std;

class MinHeap
{
    int* arr;
    int size, capacity;
    public:
        MinHeap(){}

        MinHeap(int c)
        { 
            size=0;
            capacity=c;
            arr = new int[c];
        }

        int left(int i){return 2*i+1;}

        int right(int i){return 2*i+2;}

        int parent(int i){return ((i-1)/2);}

        void insert(int);
        void print();
        void MinHeapify(int);
        int GetMin();
        int ExtractMin();
        void DecreaseKey(int , int);
        void Delete(int);
        void BuildHeap();
};

void MinHeap::insert(int x)
{
    if(size==capacity)
        return;
    size++;
    arr[size-1] = x;
    int i=size-1;
    while(i!=0 && arr[i] < arr[parent(i)])
    {
        swap(arr[i],arr[parent(i)]);
        i = parent(i);
    }
}

void MinHeap:: print()
{
    if(size==0) return;
    for(int i=0;i<size;i++)
        cout<<arr[i]<<" ";
    cout<<"\n";
}

void MinHeap::MinHeapify(int i)
{   
    int lt = left(i),rt = right(i);
    int smallest = i;
    if(lt<size && arr[lt]<arr[smallest])
        smallest=lt;
    if(rt<size && arr[rt]<arr[smallest])
        smallest=rt;
    if(i!=smallest)
    {
        swap(arr[i],arr[smallest]);
        MinHeapify(smallest);
    }
}

int MinHeap::GetMin()
{
    if(size==0)
    {
        cout<<"Heap is Empty!"<<endl;
        return -1;
    }
    cout<<"Min = ";
    return arr[0];
}

int MinHeap::ExtractMin()
{
    if(size==0)
        return INT_MAX;
    if(size==1)
    {
        size--;
        return arr[0];
    }
    swap(arr[0],arr[size-1]);
    size--;
    MinHeapify(0);
    return arr[size];
}

void MinHeap::DecreaseKey(int pos, int key)
{
    if(pos > size)  return;
    else if(key < arr[pos]){
        arr[pos] = key;
        while(pos!=0 && (arr[pos] < arr[parent(pos)]))
        {
            swap(arr[pos],arr[parent(pos)]);
            pos = parent(pos);
        }
    }
    else if(key > arr[pos]){
        arr[pos] = key;
        MinHeapify(pos);
    }
}

void MinHeap::Delete(int i)
{
    if(i>size) return;
    swap(arr[i],arr[size-1]);
    size--;
    MinHeapify(i);
}

void MinHeap::BuildHeap()
{
    for(int i=(size-2)/2;i>=0;i--)
    {
        MinHeapify(i);
    }
}

int main()
{
    MinHeap h(11);
    h.insert(3);
    h.insert(5);
    h.insert(1);
    h.insert(2);
    h.insert(12);
    h.insert(4);
    h.MinHeapify(0);
    h.print();
    cout<<h.GetMin()<<endl;
    cout<<h.ExtractMin()<<" extracted!"<<endl;
    h.print();
    h.DecreaseKey(1,10);
    h.print();
    h.Delete(2);
    h.print();
    h.BuildHeap();
    h.print();
    return 0;
}
