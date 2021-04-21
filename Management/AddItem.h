#include <fstream>
#include <vector>
namespace Management {
	void addItem(std::string name,int price,int weight,int amount){
		std::string ItemPath = "../Inventory/" + name + ".txt";
		std::ofstream Item(ItemPath);
		
		Item << name + "\n";
		
		Item << std::to_string(price)  + "\n";
		
		Item << std::to_string(weight) + "\n";
		
		Item << std::to_string(amount) + "\n";
		
		Item.close();
		
		std::ofstream listFile("../Inventory/list.txt",std::ios::app);
		listFile << "\n"<< name;
		listFile.close();
	}
	
	void removeItem(std::string name){
		std::string path = "../Inventory/" + name + ".txt";
		std::remove(path.c_str());
		std::ifstream Ifile("../Inventory/list.txt");
		std::vector<std::string> listComponents;
		std::string line;
		while(getline(Ifile,line)){
			if(line != name){
				listComponents.push_back(line);
			}
		}
		Ifile.close();
		std::ofstream Ofile("../Inventory/list.txt");
		for(auto i = listComponents.begin();i != listComponents.end() ;i++){
			Ofile << *i << "\n";
		}
		Ofile.close();
	}
}
