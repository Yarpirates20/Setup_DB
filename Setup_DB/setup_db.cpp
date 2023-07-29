#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <sqlite3.h>
#include <filesystem>
#include <nlohmann/json.hpp>
#include <fstream>
#include "Db.h"

using namespace std;
namespace fs = std::filesystem;
using json = nlohmann::json;

int getMenuInput();

int main(int argc, char* argv[])
{
	char overwrite;
	//string name;
	//string db_path = dir.append(name);
	auto path = fs::path{ R"(C:\Users\rsamo\test\)"s};
	ifstream infile({ R"(C:\Users\rsamo\source\config_files\db.json)"s });

	json data = json::parse(infile);
	string defaultDir = data["DefaultDbPath"];

	cout << setw(45) << "##### Setup Database #####\n\n";


	while (true)
	{
		int menuChoice = getMenuInput();
	
		switch (menuChoice)
		{
		case 1:
			cout << "\u001b[2J";
			cout << defaultDir << endl;
			cout << "\n";

			menuChoice = getMenuInput();
			
			break;

		case 2:
			break;

		case 3:
			break;

		default:
			break;
		}


	}

	Db db;

	db.setName();

	path.append(db.getName());

	if (fs::exists(path))
	{
		cout << "Database " << db.getName() << " all ready exists at " << path.string() << endl;

		cout << "\nOverwrite existing database? (WARNING: All previous data will be removed)\n";
		cout << "Enter choice (Y/N): ";
		cin >> overwrite;

		if (tolower(overwrite) == 'n')
		{
			system("EXIT");
		}
	}

	if ((!(fs::exists(path))) || ((fs::exists(path) && tolower(overwrite) == 'y')))
	{
		db.createDatabase();
	}

	//cout << db.getName() << endl;

	return 0;
}

int getMenuInput()
{
	int menuInput;

	cout << "1. View default database location\n"
		<< "2. Choose new database directory\n"
		<< "3. Exit\n\n";

	cout << "Enter choice (1-3): ";
	cin >> menuInput;

	return menuInput;
}
