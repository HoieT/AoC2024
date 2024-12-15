    #include <iostream>
    #include <fstream>   
    #include <vector>


int main(){
    std::vector<std::vector<int>> PageOrderingRules;
    std::string line; 
    std::string filename = "C:/Users/trond/Documents/Workspace GIT/CPP Repositories/AoC2024/docs/testPageOrderingRules.txt"; 
    std::ifstream infile(filename);
    if (!infile) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return 1;
    }
    while(std::getline(infile, line)){
        std::vector<string> row; 
        for (char &c :line) {
            row.push_back(c); 
        }
        PageOrderingRules.push_back(row);
    };
    


    return 0;
}
