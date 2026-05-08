# Merkelex: Cryptocurrency Trading Simulation
---

## Overview

**Merkelex** is a C++-based cryptocurrency trading simulation that models the core mechanics of a real-world exchange.  
It focuses on order book processing, trade matching, wallet management, and market data simulation.

This project is designed for educational purposes to help understand how trading systems operate internally.

---

## Core Concepts

- Order book mechanics (buy/sell matching)
- Trade execution engine
- Wallet balance tracking
- Market data simulation using CSV files
- CLI-based user interaction system

---

## Features

### 📊 Order Book Engine
Simulates a real exchange order book, matching buy and sell orders based on price-time priority.

### 💰 Wallet System
Manages multiple currencies and handles:
- Deposits
- Withdrawals
- Trade settlements

### 📁 CSV Market Data Loader
Loads historical market data from CSV files to simulate realistic trading conditions.

### 🖥️ Interactive CLI
User-friendly command-line interface to:
- Place orders
- View market stats
- Track wallet balance
- Advance simulation time

---

## System Architecture
User (CLI)
│
▼
MerkelMain (Controller)
│
├── OrderBook (Matching Engine)
│ ├── OrderBookEntry (Orders)
│
├── Wallet (Funds Manager)
│
└── CSVReader (Market Data Loader)


---

## Project Structure

- `main.cpp` → Application entry point  
- `MerkelMain.h / MerkelMain.cpp` → Core simulation logic  
- `OrderBook.h / OrderBook.cpp` → Order matching engine  
- `OrderBookEntry.h / OrderBookEntry.cpp` → Order data structure  
- `Wallet.h / Wallet.cpp` → Balance & transaction system  
- `CSVReader.h / CSVReader.cpp` → Market data parser  

---


