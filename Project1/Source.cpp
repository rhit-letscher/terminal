#include <iostream>
#include <string>
#include <vector>
#include <list>

//i.e. "hasDiscoveredMessage, hasDiscoveredPoint1...
//depending on story arc format we might wanna store this as a tree later or create maplike "flag manager" class
bool flags[] = {0,0,0,0};

class Process {

public:
	using FuncPtr = void(*)();
	std::string name;
	Process(FuncPtr proc, std::string name): 
	proc(proc), name(name){};

	void run() {
		proc();
	}
private:
	FuncPtr proc;

};

void fileManager() {
	std::cout << "Available Files: (type anything to continue)\n";
	std::string test;
	std::cin >> test;
	return;
}

void photos() {
	std::cout << "Photo library :DDDDDDDDyay (type anything to continue)\n";
	std::string test;
	std::cin >> test;
	return;
}



int main()
{
	//init all of our apps
	std::vector<std::unique_ptr<Process>> all;
	all.push_back(std::make_unique<Process>(fileManager, "file manager"));
	all.push_back(std::make_unique<Process>(photos, "photo app"));
	int input;

	while (1) {

		std::cout << "All available processes: \n";
		for (int i = 0; i < all.size();i+=1) {
			std::cout << i << ": " << all[i]->name << "\n";
		}
		std::cout << "Enter desired process #. \n";
		std::cin >> input;
		if (std::cin.fail() || input > all.size()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore bad input
			std::cout << "Invalid input. Enter a number from the above list";
			std::cin >> input;
		}
		else {
			all[input]->run();
		}
	}
	return 0;
};

