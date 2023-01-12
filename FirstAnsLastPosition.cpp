class Solution {
public:

 int firstOcc(vector<int>& nums, int n, int target) {

    int s = 0, e = n-1;
    int mid = s + (e-s)/2;
    int ans = -1;
    while(s<=e) {

        if(nums[mid] == target){
            ans = mid;
            e = mid - 1;
        }
        else if(target > nums[mid]) {//Right me jao
            s = mid + 1;
        }
        else if(target < nums[mid]) {//left me jao
            e = mid - 1;
        }

        mid = s + (e-s)/2;
    }
    return ans;
}

int lastOcc(vector<int>& nums, int n, int target) {

    int s = 0, e = n-1;
    int mid = s + (e-s)/2;
    int ans = -1;
    while(s<=e) {

        if(nums[mid] == target){
            ans = mid;
            s = mid + 1;
        }
        else if(target > nums[mid]) {//Right me jao
            s = mid + 1;
        }
        else if(target < nums[mid]) {//left me jao
            e = mid - 1;
        }

        mid = s + (e-s)/2;
    }
    return ans;
}

    vector<int> searchRange(vector<int>& nums, int target) {
        // return {BinarySearch(nums, target, "FIRST"), BinarySearch(nums, target, "LAST")};
        int n=nums.size();
        
    return {firstOcc(nums, n, target),lastOcc(nums, n, target)} ;
   
    }
    
    // int BinarySearch(vector<int> nums, int key, string find) {
    //     // int left = 0, right = nums.size() - 1, mid;
    //     // int result = -1;

    //     // while (left <= right) {
    //     //     mid = (left + right) / 2;

    //     //     if (nums[mid] == key) {
    //     //         if(find=="FIRST"){
    //     //             right = mid - 1;
    //     //         }
    //     //         else{
    //     //             left = mid + 1;
    //     //         }
    //     //         result = mid;
    //     //         // (/find == "FIRST") ? right = mid - 1 : left = mid + 1;
    //     //     }
    //     //     else if (nums[mid] > key) {
    //     //         right = mid - 1;
    //     //     }
    //     //     else {
    //     //         left = mid + 1;
    //     //     }
    //     // }

    //     // return result;



    // }
};
