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
	auto path = fs::path{ R"(C:\Users\rsamo\test\)"s };
	ifstream infile({ R"(C:\Users\rsamo\source\config_files\db.json)"s });

	json data = json::parse(infile);
	string defaultDir = data["DefaultDbPath"];

	string newDefaultPath;

	cout << setw(45) << "##### Setup Database #####\n\n";


	while (true)
	{
		//cin.ignore();
		int menuChoice = getMenuInput();

		switch (menuChoice)
		{
		case 1:
			cout << "\u001b[2J";
			/*defaultDir = data["DefaultDbPath"];*/
			cout << "Current default directory: " << defaultDir << endl;
			cout << "\n";
			/*menuChoice = getMenuInput();*/
			break;

		case 2:
			cout << "\u001b[2J";

			cin.ignore();
			cout << "Choose new directory path \n";
			cout << R"(Example: C:\Users\Desktop\)"s << endl;
			cout << "\nEnter path: ";

			getline(cin, newDefaultPath);

			if (newDefaultPath == "")
			{
				defaultDir = data["DefaultDbPath"];
			}
			else
			{
				defaultDir = newDefaultPath;
			}

			cout << "New directory location: " << defaultDir << endl;

			cout << "\n";
			//cin.ignore();
			//menuChoice = getMenuInput();
			break;

		case 3:
		{
			// Create database
			Db db;
			path = defaultDir;
			/*cout << path.string() << endl;*/

			cin.ignore();
			db.setName();

			path.append(db.getName());

			// Ask for decision to overwrite if DB exists
			if (fs::exists(path))
			{
				cout << "\u001b[2J";

				cout << "Database " << db.getName() << " all ready exists at " << path.string() << endl;

				cout << "\nOverwrite existing database? (WARNING: All previous data will be removed)\n";
				cout << "Enter choice (Y/N): ";
				cin >> overwrite;

				if (tolower(overwrite) == 'n')
				{
					exit(0);
				}
			}

			cout << "\u001b[2J";

			// Conditions for creating database
			if ((!(fs::exists(path))) || (fs::exists(path) && tolower(overwrite) == 'y'))
			{
				db.createDatabase(path.string());
				
			}

			system("PAUSE");
			cout << "\u001b[2J";

			// Create table
			db.createTable(path.string());
			

			cout << "\n";
			break;
		}




		default:
			cout << "\nExiting program\n\n";
			exit(0);
			break;
		}


	}

	/*Db db;

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
	}*/

	//cout << db.getName() << endl;

	return 0;
}

int getMenuInput()
{
	int menuInput;

	cout << "1. View default database location\n"
		<< "2. Choose new database directory\n"
		<< "3. Setup database\n"
		<< "4. Exit\n\n";

	cout << "Enter choice (1-4): ";
	cin >> menuInput;

	return menuInput;
}
