/*
https://binarysearch.com/problems/Tic-Tac-Toe

Tic Tac Toe
Medium

Implement the tic-tac-toe game with the following methods:

TicTacToe(int n) which instantiates an n x n game board. A player wins a game if
their pieces either form a horizontal, vertical, or diagonal line of length n.
int move(int r, int c, boolean me) which places the next move at row r and
column c. me indicates whether it's my move (me = true) or it's your opponent's
(me = false) move. If this move makes you win, return 1, if your opponent wins,
return -1, and otherwise return 0. Constraints

1 ≤ n ≤ 100,000
0 ≤ m ≤ 100,000 where m is the number of calls to move
Example 1
Input
methods = ["constructor", "move", "move", "move", "move", "move"]
arguments = [[3], [0, 0, true], [2, 0, false], [0, 1, true], [2, 1, false], [0,
2, true]]` Output [null, 0, 0, 0, 0, 1] Explanation t = TicTacToe(3) t.move(0,
0, True) == 0 # I place piece (0, 0) t.move(2, 0, False) == 0 # Opponent places
piece (2, 0) t.move(0, 1, True) == 0 # I place piece (0, 1) t.move(2, 1, False)
== 0 # Opponent places piece (2, 1) t.move(0, 2, True) == 1 # I place piece (0,
2) to win

 */

class TicTacToe {
   public:
    int n;
    vector<int> rowSum;
    vector<int> colSum;
    int diagonalSum = 0;
    int revDiagonalSum = 0;

    TicTacToe(int n) {
        this->n = n;
        rowSum = vector<int>(n, 0);
        colSum = vector<int>(n, 0);
    }

    // 1 -> if you won
    //-1 -> if opponent wins
    //  0 -> otherwise
    int move(int r, int c, bool me) {
        int val = me ? 1 : -1;
        rowSum[r] += val;
        colSum[c] += val;
        if (r == c) {
            diagonalSum += val;
        }
        if (c == n - r - 1) {
            revDiagonalSum += val;
        }

        if (rowSum[r] == n || colSum[c] == n || diagonalSum == n ||
            revDiagonalSum == n) {
            return 1;
        }
        if (rowSum[r] == -n || colSum[c] == -n || diagonalSum == -n ||
            revDiagonalSum == -n) {
            return -1;
        }
        return 0;
    }
};