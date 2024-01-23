#include <cstdlib> 
#include <iostream>
#include <string>
#include <vector>

using namespace std;


bool findWord(const vector<vector<char>> &grid, const string &word,
              int gameNum) {
  
  int rows = grid.size();
  int cols = grid[0].size();

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      
      if (grid[i][j] == word[0]) {
        //  8 direções possíveis
        for (int dx = -1; dx <= 1; dx++) {
          for (int dy = -1; dy <= 1; dy++) {
            if (dx == 0 && dy == 0)
              continue; 
            int x = i, y = j, k;
            for (k = 1; k < word.length(); k++) {
              x += dx;
              y += dy;
              if (x < 0 || x >= rows || y < 0 || y >= cols ||
                  grid[x][y] != word[k]) {
                break;
              }
            }
            if (k == word.length()) {
              cout << i+1 << " " << j+1 << endl;
              return true;
            }
          }
        }
      }
    }
  }
  return false;
}


int main() {
  int numBoards;

  cin >> numBoards;
  cin.ignore(); 

  for (int gameNum = 1; gameNum <= numBoards; gameNum++) {
    int numRows, numCols;

    cin >> numRows >> numCols;
    cin.ignore(); 

    if (numRows <= 0 || numRows > 50 || numCols <= 0 || numCols > 50) {
      continue;
    }

    
    vector<vector<char>> grid(numRows, vector<char>(numCols));

    for (int i = 0; i < numRows; i++) {
      for (int j = 0; j < numCols; j++) {
        cin >> grid[i][j];
      }
    }

    cin.ignore(); 


    int numWords;
    cin >> numWords;
    cin.ignore(); 

    vector<string> words(numWords);

    for (int i = 0; i < numWords; i++) {
      cin >> words[i];
    }


    for (const string &word : words) {
      findWord(grid, word, gameNum);
    }

    
    cout << endl;
  }

  return 0;
}
