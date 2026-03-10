# Limit Order Book Engine (C++)

This project implements a simplified version of a stock exchange matching engine in C++.

Matching engines are responsible for pairing buy and sell orders in financial markets.
This implementation simulates how exchanges match orders using price priority.

---

## Features

• Buy and sell order placement  
• Price-time priority matching  
• Automatic trade execution  
• Order book visualization  
• Trade history tracking  
• Market statistics  
• Order IDs for tracking

---

## Technologies

- C++  
- STL (priority_queue, vector)  
- Object-Oriented Programming

---

## System Design

Orders are stored in two priority queues:

* **Buy orders** → max heap (highest price first)
* **Sell orders** → min heap (lowest price first)

This allows the engine to efficiently find the best orders to match.

---

### Architecture

```
Incoming Orders
      │
      ▼
Matching Engine
      │
 ┌────┴─────┐
 ▼          ▼
Buy Book   Sell Book
(MaxHeap)  (MinHeap)
      │
      ▼
Trade Execution
```
---

## Matching Logic

An order can be matched when:

```
buy_price >= sell_price
```

If the order quantities are different, the engine performs a **partial trade** and keeps the remaining order in the order book.

Example:

```
BUY 100 shares @ 105
SELL 40 shares @ 104

Trade executed: 40 shares
Remaining BUY order: 60 shares
```

---

## Data Structures Used

`priority_queue`

Maintains the buy and sell order books efficiently.

`struct Order`

Represents each order with fields such as price, quantity, and order type.

---

## What I Learned

- How financial exchanges match orders
- Implementing heap-based priority queues
- Designing algorithms for trade execution

---

## Run

Compile:
```
g++ main.cpp -o engine
```
Run:
```
engine.exe
```
---
