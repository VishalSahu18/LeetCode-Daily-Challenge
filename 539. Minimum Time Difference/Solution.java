class Solution {
    public int findMinDifference(List<String> timePoints) {
          boolean[] visit = new boolean[24 * 60 + 1];
        int min_diff = 24 * 60 + 1;

        for (String time : timePoints) {
            int hh = Integer.parseInt(time.substring(0, 2));
            int mm = Integer.parseInt(time.substring(3, 5));
            int minutes = hh * 60 + mm;
            if (visit[minutes]) return 0;
            visit[minutes] = true;
        }

        int first = 24 * 60 + 1;
        int prevMinute = -1;

        for (int i = 0; i <= 24 * 60; i++) {
            if (visit[i]) {
                if (prevMinute != -1) {
                    min_diff = Math.min(min_diff, i - prevMinute);
                }
                prevMinute = i;
                first = Math.min(first, i);
            }
        }

        return Math.min(min_diff, (24 * 60 - prevMinute) + first);
    }
}