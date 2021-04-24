#include <conio.h>
#include <iostream>
#include <map>
//#include <pair>
#include "DataBase/ItemSearch.h"
#include "DataBase/Inventory.h"
#include "DataBase/cartItemStruct.h"
#include "DataBase/itemUpdate.h"
int main (){
	int sumPrice=0;
	std::vector<DB::cartItem> cart;
	std::map<std::string,int> pendingList;
	
	std::vector<DB::item> list = DB::loadList();
	for(auto Item = list.begin();Item!=list.end();Item++){
		pendingList.insert(std::pair<std::string,char>((*Item).name,0));
	}
	
	while(true){
	std::vector<DB::item> list = DB::loadList();
	std::cout << "commands: ---- :cart / ItemName  / :purchase ---------\n";
	for(auto Item = list.begin();Item!=list.end();Item++){
		std::cout << (*Item).name << "\n";
	}
	std::cout << "price: " << sumPrice << "\n";
	std::string choice;
	std::cin >> choice;
	if(choice == ":cart"){
		system("cls");
		for(auto cartItem = cart.begin();cartItem!=cart.end();cartItem++){
			std::cout << (*cartItem).name << " " << (*cartItem).amount <<"\n";
		}
	}
	
	if(choice == ":purchase"){
		sumPrice = 0;
		system("cls");
		for(auto cartItem = cart.begin();cartItem!=cart.end();cartItem++){
			DB::updateItem((*cartItem).name,(*cartItem).amount);
			pendingList[choice] = 0;
		}
		cart.clear();
	}
	
	for(auto Item = list.begin();Item!=list.end();Item++){
		if((*Item).name == choice){
			int amount;
			std::cout << "Amount: ";
			std::cin >> amount;
			
			pendingList[choice] += amount;
			
			system("cls");
			if(pendingList[choice] > (*Item).amount){
				system("cls");
				std::cout << "\n\n          [ERROR] Not Enought Items\n\n";
				break;
			}
			
			DB::cartItem pendingItem;
			
			pendingItem.name = choice;
			pendingItem.price = (*Item).price;
			pendingItem.amount = amount;
			
			cart.push_back(pendingItem);
			
			sumPrice += pendingItem.price * pendingItem.amount;
			
			break;
		}
	}
	}
}
