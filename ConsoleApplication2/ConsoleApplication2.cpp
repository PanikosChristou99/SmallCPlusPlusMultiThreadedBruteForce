// ConsoleApplication2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread> 
#include <vector>
#include <chrono>


void visit(std::string chars, std::string startChars, size_t max_len, std::string curr, int count) {
	if (count == 0) {
		for (auto c : startChars) {
			std::string a = curr + c;
			std::cout << (a + "\n");
			visit(chars, startChars, max_len, a, count + 1);
		}

	}
	else if (count != max_len - 1) {
		for (auto c : chars) {
			std::string a = curr + c;
			std::cout << (a + "\n");
			visit(chars, startChars, max_len, a, count + 1);
		}
	}
	else {
		for (auto c : chars) {
			std::string a = curr + c;
			std::cout << (a + "\n");
		}
	}
}

int main() {
	std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
	std::string alphabetCaps = "";
	std::string symbols = "!?";
	std::string numbers = "1234567890";
	for (char c : alphabet) {
		alphabetCaps += (char)toupper(c);
	}
	std::string finalLetters = alphabet + alphabetCaps + symbols + numbers;
	int num_of_threads = 1;
	int length = finalLetters.length();
	std::vector < std::thread > threads;

	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();


	//visit(finalLetters, finalLetters, 3, "", 0);

	//std::chrono::steady_clock::time_point end2 = std::chrono::steady_clock::now();


	//std::cout << "Elapsed time in milliseconds : " << std::chrono::duration_cast<std::chrono::milliseconds>(end2 - begin).count() << " ms" << std::endl;

	//exit(0);

	int start = 0;
	int end = 0;
	int i;
	for (i = 0; i < num_of_threads-1; i++) {
		start = (int)((float)i / num_of_threads * length);
		end = (int)((float)(i + 1) / num_of_threads * length)+1;

		//std::cout << start << std::endl << end << std::endl << length << std::endl ;

		threads.push_back(std::thread(visit, finalLetters, finalLetters.substr(start, end), 3, "", 0));
	}

	start = (int)((float)i / num_of_threads * length);
	end = (int)((float)(i + 1) / num_of_threads * length)+1;

	visit(finalLetters, finalLetters.substr(start, end), 3, "", 0);

	for (auto& th : threads) {
		th.join();
	}

	//visit(finalLetters, finalLetters, 3, "", 0);

	std::chrono::steady_clock::time_point end2 = std::chrono::steady_clock::now();


	std::cout << "Elapsed time in seconds : " << std::chrono::duration_cast<std::chrono::seconds>(end2 - begin).count() << " s" << std::endl;


	return 0;
}




// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
