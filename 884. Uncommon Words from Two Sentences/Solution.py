class Solution:
    def store_string(self, count, s):
        words = s.split(" ")
        for word in words:
            if word in count:
                count[word] += 1
            else:
                count[word] = 1
                
    def uncommonFromSentences(self, s1: str, s2: str) -> List[str]:
        count = {}
        self.store_string(count, s1)
        self.store_string(count, s2)
        
        ans = [word for word, freq in count.items() if freq == 1]
        return ans
        