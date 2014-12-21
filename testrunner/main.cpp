#include "/Users/riad/ClionProjects/jhelper-example-project/tasks/Task.cpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cctype>

namespace jhelper {

struct Test {
	std::string input;
	std::string output;
};

bool check(std::string expected, std::string actual) {
	while(!expected.empty() && isspace(*--expected.end()))
		expected.erase(--expected.end());
	while(!actual.empty() && isspace(*--actual.end()))
		actual.erase(--actual.end());
	return expected == actual;
}

} // namespace jhelper

int main() {
	std::vector<jhelper::Test> tests = {
		{"1", "43"},{"0", "43"},
	};
	bool allOK = true;
	for(const jhelper::Test& test: tests ) {
		std::stringstream in(test.input);
		std::ostringstream out;
		Task solver;
		solver.solve(in, out);
		std::cout << "Input: \n" << test.input << std::endl;
		std::cout << "Expected output: \n" << test.output << std::endl;
		std::cout << "Actual output: \n" << out.str() << std::endl;
		allOK = allOK && jhelper::check(test.output, out.str());
	}
	if(allOK) {
		std::cout << "All OK" << std::endl;
	}
	else {
		std::cout << "Some cases failed" << std::endl;
	};
}