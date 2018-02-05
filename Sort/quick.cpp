#include<iostream>
using namespace std;

int partition(int a[],int p,int r)
{
    int x,i;
    x=a[r];
    i=p-1;
    for(int j=p;j<r;j++)
    {
        if(a[j]<=x)
        {
            i=i+1;
            swap(a[j],a[i]);
        }

    }
    swap(a[i+1],a[r]);

    return i+1;
}


void quicksort(int a[],int p,int r)
{
    if(p<r)
       {
            int q=partition(a,p,r);
            quicksort(a,p,q-1);
            quicksort(a,q+1,r);
       }

}


int main()
{
    int n,i,j,p,r;


    cout<<"how many element u want to enter:";
    cin>>n;
    int a[n];

    for(i=0;i<n;i++)
      {
         cin>>j;

        a[i]=j;
      }

      cout<<"input:"<<endl;

    for(i=0;i<n;i++)
      {


        cout<<a[i]<<endl;
      }
      p=0;
      r=sizeof(a) / sizeof(int);
    quicksort(a,p,r);

    cout<<"sorted:"<<endl;

    for(i=0;i<n;i++)
      {


        cout<<a[i]<<endl;
      }
    return 0;

}
