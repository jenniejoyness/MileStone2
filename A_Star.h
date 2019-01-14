
#ifndef MILESTONE2_A_STAR_H
#define MILESTONE2_A_STAR_H

#include <cfloat>
#include "Searcher.h"
#include <set>
#include <stack>
#include <cstring>
using namespace std;
// Creating a shortcut for int, int pair type
typedef pair<int, int> Pair;

// Creating a shortcut for pair<int, pair<int, int>> type
typedef pair<double, pair<int, int>> pPair;
// A structure to hold the neccesary parameters
struct cell {
    // f = g + h
    double f, g, h;
    int parent_i, parent_j;
};

template<class T>

class A_Star : public Searcher<T> {
public:
    string search(Searchable<T> *searchable) {

    int row = searchable->getRow();
    int col = searchable->getCol();

    vector<double> costs;
    vector<pair<double, pair<int, int>>> structure = searchable->getStateLocations();
        for (int k = 0; k < structure.size(); ++k) {
            costs.push_back(structure[k].first);
        }

    int grid[row][col];
    for (int i = 0; i < row; ++i){
        for (int j = 0; j < col ; ++j) {
            grid[i][j] = costs[col*i + j];
        }
    }

    Pair dest = searchable->getDest();
    Pair src = searchable->getSource();
    // A Utility Function to check whether given cell (row, col)
    // is a valid cell or not.


    // A Function to find the shortest path between
    // a given source cell to a destination cell according
    // to A* Search Algorithm



        // Either the source or the destination is blocked
        if (grid[0][0] == -1 || grid[row][col] == -1) {
            printf("Source or the destination is blocked\n");
            return "-1";
        }

        // If the destination cell is the same as source cell
        if (searchable->getInitialState()->Equals(searchable->getGoalState())) {
            printf("We are already at the destination\n");
            return "";
        }

        // Create a closed list and initialise it to false which means
        // that no cell has been included yet
        // This closed list is implemented as a boolean 2D array

        bool closedList[row][col];
        memset(closedList,false, sizeof(closedList));

        // Declare a 2D array of structure to hold the details
        //of that cell
        cell cellDetails[row][col];
        int i, j;

        for (i = 0; i < row; i++) {
            for (j = 0; j < col; j++) {
                cellDetails[i][j].f = FLT_MAX;
                cellDetails[i][j].g = FLT_MAX;
                cellDetails[i][j].h = FLT_MAX;
                cellDetails[i][j].parent_i = -1;
                cellDetails[i][j].parent_j = -1;
            }
        }

        // Initialising the parameters of the starting node
        i = searchable->getSource().first;
        j = searchable->getSource().second;

        cellDetails[i][j].f = 0.0;
        cellDetails[i][j].g = 0.0;
        cellDetails[i][j].h = 0.0;
        //starting point
        cellDetails[i][j].parent_i = i;
        cellDetails[i][j].parent_j = j;

        /*
         Create an open list having information as-
         <f, <i, j>>
         where f = g + h,
         and i, j are the row and column index of that cell
         Note that 0 <= i <= ROW-1 & 0 <= j <= COL-1
         This open list is implenented as a set of pair of pair.*/
        set <pPair> openList;

        // Put the starting cell on the open list and set its
        // 'f' as 0
        openList.insert(make_pair(0.0, make_pair(i, j)));

        // We set this boolean value as false as initially
        // the destination is not reached.
        //bool foundDest = false;

        while (!openList.empty()) {
            pPair p = *openList.begin();

            // Remove this vertex from the open list
            openList.erase(openList.begin());

            // Add this vertex to the closed list
            i = p.second.first;
            j = p.second.second;
            closedList[i][j] = true;

            // To store the 'g', 'h' and 'f' of the 8 successors
            double gNew, hNew, fNew;

            //----------- 1st Successor (North) ------------

            // Only process this cell if this is a valid one
            if (isValid(i - 1, j, row, col)) {
                // If the destination cell is the same as the
                // current successor
                if (isDestination(i - 1, j, dest)) {
                    // Set the Parent of the destination cell
                    cellDetails[i - 1][j].parent_i = i;
                    cellDetails[i - 1][j].parent_j = j;
                    printf("The destination cell is found1111111111\n");
                    return tracePath((cell*)cellDetails, dest, col);
                }
                    // If the successor is already on the closed
                    // list or if it is blocked, then ignore it.
                    // Else do the following
                else if (!closedList[i - 1][j] && grid[i-1][j] != -1) {
                    gNew = cellDetails[i][j].g + grid[i-1][j];
                    hNew = calculateHValue(i - 1, j, dest);
                    fNew = gNew + hNew;

                    // If it isn’t on the open list, add it to
                    // the open list. Make the current square
                    // the parent of this square. Record the
                    // f, g, and h costs of the square cell
                    //                OR
                    // If it is on the open list already, check
                    // to see if this path to that square is better,
                    // using 'f' cost as the measure.
                    if (cellDetails[i - 1][j].f == FLT_MAX ||
                        cellDetails[i - 1][j].f > fNew) {
                        openList.insert(make_pair(fNew, make_pair(i - 1, j)));

                        // Update the details of this cell
                        cellDetails[i - 1][j].f = fNew;
                        cellDetails[i - 1][j].g = gNew;
                        cellDetails[i - 1][j].h = hNew;
                        cellDetails[i - 1][j].parent_i = i;
                        cellDetails[i - 1][j].parent_j = j;
                    }
                }
            }

            //----------- 2nd Successor (South) ------------

            // Only process this cell if this is a valid one
            if (isValid(i + 1, j, row, col)) {
                // If the destination cell is the same as the
                // current successor
                if (isDestination(i + 1, j, dest)) {
                    // Set the Parent of the destination cell
                    cellDetails[i + 1][j].parent_i = i;
                    cellDetails[i + 1][j].parent_j = j;
                    printf("The destination cell is found2222222222222\n");
                    return tracePath((cell*)cellDetails, dest, col);


                }
                    // If the successor is already on the closed
                    // list or if it is blocked, then ignore it.
                    // Else do the following
                else if (!closedList[i + 1][j] && grid[i+1][j] != -1) {
                    gNew = cellDetails[i][j].g + grid[i+1][j];
                    hNew = calculateHValue(i + 1, j, dest);
                    fNew = gNew + hNew;

                    // If it isn’t on the open list, add it to
                    // the open list. Make the current square
                    // the parent of this square. Record the
                    // f, g, and h costs of the square cell
                    //                OR
                    // If it is on the open list already, check
                    // to see if this path to that square is better,
                    // using 'f' cost as the measure.
                    if (cellDetails[i + 1][j].f == FLT_MAX ||
                        cellDetails[i + 1][j].f > fNew) {
                        openList.insert(make_pair(fNew, make_pair(i + 1, j)));
                        // Update the details of this cell
                        cellDetails[i + 1][j].f = fNew;
                        cellDetails[i + 1][j].g = gNew;
                        cellDetails[i + 1][j].h = hNew;
                        cellDetails[i + 1][j].parent_i = i;
                        cellDetails[i + 1][j].parent_j = j;
                    }
                }
            }

            //----------- 3rd Successor (East) ------------

            // Only process this cell if this is a valid one
            if (isValid(i, j + 1, row, col)) {
                // If the destination cell is the same as the
                // current successor
                if (isDestination(i, j + 1, dest)) {
                    // Set the Parent of the destination cell
                    cellDetails[i][j + 1].parent_i = i;
                    cellDetails[i][j + 1].parent_j = j;
                    printf("The destination cell is found3333333333333333\n");
                    return tracePath((cell*)cellDetails, dest, col);
                }

                    // If the successor is already on the closed
                    // list or if it is blocked, then ignore it.
                    // Else do the following
                else if (!closedList[i][j + 1] && grid[i][j + 1] != -1) {
                    gNew = cellDetails[i][j].g + grid[i][j + 1];
                    hNew = calculateHValue(i, j + 1, dest);
                    fNew = gNew + hNew;

                    // If it isn’t on the open list, add it to
                    // the open list. Make the current square
                    // the parent of this square. Record the
                    // f, g, and h costs of the square cell
                    //                OR
                    // If it is on the open list already, check
                    // to see if this path to that square is better,
                    // using 'f' cost as the measure.
                    if (cellDetails[i][j + 1].f == FLT_MAX ||
                        cellDetails[i][j + 1].f > fNew) {
                        openList.insert(make_pair(fNew, make_pair(i, j + 1)));

                        // Update the details of this cell((Crow >= 0) && (Crow < row) && (Ccol >= 0) && (Ccol < col))
                        cellDetails[i][j + 1].f = fNew;
                        cellDetails[i][j + 1].g = gNew;
                        cellDetails[i][j + 1].h = hNew;
                        cellDetails[i][j + 1].parent_i = i;
                        cellDetails[i][j + 1].parent_j = j;
                    }
                }
            }

            //----------- 4th Successor (West) ------------

            // Only process this cell if this is a valid one
            if (isValid(i, j - 1, row, col)) {
                // If the destination cell is the same as the
                // current successor
                if (isDestination(i, j - 1, dest)) {
                    // Set the Parent of the destination cell
                    cellDetails[i][j - 1].parent_i = i;
                    cellDetails[i][j - 1].parent_j = j;
                    printf("The destination cell is found444444444444\n");
                    return tracePath((cell*) cellDetails, dest, col);
                }

                    // If the successor is already on the closed
                    // list or if it is blocked, then ignore it.
                    // Else do the following
                else if (!closedList[i][j - 1] && grid[i][j - 1] != -1) {
                    gNew = cellDetails[i][j].g + grid[i][j - 1];
                    hNew = calculateHValue(i, j - 1, dest);
                    fNew = gNew + hNew;

                    // If it isn’t on the open list, add it to
                    // the open list. Make the current square
                    // the parent of this square. Record the
                    // f, g, and h costs of the square cell
                    //                OR
                    // If it is on the open list already, check
                    // to see if this path to that square is better,
                    // using 'f' cost as the measure.
                    if (cellDetails[i][j - 1].f == FLT_MAX || cellDetails[i][j - 1].f > fNew) {
                        openList.insert(make_pair(fNew, make_pair(i, j - 1)));

                        // Update the details of this cell
                        cellDetails[i][j - 1].f = fNew;
                        cellDetails[i][j - 1].g = gNew;
                        cellDetails[i][j - 1].h = hNew;
                        cellDetails[i][j - 1].parent_i = i;
                        cellDetails[i][j - 1].parent_j = j;
                    }
                }
            }
        }
        return "-1";
    }


