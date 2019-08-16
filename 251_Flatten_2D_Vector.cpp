#include <iostream>
#include <vector>

using namespace std;

class Vector2D {
private:
    vector<int> flattened_vector;
    int idx = 0;
public:
    Vector2D(vector<vector<int>>& v) {
        for (int i = 0; i < v.size(); ++i) {
            flattened_vector.insert(flattened_vector.end(),
                                    v[i].begin(), v[i].end());
        }
    }
    
    int next() {
        return flattened_vector[idx++];
    }
    
    bool hasNext() {
        return idx < flattened_vector.size();
    }
};


/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(v);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

int main() {
    vector<vector<int>> v;
    v.push_back(vector<int>{1, 2});
    v.push_back(vector<int>{3});
    v.push_back(vector<int>{4});

    Vector2D p(v);
    std::cout << p.next() << std::endl;
    std::cout << p.next() << std::endl;
    std::cout << p.next() << std::endl;
    std::cout << p.hasNext() << std::endl;
}