#ifndef _SYMBOL_FREQ_ 
#define _SYMBOL_FREQ_
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class SymbolFreq
{
public:
	SymbolFreq();
	~SymbolFreq();
	void LoadFromFile(string fileName);
	void CountLetters();
	void InitialiseCharacterStorage();

	
private:

	//int a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z, space, comma, fullstop, apostophe, hyphen;
	
protected:
	vector<char> characterList;
	vector<char> SymbolType;
	vector<int> SymbolCount;

};
#endif

SymbolFreq::SymbolFreq()
{
	//SymbolType[0] = ( 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', ' ', ',' , '.', '\'', '-' );
	//SymbolCount = { a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z, space, comma, fullstop, apostophe, hyphen };
	
	InitialiseCharacterStorage();
	LoadFromFile("richardiii");
	CountLetters();

}

SymbolFreq::~SymbolFreq()
{

}

void SymbolFreq::LoadFromFile(string fileName)
{
	string fileContents;
	ifstream infile;
	infile.open(fileName + ".txt");//Opens richardiii.txt
	getline(infile,fileContents);//Sets contents of richardiii equal to string fileContents
	cout << "Total Characters : " << fileContents.size();

	for (int i = 0; i < fileContents.size(); i++)
	{
		characterList.push_back(fileContents[i]);//puts fileContents into characterList Vector
	}

	for (vector<char>::iterator it = characterList.begin(); it != characterList.end(); it++)
	{
		
	}
		/*for (vector<char>::iterator itTwo = SymbolType.begin(); itTwo != SymbolType.end(); itTwo++)
		{
			cout << "OOO";
			if (characterList[*it] == SymbolType[*itTwo])
			{
				SymbolType.push_back(characterList[*it]);
				SymbolCount.push_back(1);
			}
		}
	}*/
}

void SymbolFreq::InitialiseCharacterStorage()
{
	//Initialises all of the character counts to Null
	for (vector<int>::iterator it = SymbolCount.begin(); it != SymbolCount.end(); it++)
	{
		(*it) = 0;
	}
}
void SymbolFreq::CountLetters()
{
	for (vector<char>::iterator it = characterList.begin(); it != characterList.end(); it++)
	{
		for (size_t i = 0; i < SymbolType.size(); i++)
		{
			if ((*it) == SymbolType[i])
			{
				SymbolCount[i]++;
			}
		}
	}

	cout << endl;
	
	for (size_t i = 0; i < SymbolType.size(); i++)
	{
		cout << SymbolType[i] << " : " << SymbolCount[i] << endl;
	}
	int count = 0;
	for (int i = 0; i < SymbolType.size(); i++)
	{
		count += SymbolCount[i];
	}
	SymbolCount.clear();
	SymbolType.clear();
}