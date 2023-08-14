bool removeIJ(int i, int j, string s){
        while(i<j){
            if(s[i]==s[j]){
                i++;
                j--;
            }
            else{
                return false;
            }
        }
        return true;
}

bool validPalindrome(string s) {
      int i=0;
      int j=s.length()-1;
      while(i<j){
          if(s[i]==s[j]){
              i++;
              j--;
          }
          else{
              return removeIJ(i+1,j, s) || removeIJ(i,j-1, s);
          }
      }
      return true;
}
