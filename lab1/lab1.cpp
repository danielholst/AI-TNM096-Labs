#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

/*
 * class to represent the current state of the board,
 * with pointer to previous state
 */
class State
{
public:
    State () = default;
    State ( vector<int> currentState, State* prevState = nullptr, int nrOfMoves = 0 )
            : currentState_(currentState), prevState_(prevState), nrOfMoves_(nrOfMoves) {}
    
    vector<int> getBoard() const { return currentState_; }
    //void setBoard(vector<int> newBoard);
    
    bool compare(const State& s) const;
    int getZeroPos() const;
    
    int getMoves() const { return nrOfMoves_; }

    
    int countH1() const;
    bool checkBoard() const;
    
private:
    vector<int> currentState_;
    State* prevState_;
    int nrOfMoves_;
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

// to compare the different states depending on heuristic
struct cmp
{
    bool operator() (State& s1, State& s2)
    {
        return (s1.countH1() < s2.countH1());
    }
};

// function to find possible moves
vector<int> findMoves(State state)
{
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
            break;
    }
    
    return moves;
}

// solve the 8 puzzle and find the fastest way to solve it
bool solve(State state)
{
    cout << "number of correct boards from beginning: " << state.countH1() << endl;
    vector<int> possibleMoves;
    priority_queue<State, vector<State>, cmp> q;
    
    q.push(state);
    
    for( int k = 0; k < 10; k++) // temp, change to while (true) when working
    {
        State currentState = q.top();
        q.pop();
        
        cout << "=======================" << endl;
        cout << "0 at pos: " << currentState.getZeroPos() << endl;
        printVec(currentState.getBoard());
        
        // check if correct board
        if (currentState.checkBoard())
        {
            cout << "Found correct board after " << currentState.getMoves() << " iterations" << endl;
            break;
        }
        
        //find possible moves
        possibleMoves = findMoves(currentState);
        cout << "Possible moves: ";
        printVec(possibleMoves);
        
        //add new states to queue
        for ( auto i : possibleMoves )
        {
            vector<int> board = currentState.getBoard();
            swap(board.at(i), board.at(currentState.getZeroPos()));
            State newState { board, &currentState, currentState.getMoves()+1 };
            q.push(newState);
        }
    }

    return true;
    
}

//main function
int main()
{
    vector<int> startBoard { 1, 2, 3, 4, 5, 6, 0, 7, 8 };
    /*
     * 1 2 3
     * 4 5 0
     * 7 8 6
     */
    
    State state { startBoard, nullptr, 0 };
    
    solve(state);
    
    return 0;
}