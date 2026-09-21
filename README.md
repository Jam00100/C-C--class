# Texas Hold'em Poker Simulator

這是一個使用 C 語言編寫的簡易德州撲克模擬程式。

程式會建立並洗亂一副 52 張撲克牌，向 5 位玩家各發 2 張手牌，再發出 5 張公共牌，最後判斷每位玩家能組成的最佳牌型。

## 功能

* 建立並隨機洗牌
* 支援 5 位玩家
* 每位玩家取得 2 張手牌
* 產生 5 張公共牌
* 判斷以下牌型：

  * High Card
  * One Pair
  * Two Pair
  * Three of a Kind
  * Straight
  * Flush
  * Full House
  * Four of a Kind
  * Straight Flush
* 比較所有玩家的牌型並顯示結果

## 編譯與執行

使用 GCC 編譯：

```bash
gcc TexaHoldem.c -o TexaHoldem
```

執行程式：

```bash
./TexaHoldem
```

## 操作方式

執行程式後，依照畫面提示按下 Enter，即可依序查看：

1. 所有玩家的手牌
2. 五張公共牌
3. 每位玩家的最佳牌型
4. 最終勝負結果

## 牌面表示方式

花色使用以下英文字母表示：

| 字母 | 花色           |
| -- | ------------ |
| S  | Spades（黑桃）   |
| H  | Hearts（紅心）   |
| D  | Diamonds（方塊） |
| C  | Clubs（梅花）    |

例如：

```text
A S
10 H
```

分別表示黑桃 A 與紅心 10。

## 已知限制

目前程式只比較玩家的牌型等級。

如果兩位以上玩家擁有相同牌型，程式會直接判定為平手，不會進一步比較牌面點數、踢腳牌（Kicker）或同花的最高牌。
