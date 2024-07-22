// https://www.geeksforgeeks.org/problems/smallest-window-in-a-string-containing-all-the-characters-of-another-string-1587115621/1

class Solution
{
    public:
        string smallestWindow (string s, string p)
        {
            // 1. m1 has freq of p, m2 will have freq of window
            // 2. Two pointers, l and r
            // 3. Two variables, need and have. Need will store total chars needed, 
            //    have will store total chars we have
            // 4. When arrive at a char, check if it is in m1
            //    -> If yes, increase it's freq in m2
            //       -> If value equals that in m1, increase have
            // 5. If have == need, we found a valid window. Now, move the left side of window until the window is valid
            //    Everytime while moving the window, update maxWindowLength.
            
            int have = 0, need = 0, l = 0, r = 0, n = s.size();
            int validWindow = INT_MAX, validWindowLeft = -1, validWindowRight = n;
            vector<int> m1(26, 0), m2(26, 0);
            
            for(char c : p) {
                m1[c - 'a']++;
            }
            
            for(int i : m1)
                if(i != 0) need++;
            
            for(r = 0; r<n; r++) {
                
                char c = s[r];
                if(m1[c - 'a'] != 0) {
                    m2[c - 'a']++;
                    
                    if(m2[c - 'a'] == m1[c - 'a']) {
                        have++;
                    }
                    
                }
                
                while(l <= r && have == need) {
                    
                    int currWindowLen = r - l + 1;
                    if(currWindowLen < validWindow) {
                        validWindow = currWindowLen;
                        validWindowLeft = l;
                        validWindowRight = r;
                    }
                    
                    char ch = s[l];
                    
                    if(m2[ch - 'a'] != 0) {
                        m2[ch - 'a']--;
                        
                        if(m2[ch - 'a'] < m1[ch - 'a']) {
                            have--;
                        }
                    }
                    l++;
                }
                
            }
            if(validWindowLeft == -1 && validWindowRight == n)
                return "-1";
            
            return s.substr(validWindowLeft, validWindowRight-validWindowLeft+1);
        }
};
