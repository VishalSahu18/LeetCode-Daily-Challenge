class Solution:
    def longestCommonPrefix(self, arr1: List[int], arr2: List[int]) -> int:
        st = set()
        n1, n2 = len(arr1), len(arr2)
        mx = 0

        for num in arr1:
            curr = ""
            for x in str(num):
                curr += x
                st.add(curr)

        for num in arr2:
            curr = ""
            for x in str(num):
                curr += x
                if curr in st:
                    mx = max(mx, len(curr))

        return mx