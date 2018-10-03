/**
 * This algorithm does not belong to any paradigm:
 * 1) Select out people with highest height
 * 2) Sort them in index order
 * 3) Select out people with second highest height
 * 4) Insert them into its index position
 * ...
 * 
 * However, insertion itself requires array relocation.
 */

class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        
        /* Sort pair by first descending, if equal second ascending */
        auto comp = [](const pair<int, int> &a, const pair<int, int> &b) 
            -> bool { return a.first > b.first || 
            (a.first == b.first && a.second < b.second); };
        std::sort(people.begin(), people.end(), comp);
        
        /* Insert into vector */
        vector<pair<int, int>> result;
        for(const pair<int, int> &p : people)
            result.insert(result.begin() + p.second, p);

        return result;
    }
};
