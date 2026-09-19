#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
//只比較牌型，如果牌型相同則為平手

//遊玩人數, 手牌, 公牌
#define PLAYERS 5
#define HandCard 2
//撲克牌數量, 花色, 每個花色張數
#define MaxCards 52
#define MaxSuit 4
#define MaxRank 13

int handType[5];
//牌面
const char cardRanks[] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
const char suit[] = {'D', 'C', 'H', 'S'};
//poker資訊
typedef struct 
{
    int rank;
    int suit;
} Card;
//玩家資訊
typedef struct
{
    int playerIndex;
    int handRank;
    char *handType;
} PlayerResult;

int top = -1;
void push(int data)
{
    if (top >= 5)
    {
        printf("STACK is full");
    }
    else
    {
        top++;
        handType[top] = data;

    }
}
void findMax(int arr[], int size)
{
    int max = arr[0];
    int maxIndex = 0;
    int count = 1;
    for (int i = 1; i < size; i++) 
        {
        if (arr[i] > max) 
        {
            max = arr[i];
            maxIndex = i;
            count = 1;
        } 
        else if (arr[i] == max) 
        {
            count++;
        }
    }

    // printf("Max value: %d\n", max);
    // printf("Max cardtype player: %d\n", maxIndex+1);
    // printf("Replicate times: %d\n", count);
    if (max == 1)
    {
        printf("Max Card type: High card\n");
        if (count == 1)
        {
            printf("Player %d win the game\n", maxIndex+1);
        }
        else if (count > 1)
        {
            printf("This game is tie\n");
        }
    }
    else if (max == 2)
    {
        printf("Max Card type: One pair\n");
        if (count == 1)
        {
            printf("Player %d win the game\n", maxIndex+1);
        }
        else if (count > 1)
        {
            printf("This game is tie\n");
        }
    }
    else if (max == 3)
    {
        printf("Max Card type: Two pair\n");
        if (count == 1)
        {
            printf("Player %d win the game\n", maxIndex+1);
        }
        else if (count > 1)
        {
            printf("This game is tie\n");
        }
    }
    else if (max == 4)
    {
        printf("Max Card type: Three of kind\n");
        if (count == 1)
        {
            printf("Player %d win the game\n", maxIndex+1);
        }
        else if (count > 1)
        {
            printf("This game is tie\n");
        }
    }
    else if (max == 5)
    {
        printf("Max Card type: Straight\n");
        if (count == 1)
        {
            printf("Player %d win the game\n", maxIndex+1);
        }
        else if (count > 1)
        {
            printf("This game is tie\n");
        }
    }
    else if (max == 6)
    {
        printf("Max Card type: Flush\n");
        if (count == 1)
        {
            printf("Player %d win the game\n", maxIndex+1);
        }
        else if (count > 1)
        {
            printf("This game is tie\n");
        }
    }
   else if (max == 7)
    {
        printf("Max Card type: Full house\n");
        if (count == 1)
        {
            printf("Player %d win the game\n", maxIndex+1);
        }
        else if (count > 1)
        {
            printf("This game is tie\n");
        }
    }
    else if (max == 8)
    {
        printf("Max Card type: Four four of kind\n");
        if (count == 1)
        {
            printf("Player %d win the game\n", maxIndex+1);
        }
        else if (count > 1)
        {
            printf("This game is tie\n");
        }
    }
    else if (max == 9)
    {
        printf("Max Card type: Straight Flush\n");
        if (count == 1)
        {
            printf("Player %d win the game\n", maxIndex+1);
        }
        else if (count > 1)
        {
            printf("This game is tie\n");
        }
    }
    
}

