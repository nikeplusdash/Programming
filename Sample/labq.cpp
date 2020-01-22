#include "./Lab2/LinkedList.cpp"
#include<cstdio>


int main() {
    std::string s;int n;
    std::cin >> n;
    for(int k=0;k<n;k++) {
        std::cin >> s;
        LinkedLists<char> ll;
        LinkedLists<int> numlist;
        int j=1;
        for(int i=0;i<s.length();i++) {
            ll.Insert(s[i]);
        }
        for(int i=0;i<s.length()-1;i++,j++) {
            if((s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U') && (s[i+1] == 'a' || s[i+1] == 'e' || s[i+1] == 'i' || s[i+1] == 'o' || s[i+1] == 'u' || s[i+1] == 'A' || s[i+1] == 'E' || s[i+1] == 'I' || s[i+1] == 'O' || s[i+1] == 'U')) {if(!numlist.Search(j)) numlist.Insert(j);numlist.Insert(j+1);}
        }
        ll.Display();
        numlist.Display();
    }
}