#include "app.hpp"

int main() {
	App app;
	try {
		app.start();
	} catch (runtime_error e) {
		cout << e.what() << endl;
	}
	return 0;
}
