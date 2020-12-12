#pragma once
#include <iostream>
enum type{
	NUMBER,
	OPERATOR,
	OPENING_BRACKET,
	CLOSING_BRACKET
};
class Term {
public:
	type token;
	type GetType() {
		return token;
	}
	virtual void print() = 0;
};

class Number : public Term {
public:
	double value;
	Number(double num) {
		token = type::NUMBER;
		value = num;
	}
	void print() {
		std::cout << value <<" ";
	}
};

class Operator : public Term {
public:
	char value;
	Operator(char oper) {
		token = type::OPERATOR;
		value = oper;
	}
	int Priority() {
		if (value == '*' || value == '/') return 1;
		if (value == '+' || value == '-') return 0;
		//else throw "unidentified operation";
	}
	void print() {
		std::cout << value << " ";
	}
};

class Bracket : public Term {
public:
	char value;
	Bracket(char br) {
		if (br == '(')
			token = type::OPENING_BRACKET;
		else token = type::CLOSING_BRACKET;
		value = br;
	}
	void print() {
		std::cout << value << " ";
	}
};