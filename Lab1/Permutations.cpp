#include<iostream>
#include<cstdio>
#include<chrono>

using namespace std::chrono;

int count;

void Permutations(std::string s,int l,int r) {
    if(l == r) {std::cout << "Permutation: " << s << std::endl;count++;return;}
    for(int i = l;i <= r;i++) {
        std::swap(s[l],s[i]);count++;
        Permutations(s,l+1,r);count++;
        std::swap(s[l],s[i]);count++;
    }
}

void Permutations(std::string s){
    Permutations(s,0,s.length()-1);
}

int main() {
    freopen("myfile.txt","w",stdout);
    std::string s = "abc";
    auto start = high_resolution_clock::now();
    Permutations(s);
    auto stop = high_resolution_clock::now();
    std::cout << "Step Count: " << count << "\nSize of String: " << s.length() << std::endl;
    auto duration = duration_cast<nanoseconds>(stop - start);
    std::cout << "Time taken: " << duration.count() << "ns" << std::endl;
    fclose(stdout);
}