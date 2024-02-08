
#include <string>

namespace StringUtils {
    bool contains(const std::string& search_field, const std::string& search_param) {
	return (search_field.find(search_param)!=std::string::npos);
    }

    bool contains_after(const std::string& search_field, const std::string& search_value) {
	return true;
    }

}
