    #include <iostream>
    #include <fstream>   
    #include <vector>

// Function to check if the position is within bounds 
bool isInBounds(int x, int y, int rows, int cols) { 
    return (x >= 0 && x < cols && y >= 0 && y < rows); 
    } 
bool is_M_and_S(const std::vector<std::vector<char>>& matrix,int x, int y, const std::vector<char>& target){
    bool diagOK=true; 
    for (int i = 0; i<2; i++){
        int coordinates[2][4] = { 
                            {1, 1, -1, -1},   // Diagonal 1
                            {1, -1, -1, 1},  // Diagonal 2 
                            }; 
    
        int chX1 = x + coordinates[i][1]; 
        int chY1 = y + coordinates[i][0]; 
        int chX2 = x + coordinates[i][3]; 
        int chY2 = y + coordinates[i][2]; 
        
        if(!((matrix[chY1][chX1]==target[0]&&matrix[chY2][chX2]==target[2])||
            (matrix[chY1][chX1]==target[2]&&matrix[chY2][chX2]==target[0]))){
            return false;// break
            }
        }
        return true; 
}
int searchMatrix2(const std::vector<std::vector<char>>& matrix, std::vector<char> target) { //PART 2
    int cols = matrix[0].size();
    int rows = matrix.size(); 
    int antall=0;  
    
    for(auto rowit=1; rowit<rows-1; rowit++){
        for (auto colsit=1; colsit<cols-1; colsit++){
            if(matrix[rowit][colsit]==target[1]){// search for 'A'
                    std::cout<<"A found at "<<colsit<<" , "<<rowit<<std::endl;
                    if(is_M_and_S(matrix, colsit, rowit, target)){
                        antall++;    
                        std::cout<<"Pattern found at: "<<"["<<colsit<<"]["<<rowit<<"] - Antall: "<<antall<<"\n";
                        std::cout<<matrix[rowit-1][colsit-1]<<" "<<matrix[rowit-1][colsit+1]<<" "<<matrix[rowit+1][colsit+1]<<" "<<matrix[rowit+1][colsit-1];
                        std::cout<<std::endl;
                        }
                    }
            }    
        }
    return antall;  
}

int searchMatrix(const std::vector<std::vector<char>>& matrix, std::vector<char> target) { // PART 1
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
                                //std::cout << "test1- i:"<<i<<" tIT:"<<tIT<<" target[tIT]:"<<target[tIT]<<" matrix["<<y<<"]["<<x<<"]:"<<matrix[y][x]<<"\n";
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
    int totantall2=0; 

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
    
    std::vector<char> target = {'X','M','A','S'};

   // totantall = searchMatrix(matrix,target); 
    std::cout<<" antall funn av XMAS: "<<totantall<<std::endl;
// Part 2

    std::vector<char> target2 = {'M','A','S'};
    totantall2 = searchMatrix2(matrix,target2); 
    std::cout<<" antall funn av X-MAS: "<<totantall2<<std::endl;
    
    return 0;
}
