#include <iostream>
#include <string>
#include <cstring>
#include "../include/controller/sql_parser/sql-parser.h"

int main(int argc, char* argv[]){

    bool applicationRunning = true;
    while (applicationRunning){
	std::cout << "db > \n";

	std::string sqlCommand;

	if(!(std::cin >> sqlCommand)){
	    std::cout << "Error reading input. \n";
	    std::cin.clear();
	    std::cin.ignore();
	    continue;
	}

	SQLParser sql_parser(sqlCommand);

	bool validitySQLCommand = sql_parser.isValidSQLCommand();

	if (!validitySQLCommand){
	    std::cout "Unrecognised command. \n";
	    std::cin.clear();
	    std::cin.ignore();
	    continue;
	}

	std::unique_ptr<CommandsHandler> sql_command_instance = sql_parser.fetchSQLHandlerInstance();
    }
    return EXIT_SUCCESS;
}
