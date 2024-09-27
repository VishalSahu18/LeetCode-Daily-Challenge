import java.util.TreeMap;

class MyCalendarTwo {

    private TreeMap<Integer, Integer> map;

    public MyCalendarTwo() {
        map = new TreeMap<>();
    }

    public boolean book(int start, int end) {

        map.put(start, map.getOrDefault(start, 0) + 1);
        map.put(end, map.getOrDefault(end, 0) - 1);
        int activeBookings = 0;

        for (int value : map.values()) {
            activeBookings += value;
            if (activeBookings >= 3) {
                map.put(start, map.get(start) - 1);
                map.put(end, map.get(end) + 1);
                return false;
            }
        }

        return true;
    }
}
