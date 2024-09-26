class MyCalendar:

    def __init__(self):
        self.st = set()

    def book(self, start: int, end: int) -> bool:
        for s, e in self.st:
            if not (end <= s or start >= e):  # Check for overlap
                return False
        
        self.st.add((start, end))  # Add the booking
        return True