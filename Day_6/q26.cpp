// https://leetcode.com/problems/insert-delete-getrandom-o1-duplicates-allowed/description/

class RandomizedCollection {
public:
    unordered_map<int, int> m;
    list<int> li;
    RandomizedCollection() {}
    
    bool insert(int val) {
        bool found = false;
        if(m.find(val) == m.end())
            found = true;
        li.push_back(val);
        m[val]++;
        return found;
    }
    
    bool remove(int val) {
        
        bool found = false;
        if(m.find(val) != m.end()) {
            found = true;
            m[val]--;
            if(m[val] == 0) m.erase(val);
            for (auto it = li.begin(); it != li.end(); it++)
            {
                if (*it == val) {
                    li.erase(it);
                    break;
                }
            }
        }

        return found;
    }
    
    int getRandom() {

        int listSize = li.size();
        int randomPosition = rand() % listSize;
        list<int>::iterator it = li.begin();
        std::advance(it, randomPosition);
        
        return *it;
    }
};