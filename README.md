# Tic-Tac-Toe

Contents
---------------------
* File Contents
* Introduction
* Algorithm
* Requirements

## File Contents
	
	tic_tac_toe.cpp (program file containing code)

## Introduction
Book practice project from Problem Solving With C++ Chapter 7. Project 10.
A program that allows two players to play tic-tac-toe. Displays the updated game board after every move. Demonstrates ability to write multiple interacting functions and work with arrays in c++.
Written using Microsoft Visual Studio. 

## Algorithm

	1. output clean board to screen
		1a. positions are labeled one through nine - output should look like the following:
			1 2 3
			4 5 6
			7 8 9
	2. play game
		2a. take input of move from player 1, place an x in that location
			2aa. ensure no player has already placed an x or o in that location
			2ab. output updated board
			2ac. check for winner
		2b. take input of move from player 2, place an o in that location
			2ba. ensure no player has already placed an x or o in that location
			2bb. output updated board
			2bc. check for winner
		2c. if no winner, repeat
	3. output winner (or if no winner, output tied status)
	4. prompt user whether to continue

## Requirements
No requirements or modules needed for running this program.
