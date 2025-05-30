//Card counting simulator

#include<iostream>
#include<iomanip>
#include<vector>
#include<time.h>
#include<cstdlib>

using namespace std;

const double cardProb = (1.0 / 13.0);//Probability of a single card being selected
const int decksInShoe = 8;
const int numCards = decksInShoe * 52;

class Dealer
{
public:
	Dealer() { cards.clear(); }//Constructor to initalize cards
	~Dealer(){}//Destructor
	void addCard(int card)
	{
		cards.push_back(card);
	}

	void clearCards()
	{
		cards.clear();
	}

private:
	vector<int> cards;
};

class Counter
{
public:
	//Constructor initalizes count and vector holding cards
	Counter() : count(0), split(false), numSplits(0)
	{
		cards.clear();
	}
	~Counter(){}//Destructor
	void changeCount(int change)
	{
		count += change;
	}

	void addCard(int card)
	{
		cards.push_back(card);
	}

	void clearCards()
	{
		cards.clear();
	}

private:
	int count;//Holds current count
	vector<int> cards;//Holds current cards
	bool split;
	int numSplits;
};

class Game
{
public:
	int pullCard()
	{
		srand(time(NULL));//Initalizes seed
		int card = rand() % 13 + 1;//Generates random number between 1-13
		return card;
	}
private:

};

int main()
{
	Game game;

	return 0;
}