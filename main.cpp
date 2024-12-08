#include <iostream>
    #include <vector>
    #include <fstream>   
    #include <ranges>
    #include <algorithm>
    #include <sstream>
    #include <functional>
    #include <cmath>
    #include <bits/stdc++.h>
    #include <string>
    #include <numeric>

int main(){
    std::string filename = "C:/Users/trond/Documents/Workspace GIT/CPP Repositories/AoC2024/docs/input.txt"; 
    std::ifstream infile(filename);
    if (!infile) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return 1;
    }
    std::string line;
    int antall = 0;
    int threshold = 3; 
 
    while (std::getline(infile, line)) {
        std::istringstream iss(line); 
        std::vector<int>numbers; 
        std::vector<int>numbersMOD;
        std::string value;
        
        bool safe=false; 
        bool done=false;

        auto predicate_asc = [threshold](int a, int b) {
            return a >= b || std::abs(a - b) > threshold;
            };
        auto predicate_dec = [threshold](int a, int b) {
            return a <= b || std::abs(a - b) > threshold;
            };
    
        while(iss>>value){
            numbers.push_back(std::stoi(value));
            }
            
            for(int x = 0; x<numbers.size(); x++){
                numbersMOD=numbers;
                numbersMOD.erase(numbersMOD.begin()+x);
                auto it = std::ranges::adjacent_find(numbersMOD, predicate_asc);// check ascending & Threshold
                if (it==numbersMOD.end()){
                    safe=true;
                    x=numbers.size();
                    }
                it = std::ranges::adjacent_find(numbersMOD, predicate_dec);// check decending & Threshold
                if (it==numbersMOD.end()){
                    safe=true;
                    x=numbers.size();
                    }
            }
                if(safe){antall++;}
    }
    std::cout<<"Antall safe levels :"<<antall;        
        
    infile.close();
    return 0; 
    
 }