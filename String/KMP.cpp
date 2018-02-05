//KMP Algorithm in CPP, just function part
int MySearch(char arrS[],char arrW[])
{
	int m, i = 0;

	while ((m + i) < sizeof(arrS))
	{
		if (W[i] == S[m + i])
		{
			if (i == (sizeof(arrW)-1))
			{
				return m;
			}
			++i
		}
		else
		{
			if (arrT[i] > -1)
			{
				m = (m + i) - arrT[i];
				i = arrT[i];
			}
			else
			{
				i = 0;
				m = ++m;
			}
		}
	}
}
