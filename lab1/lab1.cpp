#include <iostream>
#include <vector>
#include <queue>

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
    
    int countH1() const;
    bool checkBoard() const;
    
private:
    vector<int> currentState_;
    State* prevState_;
};

// returns the number of squares that are in the right place
int State::countH1() const
{
    int count = 0;
    for ( int i = 0; i < 9; i++)
    {
        if ( currentState_.at(i) == i + 1 )
            count++;
        else if ( i == 8 && currentState_.at(i) == 0 )
            count++;
    }
    
    return count;
}

// check if the board is correct
bool State::checkBoard() const
{
    vector<int> endBoard { 1, 2, 3, 4, 5, 6, 7, 8, 0 };
    
    for ( int i = 0; i < 9; i++)
    {
        if ( currentState_.at(i) != endBoard.at(i) )
            return false;
    }
    return true;
}

// function to find the best next move
//vector<int> findBestMove(vector<int> currentBoard) {}


// solve the 8 puzzle and find the fastest way to solve it
bool solve(State state)
{
    cout << "number of correct boards from beginning: " << state.countH1() << endl;
    
    std::queue<State> q;
    
    if (state.checkBoard())
        cout << "correct" << endl;
    else
        cout << "not correct board" << endl;

    return true;
    
}

int main()
{
    vector<int> startBoard { 1, 2, 3, 4, 5, 0, 7, 8, 6 };
    State state { startBoard };
    
    solve(state);
    
    return 0;
}