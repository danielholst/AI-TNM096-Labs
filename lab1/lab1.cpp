#include <iostream>
#include <vector>

using namespace std;

/*
 * class to represent the current state of the board,
 * with pointer to previous state
 */
class State
{
public:
    State() = default;
    State( vector<int> currentState ) : currentState_(currentState), prevState_(nullptr) {}
    
    vector<int> getBoard() const { return currentState_; }
    //void setBoard(vector<int> newBoard);
    
private:
    vector<int> currentState_;
    State* prevState_;
};

// returns the number of squares that are in the right place
int countH1(vector<int> vec)
{
    int count = 0;
    for ( int i = 0; i < 9; i++)
    {
        if ( vec.at(i) == i + 1 )
            count++;
        else if ( i == 8 && vec.at(i) == 0 )
            count++;
    }
    
    cout << count << endl;
    return count;
}

// check if the board is correct
bool checkBoard(vector<int> board)
{
    vector<int> endBoard { 1, 2, 3, 4, 5, 6, 7, 8, 0 };
    
    for ( int i = 0; i < 9; i++)
    {
        if ( board.at(i) != endBoard.at(i) )
            return false;
    }
    return true;
}

int main()
{
    vector<int> startBoard { 1, 3, 5, 6, 2, 8, 7, 4, 0 };
    State state { startBoard };
    
    countH1(state.getBoard());
    
    if (checkBoard(state.getBoard()))
        cout << "correct" << endl;
    else
        cout << "not correct board" << endl;
    
    
    return 0;
}