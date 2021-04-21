#include <iostream>
#include <fstream>
#include <vector>
#include "ItemStruct.h"
namespace DB{
	std::string loadItem(std::string itemTitle){
		std::string Info[4];
		
		std::string ItemFileTitle = "Inventory/" + itemTitle + ".txt";
		std::ifstream itemFile(ItemFileTitle);
		
		std::string line;
		int i=0;
		while(getline(itemFile,line)){
			Info[i] = line;
			i++;
		}
		
		itemFile.close();
		return Info[0] + '.' + Info[1] + '.' + Info[2] + '.' + Info[3];
	}
	
	std::vector<std::string> loadListVec(){
		std::vector<std::string> listV;
		std::ifstream file("Inventory/list.txt");
		std::string line;
		while(getline(file,line)){
			listV.push_back(line);
		}
		file.close();
		return listV;
	}
}
