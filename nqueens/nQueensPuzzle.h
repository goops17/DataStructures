#ifndef NQUEENSPUZZLE_H
#define NQUEENSPUZZLE_H

//class specifies the functions to solve the n-queens puzzle
class nQueensPuzzle
{
public:
    nQueensPuzzle(int queens = 8);
    //the constructor - starts with 8 noOfSolutions = 0; noOfQueens = queens;
    //queensInRow is a pointer to the array to store the n-tuple
    ~nQueensPuzzle();
    //destructor
    bool canPlaceQueen(int k, int i);
    //determines whether a queen can be placed in row k and col i
    void queensConfig (int k);
    //determines all solutions to the n-queens puzzle - uses backtracking algorithm
    void printConfig();
    //output an n-tuple containing a solution to n-queens puzzle
    int solutionsCount();
    //Returns the total number of solutions

private:
    int noOfSolutions;
    int noOfQueens;
    int *queensInRow;
    int **board;
};
#endif // NQUEENSPUZZLE_H
