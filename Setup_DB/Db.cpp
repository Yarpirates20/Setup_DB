#include "Db.h"
#include <iostream>
#include <filesystem>
#include <string>
using namespace std;
namespace fs = std::filesystem;

// Sets dbName member variable to input name from user
void Db::setName()
{
	string name;
	cout << "Enter database name: ";
	getline(cin, name);

	/*auto path = fs::path("C:\\Users\\rsamo\\test\\");*/
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
int Db::createDatabase(string name)
{
	// Open database
	int rc = sqlite3_open(name.c_str(), &db);

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

int Db::createTable(string absDbPath)
{

	int rc;

	// Open db
	rc = sqlite3_open(absDbPath.c_str(), &db);

	if (rc)
	{
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		return(0);
	}
	else
	{
		fprintf(stdout, "Opened database successfully\n");
	}

	/*char* messageError;*/

	//Create SQL statement

	string sql = "CREATE TABLE users ("
		"USERNAME VARCHAR,"
		"PASSWORD_HASH VARCHAR);";


	// Execute SQL statement
	rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);

	if (rc != SQLITE_OK)
	{
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}
	else
	{
		fprintf(stdout, "Table created successfully\n");
	}

	sqlite3_close(db);
	return 0;
}

int Db::callback(void* NotUsed, int argc, char** argv, char** azColName)
{
	int i;
	for (i = 0; i < argc; i++)
	{
		printf("%s = %s \n", azColName[i], argv[i] ? argv[i] : "NULL");
	}
	printf("\n");
	return 0;
}

//bool Db::dbExists(string pathName)
//{
//	auto path = fs::path(pathName);
//	return fs::exists(path);
//}


