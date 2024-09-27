#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>   // for std::rand and std::srand
#include <ctime>     // for std::time
#include <SFML/Graphics.hpp>

using std::cout;
using std::endl;

#define MAX 15
#define LAST 14

int calculate_neighbours(int matrix[MAX][MAX],int i, int j)
{
    int num = 0;
    // Corner Cases
    if (i == 0 && j == 0) {
        num += matrix[i][j+1] + matrix[i+1][j+1] + matrix[i+1][j];
        return num;
    }
    else if (i == LAST && j == LAST) {
        num += matrix[i][j-1] + matrix[i-1][j-1] + matrix[i-1][j];
        return num;
    }
    else if (i == 0 && j == LAST) {
        num += matrix[i][j-1] + matrix[i+1][j-1] + matrix[i+1][j];
        return num;
    }
    else if (i == LAST && j == 0) {
        num += matrix[i][j+1] + matrix[i-1][j+1] + matrix[i-1][j];
        return num;
    }

    else if (i == 0 && (j > 0 && j < LAST)) {
        num += matrix[i+1][j-1] + matrix[i+1][j] + matrix[i+1][j+1];
        num += matrix[i][j-1] + matrix[i][j+1];
        return num;
    }
    else if (i == LAST && (j > 0 && j < LAST)) {
        num += matrix[i-1][j-1] + matrix[i-1][j] + matrix[i-1][j+1];
        num += matrix[i][j-1] + matrix[i][j+1];
        return num;
    }
    else if (j == 0 && (i > 0 && i < LAST)) {
        num += matrix[i-1][j+1] + matrix[i][j+1] + matrix[i+1][j+1];
        num += matrix[i-1][j] + matrix[i+1][j];
        return num;
    }
    else if (j == LAST && (i > 0 && i < LAST)) {
        num += matrix[i-1][j-1] + matrix[i][j-1] + matrix[i+1][j-1];
        num += matrix[i-1][j] + matrix[i+1][j];
        return num;
    }

    else {
        for (int m=-1; m<2;m++) {
            for (int n=-1; n<2;n++) {
                if (m == 0 && n == 0) continue;
                num += matrix[i+m][j+n];
            }
        }
        return num;
    }
}

// Rules for Cell Evolution

// Each cell's next state (alive or dead) depends on the current state and the number of alive neighbors it has:

//     Overpopulation: If a live cell has more than three live neighbors, it dies (as if by overpopulation).    > 3
//     Underpopulation: If a live cell has fewer than two live neighbors, it dies (as if by underpopulation).   < 2
//     Survival: If a live cell has two or three live neighbors, it stays alive.                                == 2 | 3
//     Reproduction: If a dead cell has exactly three live neighbors, it becomes alive.                         == 3

void update_matrix(int matrix[MAX][MAX])
{
    int nextState[MAX][MAX] = {};

    for (int i = 0; i < MAX; ++i) {
        for (int j = 0; j < MAX; ++j) {
            int neig = calculate_neighbours(matrix,i,j);
            if (matrix[i][j] == 0 && neig == 3) {
                // Reproduction : Dead Cell --> Alive
                nextState[i][j] = 1;
            }
            else if (matrix[i][j] == 1 && neig > 3) {
                // Overpopulation : Live Cell --> Dead
                nextState[i][j] = 0;
            }
            else if (matrix[i][j] == 1 && neig < 2) {
                // Underpopulation : Live Cell --> Dead
                nextState[i][j] = 0;
            }
            else if (matrix[i][j] == 1 && (neig == 2 || neig == 3)) {
                // Survival : Live Cell --> Live
                nextState[i][j] = 1;
            }
            cout << neig << " " ;
        }
        cout << endl;
    }

    // Copy the next state back to the original grid
    for (int i = 0; i < MAX; ++i) {
        for (int j = 0; j < MAX; ++j) {
            matrix[i][j] = nextState[i][j];
        }
    }
}

void print_matrix(int matrix[MAX][MAX])
{
    for (int i = 0; i < MAX; ++i) {
        for (int j = 0; j < MAX; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int matrix[MAX][MAX] = {};

    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    for (int i = 0; i < MAX; ++i) {
        for (int j = 0; j < MAX; ++j) {
            matrix[i][j] = std::rand() % 2;  // Randomly set to 0 or 1
        }
    }

    cout << "= = = = = = = = = = = = = = = = = = = = = =" << endl << endl;
    // while(1) {
        print_matrix(matrix);
        cout << endl <<  "= = = = = = = = = = = = = = = = = = = = = =" << endl << endl;
        update_matrix(matrix);
        cout << endl <<  "= = = = = = = = = = = = = = = = = = = = = =" << endl << endl;
        sf::sleep(sf::seconds(1));
        print_matrix(matrix);
        cout << endl <<  "= = = = = = = = = = = = = = = = = = = = = =" << endl << endl;
    // }

    return 0;
}