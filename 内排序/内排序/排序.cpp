typedef int KeyType;
typedef int InfoType;
typedef struct {
	KeyType key;
	InfoType info;
}RecType;
//≤Â»Î≈≈–Ú
//1.÷±Ω”≤Â»Î≈≈–Ú
void InsertSort(RecType R[],int  n)
{
	int i, j;
	RecType temp;
	for(i=1;i<n;i++){
		if (R[i].key < R[i - 1].key)
		{
			temp = R[i];
			j = i - 1;
			do {
				R[j + 1] = R[j];
				j--;
			} while (j >= 0 && R[j].key > temp.key);
			R[j + 1] = temp;
	     }
	}
}
//2.’€∞Î≤Â»Î≈≈–Ú
void BinInsertSort(RecType R[], int n)
{
	int i, j, low,high, mid;
	RecType temp;
	for (i = 1; i < n; i++) {
		if (R[i].key < R[i-1].key)
		{
			temp = R[i];
			low = 0;
			high = i - 1;
			while (low <= high) {
				mid = (low + high) / 2;
				if (temp.key < R[mid].key)
				{
					high = mid - 1;
				}
				else
					low = mid + 1;
			}
			for (j = i - 1; j >= high + 1; j--) {
				R[j + 1] = R[j];
			}
			R[high + 1] = temp;

		}
	}
}
//3.œ£∂˚≈≈–Ú
void ShellSort(RecType R[], int n)
{
	int i, j, d;
	RecType temp;
	d = n / 2;
	while (d > 0)
	{
		for (i = d; i < n; i++)
		{
			temp = R[i];
			j = i - d;
			while (j >= 0 && temp.key < R[j].key)
			{
				R[j + d] = R[j];
				j = j - d;
			}
		}
		d = d / 2;
	}
}