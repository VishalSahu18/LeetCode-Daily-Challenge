var MyCalendarTwo = function() {
    this.bookings = [];
    this.overlaps = [];
};

/** 
 * @param {number} start 
 * @param {number} end
 * @return {boolean}
 */
MyCalendarTwo.prototype.book = function(start, end) {
    for (let [s, e] of this.overlaps) {
        if (start < e && end > s) {
            return false;
        }
    }

    for (let [s, e] of this.bookings) {
        if (start < e && end > s) {
            this.overlaps.push([Math.max(start, s), Math.min(end, e)]);
        }
    }

    this.bookings.push([start, end]);
    return true;
};
