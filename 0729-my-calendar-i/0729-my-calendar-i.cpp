class MyCalendar {
public:
    set<pair<int, int>> intervals;

    MyCalendar() {}

    bool book(int st, int et) {
        auto it = intervals.lower_bound({st, et});

        // Check next interval
        if (it != intervals.end() && et > it->first)
            return false;

        // Check previous interval
        if (it != intervals.begin()) {
            auto prev = std::prev(it);

            if (prev->second > st)
                return false;
        }

        intervals.insert({st, et});
        return true;
    }
};