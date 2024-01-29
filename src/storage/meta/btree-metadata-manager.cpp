#include<iostream>
#include<fstream>
#include<unordered_map>
#include<string>


struct TableMetadata{
    std::string table_name;
    std::string dat_file_path;
};

class BTreeDirInitialiser {
    public:
	void fetchCurrentTables();

    private:
	std::unordered_map<int, TableMetadata> tableDirectory;
}; 

class BTreeFinder {
    public:
	std::unordered_map<int, TableMetadata> tableDirectory;
	void fetchCurrentTables(){
		// reading out the dat file contaning all the directories
	}

	bool tableExists(const int& page_id) const {
	    return tableDirectory.find(page_id) != tableDirectory.end();

	}

	std::string& fetchDatFilePath(const int& page_id) const {
	    return tableDirectory.at(page_id).dat_file_path;
	}
    private:
	std::unordered_map<int, TableMetadata> tableDirectory;
};
