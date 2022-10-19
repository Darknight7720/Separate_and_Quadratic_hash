#include "Speciallib.h"

using namespace std;

class Hash{
	int BUCKET;
	list < int >	*table;
	public:
		Hash (int V);
		void	insertItem(int x);
		void	deleteItem(int key);
		int		hashFunction(int x)
		{
			// printf("Test = %d\n", x);
			return (x % BUCKET);
		}
		void	displayHash();
};

Hash::Hash(int b)
{
	// printf("Test  = %d\n", b);
	this->BUCKET = b;
	table = new list < int > [BUCKET];
}

void	Hash::insertItem(int key)
{
	int	index = hashFunction(key);
	// printf("ID = %d\nKEY = %d\n", index, key);
	// can't put 1 bc push_back problem
	table[index].push_back(key);
}

void	Hash::deleteItem(int key)
{
	int	index = hashFunction(key);
	list < int >::iterator i;
	for(i = table[index].begin(); i != table[index].end (); i++)
	{
		if (*i == key)
			break;
	}
	if(i != table[index].end())
	table[index].erase(i);
}

void	Hash::displayHash()
{
	for (int i = 0; i < BUCKET ; i++)
	{
		printf("%d", i);
		for (int x:table[i])
		{
			// printf("%d\n", x);
			cout << " --> " << x;
		}
		cout << endl;
	}
}

int	main(int argc, char *argv[])
{
	int	i = 0;
	int	j = 1;
	int	k = 0;
	if (argc == 1)
	{
		system("cls || clear");
		printf("No value plase try again.\n");
		printf("=========================================\n");
		printf("||             Created by               ||\n");
		printf("||   1. Chayanon Sutrak 6430250024      ||\n");
		printf("||  2. Nathadith Luangon 6430250032     ||\n");
		printf("|| 3. Bhurinatha Kamolhansa 6430250270  ||\n");
		printf("|| 4. Songpon    Bumrungkool 6430250075 ||\n");
		printf("=========================================\n");
		return (0);
	}
	int	*a = (int *)malloc(sizeof(int) * argc - 1);
	if (!a)
		return (0);
	a[argc - 1] = 0;
	while (argv[j])
	{
		a[i] = atoi(argv[j]);
		i++;
		j++;
	}
	Hash h (BUFFER_SIZE);
	while (k < argc - 1)
	{
		h.insertItem(a[k]);
		h.deleteItem(1);
		k++;
	}
	h.displayHash();
	free(a);
	return (0);
}