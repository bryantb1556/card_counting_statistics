//Card counting simulator

#include<iostream>
#include<iomanip>
#include<vector>

using namespace std;

const double cardProb = (1.0 / 13.0);//Probability of a single card being selected

class RandomNumGenerator
{
public:

private:
};

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

private:

};


int main()
{
	Game game;

	return 0;
}