    bool isValid(int Crow, int Ccol, int row, int col) {
        return ((Crow >= 0) && (Crow < row) && (Ccol >= 0) && (Ccol < col));
    }

    // A Utility Function to check whether destination cell has
    // been reached or not
    bool isDestination(int row, int col, Pair dest) {
       return row == dest.first && col == dest.second;

    }

    // A Utility Function to calculate the 'h' heuristics.
    double calculateHValue(int row, int col, Pair dest) {
        // Return heuristic distance using manhattan
        return (double) (abs(row - dest.first) + abs(col - dest.second));
    }

// A Utility Function to trace the path from the source
// to destination
    string tracePath(cell* cellDetails,Pair dest, int col) {
        printf("\nThe Path is ");
        int i = dest.first;
        int j = dest.second;
        string result;
        stack<Pair> Path;

        //*((blah + i*col) +j)
        while (!((*((cellDetails + i * col) + j)).parent_i == i
                 && (*((cellDetails + i * col) + j)).parent_j == j)) {

            Path.push(make_pair(i, j));
            i =(*((cellDetails + i * col) + j)).parent_i;
            j = (*((cellDetails + i * col) + j)).parent_j;
        }

        int size  = Path.size();
        int k = 0;
        Path.push(make_pair(i, j));
        while (k < size) {
            pair<int, int> point1 = Path.top();
            Path.pop();
            pair<int, int> point2 = Path.top();
            if (point1.first == point2.first && point1.second> point2.second) {
                result += "R";
            }
            if (point1.first == point2.first && point1.second < point2.second) {
                result += "L";
            }
            if (point1.first > point2.first && point1.second == point2.second) {
                result+= "D";
            }
            if (point1.first < point2.first && point1.second == point2.second) {
                result+= "U";
            }
            k++;

        }
        reverse(result.begin(), result.end());
        return result;
    }
};

#endif //MILESTONE2_A_STAR_H
