class MyCalendarTwo:

    def __init__(self):
        self.bookings = {}

    def book(self, start: int, end: int) -> bool:
        self.bookings[start] = self.bookings.get(start, 0) + 1
        self.bookings[end] = self.bookings.get(end, 0) - 1

        active_bookings = 0

       
        for time in sorted(self.bookings):
            active_bookings += self.bookings[time]
            if active_bookings >= 3:
                self.bookings[start] -= 1
                self.bookings[end] += 1
                return False

        return True
