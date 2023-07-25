#include <iostream>
#include <sqlite3.h>
using namespace std;

int main()
{
	sqlite3* db;
	sqlite3_open("test.db", &db);


	return 0;
}