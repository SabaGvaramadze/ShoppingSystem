#include <conio.h>
#include <iostream>
#include "DataBase/ItemSearch.h"
#include "DataBase/Inventory.h"
#include "DataBase/cartItemStruct.h"
#include "DataBase/itemUpdate.h"
int main (){
	int sumPrice=0;
	std::vector<DB::cartItem> cart;
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
		}
	}
	
	for(auto Item = list.begin();Item!=list.end();Item++){
		if((*Item).name == choice){
			int amount;
			
			std::cout << "Amount: ";
			std::cin >> amount;
			
			system("cls");
			if(amount > (*Item).amount){
				system("cls");
				std::cout << "\n[ERROR] Not Enought Items\n\n";
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