//準備撲克牌四組1-13
void iniDeck(Card deck[])
{
    int i, j, card = 0;
    for (i = 0; i < MaxSuit; i++)
    {
        for (j = 0; j < MaxRank; j++)
        {
            deck[card].rank = j;
            deck[card].suit = i;
            card ++;
        }
    }
}
//洗牌
void shuffle(Card deck[])
{
    int i, j;
    Card temp; 
    for (i = 0; i < MaxCards; i++)
    {
        j = rand() % MaxCards;
        temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}
//發牌
void deal(Card deck[], Card player[][2])
{
    int i, j, card = 0;
    for (i = 0; i < PLAYERS; i++)
    {
        for (j = 0; j < 2; j++)
        {
            player[i][j] = deck[card];
            card ++;
        }
    }
}
//發公牌
void dealBoard(Card deck[], Card boardCards[])
{
    int i, card = PLAYERS * 2;
    for (i = 0; i < 5; i++)
    {
        boardCards[i] = deck[card];
        card++;
    }
}
//print card 並給suit
void printCard(Card card)
{
    char *ranks[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
    char *suits[] = {"S", "H", "D", "C"}; //"Spades", "Hearts", "Diamonds", "Clubs"
    printf("%s %s\t", ranks[card.rank], suits[card.suit]);
}
// print player cards
void printPlayerCards(Card player[][2])
{
    int i, j;
    for (i = 0; i < PLAYERS; i++)
    {
        printf("Player %d's cards:\n", i+1);
        for (j = 0; j < 2; j++)
        {
            printCard(player[i][j]);
        }
        printf("\n");
    }
}
//Print board cards
void printBoardCards(Card BoardCards[])
{
    int i;
    printf("Board cards is:\n");
    for (i = 0; i < 5; i++)
    {
        printCard(BoardCards[i]);
    }
    printf("\n");
}
//compare cards
int compareCards(const void *cardA, const void *cardB)
{
    Card *a = (Card *)cardA; 
    Card *b = (Card *)cardB;
    return (b->rank - a->rank);
}
//牌型
//Straight flush > four of kind > Full house > Flush >
//Straight > Three of kind > Two pair > One pair > High Card
//判斷牌型
int hasFlush(Card hand[])
{
    int suits[4] = {0};
    int i;
    for (i = 0; i < 7; i++)
    {
        suits[hand[i].suit]++;
        if (suits[hand[i].suit] >= 5)
            return 1; // has flush
    }
    return 0; //no flush
}

int hasStraight(Card hand[])
{
    qsort(hand, 7, sizeof(Card), compareCards);
    int i, j;
    int count = 1;
    for (i = 0; i < 6; i++)
    {
        if (hand[i].rank - hand[i+1].rank == 1)
        {
            count ++;
            if (count >= 5)
                return 1;
        }
        else if (hand[i].rank - hand[i + 1].rank > 1)
        {
            count = 1;
        }
    }
    // Check if there is a straight with Ace as the lowest card
    if (hand[0].rank == 12 && hand[1].rank == 3 && hand[2].rank == 2 && hand[3].rank == 1 && hand[6].rank == 0)
        return 1; // straight
    return 0; // no straight
}

int hasStraighFlush(Card hand[])
{
    if (hasFlush(hand) && hasStraight(hand))
        return 1;
    return 0;
}

int hasFourOfKind(Card hand[])
{
    qsort(hand, 7, sizeof(Card), compareCards);
    int i;
    int count = 1;
    for (i = 0; i < 6; i++)
    {
        if (hand[i].rank == hand[i+1].rank)
        {
            count++;
            if (count == 4)
                return 1; //four of a kind
        }
        else
        {
            count = 1;
        }
    }
    return 0; //no four of a kind
}

int hasFullHouse(Card hand[])
{
    qsort(hand, 7, sizeof(Card), compareCards);
    int i;
    int threeCount = 0;
    int pairCount = 0;
    int count = 1;
    for (i = 0; i < 6; i++)// ???
    {
        if (hand[i].rank == hand[i + 1].rank)
        {
            count ++;
        }
        else if (count == 2)
        {
            pairCount = 1;
        }
        else
        {
            count = 1;
        }
    }
    if (threeCount && pairCount)
        return 1;
    return 0;
}

int hasThreeOfKind(Card hand[])
{
    qsort(hand, 7, sizeof(Card), compareCards);
    int i;
    int count = 1;
    for (i = 0; i < 6; i++)
    {
        if (hand[i].rank == hand[i+1].rank)
        {
            count ++;
            if (count == 3)
                return 1;
        }
        else
        {
            count = 1;
        }
    }
    return 0;
}

int hasTwoPair(Card hand[]) 
{
    qsort(hand, 7, sizeof(Card), compareCards);
    int i;
    int pairCount = 0;
    int count = 1;
    for (i = 0; i < 6; i++) 
    {
        if (hand[i].rank == hand[i + 1].rank)
        {
            count++;
            if (count == 2)
            {
                pairCount++;
            } 
            else if (count == 3)
            {
                pairCount--;
            }
        } 
        else 
        {
            count = 1;
        }
    }
    if (pairCount >= 2)
        return 1; // two pair
    return 0; // no two pair
}

int hasOnePair(Card hand[])
{
    qsort(hand, 7, sizeof(Card), compareCards);
    int i;
    int count = 1;
    for (i = 0; i < 6; i++)
    {
        if (hand[i].rank == hand[i + 1].rank)
        {
            count++;
            if (count == 2)
                return 1; // one pair
        }
        else
        {
            count = 1;
        }
    }
    return 0; // no one pair
}

PlayerResult evaluateHand(Card hand[])
{
    int handRank = 0;
    if (hasStraighFlush(hand))
    {
        handRank = 9;
    }
    else if (hasFourOfKind(hand))
    {
        handRank = 8;
    }
    else if (hasFullHouse(hand))
    {
        handRank = 7;
    }
    else if (hasFlush(hand))
    {
        handRank = 6;
    }
    else if (hasStraight(hand))
    {
        handRank = 5;
    }
    else if (hasThreeOfKind(hand))
    {
        handRank = 4;
    }
    else if (hasTwoPair(hand))
    {
        handRank = 3;
    }
    else if (hasOnePair(hand))
    {
        handRank = 2;
    }
    else
    {
        handRank = 1;
    }
    
    PlayerResult result;
    result.playerIndex = -1;
    result.handRank = handRank;
    
    return result;
}

PlayerResult findWinner(Card players[][2], Card BoardCards[])
{
    PlayerResult winner;
    int maxHandRank = 0;

    int i;
    for (i = 0; i < PLAYERS; i++)
    {
        //玩家手牌＋公牌
        Card hand[7];
        int j;
        for (j = 0; j < 2; j++)
        {
            hand[j] = players[i][j];
        }
        for (j = 0; j < 5; j++)
        {
            hand[j + 2] = BoardCards[j];
        }
        PlayerResult playerResult = evaluateHand(hand);

        if (playerResult.handRank > maxHandRank) 
        {
            maxHandRank = playerResult.handRank;
            winner = playerResult;
        }
    }
    //開始進出每位玩家最大的手牌
    int count = 0;
    for (i = 0; i < PLAYERS; i++)
    {
        Card hand[7];
        int j;
        for (j = 0; j < 2; j++)
        {
            hand[j] = players[i][j];
        }
        for (j = 0; j < 5; j++)
        {
            hand[j + 2] = BoardCards[j];
        }

        PlayerResult playerResult = evaluateHand(hand);

        if (playerResult.handRank != maxHandRank)
        {
            count++;
            printf("Player %d's best hand: ", i+1);
            switch (playerResult.handRank) 
            {
                case 9 :
                    printf("Straight Flush\n");
                    push(9);
                    break;
                case 8:
                    printf("Four of a Kind\n");
                    push(8);
                    break;
                case 7:
                    printf("Full House\n");
                    push(7);
                    break;
                case 6:
                    printf("Flush\n");
                    push(6);
                    break;
                case 5:
                    printf("Straight\n");
                    push(5);
                    break;
                case 4:
                    printf("Three of a Kind\n");
                    push(4);
                    break;
                case 3:
                    push(3);
                    printf("Two Pair\n");
                    break;
                case 2:
                    printf("One Pair\n");
                    push(2);
                    break;
                default:
                    printf("High Card\n");
                    push(1);
                    break;
            }
        }
       else if (playerResult.handRank == maxHandRank)
       {
            count++;
            printf("Player %d's best hand: ", i+1);
            // printf("Player %d's best hand: ", i+1);
            switch (playerResult.handRank) 
            {
                case 9 :
                    printf("Straight Flush\n");
                    push(9);
                    break;
                case 8:
                    printf("Four of a Kind\n");
                    push(8);
                    break;
                case 7:
                    printf("Full House\n");
                    push(7);
                    break;
                case 6:
                    printf("Flush\n");
                    push(6);
                    break;
                case 5:
                    printf("Straight\n");
                    push(5);
                    break;
                case 4:
                    printf("Three of a Kind\n");
                    push(4);
                    break;
                case 3:
                    printf("Two Pair\n");
                    push(3);
                    break;
                case 2:
                    printf("One Pair\n");
                    push(2);
                    break;
                default:
                    printf("High Card\n");
                    push(1);
                    break;
            }
       }
    }
    //Check
    // for (int i = 0; i <5 ; i++)
    // {
    //     printf("%d\t",handType[i]);
    //     printf("\n");
    // }
    
    //print result
    getchar();
    printf("Show result\n");
    printf("Press enter to continue!\n");
    getchar();
    findMax(handType, 6);

    return winner;
}
//Main function
int main()
{
    srand(time(NULL));
    
    Card deck[52];
    Card players[5][2];
    Card BoardCards[5];
    //洗牌發牌
    iniDeck(deck);
    shuffle(deck);
    deal(deck, players);
    dealBoard(deck, BoardCards);
    //顯示玩家手牌
    printf("Show 5 player hand card:\n");
    printf("Press enter to continue!\n");
    getchar();
    printPlayerCards(players);
    //顯示公牌
    printf("\n");
    printf("Show 5 board cards:\n");
    printf("Press enter to continue!\n");
    getchar();
    printBoardCards(BoardCards);
    getchar();
    //顯示結果
    printf("Show player best hand\n");
    printf("Press enter to continue!\n");
    getchar();
    PlayerResult winner = findWinner(players, BoardCards);

    return 0;
}
