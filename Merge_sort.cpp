#include "stdafx.h"

namespace SortingMethods
{
	void Simple_merge_sort()
	{
		int k = 1,n;
		n = Counting() - 1;
		N = n;
		while (N > k)
		{
			Distribution(k);
			Merge(k);
			k *= 2;
		}
	}

	int Counting()
	{
		ifstream A("Input.txt");
		int tmp, counter = 0;
		while (!A.eof())
		{
			A >> tmp;
			counter++;
		}
		A.close();
		return counter;
	}

	void Distribution(int &k)
	{
		ifstream A("Input.txt");
		ofstream B("B.txt"), C("C.txt");
		int temp;
        bool first = 0;
		while (!A.eof())
		{
			first = !first;
			for (int i = 0; i < k && !A.eof(); i++)
			{
				A >> temp;
				if (A.eof()) break;
				if (first)
				{
					B << temp << " ";
				}
				else
				{
					C << temp << " ";
				}
			}
		}
		A.close();
		B.close();
		C.close();
	}

	void Merge(int &k)
	{
		int b, c, ib = 0, ic = 0;
		ofstream A("Input.txt");
		ifstream B("B.txt"), C("C.txt");
		B >> b; C >> c;
		while (!B.eof() && !C.eof())
		{
			ib = 0; ic = 0;
			while (ib < k && ic < k && !B.eof() && !C.eof())
			{
				if (b < c)
				{
					A << b << " ";
					B >> b;
					ib++;
				}
				else
				{
					A << c << " ";
					C >> c;
					ic++;
				}
			}
			while (ib < k && !B.eof())
			{
				A << b << " ";
				B >> b;
				ib++;
			}
			while (ic < k && !C.eof())
			{
				A << c << " ";
				C >> c;
				ic++;
			}
		}
		while (!B.eof())
		{
			A << b << " ";
			B >> b;
		}
		while (!C.eof())
		{
			A << c << " ";
			C >> c;
		}
		A.close();
		B.close();
		C.close();
	}
}
