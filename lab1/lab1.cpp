#include <iostream>
#include <vector>

using namespace std;

// returns the number of squares that are in the right place
int countH1(vector<int> vec)
{
    int count = 0;
    for ( int i = 0; i < 8; i++)
    {
        if ( vec.at(i) == i + 1 )
            count++;
    }
    
    cout << count << endl;
    return count;
}

int main()
{
    vector<int> startBoard { 1, 3, 5, 6, 2, 8, 7, 4 };
    countH1(startBoard);
    
    
    return 0;
}