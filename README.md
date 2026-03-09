# Limit Order Book Engine (C++)

A simplified trading engine that simulates the order matching logic used in modern electronic stock exchanges.

## Features

• Buy and sell order placement  
• Price-time priority matching  
• Automatic trade execution  
• Order book visualization  
• Trade history tracking  
• Market statistics  
• Order IDs for tracking

## Technologies

C++  
STL (priority_queue, vector)  
Object-Oriented Programming

## System Design

Buy Orders → Max Heap  
Sell Orders → Min Heap  

Trades execute when:

highest buy price >= lowest sell price

## Run

Compile:

g++ main.cpp -o engine

Run:

engine.exe