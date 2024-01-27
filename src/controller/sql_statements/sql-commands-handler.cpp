
class CommandsHandler {
    public:
	virtual void execute() = 0;
	bool validate_args() = 0;
	virtual~CommandsHandler() = default;

	void inititalise() {
	    execute();
	}
};

class SelectCommand : public CommandsHandler {
    public:
	void execute() override {
	    std::cout << "Executing select command...\n";
	}

	void validate_args() override {
	    	    std::cout << "Provide your SELECT command \n";

	    bool selectArgsActive = true;
	    while(selectArgsActive){
		std::cout << "------ SELECT STATEMENT ------\n";
		std::cout << "provide your SELECT statement...\m";

		std::string selectStatement;
		if(!(std::cin >> selectStatement)) {
		    std::cout << "Error reading input. \m";
		    std::cin.clear();
		    std::cin.ignore();
		    continue;
		}


	    }
	}	    

    private:
	std::string fetch_args(){
	}
};

class DeleteCommand : public CommandsHandler {
    public:
	void execute() override {
	    std::cout << "Executing delete command...\n";
	}
};

class CreateCommand : public CommandsHandler {
    public:
	void execute() override {
	    std::cout << "Executing create command...\n";
	}
};

class InsertCommand : public CommandsHandler {
    public:
	void execute() override {
	    std::cout << "Executing insert command...\n";
	}
};

class UpdateCommand : public CommandsHandler {
    public:
	void execute() override {
	    std::cout << "Executing update command...\n";
	}
};

class ExitCommand : public CommandsHandler {
    public:
	void execute() override {
	    std::cout << "Executing exit command...\n";
	}
};

class InvalidCommand : public CommandsHandler {
    public:
	void execute() override {
	    std::cout << "Executing invalid command...\n";
	}
};
