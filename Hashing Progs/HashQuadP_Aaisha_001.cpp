//quadratic probing
#include<iostream>
using namespace std;

int hashTab[5];

void table()
{
	for(int i=0;i<5;i++)
	{
		hashTab[i]=-1; //set all indexes as empty slots initially by -1 to avoid garbage value
	}
}

void insert()
{
	int value;
	cout<< "Enter the value:\t";
	cin>> value;
	int index= value%5;
	int startindex= index;

	if(hashTab[index]==-1)
	{
		hashTab[index]=value;
		return;
	}
	
	else
	{
		
		int i=1;
		while(hashTab[index]!=-1)
		{
			index=(startindex+i*i)%5; //move slots quadratically
		
			if(index==startindex) //if table is full
			{
				cout<< "HashTable is full! cannot insert value " << value << endl;
				return;
			}
			i++; 
		}
		hashTab[index]=value;
	}
}

void display()
{
	cout<< "The Hash Table is:\n";
	for(int i=0; i<5;i++)
	{
		if(hashTab[i]==-1)
		{
			cout<< "Index " << i << ": empty\n"; 
		}
		else{
			cout << "Index " << i << ": " << hashTab[i] << endl;
		}
	
	}
}

int main()
{
	table(); //call table to initialise hash table
	cout<< "Enter any 5 values!\n";
	for(int i=0 ;i<5 ;i++)
	{
		insert();
	}
	display();
	return 0;
	
} 

