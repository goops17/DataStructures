#include <iostream>

typedef unsigned char uchar;
typedef unsigned int uint;

int d = 256; // Grootte van het alfabet: ASCI
int Q = 997; // Ons priem getal

int hash(const uchar* str, uint m) {
    int h = 0;
    for (uint j = 0; j < m; j++)
        h = (d * h + str[j]) % Q;
	
    return h;
}

bool check_same(const uchar* str, uint pos, const uchar* pattern, uint m) {
   
    for (uint i = 0; i < m; i++)
        if (str[pos + i] != pattern[i])
            return false;
	
    return true;
}

void search(const uchar* text, uint n, const uchar* pattern, uint m) {
    int pattern_hash = hash(pattern, m);
    int text_hash = hash(text, m); // we berekenen een hash voor lengte m !!! (dus niet de hele haystack!)
    int dm = 1;
    for (uint i = 0; i < m - 1; i++)
        dm = (dm * d) % Q;
    for (uint i = 0; i <= n-m; i++) {
        if (text_hash == pattern_hash){
			int j=0;
			while(text[i+j] == pattern[j]){
				j++;
			}
			if(j==m){
				std::cout<<i<<std::endl;
			}
        }
        text_hash = (((text_hash + Q*(d-1) - text[i]*(dm % Q)) % Q)*d + text[i+m])%Q;
    }
}

int main() {
    const uchar text[] = "abeta beta charly alfa";
    const uchar pattern[] = "beta";
	
    search(text, 23, pattern, 4);
    
	
    return 0;
}
