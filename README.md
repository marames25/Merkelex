# Merkelex

Merkelex is a **C++ cryptocurrency trading simulation** that models a simplified cryptocurrency exchange environment.

The project simulates market data, order books, wallets, and trading operations using historical data loaded from CSV files.

## Features

* Cryptocurrency market simulation
* Order book management
* Buy and sell orders
* Wallet management
* Market data loaded from CSV files
* Order matching and trading simulation
* Console-based interaction
* Object-oriented design

## Technologies Used

* C++
* Object-Oriented Programming
* CSV File Processing
* Standard Template Library (STL)

## Project Structure

```text
Merkelex/
│
├── CSVReader.cpp
├── CSVReader.h
│
├── MerkelMain.cpp
├── MerkelMain.h
│
├── OrderBook.cpp
├── OrderBook.h
├── OrderBokkEntry.h
├── OrderBookEntry.cpp
│
├── Wallet.cpp
├── Wallet.h
│
├── main.cpp
│
└── 20200317 (3).csv
```

## Main Components

### Order Book

The `OrderBook` component manages market orders and provides the core structure for simulating cryptocurrency trading.

### Order Book Entry

`OrderBookEntry` represents individual market orders and their related information.

### Wallet

The `Wallet` component manages the user's simulated cryptocurrency holdings and supports trading-related operations.

### CSV Reader

`CSVReader` is responsible for loading and processing market data from CSV files.

### MerkelMain

`MerkelMain` controls the main application flow and provides the user interaction layer.

## Getting Started

### Prerequisites

* C++ compiler
* C++11 or later
* IDE such as Visual Studio, CLion, Code::Blocks, or VS Code

### Clone the Repository

```bash
git clone https://github.com/marames25/Merkelex.git
cd Merkelex
```

### Build and Run

Compile the project using your preferred C++ compiler or open it in a C++ IDE.

For example:

```bash
g++ *.cpp -o Merkelex
./Merkelex
```

## Learning Objectives

This project demonstrates practical application of:

* Object-Oriented Programming
* Classes and objects
* Encapsulation
* File handling
* CSV parsing
* Data structures
* Market/order-book simulation
* C++ project organization

## Purpose

Merkelex was developed as a practical C++ project to simulate the basic concepts behind cryptocurrency trading platforms and to strengthen understanding of object-oriented programming and data processing.

## Author

**Maram Esmaeil**

[GitHub Repository](https://github.com/marames25/Merkelex)
