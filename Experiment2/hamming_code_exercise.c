#include <iostream>
using namespace std;

// function to calculate the parity bit for a given position
int parity(int n, int *arr) {
	int p = 0;
	for (int i = 0; i < n; i++) {
		if (i != (1 << p) - 1) {
			p++;
		}
		else {
			p++;
			i += (1 << p) - 2;
		}
	}
	int sum = 0;
	for (int i = 0; i < n; i++) {
		if ((i & (1 << p - 1)) == 0) {
			sum ^= arr[i];
		}
	}
	return sum;
}

// function to encode the data using the Hamming code
void encode(int *data, int n, int *encoded) {
	int r = 0;
	while ((1 << r) < n + r + 1) {
		r++;
	}
	int j = 0;
	for (int i = 0; i < n + r; i++) {
		if ((i & (i + 1)) == 0) {
			encoded[i] = 0;
		}
		else {
			encoded[i] = data[j];
			j++;
		}
	}
	for (int i = 0; i < r; i++) {
		int p = parity(n + r, encoded);
		encoded[(1 << i) - 1] = p;
	}
}

// function to decode the data using the Hamming code
bool decode(int *data, int n, int *received) {
	int r = 0;
	while ((1 << r) < n + r + 1) {
		r++;
	}
	int error = 0;
	for (int i = 0; i < r; i++) {
		int p = parity(n + r, received);
		if (p != received[(1 << i) - 1]) {
			error += (1 << i) - 1;
		}
	}
	if (error != 0) {
		received[error - 1] ^= 1;
	}
	int j = 0;
	for (int i = 0; i < n + r; i++) {
		if ((i & (i + 1)) != 0) {
			data[j] = received[i];
			j++;
		}
	}
	return error == 0;
}

int main() {
	int n = 4; // size of data
	int r = 3; // number of redundant bits
	int data[n] = {1, 0, 1, 1}; // data to be transmitted
	int encoded[n + r] = {0}; // encoded data

