#include<iostream>
#include<vector>
#include<string>

enum class StatementType {
    SELECT,
    DELETE,
    CREATE,
    INSERT,
    UPDATE
};

class SQLParser{
    public:
	SQLParser(const std::string& sql): sql(sql){}


};
