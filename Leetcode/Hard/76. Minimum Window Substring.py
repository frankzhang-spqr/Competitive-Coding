class Solution:
    def minWindow(self, s: str, t: str) -> str:
        if not s or not t:
            return ""
            
        # Dictionary to store frequency of characters in t
        needed = {}
        for char in t:
            needed[char] = needed.get(char, 0) + 1
        
        # Initialize variables
        l = 0  # left pointer
        min_length = float('inf')  # length of minimum window
        min_window_start = 0  # start index of minimum window
        required = len(needed)  # count of distinct characters needed
        formed = 0  # count of distinct characters formed
        window_counts = {}  # frequency map for current window
        
        # Iterate through string s with right pointer
        for r in range(len(s)):
            char = s[r]
            window_counts[char] = window_counts.get(char, 0) + 1
            
            # If we have found all occurrences of current character
            if char in needed and window_counts[char] == needed[char]:
                formed += 1
                
            # Try to minimize window by moving left pointer
            while l <= r and formed == required:
                char = s[l]
                
                # Update minimum window if current window is smaller
                if r - l + 1 < min_length:
                    min_length = r - l + 1
                    min_window_start = l
                    
                # Remove leftmost character from window
                window_counts[char] -= 1
                if char in needed and window_counts[char] < needed[char]:
                    formed -= 1
                    
                l += 1
                
        return s[min_window_start:min_window_start + min_length] if min_length != float('inf') else ""
