#include"Check.h"

bool CCheck::checkValue6Number(string t_rgValue)
{
	int iSize;
	for (int i = 0; t_rgValue[i] != '\0'; i++)
	{
		if (t_rgValue[i] < '0' || t_rgValue[i] > '9')
			return 0;
		if (i > 5)
			return 0;
		iSize = i+1;
	}
	if (iSize != 6)
	{
		return 0;
	}
	return 1;
}

bool CCheck::checkYearBook(int t_nValue)
{
	if (t_nValue <= 1900)
		return 0;
	return 1;
}

bool CCheck::checkFormat(string t_rgValue)
{
	int iSize = 0;
	for (int i = 0; t_rgValue[i] != '\0'; i++)
	{
		if (t_rgValue[i] < '0' || t_rgValue[i] > '9')
		{
			if (i != 2 && i != 5)
				return 0;
		}	
		++iSize;
	}
	if (iSize != 10)
		return 0;
	if (t_rgValue[2] != '/' && t_rgValue[5] != '/')
		return 0;
	return 1;
}

bool CCheck::checkNaturalNumber(int t_nValue)
{
	if (t_nValue < 0)
		return 0;
	return 1;
}
