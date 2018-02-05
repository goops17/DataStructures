#include <iostream>
#include <vector>
#include <algorithm>

typedef unsigned int uint;
typedef unsigned char uchar;

using namespace std;

class BoyerMoore {
public:
    BoyerMoore(const uchar* pattern, uint m);
    void search(const uchar* text, uint n);

    uint d; // ASCII
    uint m;
    const uchar* pattern;
    
    int heuristiek_1[256];
    vector<uint> suffix_tabel;
    vector<uint> verschuivings_tabel;
    
    int heuristiek_verkeerde_karakter(const uchar* text, uint k, uint i);
    int heuristiek_juiste_suffix(uint j);
    
    uint bereken_suffix(const uchar* str, uint length, uint j);
};

BoyerMoore::BoyerMoore(const uchar* pattern, uint m)
: d(256), pattern(pattern), m(m) {
    
    for (uint i = 0; i < d; i++)
        heuristiek_1[i] = -1;
    
    for (uint i = 0; i < m; i++)
        heuristiek_1[pattern[i]] = i;
   
    suffix_tabel.resize(m,0);
    for(int i = m-2; i >= 0; i--) {
        uint current = suffix_tabel[i+1];
        while(current>0 && pattern[m-1-current] != pattern[i])
            current = suffix_tabel[m-1-current];
        if(pattern[m-1-current] == pattern[i])
            current++;
        suffix_tabel[i] = current;
    }
    
    int i;
    verschuivings_tabel.resize(suffix_tabel.size(),m - suffix_tabel[0] - 1);
    for(int j = suffix_tabel.size()-1; j>=0; j--){
        i =  m - suffix_tabel[j] - 1;
        verschuivings_tabel[i] = verschuivings_tabel[i]<(i+1-j) ? verschuivings_tabel[i]: i+1-j;
    }
    
}

int BoyerMoore::heuristiek_verkeerde_karakter(const uchar* text, uint k, uint i) {
    int j = heuristiek_1[text[k]];
    int verschuiving = i - j;
    
    if (verschuiving < 1)
        verschuiving = 1;
    
    return verschuiving;
}

int BoyerMoore::heuristiek_juiste_suffix(uint j) {
    return verschuivings_tabel[j];
}

void BoyerMoore::search(const uchar* text, uint n) {
    
    std::vector<int> locaties;
    
    int i=0;
    while(i < n-m) {
        int j;
        for(j=m-1; j>=0 && pattern[j] == text[i+j]; j--);
        if(j<0){
            cout<<"Pattern found at index "<<i<<endl;
            i++;
        }else{
            int h1 = heuristiek_verkeerde_karakter(text, i+j, j);
            int h2= heuristiek_juiste_suffix(j);
            i+=max(h1,h2);
        }
        
    }
}

int main() {
    const uchar text[] = "alfa beta alfa charly";
    const uchar pattern[] = "alfa";
    
    uint n = 21;
    uint m = 4;
    
    BoyerMoore bm(pattern, m);
    
    bm.search(text, n);
    
    return 0;
}
