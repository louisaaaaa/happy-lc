class Solution {
    public:
        vector<int> spiralOrder(vector<vector<int>>& matrix) {
            int m = matrix.size()-1; //赋值别错
            int n = matrix[0].size()-1;
            int left = 0;
            int right = n;
            int top = 0;
            int bottom = m;
            vector<int> res;
    
            while(left <= right && top <= bottom){
                for (int i = left;i<=right;i++){
                    res.push_back(matrix[top][i]);
                }
                top++;
                for (int i = top;i<=bottom;i++){
                    res.push_back(matrix[i][right]);
                }
                right--;
                if (top <=bottom){ //需要在里面也重新条件判断,如果不是n*n的方形，会有一个先耗尽
                    for (int i = right;i>=left;i--){
                        res.push_back(matrix[bottom][i]);
                    }
                }
                
                bottom--;
                if (left <= right){
                    for (int i = bottom;i>=top;i--){
                        res.push_back(matrix[i][left]);
                    }
                }
                
                left++;
            }
            return res;
        }
    };