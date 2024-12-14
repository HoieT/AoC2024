    #include <iostream>
    #include <fstream>   
    #include <vector>

// Function to check if the position is within bounds 
bool isInBounds(int x, int y, int rows, int cols) { 
    return (x >= 0 && x < cols && y >= 0 && y < rows); 
    } 

int searchMatrix(const std::vector<std::vector<char>>& matrix, std::vector<char> target) { 
    int cols = matrix[0].size();
    int rows = matrix.size(); 
    int antall=0;  
    
    for(auto rowit=0; rowit<rows; rowit++){
        for (auto colsit=0; colsit<cols; colsit++){
            if(matrix[rowit][colsit]==target[0]){
                    std::cout<<"X found at "<<colsit<<" , "<<rowit<<std::endl;

                    int directions[8][2] = { 
                        {0, 1},   // Right 
                        {1, 0},   // Down 
                        {0, -1},  // Left 
                        {-1, 0},  // Up 
                        {1, 1},   // Down-Right 
                        {1, -1},  // Down-Left 
                        {-1, 1},  // Up-Right 
                        {-1, -1}  // Up-Left 
                    }; 
                    for (int i = 0; i < 8; ++i) { 
                            int dx = directions[i][1]; 
                            int dy = directions[i][0]; 
                            int x = colsit; 
                            int y = rowit;
                            int tIT = 0;  
                            bool targetmissed=false; 
                            //tIT=0; 
                            //for( int tIT= 1; tIT<target.size(); tIT++){
                            // Move in the current direction until out of bounds 
                            while (isInBounds(x, y, rows, cols)&&tIT<target.size() && !targetmissed) { 
                                targetmissed=false; 
                                std::cout << "test1- i:"<<i<<" tIT:"<<tIT<<" target[tIT]:"<<target[tIT]<<" matrix["<<y<<"]["<<x<<"]:"<<matrix[y][x]<<"\n";
                                if (matrix[y][x] == target[tIT] ) { 
                                    std::cout<<target[tIT]<<" found at: "<<"["<<y<<"]["<<x<<"]:"<<matrix[y][x]<<"\n";
                                        if(tIT==target.size()-1){
                                            antall++; 
                                            std::cout << "XMAS found at (" << rowit << ", " << colsit << ")" << "i= "<<i<<"\n";
                                        }
                                } 
                                else{
                                    targetmissed=true;
                                    std::cout<<" target[tIT]:"<<target[tIT]<<" missed at: ["<<y<<"]["<<x<<"]:"<<matrix[y][x]<<"\n";
                                }
                                
                                //std::cout << "test2- i:"<<i<<" tIT:"<<tIT<<" target[tIT]:"<<target[tIT]<<" matrix["<<y<<"]["<<x<<"]:"<<matrix[y][x]<<"\n";
                                x += dx; 
                                y += dy; 
                                tIT++;
                                
 
                            } 
                        //} 
                            x = colsit; 
                            y = rowit;
                            tIT=0;
                    }

            }    
        }
    }
        
    return antall;  

}

int main(){
    std::vector<std::vector<char>> matrix;
    std::string line; 
    int totantall=0; 

    std::string filename = "C:/Users/trond/Documents/Workspace GIT/CPP Repositories/AoC2024/docs/input.txt"; 
    std::ifstream infile(filename);
    if (!infile) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return 1;
    }
    while(std::getline(infile, line)){
        std::vector<char> row; 
        for (char &c :line) {
            row.push_back(c); 
        }
        matrix.push_back(row);
    };
    
//print matrix
    /*for(auto y = 0; y<10; ++y){
        for (auto x=0; x<10; ++x){
            std::cout<<matrix[y][x]; 
        }
        std::cout<<std::endl; 
    }*/
    std::vector<char> target = {'X','M','A','S'};

    totantall = searchMatrix(matrix,target); 
    std::cout<<" antall funn av XMAS: "<<totantall<<std::endl;

    
    return 0;
}
