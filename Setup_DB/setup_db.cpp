#include <stdio.h>
#include <iostream>
#include <sqlite3.h>
#include <filesystem>
#include <SQLiteCpp/SQLiteCpp.h>


using namespace std;
namespace fs = std::filesystem;

int main(int argc, char* argv[])
{
	string dir = "C:\\Users\\rsamo\\test\\";
	string name;

	cout << "Enter database name: ";
	getline(cin, name);

	string db_path = dir.append(name);

	
	SQLite::Database db("test.db");

	return 0;
}