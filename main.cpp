    #include <iostream>
    #include <fstream>   
    #include <vector>
    #include <bits/stdc++.h>
    #include <sstream>
    #include <ranges>

bool fixPrintOrderREC(const std::vector<std::vector<int>>& por, std::vector<int>& ptpLine, int n){
    //print ut ptpLine
//    for (auto x:ptpLine)std::cout<<x<<" "; 
//    std::cout<<std::endl; 
    //
    int first= por[n][0];
    int last = por[n][1];
    auto itFirst = std::ranges::find(ptpLine, first); 
    auto itLast = std::ranges::find(ptpLine, last);  
    if ( itFirst==ptpLine.end()||itLast==ptpLine.end()||itFirst<itLast){
       
  //      if(itFirst==ptpLine.end())std::cout<<" No First "<<std::endl;
  //      if(itLast==ptpLine.end())std::cout<<" No Last "<<std::endl; 
  //      if(itFirst<itLast)std::cout<<" Rule Confirmed "<<std::endl;
        if (n==0){
            std::cout<<"Print order apply to all rules \n";
            return true; 
        } 
        n--;
        return fixPrintOrderREC(por, ptpLine, n);
    }
       // 1, 7, 2, 3, 4, 5, 6, 8
        std::iter_swap(itFirst, itLast);
        int dist = std::distance(itFirst, itLast); 
        for (int x=0; x<dist; x++){
            std::iter_swap(itLast-x, itLast-x-1);
        }
      
     return false;// fixPrintOrderREC(por, ptpLine, n);     
    }

bool checkPrintOrderREC(const std::vector<std::vector<int>>& por, const std::vector<int>& ptpLine, int n){
    //print ut ptpLine
//    for (auto x:ptpLine)std::cout<<x<<" "; 
//    std::cout<<std::endl; 
    //
    int first= por[n][0];
    int last = por[n][1];
    auto itFirst = std::ranges::find(ptpLine, first); 
    auto itLast = std::ranges::find(ptpLine, last);  
    if ( itFirst==ptpLine.end()||itLast==ptpLine.end()||itFirst<itLast){
       
  //      if(itFirst==ptpLine.end())std::cout<<" No First "<<std::endl;
  //      if(itLast==ptpLine.end())std::cout<<" No Last "<<std::endl; 
  //      if(itFirst<itLast)std::cout<<" Rule Confirmed "<<std::endl;
        if (n==0){
            std::cout<<" Print order apply to all rules \n";
            return true; 
        } 
        n--;
        return checkPrintOrderREC(por, ptpLine, n);
    }
    std::cout<<"ERROR: n="<<n<<"first = "<<first<<" last = "<<last<<std::endl;
    return false;     
    }



int main(){
    std::vector<std::vector<int>> PageOrderingRules;
    std::string line; 
    std::string value;
    std::vector<std::vector<int>>ProductionList; 
   // std::vector<std::vector<int>> PagesToProduce; 
   


    std::string filename = "C:/Users/trond/Documents/Workspace GIT/CPP Repositories/AoC2024/docs/PageOrderingRules.txt"; 
    std::ifstream infile(filename);
    if (!infile) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return 1;
    }
    while(std::getline(infile, line)){
        std::istringstream iss(line); 
        int first; int last; 
        int newvalue=false;
        char x1; 
        //parse the line in first & last
        if(iss >> first >> x1 >> last && x1=='|'){
            std::vector<int> rule = {first, last};
            PageOrderingRules.push_back(rule);
        } else {
           std::cerr << "Error: Malformed line -> " << line << std::endl;
            } 
        }
   
    std::string filename2 = "C:/Users/trond/Documents/Workspace GIT/CPP Repositories/AoC2024/docs/PagesToProduce.txt"; 
    std::ifstream infile2(filename2);
    if (!infile2) {
        std::cerr << "Error: Could not open file " << filename2 << std::endl;
        return 1;
    }
    
    while(std::getline(infile2, line )){
        std::istringstream iss2(line); 
        std::vector<int> v;
        while (iss2.good()) {
            std::string substr;
            std::getline(iss2, substr, ',');
            v.push_back(std::stoi(substr));
        }
        ProductionList.push_back(v); 
    }   
