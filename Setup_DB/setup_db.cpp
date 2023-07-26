#include <iostream>
#include <sqlite3.h>
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

int main(int argc, char* argv[])
{
	string dir = "C:\\Users\\rsamo\\test\\";
	string name;

	cout << "Enter database name: ";
	getline(cin, name);

	string db_path = dir.append(name);

	


	return 0;
}