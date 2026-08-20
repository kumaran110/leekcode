from collections import Counter

class Solution(object):
    def minWindow(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: str
        """
        if not s or not t:
            return ""

        # Count frequencies of characters in t
        t_freq = Counter(t)
        required = len(t_freq)

        # Sliding window tracking variables
        window_freq = {}
        formed = 0  # Tracks how many unique characters meet their required frequency

        left = 0
        ans = (float("inf"), 0, 0)  # (window_length, left, right)

        for right, char in enumerate(s):
            # Add character from the right pointer to window
            window_freq[char] = window_freq.get(char, 0) + 1

            # If frequency matches required frequency in t, increment formed
            if char in t_freq and window_freq[char] == t_freq[char]:
                formed += 1

            # Contract window from left while it remains valid
            while left <= right and formed == required:
                # Update smallest window result
                if right - left + 1 < ans[0]:
                    ans = (right - left + 1, left, right)

                # Remove left character from window
                left_char = s[left]
                window_freq[left_char] -= 1

                if left_char in t_freq and window_freq[left_char] < t_freq[left_char]:
                    formed -= 1

                left += 1

        return "" if ans[0] == float("inf") else s[ans[1]:ans[2] + 1]