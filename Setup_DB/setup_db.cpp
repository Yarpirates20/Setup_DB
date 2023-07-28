#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <sqlite3.h>
#include <filesystem>
#include "Db.h"

using namespace std;
namespace fs = std::filesystem;

int main(int argc, char* argv[])
{
	char overwrite;
	//string name;
	//string db_path = dir.append(name);
	auto path = fs::path("C:\\Users\\rsamo\\test\\");

	cout << setw(45) << "##### Setup Database #####\n\n";

	Db db;

	db.setName();

	path.append(db.getName());

	if (fs::exists(path))
	{
		cout << "Database " << db.getName() << " all ready exists at " << path.make_preferred() << endl;

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
		cout << "WOO" << endl;
	}

	//cout << db.getName() << endl;





	return 0;
}