#include <iostream>
#include <conio.h>
#include "AddItem.h"
using namespace std;
using namespace Management;

int main (){
	while(true){
		system("cls");
		char a;
		std::cout << "Press '1' to add an item \nPress'2' to remove an item\n";
		a = getch();
		if(a == '1'){
			string name;
			int price,weight,amount;
			cout << "Name: ";
			cin >> name;
			cout << "Price: ";
			cin >> price;
			cout << "Weight: ";
			cin >> weight;
			cout <<  "Amount: ";
			cin >> amount;
			addItem(name,price,weight,amount);
		}
		if(a == '2'){
			string name;
			std::cout << "Please Enter the Item Name: ";
			cin >> name;
			removeItem(name);
		}
	}
}
