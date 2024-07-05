class Solution
{
    public:
        vector <int> fillLPS(string s){
            int len = 0,i=1;
            vector <int> lps(s.size(),0);
            while(i<s.size()){
                if(s[i]==s[len]){
                    len+=1;
                    lps[i] = len;
                    i+=1;
                }
                else if(len==0){
                    lps[i] = 0;
                    i+=1;
                }
                else{
                    len = lps[len-1];
                }
            }
            return lps;
        }
        vector <int> search(string pat, string txt)
        {
            int n = txt.size();
            int m = pat.size();
            vector <int> lps = fillLPS(pat);
            vector <int> ans;
            int j = 0,i=0;
            
            
          // return {};
            while(i<n){
                
                if(txt[i]==pat[j]){
                    i+=1;
                    j+=1;
                    if(j==m)
                    {
                        ans.push_back(i-m+1);
                        j = lps[j-1];
                    }
                }
                else if(i<n && txt[i]!=pat[j]){
                    if(j==0) i+=1;
                    else{
                        j = lps[j-1];
                    }
                }
            }
            return ans;
        }
     
};