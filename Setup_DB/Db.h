#pragma once
#include <sqlite3.h>
#include <string>
class Db
{
private:
	std::string dbName;
	//string dbPath = "C:\\Users\\rsamo\\test\\";
	sqlite3* db;
	const char* data = "Callback function called";
	char* zErrMsg = 0;
	

public:
	Db() = default;
	void setName();
	std::string getName();
	int createDatabase(std::string);
	int createTable();
	bool dbExists(std::string);
	static int callback(void* data, int argc, char** argv, char** azColName);
	
};

