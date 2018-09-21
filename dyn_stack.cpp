#include <iostream>
using namespace std;

struct msg {
	msg() {
		prev = nullptr;
	}
	double currency_amt_usd;
	double currency_amt_eur;
	msg* prev;
};

msg* g_top(nullptr);

bool check_empty() {
	return g_top == nullptr;
}

msg* create_msg() {
	return new msg();
}

void init_msg(msg* msg_ptr) {
	msg_ptr->currency_amt_usd = 60.0 + (rand () % 20) - 10;
	msg_ptr->currency_amt_eur = 75.0 + (rand () % 20) - 10;
}

void push(msg* msg_ptr) {
	if (!check_empty()) {
		msg_ptr->prev = g_top;
	}
	g_top = msg_ptr;
}

msg* pop() {
	msg* top = g_top;
	g_top = g_top->prev;
	return top;
}

void del(const msg* msg_ptr) {
	delete msg_ptr;
}

void fill_stack(int n) {
	for (int i = 0; i < n; ++i) {
		msg* msg_ptr = create_msg();
		init_msg(msg_ptr);
		push(msg_ptr);
	}
}

void output_stack() {
	//TODO: read from top of stack
	//TODO: print to stdout
	//TODO: delete
	int i = 1;
	while (!check_empty()) {
		msg* msg_ptr = pop();
		cout << "Day " << i++ << endl;
		cout << "USD = " << msg_ptr->currency_amt_usd << " RUB \n";
		cout << "EUR = " << msg_ptr->currency_amt_eur << " RUB \n\n";
		del(msg_ptr);
	}
}

int main() {
	srand(time(NULL));

	int n; //number of days for currency analysis
	cout << "Days for analysis: ";
	cin >> n;

	fill_stack(n);
	output_stack();
	return 0;
}

