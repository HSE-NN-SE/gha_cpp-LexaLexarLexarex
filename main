#include<vector>
#include<iostream>

using namespace std;

class BinCalc {
private:

	int decimal;
	vector<bool> binary_number;
	int amount_of_bit;
	void count_decimal() {
		decimal = 0;
		for (int i = 0, k = 1; i < amount_of_bit - 1; i++, k *= 2)
			if (binary_number[i])
				decimal += k;
		if (binary_number[amount_of_bit - 1]) decimal *= -1;
	}

public:

	BinCalc(const int decimal, const int amount_of_bit) {
		this->decimal = decimal;
		this->binary_number.reserve(amount_of_bit);
		this->amount_of_bit = amount_of_bit;
		for (int i = 0, buffer = decimal; i < amount_of_bit; i++, buffer /= 2)
			binary_number.push_back(buffer % 2);
		if (decimal < 0) binary_number[amount_of_bit - 1] = 1;
	}

	BinCalc operator+(BinCalc& bincalc) {
		int max_bit = this->amount_of_bit;
		if (this->binary_number[this->amount_of_bit - 1] && !bincalc.binary_number[bincalc.amount_of_bit - 1])
			return bincalc + *this;
		else if (!this->binary_number[this->amount_of_bit - 1] && bincalc.binary_number[bincalc.amount_of_bit - 1]) {
			bincalc.binary_number[bincalc.amount_of_bit - 1] = 0;
			bincalc.count_decimal();
			return *this - bincalc;
		}
		else {
			BinCalc responce(0, max_bit);
			for (int i = 0, buffer = 0; i < max_bit - 1; i++) {
				if (bincalc.binary_number[i] && this->binary_number[i] && buffer) responce.binary_number[i] = 1;
				else if ((bincalc.binary_number[i] && this->binary_number[i]) || (((bincalc.binary_number[i] || this->binary_number[i]) && buffer))) {
					responce.binary_number[i] = 0;
					buffer = 1;
				}
				else if (buffer && !(bincalc.binary_number[i] || this->binary_number[i])) {
					responce.binary_number[i] = 1;
					buffer = 0;
				}
				else responce.binary_number[i] = bincalc.binary_number[i] + this->binary_number[i];
			}
			if (bincalc.binary_number[bincalc.amount_of_bit - 1] == 1 && this->binary_number[this->amount_of_bit - 1] == 1)
				responce.binary_number[max_bit - 1] = 1;
			responce.count_decimal();
			return responce;
		}
	}

	BinCalc operator-(BinCalc& bincalc) {
		int max_bit = this->amount_of_bit;
		if (this->binary_number[this->amount_of_bit - 1] && !bincalc.binary_number[bincalc.amount_of_bit - 1]) {
			bincalc.binary_number[bincalc.amount_of_bit - 1] = 1;
			return *this + bincalc;
		}
		else if (!this->binary_number[this->amount_of_bit - 1] && bincalc.binary_number[bincalc.amount_of_bit - 1]) {
			bincalc.binary_number[bincalc.amount_of_bit - 1] = 0;
			return *this + bincalc;
		}
		else if (this->binary_number[this->amount_of_bit - 1] && bincalc.binary_number[bincalc.amount_of_bit - 1]) {
			bincalc.binary_number[bincalc.amount_of_bit - 1] = 0;
			this->binary_number[this->amount_of_bit - 1] = 0;
			this->count_decimal();
			bincalc.count_decimal();
			if (bincalc.decimal < this->decimal) {
				BinCalc responce = *this - bincalc;
				responce.binary_number[responce.amount_of_bit - 1] = 1;
				responce.count_decimal();
				return responce;
			}
			else {
				BinCalc responce = bincalc - *this;
				responce.binary_number[max_bit] = false;
				responce.count_decimal();
				return responce;
			}
		}
		else if (bincalc.decimal > this->decimal) {
			BinCalc responce = bincalc - *this;
			responce.binary_number[responce.amount_of_bit - 1] = 1;
			responce.count_decimal();
			return responce;
		}
		else if (bincalc.decimal == this->decimal) {
			BinCalc responce(0, max_bit);
			return responce;
		}
		else {
			BinCalc responce = *this;
			for (int i = 0; i < responce.amount_of_bit - 1; i++) {
				if ((responce.binary_number[i] && bincalc.binary_number[i]) || (!responce.binary_number[i] && !bincalc.binary_number[i]))
					responce.binary_number[i] = false;
				else if (!responce.binary_number[i]) {
					int j = 0;
					for (; !responce.binary_number[i + j] && (i + j < responce.amount_of_bit - 1); j++)
						responce.binary_number[i + j] = true;
					responce.binary_number[i + j] = false;
				}
			}
			responce.count_decimal();
			return responce;
		}
	}

