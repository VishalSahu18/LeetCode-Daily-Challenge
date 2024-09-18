class Solution:
    def largestNumber(self, nums: List[int]) -> str:
              
        store = list(map(str, nums))
    
        store.sort(key=lambda a: a*10, reverse=True)
        
        ans = ''.join(store)
        
        return '0' if ans[0] == '0' else ans
