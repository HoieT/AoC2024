    #include <iostream>
    #include <vector>
    #include <fstream>   
    #include <sstream>
    #include <string>
    #include <regex>

int main(){
    std::string line;
    int summary=0; 
    std::string element;
    std::string filename = "C:/Users/trond/Documents/Workspace GIT/CPP Repositories/AoC2024/docs/input.txt"; 
    std::ifstream infile(filename);
    if (!infile) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return 1;
    }
    std::getline(infile, line);
        
    std::regex pattern ("mul\\(\\d{1,3},\\d{1,3}\\)");
    std::smatch result;
    std::regex_match(line, result, pattern);
    
    while(std::regex_search(line,result,pattern)){
       element=result[0];
       std::istringstream iss(element);
        int a, b;
        char x1, x2, x3, m1, m2, m3;
        if (iss >> m1 >> m2 >> m3 >> x1 >> a >> x2 >> b >> x3 && x1 == '(' && x2 == ',' && x3 ==')' && m1=='m' && m2=='u'&& m3=='l') {
        std::vector<int> t = {a,b};
        summary=summary + (a*b);
        }     

       for(auto x:result){
           std::cout<< x << " ";
            } 
     
        std::cout<<std::endl; 
        line = result.suffix();
    }
   
    std::cout<< "summary = "<<summary;
    return 0;
}
