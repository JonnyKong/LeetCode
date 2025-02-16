bool comparePair(const std::pair<int, int> &p1, const std::pair<int, int> &p2) {
    return p1.first < p2.first;
}

class SnapshotArray {
public:
    vector<vector<pair<int, int>>> per_elem_hist;
    int snap_id_latest;

    SnapshotArray(int length) {
        per_elem_hist = vector<vector<pair<int, int>>>(length);
        for (int i = 0; i < length; i++) {
            per_elem_hist[i].push_back(std::make_pair(-1, 0));
        }
        snap_id_latest = 0;
    }
    
    void set(int index, int val) {
        int last_snap = per_elem_hist[index][per_elem_hist[index].size() - 1].first;
        if (last_snap == snap_id_latest) {
            // Overwrite if write multiple values with the same snapshot ID
            per_elem_hist[index][per_elem_hist[index].size() - 1] = make_pair(snap_id_latest, val);
        } else {
            per_elem_hist[index].push_back(std::make_pair(snap_id_latest, val));
        }
    }
    
    int snap() {
        return snap_id_latest++;
    }
    
    int get(int index, int snap_id) {
        auto p = upper_bound(per_elem_hist[index].begin(), per_elem_hist[index].end(),
                            make_pair(snap_id, 0),
                            comparePair);
        return prev(p)->second;
    }
};
