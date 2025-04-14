class Solution {
    public:
        void expand(vector<int>& nums, int target, vector<int>& res, int mid){
            int pointer = mid-1;
            while(pointer >= 0 && nums[pointer] == target){ // find left
                pointer--;
            }
            res[0] = pointer+1;
    
            pointer = mid+1;
            while(pointer < nums.size() && nums[pointer] == target){ // find left
                // 这种地方也错，写了小于号就不要再-1了！
                pointer++;
            }
            res[1] = pointer-1; // 这个地方一开始还是res[0]，你个笨蛋
            // printf("enter");
        }
        vector<int> searchRange(vector<int>& nums, int target) {
            int left = 0;
            int right = nums.size()-1;  
            vector<int> res = {-1,-1};
            while(left <= right){ // 注意，这个地方要等于，因为会出现左右相等的情况
                printf("enter");
                int mid = left + (right-left)/2;
                if (target == nums[mid]){ // find target
                    printf("mid: %d", mid);
                    expand(nums, target, res, mid);
                    return res; //这个地方不能是break，直接返回即可(又检查了一遍，可以是break)
                } else if (target < nums[mid]){ // find in left section
                    right = mid-1; // 记住，二分查找不要包括中点！！！！！！！！！！！！！！！！！
                } else{
                    left = mid+1;
                }
            }
            return res;
        }
    };