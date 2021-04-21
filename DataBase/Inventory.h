#include <vector>
namespace DB {
	
	std::vector<item> loadInventory(std::vector<std::string> listVec){
		std::vector<item> inventory;
		
		int start = 0;
		
		for(auto itemName = listVec.begin();itemName != listVec.end();itemName++){
			
			item pendingItem;
			std::string itemInfo[4];
			
			std::string itemNameString = *itemName;
			
			std::string itemString = loadItem(itemNameString);
			
			int index=0;
			start=0;
			for(int j = 0; j < itemString.length(); j++){
				if( j == itemString.length()-1){
					itemInfo[3] = itemString.substr(start,j-start+1);
				}
				if(itemString[j] == '.'){
					itemInfo[index] = itemString.substr(start,j-start);
					start = j+1;
					index++;
				}
			}
			
			pendingItem.name = itemInfo[0];
			
			pendingItem.price = stoi(itemInfo[1]);
			
			pendingItem.weight = stoi(itemInfo[2]);
			
			pendingItem.amount = stoi(itemInfo[3]);
			
			inventory.push_back(pendingItem);
		}
		return inventory;
	}
	
	std::vector<item> loadList(){
		return (loadInventory(loadListVec()));
	}
	
}
