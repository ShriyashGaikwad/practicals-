// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
template <typename t>
void create(t *p,int size)
{
    int i;
    cout<<"Enter the element: ";
    for(i=0;i<size;i++)
    {
        cin>>p[i];
    }
    
}

template <typename t>
void sort(t *arr,int size)
{
for(int i=0;i<size;i++)
{
    int min=i;
    for(int j=i+1;j<size;j++)
    {
        if(arr[j]<arr[min])
        {
            min=j;
        }
    }
    t temp=arr[i];
    arr[i]=arr[min];
    arr[min]=temp;

}
}

template <typename t>
void show(t *p,int size)
{
    int i;
    cout<<"Sorted Elemnents are: ";
    for(i=0;i<size;i++)
    { 
        cout<<p[i]<<" ";
    }
    cout<<endl;
}

int main() {
    int size=4;
    int arr[size];

    create(arr,size);
    sort(arr,size);
    show(arr,size);

    float ar[size];

    create<float>(ar,size);
    sort<float>(ar,size);
    show<float>(ar,size);
    
    return 0;
}