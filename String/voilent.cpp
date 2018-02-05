#include<cstring>
int voilent(char* s,char* p)
{
    int slen=strlen(s);
    int plen=strlen(p);
    int i=0,j=0;
    while(i<slen&&j<plen){
        if(s[i]==p[i]){
            i++;
            j++;
        }
        else{
            i=i-j+1;
            j=0;
        }
    }
    if(j==plen)return i-j;
    else return -1;
}
