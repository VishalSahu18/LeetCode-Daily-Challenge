class MyCalendar {

    private TreeSet<int[]> calendar;

    public MyCalendar() {
        calendar = new TreeSet<>((a, b) -> a[0] - b[0]);
    }
    
    public boolean book(int start, int end) {
        int[] newEvent = {start, end};
        int[] prev = calendar.floor(newEvent);
        int[] next = calendar.ceiling(newEvent);

        if (prev != null && prev[1] > start) {
            return false; 
        }
        if (next != null && next[0] < end) {
            return false; 
        }

        calendar.add(newEvent);
        return true;
    }
}