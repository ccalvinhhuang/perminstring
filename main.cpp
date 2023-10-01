#include <iostream>
#include <map>

using namespace std;

bool checkInclusion(string s1, string s2){
    map<char, int>m;
    for(int i = 0; i < s1.length(); i++){
        m[s1[i]]++;
    }
    int l = 0, h = 0, cur_count = s1.length();
    map<char, int>cur_m;
    while(h < s2.length()){
        if(m.count(s2[h]) == 0){
            //reset
            cur_m = {};
            cur_count = s1.length();
            l = h;
            l++, h++;
        }
        else{
            if(cur_m[s2[h]] < m[s2[h]]){
                cur_m[s2[h]]++;
                cur_count--;
                h++;
            }
            else{
                while(true){
                    if(s2[l] != s2[h]){
                        cur_m[s2[l]]--;
                        cur_count ++;
                        l++;
                    }
                    else{
                        cur_m[s2[l]]--;
                        cur_count ++;
                        l++;
                        break;
                    }
                }
            }
            if(cur_count == 0) return true;
        }
    }
    return false;
}

int main(){
    cout << checkInclusion("abc", "abcd");
}

