class Solution:
    def __init__(self):
        self.map = {}

    def recursion(self, curr: str) -> List[int]:
        if curr in self.map:
            return self.map[curr]

        ans = []
        n = len(curr)

        for i in range(n):
            c = curr[i]

            if c == '-' or c == '*' or c == '+':
                a = self.recursion(curr[:i])
                b = self.recursion(curr[i + 1:])

                for x in a:
                    for y in b:
                        if c == '-':
                            z = x - y
                        elif c == '+':
                            z = x + y
                        else:
                            z = x * y
                        ans.append(z)

        if not ans:
            ans.append(int(curr))

        self.map[curr] = ans
        return ans

    def diffWaysToCompute(self, expression: str) -> List[int]:
         return self.recursion(expression)
        