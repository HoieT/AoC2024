    #include <iostream>
    #include <vector>
    #include <fstream>   
    #include <sstream>
    #include <string>
    #include <regex>
    #include <numbers>
  

int main(){
    std::string line;
    int summary=0;
    bool skip= false;   
    std::string element0;
    std::string element1;
    std::string element2;
    std::string filename = "C:/Users/trond/Documents/Workspace GIT/CPP Repositories/AoC2024/docs/input.txt"; 
    std::ifstream infile(filename);
    if (!infile) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return 1;
    }
    std::getline(infile, line);
        
    std::regex pattern ("mul\\((\\d{1,3}),(\\d{1,3})\\)|(do\\(\\))|(don't\\(\\))");
    std::smatch result;
    std::regex_match(line, result, pattern);
    bool operate = true; 
    while(std::regex_search(line,result,pattern)){
         
        if(result[0]=="don't()")operate=false;
        if(result[0]=="do()"){
        operate=true;
        skip= true;// juks :-)
        }    

            if(operate && !skip){
            int a = std::stoi(result[1]);
            int b = std::stoi(result[2]);
            summary=summary + (a*b);
            }
       skip = false; // juks :-) 

       /*for(auto x:result){
           std::cout<< x << " ";
            }*/ 
     
        //std::cout<<std::endl; 
        line = result.suffix();
    }
   
    std::cout<< "Sum do's and don'ts = "<<summary;
    return 0;
}
