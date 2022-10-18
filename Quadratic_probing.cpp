#include "Speciallib.h"
using namespace std;

bool    isPrime(size_t n)
{
    if (n == 2 || n == 3 )
        return (1);
    if (n == 1 || n % 2 == 0)
        return (0);
    for(int i = 3; i * i <= n; i += 2)
    {
        if (n % i == 0)
            return (0);
    }
    return (1);
}

size_t nextPrime(size_t n)
{
    if(n <= 0)
        n == 3;
    if(n % 2 == 0)
        n++;
    for(; !isPrime(n); n += 2);
    return (n);
}

int HashFunc(int k, int s)
{
    return (k % s);
}

HTable   *initiateTable(int s)
{
    HTable   *ht;
    if(s < T_S)
    {
        cout << "Table's size is too small." << endl;
        return (NULL);
    }
    ht = new HTable;
    if (ht == NULL)
    {
        cout << "Out of space." << endl;
        return (NULL);
    }
    ht->s = nextPrime(s);
    ht->t = new Hashentry [ht->s];
    if(ht->t == NULL)
    {
        printf("Table's size is too small.\n");
        return (NULL);
    }
    for(int i = 0; i < ht->s ; i++)
    {
        ht->t[i].info = Emp;
        ht->t[i].e = 0;
    }
    return (ht);
}

int SearchKey(int k, HTable *ht)
{
    int pos = HashFunc(k, ht->s);
    int collisions = 0;
    while(ht->t[pos].info != Emp && ht->t[pos].e != k)
    {
        pos = pos + 2 * ++collisions - 1;
        if (pos >= ht->s)
            pos = pos - ht->s;
    }
    return (pos);
}

void	Insert(int k, HTable *ht)
{
	int	pos = SearchKey(k, ht);
	if (ht->t[pos].info != Legi)
	{
		ht->t[pos].info = Legi;
		ht->t[pos].e = k;
	}
}

HTable	*Rehash(HTable *ht)
{
	int	s = ht->s;
	Hashentry	*t = ht->t;
	ht = initiateTable(2 * s);
	for(int i = 0; i < s ; i++)
	{
		if (t[i].info == Legi)
			Insert(t[i].e, ht);
	}
	free(t);
	return (ht);
}

void	Display(HTable *ht)
{
	int i = 0;
	while(i < ht->s)
	{
		int	value = ht->t[i].e;
		if(!value)
			printf("Position : %d Element : NULL\n", i + 1);
		else
			printf("Position %d Element: %d\n", i + 1, value);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	system("cls");
	int	select,pos, count = 0;
	char	*inp;
	HTable *ht;
	int		v, i = 1;
	size_t	s;
	while (true)
	{
		printf("======================================\n");
		printf("||       Please select option       ||\n");
		printf("||    1. Initialize size of table   ||\n");
		printf("|| 2. Insert element into the table ||\n");
		printf("||      3. Display hash table       ||\n");
		printf("||       4. Rehash the table        ||\n");
		printf("||           5. Exit                ||\n");
		printf("======================================\n");
		printf("Enter your choice : ");
		inp = (char *)malloc(sizeof(char) * 10);
		cin >> inp;
		select = atoi(inp);
		free(inp);
		// printf("%d\n", select);
		switch(select){
			case 1:
				printf("Enter size of the Hash table : ");
				cin >> s;
				if (s > INT_MAX)
				{
					system("cls");
					printf("Too big size. Try again.\n");
					continue;
				}
				if (nextPrime(s) >= T_S)
				{
					ht = initiateTable(s);
					count += 1;
					printf("Size of Hash Table : %zu\n", nextPrime(s));
				}
				if (nextPrime(s) < T_S)
				{
					system("cls");
					printf("Size of Hash Table : %zu\n", nextPrime(s));
					printf("Initialize fail you must initialize at least %d\n", T_S);
					count = 0;
					continue;
				}
			break;
			case 2:
				if (count == 0)
				{
					system("cls");
					printf("You must initialize your table first\n");
					continue;
				}
				if (i > ht->s)
				{
					printf("Table is Full, Rehash the table\n");
					continue;
				}
				printf("Enter element to be insert : ");
				cin >> v;
				Insert(v, ht);
				i++;
			break;
			case 3:
				if (count == 0)
				{
					system("cls");
					printf("You must initialize your table first\n");
					continue;
				}
				Display(ht);
			break;
			case 4:
				if (count == 0)
				{
					system("cls");
					printf("You must initialize your table first\n");
					continue;
				}
				ht = Rehash(ht);
			break;
			case 5:
				system("cls");
				printf("=========================================\n");
				printf("||             Created by              ||\n");
				printf("||   1. Chayanon Sutrak 6430250024     ||\n");
				printf("||  2. Nathadith Luangon 6430250032    ||\n");
				printf("|| 3. Bhurinatha Kamolhansa 6430250270 ||\n");
				printf("=========================================\n");
				return (0);
			default:
				system("cls");
				printf("Your choice is invalid.\n");
		}
	}
	return (0);
}