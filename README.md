Here’s a well-structured, polished `README.md` for your project, suitable for a public GitHub repository:

---

# Project 09: Navigate a Maze Using a Stack

This project demonstrates how to use a **stack data structure** to navigate a maze by implementing a depth-first search (DFS)-style algorithm. The maze is read from a file, and the program attempts to find a path from a start point (`S`) to a goal (`G`) while avoiding obstacles (`X`). If a path is found, it prints the path as a stack of `Location` objects.

---

## Project Structure

* `main.cpp` – Entry point, includes the maze solver and `Location` class.
* `maze.cpp` – Functions to read the maze and determine if a path exists.
* `maze1.txt` / `maze2.txt` – Sample maze input files.
* `README.md` – Project documentation.

---

## Concepts Covered

* Stack data structure (using C++ STL `std::stack`)
* Maze solving with backtracking (Depth-First Search)
* File I/O in C++
* Tracking visited locations
* Clean code, documentation, and optional visual output for extra credit

---

## Example Maze Input

File: `maze1.txt`

```
4 5
SX__X
___X_
X_XG_
_____
```

Legend:

* `S`: Start
* `G`: Goal
* `X`: Wall
* `_`: Open space

---

## 🧾 Sample Output

```
Enter the name of the file containing the maze: maze1.txt
push on stack. stack is now (0, 0, S)
push on stack. stack is now (1, 0, E) (0, 0, S)
...
FINAL PATH: (2, 3, X) (3, 3, N) (3, 2, E) (3, 1, E) (2, 1, S) (1, 1, S) (1, 0, E) (0, 0, S)
Path Found!
```

---

##  How It Works

1. **Read the Maze:** The `readMazeFromFile()` function loads the maze from a text file and initializes a grid representation.
2. **Solve the Maze:** The `isReachable()` function uses a stack to explore paths:

   * Always checks directions in the order: **North**, **West**, **South**, **East**
   * Marks visited cells and backtracks on dead ends by popping the stack
3. **Print Final Path:** If the goal is reached, the stack represents the full path from the start.


This project is open source and available under the MIT License.

---

Let me know if you'd like a Markdown file version or want it customized with your GitHub username or link.
