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
    State () = default;
    State ( vector<int> currentState, State* prevState = nullptr )
            : currentState_(currentState), prevState_(prevState) {}
    
    vector<int> getBoard() const { return currentState_; }
    //void setBoard(vector<int> newBoard);
    
    bool compare(const State& s) const;
    int getZeroPos() const;
    
    int countH1() const;
    bool checkBoard() const;
    
private:
    vector<int> currentState_;
    State* prevState_;
};

// compare two states
bool State::compare(const State& s) const
{
    return currentState_ == s.currentState_;
}

// get the position of the empty block
int State::getZeroPos() const
{
    for ( int i = 0; i < 9; i++ )
    {
        if ( currentState_.at(i) == 0 )
        {
            cout << "0 at pos: " << i << endl;
            return i;
        }
    }
    
    return 0;
}

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
    
    return this->compare(State(endBoard));
}

// print out values in vector
void printVec(vector<int> vec)
{
    for (auto i : vec)
        cout << i << " ";
    cout << endl;
    
}

// function to find possible moves
vector<int> findMoves(State state)
{
    //find position of empty block
    int pos = state.getZeroPos();
    
    vector<int> moves;
    
    switch (pos) {
        case 0:
            moves = { 1, 3 };
            break;
        case 1:
            moves = {0,2,4};
            break;
        case 2:
            moves = {1,5};
            break;
        case 3:
            moves = {0,4,6};
            break;
        case 4:
            moves = {1,3,5,7};
            break;
        case 5:
            moves = {2,4,8};
            break;
        case 6:
            moves = {3,7};
            break;
        case 7:
            moves = {6,4,8};
            break;
        case 8:
            moves = {5,7};
            break;
            
        default:
            cout << "error in findMoves" << endl;
            break;
    }
    
    return moves;
}

// solve the 8 puzzle and find the fastest way to solve it
bool solve(State state)
{
    cout << "number of correct boards from beginning: " << state.countH1() << endl;
    vector<int> possibleMoves;
    std::queue<State> q;
    
    q.push(state);
    //find possible moves
    possibleMoves = findMoves(q.front());
    
    printVec(possibleMoves);
    
    if (state.checkBoard())
        cout << "correct" << endl;
    else
        cout << "not correct board" << endl;

    return true;
    
}

//main function
int main()
{
    vector<int> startBoard { 1, 2, 3, 4, 5, 0, 7, 8, 6 };
    /*
     * 1 2 3
     * 4 5 0
     * 7 8 6
     */
    
    State state { startBoard };
    
    solve(state);
    
    return 0;
}