int toMinutes(char *time) {
    int hh = (time[0] - '0') * 10 + (time[1] - '0');
    int mm = (time[3] - '0') * 10 + (time[4] - '0');
    return hh * 60 + mm;
}

int findMinDifference(char** timePoints, int timePointsSize) {
    
 int min_diff = 24 * 60 + 1;
    bool visit[24 * 60 + 1] = {false};

    for (int i = 0; i < timePointsSize; i++) {
        int minutes = toMinutes(timePoints[i]);
        if (visit[minutes])
            return 0;
        visit[minutes] = true;
    }

    int first = 24 * 60 + 1;
    int prevMinute = -1;

    for (int i = 0; i <= 24 * 60; i++) {
        if (visit[i]) {
            if (prevMinute != -1)
                min_diff = min_diff < (i - prevMinute) ? min_diff : (i - prevMinute);
            prevMinute = i;
            first = first < i ? first : i;
        }
    }

    return min_diff < ((24 * 60 - prevMinute) + first) ? min_diff : ((24 * 60 - prevMinute) + first);
}