#include "stdafx.h"

namespace SortingMethods
{
    const int WAYS = 4;

    void Balanced_Multiway_Merge()
	{
		int k = 1;
		Generation_files(WAYS);
		while (N > k)
		{
			Multiway_Distribution(WAYS, k);
			Multiway_Merge(k);
			k *= WAYS;
		}
		Remove_files(WAYS);
	}

	void Generation_files(int n)
	{
        char **a = new char*[n];
		for (int i = 0; i < n; i++)
		{
            a[i] = new char[10];
			sprintf(a[i], "%s%d%s", "tmp", i, ".txt");
            ofstream N(a[i]);
			N.close();
		}
		for (int i = 0; i < n; i++)
		{
			delete[] a[i];
		}
		delete[] a;
	}

    void Multiway_Distribution(int n, int k)
	{
		ifstream A("Input.txt");
		ofstream B[WAYS];
        char **a = new char*[n];
		for (int i = 0; i < n; i++)
		{
			a[i] = new char[10];
			sprintf(a[i], "%s%d%s", "tmp", i, ".txt");
			B[i].open(a[i]);
		}
        int flag = 0;
		int tmp;
		while (!A.eof())
		{
			for (int i = 0; i < k && !A.eof(); i++)
			{
				A >> tmp;
				if (A.eof()) break;
				switch (flag)
				{
				case 0:
					B[0] << tmp << " ";
					break;
				case 1:
					B[1] << tmp << " ";
					break;
				case 2:
					B[2] << tmp << " ";
					break;
				case 3:
					B[3] << tmp << " ";
					break;
				default:
					flag = -1;
					break;
				}
			}
			flag++;
			if (flag == 4) flag = 0;
		}
		A.close();
		for (int i = 0; i < n; i++)
			B[i].close();
		for (int i = 0; i < n; i++)
			delete[] a[i];
		delete[] a;
	}

	void Remove_files(int n) 
	{
        char **a = new char*[n];
		for (int i = 0; i < n; i++)
		{
            a[i] = new char[10];
			sprintf(a[i], "%s%d%s", "tmp", i, ".txt");
			remove(a[i]);
		}

		for (int i = 0; i < n; i++)
			delete[] a[i];
		delete[] a;
	}

	void Multiway_Merge(int k)
	{
		ofstream A("Input.txt");
		ifstream B[WAYS];
        char **a = new char*[WAYS];
		for (int i = 0; i < WAYS; i++)
		{
			a[i] = new char[10];
			sprintf(a[i], "%s%d%s", "tmp", i, ".txt");
			B[i].open(a[i]);
		}
		int position = 0,
			min = INT_MAX - 1;
		int b[WAYS],
            ib[WAYS];
		bool marker,
			used[WAYS] = { false },
			limit[WAYS] = { false };
		while (!B[0].eof() || !B[1].eof() || !B[2].eof() || !B[3].eof())
		{
			for (int i = 0; i < WAYS; i++)
			{
				ib[i] = 0;
				B[i] >> b[i];
				limit[i] = false;
				if (B[i].eof()) used[i] = true;
			}
			marker = true;
			while (marker && (!B[0].eof() || !B[1].eof() || !B[2].eof() || !B[3].eof()))
			{
				for (int i = 0; i < WAYS; i++)
				{
					if (b[i] < min)
					{
						if (B[i].eof()) continue;
						if (limit[i]) continue;
						position = i;
						min = b[i];
					}
				}
				if (limit[position] || used[position]) break;
				ib[position]++;
				if (ib[position] == k) limit[position] = true;
				if (ib[position] == k) b[position] = INT_MAX;
				else
				{
					B[position] >> b[position];
					if (B[position].eof()) used[position] = true;
				}
				A << min << " ";
				min = INT_MAX - 1;
				marker = Check_one_element_less(ib, k);
			}
		}
		A.close();
		for (int i = 0; i < WAYS; i++)
			B[i].close();
		for (int i = 0; i < WAYS; i++)
			delete[] a[i];
		delete[] a;
	}

    bool Check_one_element_less(int *M, int k)
	{
		int counter = 0;
		for (int i = 0; i < WAYS; i++)
			counter = counter + M[i];
		if (counter == k * WAYS) return false;
			else return true;
	}
}
