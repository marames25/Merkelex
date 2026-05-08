#Merkelex: A Cryptocurrency Trading Simulation

Overview

Merkelex is a C++-based cryptocurrency trading simulation designed to provide a foundational understanding of order book mechanics, wallet management, and basic trading operations within a simulated market environment. This project serves as an educational tool to explore how cryptocurrency exchanges process orders and manage user funds.

#Features

•
Order Book Management: Implements a robust order book to handle buy and sell orders, matching them to execute trades.

•
Wallet System: Manages user balances for different cryptocurrencies and fiat currencies, supporting deposits, withdrawals, and trade settlements.

•
CSV Data Integration: Reads market data from CSV files to simulate historical trading activity.

•
User Interaction: Provides a command-line interface for users to interact with the simulation, place orders, and view their wallet status.

#Project Structure

The project is organized into several key C++ files, each responsible for a specific aspect of the simulation:

•
main.cpp: The entry point of the application, initializing and running the simulation.

•
MerkelMain.h/MerkelMain.cpp: Contains the core logic for the trading simulation, including the main menu, market statistics, and user interaction handling.

•
OrderBook.h/OrderBook.cpp: Manages the order book, including adding, matching, and processing orders.

•
OrderBookEntry.h/OrderBookEntry.cpp: Defines the structure for individual order entries within the order book.

•
Wallet.h/Wallet.cpp: Implements the user wallet functionality, handling currency balances and transactions.

•
CSVReader.h/CSVReader.cpp: Utility for reading and parsing market data from CSV files.

#Getting Started

Prerequisites

To build and run Merkelex, you will need:

•
A C++ compiler (e.g., g++)

•
Make (for building from Makefile, if provided)

Building the Project

(Assuming a Makefile is present or standard C++ compilation commands are used)

Bash


g++ -o merkelex *.cpp -std=c++17



Running the Simulation

Bash


./merkelex



#Usage

Upon running the simulation, you will be presented with a menu of options, allowing you to:

•
View market statistics

•
Place buy or sell orders

•
View your wallet balance

•
Advance to the next time frame

•
Exit the application

Follow the on-screen prompts to interact with the simulation.

#Credits

Developed by Maram Esmaeil.

#
