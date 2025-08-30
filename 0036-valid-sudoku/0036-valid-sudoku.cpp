class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        for (int i = 0; i < 9; i++)
        {
            unordered_map<char, int> mpp;
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] != '.')
                {
                    if (mpp[board[i][j]] > 0)
                    {
                        return false;
                    }
                    mpp[board[i][j]] += 1;
                }
            }
        }
        for (int j = 0; j < 9; j++)
        {
            unordered_map<char, int> mpp;
            for (int i = 0; i < 9; i++)
            {
                if (board[i][j] != '.')
                {
                    if (mpp[board[i][j]] > 0)
                    {
                        return false;
                    }
                    mpp[board[i][j]] += 1;
                }
            }
        }
        for (int k = 0; k < 9; k++)
        {
            int row = k / 3;
            int col = k % 3;
            unordered_map<char, int> mpp;
            for (int i = row * 3; i < row * 3 + 3; i++)
            {
                for (int j = col * 3; j < col * 3 + 3; j++)
                {
                    if (board[i][j] != '.')
                    {
                        if (mpp[board[i][j]] > 0)
                        {
                            return false;
                        }
                        mpp[board[i][j]] += 1;
                    }
                }
            }
        }
        return true;
    }
};