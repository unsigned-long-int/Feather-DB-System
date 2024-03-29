
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
	    std::cout << "Executing select command...\n";
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
