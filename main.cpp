    #include <iostream>
    #include <vector>
    #include <fstream>   
    #include <ranges>
    #include <algorithm>
 
 /* #include <bits/stdc++.h>
    #include <string>
    #include <numeric>
    #include <sstream>
*/

int main(){
    std::string filename = "C:/Users/trond/Documents/Workspace GIT/CPP Repositories/AoC2024/docs/input.txt"; 
    std::ifstream infile(filename);
    if (!infile) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return 1;
    }
    std::vector<int> list1;
    std::vector<int> list2;
    int a, b;

    while (infile >> a >> b ) {
    list1.push_back(a);
    list2.push_back(b);
    }

//Sorter listene og summer differansen linje for linje. 
    std::sort(list1.begin(), list1.end());
    std::sort(list2.begin(), list2.end());
    
    int accumSum=0;
    for( auto i=0; i < list1.size(); ++i ) {
        accumSum = accumSum + std::abs((list1[i] - list2[i]));
    }
    std::cout << "Dag 1_a: Akkumulert differanse, linje for linje : "<<accumSum<<std::endl;

//Finn antall ganger et tall i list1 opptrer i list2
    int accumEqual= 0; 
    for (int num : list1) {
        auto range = std::ranges::equal_range(list2, num);
        auto count = std::distance(range.begin(), range.end());
        //std::cout << "Tallet " << num << " i liste 1 finnes  " << count << " ganger i liste 2.\n";
        accumEqual = accumEqual + (num *count);
    }
    std::cout << "Dag 1_b: Summen av produktene av: (like tall * antall like) : " << accumEqual<<std::endl;
    return 0; 
 }

    