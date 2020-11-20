//
//  main.cpp
//  Suduku
//
//  Created by Huw Borradaile on 07/11/2020.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
    bool sudoku2(vector<vector<char>> grid) {

        int n = 9;
        
        //options to be ruled out
        set<char> numbers = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
        set<char> options;
        vector<char> check;
       
       for(int ii=0; ii<100; ii++)
       {
            //loop of each element
            for(int i=0; i<n; i++)
            {
                for(int j=0; j<n; j++)
                {
                    options = numbers;
                    
                    //check row - remove options/if present
                    for(int k=0; k<n; k++)
                    {
                    if((grid[i][k] != '.') && (k != j)) options.erase(grid[i][k]);
                    }
                    
                    //check column - remove options/if present
                    for(int k=0; k<n; k++)
                    {
                    if((grid[k][j] != '.') && (k != i)) options.erase(grid[k][j]);
                    }
                    
                    //check box
                    int boxRow = i/3;
                    int boxCol = j/3;

                    for(int k = 0; k<3; k++)
                    {
                        for(int l = 0; l<3; l++)
                        {
                            if((grid[(boxRow*3)+k][(boxCol*3)+l] != '.') && ((boxRow*3)+k != i) && ((boxCol*3)+l != j)) options.erase(grid[(boxRow*3)+k][(boxCol*3)+l]);
                        }
                    }
                    
                    if(options.size() == 1) grid[i][j] = *options.begin();
                    
                    if(options.size() == 0) return false;
                    
                }
            }
       }
    return true;
    }

    
}
