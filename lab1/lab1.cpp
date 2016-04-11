#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <math.h>

using namespace std;

/*
 * class to represent the current state of the board,
 * with pointer to previous state
 */
class State
{
public:
    State () = default;
    State ( vector<int> currentState, int prevZero, int nrOfMoves = 0 )
            : currentState_(currentState), prevZero_(prevZero), nrOfMoves_(nrOfMoves) {}
    
    vector<int> getBoard() const { return currentState_; }
    
    bool compare(const State& s) const;
    
    int getZeroPos() const;
    int getPrevZero() const { return prevZero_; }
    
    int getMoves() const { return nrOfMoves_; }
    
    int countH1() const;
    int countManhattan() const;
    bool checkBoard() const;
    
private:
    vector<int> currentState_;
    int prevZero_;
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

int State::countManhattan() const
{
    int counter = 0;
    int xPosV, xPosReal;
    int yPosV, yPosReal;
    
    for(int i = 0; i < 9; i++)
    {
        xPosV = ((currentState_[i]-1) % 3);
        yPosV = floor((currentState_[i]-1) / 3);
        
        xPosReal = i%3;
        yPosReal = floor(i/3);
        if ( currentState_[i] != 0 )
        {
            counter += abs(xPosV - xPosReal) + abs(yPosV - yPosReal);
            //cout << "manhattan: " << i << " : counter: " << counter << endl;
        }
    }
    return counter;
}

// check if the board is correct
bool State::checkBoard() const
{
    vector<int> endBoard { 1, 2, 3, 4, 5, 6, 7, 8, 0 };

    return this->compare(State(endBoard, 0, 0));
}

// print out values in vector
void printVec(vector<int> vec)
{
    for (int i = 0; i < 9; i++) {
        cout << vec[i] << " ";
        
        if ( (i+1) % 3 == 0)
            cout << "\n";
    }
    
 
    cout << endl;
    
}

// to compare the different states depending on heuristic (h1)
struct cmpH1
{
    bool operator() (State& s1, State& s2)
    {
        if ( s1.countH1() == s2.countH1() )
            return s1.getMoves() < s2.getMoves();
        else
            return (s1.countH1() < s2.countH1());
    }
};

// to compare the different states depending on heuristic (manhattan)
struct cmpManhattan
{
    bool operator() (State& s1, State& s2)
    {
        if ( s1.countManhattan() == s2.countManhattan() )
            return s1.getMoves() < s2.getMoves();
        else
            return (s1.countManhattan() > s2.countManhattan());
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
            moves = {4,6,8};
            break;
        case 8:
            moves = {5,7};
            break;
            
        default:
            break;
    }
    
    // remove move to previous position
    if ( state.getMoves() != 0 )
    {
        int prevZero = state.getPrevZero();
        const auto newEnd = remove(moves.begin(), moves.end(), prevZero);
        moves.erase(newEnd, moves.end());
    }
    
    return moves;
}

// solve the 8 puzzle and find the fastest way to solve it
bool solve(State state)
{
    cout << "number of correct boards from beginning: " << state.countH1() << endl;
    vector<int> possibleMoves;
    priority_queue<State, vector<State>, cmpManhattan> q;
    
    q.push(state);
    
    for( int k = 0; k < 40; k++) // temp, change to while (true) when working
    {
        State currentState = q.top();
        q.pop();
        
        cout << "=======================" << endl;
        cout << "0 at pos: " << currentState.getZeroPos() << endl;
        cout << "nr of correct blocks: " << currentState.countH1() << endl;
        printVec(currentState.getBoard());
        
        // check if correct board
        if (currentState.checkBoard())
        {
            cout << "Found correct board after " << currentState.getMoves() << " iterations" << endl;
            break;
        }
        
        //find possible moves
        possibleMoves = findMoves(currentState);
        //cout << "Possible moves: ";
        //printVec(possibleMoves);
        
        //add new states to queue
        for ( auto i : possibleMoves )
        {
            vector<int> board = currentState.getBoard();
            swap(board.at(i), board.at(currentState.getZeroPos()));
            State newState { board, currentState.getZeroPos(), currentState.getMoves()+1 };
            q.push(newState);
        }
    }

    return true;
    
}

//main function
int main()
{
  //  vector<int> startBoard { 0, 2, 1, 4, 6, 3, 7, 5, 8 };
    vector<int> startBoard { 1, 2, 3, 4, 6, 0, 7, 5, 8 };
    /*
     * 1 2 3
     * 4 6 0
     * 7 5 8
     */
    
    State state { startBoard, 6, 0 };
    
    solve(state);
    
    return 0;
}