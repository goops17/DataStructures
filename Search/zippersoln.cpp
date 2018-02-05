#include <stdio.h>
#include <string.h>

	char a[201], b[201], c[402];
	int lengthA, lengthB, lengthC;
	int dynamicP[201][201];
	 
	int main()
	{
	    int nCase;
	    scanf("%d", &nCase);

	    for(int n=1; n <= nCase; n++) {

	        a[0]='p';
	        b[0]='p';
	        c[0]='p';

	        scanf("%s%s%s", a + 1, b + 1, c + 1); 

	        lengthA = strlen(a);
	        lengthB = strlen(b);
	        lengthC = strlen(c);
	        lengthA = lengthA - 1;
	        lengthB = lengthB - 1;

	        //base cases
	        for (int i=1; i <= lengthA; i++)
	            if (a[i] == c[i]) dynamicP[i][0] = 1;
	        for (int i=1; i <= lengthB; i++)
	            if (b[i] == c[i]) dynamicP[0][i] = 1;
	        //fill table 
	        for (int i = 1; i <= lengthA; i++)
	            for (int j = 1; j <= lengthB; j++)
	                dynamicP[i][j] = (dynamicP[i - 1][j] && (a[i] == c[i + j]))
	            	|| (dynamicP[i][j - 1] && (b[j] == c[i + j]));

	        printf("Data set %d: ",n);

	        if (dynamicP[lengthA][lengthB] == 1) 
	        	printf("yes\n");
	        else 
	        	printf("no\n");
	    }
	}
