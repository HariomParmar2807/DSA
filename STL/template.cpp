#include<bits/stdc++.h>
using namespace std;
// Generic Functions
template <typename T>
T my_max(T x,T y)
{
    return (x>y)?x:y;
}
// Generic classes
template<typename T>
class Array
{
    private:
    T *ptr;
    int size;
    public:
    Array(T arr[],int s);
    void print();
};
template <typename T>
Array<T>::Array(T arr[],int s)
{
    ptr = new T[s];
    size = s;
    for(int i=0;i<size;i++)
     ptr[i]=arr[i];
}
template<class T>
void Array<T>::print()
{
    for(int i=0;i<size;i++)
     cout<<" "<<*(ptr+i);
}
// multitype argument in template
template <class T,class U>
class A
{
    T x;
    U y;
    public:
    A(){cout<<"Constructor called"<<endl;}
};
int main()
{
  cout<<my_max<int>(3,7);
  cout<<my_max<char>('g','e');
  int arr[5]={1,2,3,4,5};
  Array<int> a(arr,5);
  a.print();
  A<char,char>obj;
  A<double,char>b;
  return 0;
}