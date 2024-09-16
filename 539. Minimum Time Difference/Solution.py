class Solution:
    def findMinDifference(self, timePoints: List[str]) -> int:
        visit = [False] * (24 * 60 + 1)
        min_diff = 24 * 60 + 1

        for time in timePoints:
            hh, mm = map(int, time.split(":"))
            minutes = hh * 60 + mm
            if visit[minutes]:
                return 0
            visit[minutes] = True

        first = 24 * 60 + 1
        prev_minute = -1

        for i in range(24 * 60 + 1):
            if visit[i]:
                if prev_minute != -1:
                    min_diff = min(min_diff, i - prev_minute)
                prev_minute = i
                first = min(first, i)

        return min(min_diff, (24 * 60 - prev_minute) + first)
        