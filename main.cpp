    #include <iostream>
    #include <bits/stdc++.h>
    #include <string>
    #include <algorithm>
    #include <ranges>
    #include <vector>
    #include <numeric>
    
  
 int main(){

    std::ifstream file("C:/Users/trond/Documents/Workspace GIT/CPP Repositories/AoC2024/docs/test.txt");
    if (!file.is_open()) {
        std::cerr << "Error opening the file!";
        return 1;
    }
    std::string s;
    while (std::getline(file, s))
    file.close();

    return 0; 
 }
 