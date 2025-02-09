class Solution:
    def findMedianSortedArrays(self, nums1, nums2):
        # Ensure nums1 is the smaller array for binary search
        if len(nums1) > len(nums2):
            nums1, nums2 = nums2, nums1

        m, n = len(nums1), len(nums2)
        total_length = m + n
        half_length = (total_length + 1) // 2  # the halfway point

        # Binary search boundaries
        left, right = 0, m

        while left <= right:
            partition1 = (left + right) // 2
            partition2 = half_length - partition1

            # Set edge values when partition goes out of bounds
            max_left1 = float('-inf') if partition1 == 0 else nums1[partition1 - 1]
            min_right1 = float('inf') if partition1 == m else nums1[partition1]

            max_left2 = float('-inf') if partition2 == 0 else nums2[partition2 - 1]
            min_right2 = float('inf') if partition2 == n else nums2[partition2]

            # Check if we found the correct partition
            if max_left1 <= min_right2 and max_left2 <= min_right1:
                # If total length is odd, return the max of left side
                if total_length % 2 == 1:
                    return max(max_left1, max_left2)
                # If total length is even, return the average of max of left side and min of right side
                return (max(max_left1, max_left2) + min(min_right1, min_right2)) / 2.0

            # Adjust binary search bounds
            elif max_left1 > min_right2:
                right = partition1 - 1
            else:
                left = partition1 + 1