// All data imported
    std::vector<int> failedOrders; 
    int okOrders=0;
    int adjustedOrders=0;  
    int sumCenterCell=0;
    int nPOR= PageOrderingRules.size()-1; 
    for(int x=0; x<ProductionList.size(); x++){
        //std::cout<<" Production list size: "<<ProductionList.size()<<" x:"<<x<<" LIST: "<<std::endl;
        //for (auto x:ProductionList[x])std::cout<<x<<" "; 
        //std::cout<<std::endl;
        if(checkPrintOrderREC(PageOrderingRules,ProductionList[x], nPOR)){
            okOrders++;
            int centercell= ((ProductionList[x].size()/2));
            sumCenterCell = sumCenterCell+ProductionList[x][centercell]; 
//            std::cout<<"correctly ordered update at line: "<<x<<std::endl;
//            std::cout<<"Center page no: "<<centercell<<" Center value "<<ProductionList[x][centercell]<<" |Sum: "<<sumCenterCell<<std::endl;
        } else{
          failedOrders.push_back(x); 
        }
    }
    std::cout<<" Sum center element approved print orders= "<< sumCenterCell<<std::endl; 
   
    std::cout<<" Number of OK orders = "<< okOrders<<std::endl; 
    std::cout<<" Number of failed orders = "<< failedOrders.size()<<std::endl; 
    sumCenterCell=0; 
    for (auto x:failedOrders)std::cout<<x<<" "; 
    for (auto x:failedOrders){

    while (!fixPrintOrderREC(PageOrderingRules,ProductionList[x], nPOR)); 
    adjustedOrders++;
    int centercell= ((ProductionList[x].size()/2));
    sumCenterCell = sumCenterCell+ProductionList[x][centercell]; 
    for (auto x:ProductionList[x])std::cout<<x<<" ";      
    std::cout<<"CenterValue: "<<ProductionList[x][centercell]<<" sum: "<<sumCenterCell<<std::endl;


    }   
    std::cout<<" Sum center element adjusted print orders= "<< sumCenterCell<<std::endl; 
    //test
    std::cout<<std::endl<<" #### Test final Productionlist ### "<<std::endl;
    okOrders=0;
    std::vector<int> reTestfailedOrders;
        
    for(int x=0; x<ProductionList.size(); x++){
        //std::cout<<" Production list size: "<<ProductionList.size()<<" x:"<<x<<" LIST: "<<std::endl;
        //for (auto x:ProductionList[x])std::cout<<x<<" "; 
        //std::cout<<std::endl;
        if(checkPrintOrderREC(PageOrderingRules,ProductionList[x], nPOR)){
            okOrders++;
            int centercell= ((ProductionList[x].size()/2));
            sumCenterCell = sumCenterCell+ProductionList[x][centercell]; 
//            std::cout<<"correctly ordered update at line: "<<x<<std::endl;
//            std::cout<<"Center page no: "<<centercell<<" Center value "<<ProductionList[x][centercell]<<" |Sum: "<<sumCenterCell<<std::endl;
        } else{
          reTestfailedOrders.push_back(x); 
        }
    }
    std::cout<<" Sum center element approved print orders= "<< sumCenterCell<<std::endl; 
    std::cout<<" Number of OK orders = "<< okOrders<<std::endl; 
    std::cout<<" Failed orders = "<<std::endl;
    std::cout<<" Number of failed orders = "<< reTestfailedOrders.size()<<std::endl; 
    for (auto x:reTestfailedOrders)std::cout<<x<<" "; 
    
    return 0;
}
