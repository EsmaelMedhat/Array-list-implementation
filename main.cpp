#include<iostream>
#include"ArrayList.h"
int main() {
ArrayList<int>vec;
for(int i=1;i<=10;i++)
 vec.insert_first(i);

 vec.reverse();

vec.display();
std::cout<<"  Size   :"<<vec.get_size()<<std::endl;
std::cout<<"capacity :"<<vec.get_capacity()<<std::endl;

return 0;
}
