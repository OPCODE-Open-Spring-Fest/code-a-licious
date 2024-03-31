// your code here
// Code by Jagpreet153
#include<bits/stdc++.h>
using namespace std; 
  
string getSpaces(int n){
    string s = "";
    for(int i=0; i<n;i++) s += " ";
    return s; 
}
string getLine(vector<string>& words, int start, int end, int letterCount, int maxWidth){
    string res = words[start];
    int spaces = maxWidth - letterCount;
    
    if(start == end){ 
        res += getSpaces(spaces);
        return res;
    }
    
    int numOfSpace = spaces/(end-start);
    int extraOne = spaces%(end-start);
    string space0 = getSpaces(numOfSpace);
    string space1 = space0 + " "; 
    
    for(int i= 0; i< end-start; i++){
        res  = res + (i < extraOne? space1: space0) + words[start + 1 + i];
    }
    return res; 
}
vector<string> fullJustify(vector<string>& words, int maxWidth) {
    int N = words.size(); 
    int i = 0, j = 0;
    int counter = 0; 
    vector<string> res; 
    
    while(i<N && j<N){
        int len = words[j].length(); 
        counter += len;
        
        if(counter + j - i > maxWidth){
            counter -= len; 
            res.push_back(getLine(words, i, j-1, counter, maxWidth));
            i = j; 
            counter = 0; 
        }
        
        else{
            j++;
        }
    }
    
    if(counter){
        string last = words[i];
        
        for(int x=i+1; x < j; x++){ 
            last = last + " " + words[x];
        }
        
        last = last + getSpaces(maxWidth - last.size());
        res.push_back(last);
    }
    return res; 
}
int main(){
    string str,s1;
    getline(cin, str);
    int size,i;
    cin>>size;
    vector<string> s;
    for(i=0;i<str.length();i++)
    {
        if(str[i]!=' ')
        {
            s1.push_back(str[i]);
        }
        else{
            s.push_back(s1);
            s1.clear();
        }
    }
    s.push_back(s1);
    vector<string> lines = fullJustify(s, size); 
    
    for(auto x: lines)
        cout << x << endl;
    return 0; 
 }