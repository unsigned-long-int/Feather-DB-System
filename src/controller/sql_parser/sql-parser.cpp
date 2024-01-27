#include<iostream>
#include<vector>
#include<string>
#include<memory>
#include<unordered_map>
#include "../include/sql_statements/sql-commands-handler.h"

enum class StatementType {
    SELECT_COMMAND,
    DELETE_COMMAND,
    CREATE_COMMAND,
    INSERT_COMMAND,
    UPDATE_COMMAND,
    EXIT_COMMAND,
    INVALID_COMMAND
};

class SQLParser {
public:
    SQLParser(const std::string& sql) : sql(sql) {
        fetched_command = fetchSQLCommand(sql);
    }

    bool isValidSQLCommand(){
	return fetched_command != StatementType::INVALID_COMMAND;
    }

    std::unique_ptr<CommandsHandler> fetchSQLHandlerInstance() {
	auto it = commandMap.find(fetched_command);
	if (it != commandMap.end()) {
	    return it->second();
	}
	return nullptr;
    }

private:

    std::string sql;
    StatementType fetched_command;

    std::unordered_map<StatementType, std::unique_ptr<CommandsHandler>> commandMap = {
	{StatementType::SELECT_COMMAND, std::make_unique<SelectCommand>()},
	{StatementType::DELETE_COMMAND, std::make_unique<DeleteCommand>()},
	{StatementType::CREATE_COMMAND, std::make_unique<CreateCommand>()},
	{StatementType::INSERT_COMMAND, std::make_unique<InsertCommand>()},
	{StatementType::UPDATE_COMMAND, std::make_unique<UpdateCommand>()},
	{StatementType::EXIT_COMMAND, std::make_unique<ExitCommand>()},
	{StatementType::INVALID_COMMAND, std::make_unique<InvalidCommand>()}
    };


    // private methods
    StatementType fetchSQLCommand(const std::string& sql) const {
        if (sql == ".select") {
            return StatementType::SELECT_COMMAND;
        } else if (sql == ".delete") {
            return StatementType::DELETE_COMMAND;
        } else if (sql == ".create") {
            return StatementType::CREATE_COMMAND;
        } else if (sql == ".insert") {
            return StatementType::INSERT_COMMAND;
        } else if (sql == ".update") {
            return StatementType::UPDATE_COMMAND;
	} else if (sql == ".exit") {
	    return StatementType::EXIT_COMMAND;
	} else {
            return StatementType::INVALID_COMMAND;
        }
    }
};

