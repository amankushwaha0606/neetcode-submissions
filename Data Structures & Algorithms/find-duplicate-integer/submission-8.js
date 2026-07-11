class Solution {
    /**
     * @param {number[]} nums
     * @return {number}
     */
    findDuplicate(nums) {
    //      for(let i =0; i<nums.length;i++){
    //     for(let j=i+1;j<nums.length;j++){
    //         if(nums[i]==nums[j]){
    //             return nums[i]
    //         }
    //     }
    //    }
        for(let i=0; i<nums.length; i++) {
            let index = Math.abs(nums[i]);
            if(nums[index] < 0 ) return index;
            nums[index] = -nums[index];
        }
    }
}
