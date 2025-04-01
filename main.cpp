#include <iostream>
#include <fstream>
#include <stack>
#include <vector>

using namespace std;

// Define movement directions
enum Direction { NORTH, WEST, SOUTH, EAST };

// Struct to represent a location in the maze
struct Location {
    int row, col, dir;
    Location(int r, int c) : row(r), col(c), dir(-1) {} // Initialize direction to -1
};

// Maze variables
const int MAX_SIZE = 100;
char maze[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE] = {false};
int numRows, numCols;
int startRow, startCol, goalRow, goalCol;

// Function to read maze from file
bool readMazeFromFile(string fName) {
    ifstream file(fName);
    if (!file) return false; // File not found

    // Read the first line for number of rows and columns
    file >> numRows >> numCols;
    file.ignore(); // Ignore newline character

    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            file.get(maze[i][j]); // Read character
            if (maze[i][j] == 'S') {
                startRow = i;
                startCol = j;
            } else if (maze[i][j] == 'G') {
                goalRow = i;
                goalCol = j;
            }
        }
        file.ignore(); // Ignore newline character
    }
    
    file.close();
    return true;
}

// Function to check if the goal is reachable using DFS with a stack
bool isReachable() {
    stack<Location> st;
    st.push(Location(startRow, startCol)); // Push start location
    cout << "push on stack. stack is now (" << startRow << ", " << startCol << ", S)" << endl;

    while (!st.empty()) {
        Location current = st.top();
        st.pop();

        // If we reach the goal, return true
        if (current.row == goalRow && current.col == goalCol) {
            st.push(current); // Push final position back
            cout << "FINAL PATH:";
            stack<Location> temp;
            while (!st.empty()) {
                temp.push(st.top());
                st.pop();
            }
            while (!temp.empty()) {
                Location loc = temp.top();
                temp.pop();
                cout << " (" << loc.row << ", " << loc.col;
                if (loc.dir == NORTH) cout << ", N";
                else if (loc.dir == WEST) cout << ", W";
                else if (loc.dir == SOUTH) cout << ", S";
                else if (loc.dir == EAST) cout << ", E";
                cout << ")";
            }
            cout << endl << "Path Found!" << endl;
            return true;
        }

        // Mark current location as visited
        visited[current.row][current.col] = true;

        // Try moving in each direction
        while (++current.dir < 4) {
            int newRow = current.row;
            int newCol = current.col;

            if (current.dir == NORTH) newRow--;
            else if (current.dir == WEST) newCol--;
            else if (current.dir == SOUTH) newRow++;
            else if (current.dir == EAST) newCol++;

            // Check boundaries, walls, and visited spaces
            if (newRow >= 0 && newRow < numRows && newCol >= 0 && newCol < numCols &&
                maze[newRow][newCol] != 'X' && !visited[newRow][newCol]) {
                
                st.push(current); // Push current before moving
                cout << "push on stack. stack is now (" << newRow << ", " << newCol;

                if (current.dir == NORTH) cout << ", N";
                else if (current.dir == WEST) cout << ", W";
                else if (current.dir == SOUTH) cout << ", S";
                else if (current.dir == EAST) cout << ", E";

                cout << ") " << endl;
                st.push(Location(newRow, newCol)); // Push new location
                break; // Move to next location
            }
        }

        // If all directions were checked and no move was made, it's a dead end
        if (current.dir == 4) {
            cout << "dead end: going back" << endl;
        }
    }
    return false;
}

int main() {
    string fileName;
    cout << "Enter the name of the file containing the maze: ";
    cin >> fileName;

    if (!readMazeFromFile(fileName)) {
        cout << "Error reading file." << endl;
        return 1;
    }

    if (!isReachable()) {
        cout << "No path found." << endl;
    }

    return 0;
}
