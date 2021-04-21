#include <fstream>
namespace DB{
	void updateItem(std::string itemTitle,int amount){
		std::string path = "Inventory/" + itemTitle + ".txt";
		std::ifstream file(path);
		std::string line,price,weight,name,amountS;
		std::getline(file,line);
		name = line;
		
		std::getline(file,line);
		price = line;
		
		std::getline(file,line);
		weight = line;
		
		std::getline(file,line);
		amountS = line;
		
		file.close();
		
		std::ofstream Ifile(path);
		
		Ifile << name << "\n";
		
		Ifile << price << "\n";
		
		Ifile << weight << "\n";
		
		Ifile << stoi(amountS)-amount << "\n";
		
		Ifile.close();
	}
}
