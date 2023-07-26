#include "Db.h"
#include <iostream>
using namespace std;

// Sets dbName member variable to input name from user
void Db::setName()
{
	string name;
	cout << "Enter database name: ";
	getline(cin, name);

	dbName = name;
}

// Returns a string of the database name
std::string Db::getName()
{
	return dbName;
}

// Creates a database w/name dbName
// If no database exists, creates new one
// Overwrites existing db with same name
int Db::createDatabase()
{
	// Open database
	int rc = sqlite3_open(dbName.c_str(), &db);

	if (rc)
	{
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		return(0);
	}
	else
	{
		fprintf(stderr, "Opened database successfully\n");
	}

	// Close database
	sqlite3_close(db);
	return 0;
}
