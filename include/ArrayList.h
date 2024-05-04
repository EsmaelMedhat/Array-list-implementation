#ifndef ARRAYLIST_H
#define ARRAYLIST_H
#include <iostream>
//#include <string>
using namespace std;
template <class type>
class ArrayList {
private:
    int size;
    int capacity;
    type* data;

  void resize() // (O(N))
  {
type *old=data;
size*=2;
data=new type[size];
for(int i=0;i<capacity;i++){
data[i]=old[i];
}
delete []old;
}
public:

ArrayList(int array_size){
size=array_size;
capacity=0;
data=new type[size];
}
ArrayList(){
size=4;
capacity=0;
data=new type[size];
}
~ArrayList(){
delete []data;
}
void display() // (O(N))
{
cout<<"\n*****all element*******\n";
for(int i=0;i<capacity;i++){
cout<<"item  "<<i+1<<":   "<<data[i]<<endl;
}
}
int get_capacity() // (O(1))
{return capacity;}
int get_size() // (O(1))
{return size;}
string search(type value) // (O(N))
{
for(int i=0;i<capacity;i++){
if(data[i]==value)
return "Found in index "+to_string(i);
}
return "Not found";
}
void push_back(type new_data) // (O(N))
{
if(capacity<size){
  data[capacity]=new_data;
capacity++;
}
else{
resize();
  data[capacity]=new_data;
capacity++;

}
}
void insert(int index,type newItem) // (O(N))
{
if(isfull())
resize();

if(index>=0&&index<size)
{
for(int i=capacity;i>index;i--)
{
data[i]=data[i-1];
}
data[index]=newItem;
capacity++;
}
else {cout<<"Out of range\n";
return;
}
}
void DeleteInPosition(int index) // (O(N))
{
if(index>=0&&index<size)
{
for(int i=index;i<capacity-1;i++)
{
data[i]=data[i+1];
}
capacity--;
}
}

void reverse() // (O(N/2))
{
for(int i=0;i<capacity/2;i++){
   swap(data[i],data[capacity-1-i]);
}
}
bool isempty() // (O(1))
{return capacity==0;}
bool isfull() // (O(1))
{return capacity==size; }
void insert_first(type new_item) // (O(N))
{
if(isempty())
{
        data[0]=new_item;
        capacity++;
return;
}
else if(capacity!=0&&isfull())
resize();

for(int i=capacity;i>=0;i--)
{
  data[i]=data[i-1];
}
data[0]=new_item;
capacity++;


}
 void delete_first() // (O(N))
 {
  if(capacity>0){
  for(int i=0;i<capacity-1;i++){
   data[i]=data[i+1];
    }
  capacity--;
   }
   else{
    cout<<"array is empty";
  }
 }
 void pop_back() // (O(1))
{
 if(capacity>0){
 capacity--;
 }
 else{
  cout<<"array is empty\n";
  }
   }
  type get_first() // (O(1))
   {
    return data[0];
   }
   type get_last() // (O(1))
  {
   return data[capacity-1];
  }
};

#endif // ARRAYLIST_H
