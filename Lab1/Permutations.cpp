#include<iostream>

void Permutations(std::string s,int l,int r) {
    if(l == r) {std::cout << "Permutation: " << s << std::endl;return;}
    for(int i = l;i <= r;i++) {
        std::swap(s[l],s[i]);
        Permutations(s,l+1,r);
        std::swap(s[l],s[i]);
    }
}

void Permutations(std::string s){
    Permutations(s,0,s.length()-1);
}

int main() {
    freopen("myfile.txt","w",stdout);
    std::string s = "abc";
    Permutations(s);
    fclose(stdout);
}