	BinCalc operator*(BinCalc& bincalc) {
		int max_bit = this->amount_of_bit, k = 0;
		int* help = new int[max_bit * 2];
		BinCalc responce(0, max_bit * 2);
		bool** ne_tetrad_v_kletochku = new bool* [max_bit * 2];
		for (int i = 0; i < max_bit * 2; i++)
			ne_tetrad_v_kletochku[i] = new bool[max_bit * 2];
		for (int i = 0; i < max_bit * 2; i++)
			for (int j = 0; j < max_bit * 2; j++)
				ne_tetrad_v_kletochku[i][j] = 0;
		for (int i = 0; i < max_bit - 1; i++)
			if (bincalc.binary_number[i])
				for (int j = 0; j < max_bit - 1; j++)
					ne_tetrad_v_kletochku[i][i + j] = this->binary_number[j];
		for (int i = 0; i < max_bit * 2; i++) {
			for (int j = 0; j < max_bit * 2; j++)
				if (ne_tetrad_v_kletochku[j][i]) k++;
			help[i] = k;
			k = 0;
		}
		for (int i = 0; i < max_bit * 2 - 1; i++) {
			help[i + 1] += help[i] / 2;
			responce.binary_number[i] = help[i] % 2;
		}
		if ((this->binary_number[this->amount_of_bit - 1] && bincalc.binary_number[bincalc.amount_of_bit - 1]) || (!this->binary_number[this->amount_of_bit - 1] && !bincalc.binary_number[bincalc.amount_of_bit - 1]))
			responce.binary_number[responce.amount_of_bit - 1] = 0;
		else
			responce.binary_number[responce.amount_of_bit - 1] = 1;
		responce.count_decimal();
		return responce;

	}

	friend ostream& operator<<(ostream& out, const BinCalc& bincalc);
};

ostream& operator<<(ostream& out, const BinCalc& bincalc) {
	out << "Decimal is " << bincalc.decimal << ", Binary number is \t";
	for (int i = bincalc.amount_of_bit - 1; i >= 0; i--) out << bincalc.binary_number[i];
	return out;
}

int read() {
	int value;
	cin >> value;
	if (value == 0) throw "Division by zero!";
	return value;
}

int readZ() {
	char znak2;
	cin >> znak2;
	if (!(znak2 == '+' || znak2 == '-' || znak2 == '*')) throw "Incorrect Input!";
	else if (znak2 == '+') return 0;
	else if (znak2 == '-') return 1;
	else return 2;
}

int main() {
	int a, b, znak, a1, b1;
	try {
		a1 = read();
	}
	catch (...)
	{
		cout << "Error!" << std::endl;
	}
	try {
		a = read();
	}
	catch (...)
	{
		cout << "Error!" << std::endl;
	}

	try {
		znak = readZ();
	}
	catch (...)
	{
		cout << "Error!" << std::endl;
	}
	try {
		b = read();
	}
	catch (...)
	{
		cout << "Error!" << std::endl;
	}
	BinCalc left(a, a1), right(b, a1);
	if (znak == 0) {
		cout << left << endl << right << endl;
		cout << left + right;
	}
	else if (znak == 1) {
		cout << left << endl << right << endl;
		cout << left - right;
	}
	else {
		cout << left << endl << right << endl;
		cout << left * right;
	}
}
