/*Card counting simulator
Blackjack pays 3 to 2, insurance pays 2 to 1
Dealer stands on hard 17+, dealer must hit on soft 17
Hi-Lo card counting method
*/
#include<iostream>
#include<iomanip>
#include<vector>
#include<time.h>
#include<cstdlib>

using namespace std;

const double cardProb = (1.0 / 13.0);//Probability of a single card being selected
const int decksInShoe = 8;//Number of decks
const int cardsInDeck = 52;//Number of cards
const int maxTens = 16 * decksInShoe;//10/J/Q/K; 4 suites, max number of "10 cards"
const int maxAces = 4 * decksInShoe;//4 aces per deck,

enum Decision 
{
	HIT = 1,
	STAND = 2,
	SPLIT = 3,
	DOUBLE = 4
};

class Deck
{
public:
	Deck() { cardsAvailable.clear(); }//Constructor
	~Deck() {};//Destructor

	void initalizeCards()
	{
		int num = 0;
		for (int i = 0; i < (decksInShoe * cardsInDeck); i++)
		{
			cardsAvailable.push_back((num) % 13 + 1);
			num++;
		}
	}

	int getCard(int index)
	{
		int card = cardsAvailable[index];
		cardsAvailable.erase(cardsAvailable.begin() + index);
		return card;
	}

	void reshuffle()
	{
		cardsAvailable.clear();
		initalizeCards();
	}

private:
	vector<int> cardsAvailable;
};

class Dealer//Encompasses all information regarding dealer cards
{
public:
	Dealer() { cards.clear(); deck.initalizeCards(); srand(time(NULL)); }//Constructor to initalize cards
	~Dealer(){}//Destructor

	void startDeck()
	{
		deck.initalizeCards();
	}

	int pullCard()
	{
		int index = rand() % numCards;//Accesses vector location between 0 - numCards
		int pulledCard = deck.getCard(index);
		numCards--; 
		return pulledCard;
	}

	void addCard(int card)
	{
		cards.push_back(card);
	}

	void clearCards()
	{
		cards.clear();
	}

	void houseStrategy(int houseTotal, int playerTotal)
	{
	
	}

private:
	vector<int> cards;
	Deck deck;
	int numCards = (decksInShoe * 52);
};

class Counter//Encompasses all data about player and active count 
{
public:
	//Constructor initalizes count and vector holding cards
	Counter() : count(0), split(false), numSplits(0), money(0)
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

	bool checkEleven(int total)//ALWAYS double on 11 
	{
		if (total == 11)
		{
			return true;
		}
		return false;
	}

	int playerStrategy(int faceUp)//Main functionality function, encompasses basic strategy
	{
		int cardTotal = 0;
		bool softTotal = false;
		enum Decision choice = STAND; 
		if (cards[0] == 11 || cards[0] == 12 || cards[0] == 13) cards[0] = 10;//Face cards set to value of 10
		if (cards[1] == 11 || cards[1] == 12 || cards[1] == 13) cards[1] = 10;//Face cards-set to value of 10
		if (cards[0] == 1 || cards[1] == 1) softTotal = true;
		cardTotal = cards[0] + cards[1];
		switch (faceUp)//Player stratedgy based on dealer card
		{
		case 1://Dealer has ace
			if (checkEleven(cardTotal)) choice = DOUBLE;
			else if (cardTotal < 17) choice = HIT;
			else choice = STAND;
			break;

		case 2://Dealer has 2
			if (checkEleven(cardTotal)) choice = DOUBLE;
			else if (cardTotal == 10) choice = DOUBLE;
			else if (cardTotal < 13) choice = HIT;
			else choice = STAND;
			break;

		case 3://Dealer has 3
			if (checkEleven(cardTotal)) choice = DOUBLE;
			else if (cardTotal == 10) choice = DOUBLE;
			else if (cardTotal == 9) choice = DOUBLE;
			else if (cardTotal < 13) choice = HIT;
			else choice = STAND;
			break;

		case 4://Dealer has 4
			if (checkEleven(cardTotal)) choice = DOUBLE;
			else if (cardTotal == 10) choice = DOUBLE;
			else if (cardTotal == 9) choice = DOUBLE;
			else if (cardTotal <= 8) choice = HIT;
			else choice = STAND;
			break;

		case 5://Dealer has 5
			if (checkEleven(cardTotal)) choice = DOUBLE;
			else if (cardTotal == 10) choice = DOUBLE;
			else if (cardTotal == 9) choice = DOUBLE;
			else if (cardTotal <= 8) choice = HIT;
			else choice = STAND;
			break;

		case 6://Dealer has 6
			if (checkEleven(cardTotal)) choice = DOUBLE;
			else if (cardTotal == 10) choice = DOUBLE;
			else if (cardTotal == 9) choice = DOUBLE;
			else if (cardTotal <= 8) choice = HIT;
			else choice = STAND;
			break;

		case 7://Dealer has 7
			if (checkEleven(cardTotal)) choice = DOUBLE;
			else if (cardTotal == 10) choice = DOUBLE;
			else if (cardTotal < 17) choice = HIT;
			else choice = STAND;
			break;

		case 8://Dealer has 8
			if (checkEleven(cardTotal)) choice = DOUBLE;
			else if (cardTotal == 10) choice = DOUBLE;
			else if (cardTotal < 17) choice = HIT;
			else choice = STAND;
			break;

		case 9://Dealer has 9
			if (checkEleven(cardTotal)) choice = DOUBLE;
			else if (cardTotal == 10) choice = DOUBLE;
			else if (cardTotal < 17) choice = HIT;
			else choice = STAND;
			break;

		case 10://Dealer has 10 or any face card
			if (checkEleven(cardTotal)) choice = DOUBLE;
			else if (cardTotal < 17) choice = HIT;
			else choice = STAND;
			break;
		}
		return choice;
	}

private:
	int count;//Holds current count
	vector<int> cards;//Holds current cards
	bool split;
	int numSplits;
	int money; 
};

void Game()
{
	Dealer house;
	Counter player;
	int total = 0;
	int card = 0;
	int faceUp = 0;

	card = house.pullCard();//1st pCard
	player.addCard(card);
	total += card;
	faceUp = house.pullCard();//1st hCard(showed to player)
	house.addCard(faceUp);
	card = house.pullCard();//2nd pCard
	player.addCard(card);
	total += card;
	card = house.pullCard();//2nd hCard
	house.addCard(card);
	if (faceUp > 10) faceUp = 10;
	cout << faceUp << endl;
	cout << total << endl;
	cout << player.playerStrategy(faceUp) << endl;

}

int main()
{
	Game();

	return 0;
}