class Solution {
public:

    bool check(vector<vector<int>>&grid, int x, int y){
        unordered_set<int>val;

        int n = grid.size();
        int m = grid[0].size();

        for(int i = -1; i<=1 ; i++){
            for(int j = -1; j<=1 ; j++){
                
                val.insert(grid[x+i][y+j]);
            }
        }

        for(int i = 1; i<=9; i++){
            if(val.count(i)==0){
                return false;
            }
        }

        return true;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int result = 0;

        int n = grid.size();
        int m = grid[0].size();

        if (n <= 2 || m <= 2) {
            return 0;
        }

        for (int i = 1; i < n - 1; i++) {

            for (int j = 1; j < m - 1; j++) {

                if (check(grid, i, j)) {
                    unordered_set<int> value;

                    int a = grid[i - 1][j - 1] + grid[i - 1][j] +
                            grid[i - 1][j + 1];
                    int b = grid[i][j - 1] + grid[i][j] + grid[i][j + 1];
                    int c = grid[i + 1][j - 1] + grid[i + 1][j] +
                            grid[i + 1][j + 1];

                    int d = grid[i - 1][j - 1] + grid[i][j - 1] +
                            grid[i + 1][j - 1];
                    int e = grid[i - 1][j] + grid[i][j] + grid[i + 1][j];
                    int f = grid[i - 1][j + 1] + grid[i][j + 1] +
                            grid[i + 1][j + 1];

                    int g =
                        grid[i - 1][j - 1] + grid[i][j] + grid[i + 1][j + 1];
                    int h =
                        grid[i - 1][j + 1] + grid[i][j] + grid[i + 1][j - 1];

                    value.insert(a);
                    value.insert(b);
                    value.insert(c);
                    value.insert(d);
                    value.insert(e);
                    value.insert(f);
                    value.insert(g);
                    value.insert(h);

                    if (value.size() == 1) {
                        result++;
                    }
                }
            }
        }

        return result;
    }
};