#include <iostream>
#include <string>
#include <cstring>
#include "../include/controller/sql_parser/sql-parser.h"
#include "../include/utils/utils.h"

int main(int argc, char* argv[]){

    bool application_running = true;
    while (application_running){
	std::cout << "db > \n";

	std::string sql_command;

	if(!(std::cin >> sql_command)){
	    std::cout << "Error reading input. \n";
	    std::cin.clear();
	    std::cin.ignore();
	    continue;
	}

	toLower(sql_command);

	SQLParser sql_parser(sql_command);

	bool validity_sql_command = sql_parser.isValidSQLCommand();

	if (!validity_sql_command){
	    std::cout "Unrecognised command. \n";
	    std::cin.clear();
	    std::cin.ignore();
	    continue;
	}

	std::unique_ptr<CommandsHandler> sql_command_instance = sql_parser.fetchSQLHandlerInstance(sql_command);
    }
    return EXIT_SUCCESS;
}
