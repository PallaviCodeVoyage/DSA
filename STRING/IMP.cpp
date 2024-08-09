#include <iostream>
#include <sstream>
#include <vector>

int main() {
    std::string string = "apple,orange,banana";
    std::stringstream ss(string);
    std::string item;
    std::vector<std::string> splitString;

    while (std::getline(ss, item, ',')) {
        splitString.push_back(item);  // Splits by commas
    }

    for (const auto& str : splitString) {
        std::cout << str << std::endl;  // Output: apple\norange\nbanana
    }

    return 0;
}
///point 2
#include <iostream>
#include <sstream>
#include <vector>

int main() {
    std::string string = "apple,orange,banana";
    std::stringstream ss(string);
    std::string item;
    std::vector<std::string> splitString;

    while (std::getline(ss, item, ',')) {
        splitString.push_back(item);  // Splits by commas
    }

    for (const auto& str : splitString) {
        std::cout << str << std::endl;  // Output: apple\norange\nbanana
    }

    return 0;
}
