#include <iostream>
using namespace std;

class TowerOfHanoi
{
private:
    int moveCount;

public:
    TowerOfHanoi()
    {
        moveCount = 0;
    }
    void solve(int n, char BEG, char AUX, char END)
    {
        if (n == 1)
        {
            cout << BEG <<" to " << END <<endl;
            moveCount++;
            return;
        }
        solve(n-1, BEG, END, AUX);
        cout << BEG <<" to " << END <<endl;
        moveCount++;
        solve(n-1, AUX, BEG, END);
    }
    int totalMove()
    {
        return moveCount;
    }
};

int main()
{
    TowerOfHanoi tower;
    tower.solve(3, 'A', 'B', 'C');
    cout << "Total move: " << tower.totalMove() << endl;
}