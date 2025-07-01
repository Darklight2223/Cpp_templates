int maxOverlap(vector<pair<int, int>>& intervals) {
    vector<pair<int, int>> events;

    for (auto& [start, end] : intervals) {
        events.emplace_back(start, +1);
        events.emplace_back(end + 1, -1); 
    }

    sort(events.begin(), events.end());

    int active = 0, maxOverlap = 0;

    for (auto& [time, delta] : events) {
        active += delta;
        maxOverlap = max(maxOverlap, active);
    }

    return maxOverlap;
}
