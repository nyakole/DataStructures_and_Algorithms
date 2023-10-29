 // https://leetcode.com/problems/tweet-counts-per-frequency/
 unordered_map<string,multiset<int>>m;
    TweetCounts() {
        
    }
    
    void recordTweet(string s, int t) {
        m[s].insert(t);
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string s, int st, int et) {
        int c=60;
        if(freq=="hour"){c=3600;}
        else if(freq=="day"){c=86400;}
        int t=st;
        vector<int>ans;
        while(t<=et)
        {
            int h=min({t+c-1,et});
            int dis=distance(m[s].lower_bound(t),m[s].lower_bound(h));
            
            if(t==h)
            {
                
                if(m[s].find(t)!=m[s].end()){dis=1;}
            }
            ans.push_back(dis);
            t+=c;
        }
        return ans;

    }