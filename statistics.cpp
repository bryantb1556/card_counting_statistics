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

	void playerStrategy(int playerTotal, int houseTotal)
	{

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

}

int main()
{
	Dealer house;
	for (int i = 0; i < 100; i++)
	{
		int x = house.pullCard();
		cout << x << " ";
	} 

	return 0;
}