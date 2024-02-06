#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>
#include <vector>


struct TableMetadata{
    std::string table_name;
    std::string dat_file_path;
};

class BTreeInitialiser {
    public:
	BTreeInitialiser(const std::string& file_path) : file_path(file_path) {}
	
	std::unordered_map<int, TableMetadata> fetchCurrentTables(const std::string& file_path) {
	    std::unordered_map<int, TableMetadata> tableDirectory;
	    std::ifstream file(file_path);
	    
	    if (file.is_open()) {
		std::string line;
		int page_id = 1;
		while (std::getline(file, line)) {
		    TableMetadata table;
		    std::size_t pos = line.find(' ');
		    if (pos!=std::string::npos) {
			table.table_name = line.substr(0, pos);
			table.dat_file_path = line.substr(pos + 1);
			tableDirectory.push_back page_id, table;
			page_id++;
		    }
		}
	    } else {
		std::cerr << "Error: Unable to open file: " << file_path << std::endl;
	    }

	    return tableDirectory
	}

    private:
	const std::string file_path;
	std::unordered_map<int, TableMetadata> tableDirectory;

};


class BTreeFinder {
    public:
	BTreeFinder(const std::unordered_map<int, TableMetadata>& tableDirectory) : tableDirectory(tableDirectory){}

	bool tableExists(const int& page_id) const {
	    return tableDirectory.find(page_id) != tableDirectory.end();

	}

	std::string& fetchDatFilePath(const int& page_id) const {
	    return tableDirectory.at(page_id).dat_file_path;
	}

    private:
	const std::unordered_map<int, TableMetadata>& tableDirectory;
};
