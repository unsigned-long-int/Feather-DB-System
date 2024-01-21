#include <iostream>
#include <string>

int main(int argc, char* argv[]){

    bool applicationRunning = true;
    while (applicationRunning){
	std::cout << "db > \n";

	std::string sqlCommand;

	if(!(std::cin >> sqlCommand)){
	    std::cout << "Error reading input. \n";
	    return EXIT_FAILURE;
	}

	switch(sqlCommand){
	    case ".exit": {
			      std::cout << "The request has been terminated.\n";
			      return EXIT_SUCCESS

			  }
	    default: {
			 std::cout << "unrecognised command " sqlCommand ". \n";
		     }
	}
    }
    return EXIT_SUCCESS;
}
