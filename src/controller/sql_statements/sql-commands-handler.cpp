
#include <iostream>
#include <string>

class CommandsHandler {
    public:
	CommandsHandler(std::string sql) : sql_command(sql){}

	virtual void execute() = 0;
	virtual~CommandsHandler() = default;

	void initialise() {
	    execute();
	}

    protected:
	std::string sql_command;
};

class SelectCommand : public CommandsHandler {
    public:
	using CommandsHandler::CommandsHandler;

	void execute() override {
	    std::string table_name = fetch_table_name();

	    std::cout << "Executing select command...\n";
	}

    private:
	const std::string fetch_table_name() {
	    std::string table_name;
	    size_t from_pos = sql_command.find('from');
	    if (from_pos!=std::string::npos) {
		size_t table_name_start_pos = sql_command.find_first_not_of(' \t', from_post + 4);
		if (table_name_start_pos!=std::string::npos) {
		    size_t table_name_end_pos = sql_command.find_first_of(' \t\n', table_name_start_pos);
		    if (table_name_end_pos!=std::string::npos) {
			std::string table_name = sql_command.substr(table_name_start_post, table_name_end_pos - table_name_start_post);
		    } else {
			std::string table_name = sql_command.substr(table_name_start_pos); 
		    }
		}
	    }
	    return table_name;
	}

	const int fetch_page_id(const std::string& table_name) {
	}
};


class DeleteCommand : public CommandsHandler {
    public:
	using CommandsHandler::CommandsHandler;

	void execute() override {
	    std::cout << "Executing delete command...\n";
	}
};

class CreateCommand : public CommandsHandler {
    public:
	using CommandsHandler::CommandsHandler;

	void execute() override {
	    std::cout << "Executing create command...\n";
	}
};

class InsertCommand : public CommandsHandler {
    public:
	using CommandsHandler::CommandsHandler;

	void execute() override {
	    std::cout << "Executing insert command...\n";
	}
};

class UpdateCommand : public CommandsHandler {
    public:
	using CommandsHandler::CommandsHandler;

	void execute() override {
	    std::cout << "Executing update command...\n";
	}
};

class ExitCommand : public CommandsHandler {
    public:
	using CommandsHandler::CommandsHandler;

	void execute() override {
	    std::cout << "Executing exit command...\n";
	}
};

class InvalidCommand : public CommandsHandler {
    public:
	using CommandsHandler::CommandsHandler;

	void execute() override {
	    std::cout << "Executing invalid command...\n";
	}
};
