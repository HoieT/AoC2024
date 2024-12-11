    #include <iostream>
    #include <fstream>   
   // #include <sstream>
   // #include <string>
   //  #include <vector>

  

int main(){
    std::string line;

    std::string filename = "C:/Users/trond/Documents/Workspace GIT/CPP Repositories/AoC2024/docs/input.txt"; 
    std::ifstream infile(filename);
    if (!infile) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return 1;
    }
    while(std::getline(infile, line)){


    };
        
    
    return 0;
}
