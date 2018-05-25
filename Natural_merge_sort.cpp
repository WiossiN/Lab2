#include "stdafx.h"

namespace SortingMethods
{
	int DIVIDINGS = 0;

	void Natural_merge_sort()
	{
		int series = 0;
		while (series != 2)
		{
			series = 0;
			Natural_Distribution();
			DIVIDINGS++;
			Natural_Merge(series);
		}
	}

	void Natural_Distribution()
	{
		int s1, s2, b, c, mark;
		ifstream A("Input.txt");
		ofstream B("B.txt"), C("C.txt");
		s1 = s2 = 1;
		while (s1 > 0 && s2 > 0)
		{
			mark = 1;
			s1 = 0;
			s2 = 0;
			A >> b;
			if (!A.eof()) B << b << " ";
			if (!A.eof()) A >> c;
			while (!A.eof())
			{
				if (c < b)
				{
					switch (mark)
					{
					case 1: {B << "' "; mark = 2; s1++; break; }
					case 2: {C << "' "; mark = 1; s2++; break; }
					}
				}
				if (mark == 1)
				{
					B << c << " ";
					s1++;
				}
				else {
					C << c << " ";
					s2++;
				}
				b = c;
				A >> c;
			}
			if (s2 > 0 && mark == 2)  C << "'";
			if (s1 > 0 && mark == 1)  B << "'";
		}
		A.close();
		B.close();
		C.close();
	}

	void Natural_Merge(int &series)
	{
		int b, c;
		ofstream A("Input.txt");
		ifstream B("B.txt"), C("C.txt");
		if (!B.eof()) B >> b;
		if (!C.eof()) C >> c;
		bool file1, file2;
		while (!B.eof() && !C.eof())
		{
			file1 = file2 = false;
			while (!file1 && !file2)
			{
				if (b <= c)
				{
					A << b << " ";
					file1 = End_Series(B, series);
					B >> b;
				}
				else
				{
					A << c << " ";
					file2 = End_Series(C, series);
					C >> c;
				}
			}
			while (!file1)
			{
				A << b << " ";
				file1 = End_Series(B, series);
				B >> b;
			}
			while (!file2)
			{
				A << c << " ";
				file2 = End_Series(C, series);
				C >> c;
			}
		}
		file1 = file2 = false;
		while (!file1 && !B.eof())
		{
			A << b << " ";
			file1 = End_Series(B, series);
			B >> b;
		}
		while (!file2 && !C.eof())
		{
			A << c << " ";
			file2 = End_Series(C, series);
			C >> c;  
		}
		A.close();
		B.close();
		C.close();
	}

	bool End_Series(ifstream &f, int &series)
	{
		char tmp;
		tmp = f.get();
		tmp = f.get();
		if (tmp != '\'') f.seekg(-1, SEEK_CUR);
		else f.seekg(1, SEEK_CUR);
		if (tmp == '\'')
		{
			series++;
			return true;
		}
		else return false;
	}
}