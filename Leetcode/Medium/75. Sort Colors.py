class Solution:
    def sortColors(self, nums):
        # Dutch National Flag algorithm for in-place sorting
        left, mid, right = 0, 0, len(nums) - 1
        
        while mid <= right:
            if nums[mid] == 0:
                nums[left], nums[mid] = nums[mid], nums[left]
                left += 1
                mid += 1
            elif nums[mid] == 1:
                mid += 1
            else:
                nums[mid], nums[right] = nums[right], nums[mid]
                right -= 1
        
        return nums

# Test cases
if __name__ == "__main__":
    solution = Solution()
    
    test1 = [2,0,2,1,1,0]
    print(f"Input: nums = {test1}")
    solution.sortColors(test1)  # Modifies array in-place
    print(f"Output: {test1}")

    test2 = [2,0,1]
    print(f"\nInput: nums = {test2}")
    solution.sortColors(test2)  # Modifies array in-place
    print(f"Output: {test2}")
