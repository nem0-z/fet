#include<iostream>
#include "LinkedList.hpp"

int main(void){
	List<int> list;

	list.push_back(2).push_back(4);
	list.print();

	list.pop_back();
	list.print();

	list.push_front(3).push_front(7).push_front(1);
	list.print();

	list.pop_front().pop_front();
	list.print();

	list.replace(2,50).replace(1,30);
	list.print();

	return 0;
}
