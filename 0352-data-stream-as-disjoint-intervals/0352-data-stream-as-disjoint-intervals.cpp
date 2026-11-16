class SummaryRanges {
    set<int> set;
public:
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        set.insert(value);
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> res;

        int start, end;
        start = end = -1;

        for (auto it = set.begin(); it != set.end(); ++it) {
            if (start == -1) start = *it;
            if (set.count(*it + 1)) continue;
            else {
                auto tmp = {start, *it};
                res.push_back(std::move(tmp));
                start = -1;
            }
        }

        return res;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */