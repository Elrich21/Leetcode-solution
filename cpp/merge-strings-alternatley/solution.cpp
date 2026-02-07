class Solution {
public:
    string mergeAlternately(string word1, string word2) {
         int n = word1.length();
         int m = word2.length();

         int o = n + m;


         string s;
         int left = 0;
         int right = 0;
         //while (left < n || right < m){
         for(int i = 0; i<o; i++)
         {
            if (left < n) s += word1[left++];
            if (right < m) s += word2[right++];
            //right++;
         }
           
         
          return s;
}


   
};
