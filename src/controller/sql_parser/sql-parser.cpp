#include<iostream>
#include<vector>
#include<string>

enum class StatementType {
    SELECT_COMMAND,
    DELETE_COMMAND,
    CREATE_COMMAND,
    INSERT_COMMAND,
    UPDATE_COMMAND,
    EXIT_COMMAND
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

private:
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

private:
    std::string sql;
    StatementType fetched_command;
};

