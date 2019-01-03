//			 Fibonacci Solutions
//   The forloop, whileloop, and tail recursive are all 
// rather quick. The last recursive fibonacci can slow down 
// your computer if you go above 40-ish indexes of the fibonacci
// series. You've been warned! lolz

#include <iostream>
#include <string>

//   The forloop solution is long and non-recursive.
// The input 'n' represents the number of fibonacci
// elements to display and not the limiting value of
// the number.
void fibonacci_forloop_solution() {
	size_t n, t1 = 0, t2 = 1, next = 0;

	std::cout << "|For Loop Solution|\nEnter the number of terms: ";
	std::cin >> n;

	std::cout << "Fibonacci Series: ";

	for (size_t i = 1; i <= n; ++i)
	{
		// Prints the first two terms.
		if (i == 1)
		{
			std::cout << " " << t1;
			continue;
		}
		if (i == 2)
		{
			std::cout << t2 << ", ";
			continue;
		}
		next = t1 + t2;
		t1 = t2;
		t2 = next;

		std::cout << next << ", ";
	}
}

//   The while loop version is still non-recursive, but
// it is much shorter. The input 'n' is the limiting
// value of the number to display; while the fibonacci 
// number < n keep printing fib numbers.
void fibonacci_whileloop_solution() {
	size_t t1 = 0, t2 = 1, nextTerm = 0, n;

	std::cout << "\n\n|While Loop Solution|\nEnter a positive number to count to: ";
	std::cin >> n;

	// displays the first two terms which is always 0 and 1
	std::cout << "Fibonacci Series: " << t1 << ", " << t2 << ", ";

	nextTerm = t1 + t2;

	while (nextTerm <= n)
	{
		std::cout << nextTerm << ", ";
		t1 = t2;
		t2 = nextTerm;
		nextTerm = t1 + t2;
	}
}

//   Recusive version of the fibonacci problem.
// The function below is fed the index of of the fibonacci
// series and then returns the value of said index.
// Although this is recursive, it is HORRIBLY SLOW! This
// function proves that recursion does not always mean speed!
size_t fibonacci(size_t num) {
	return num < 2 ? num : fibonacci(num - 1) + fibonacci(num - 2);
}

//   This is a wrapper funciton that provides the needed 
// 'functionality' lolz to keep with the similar format of
// the above functions.
void fibonacci_recursive_solution() {
	int num;
	std::cout << "\n\n|Recursive Solution|\nEnter the number of terms: ";
	std::cin >> num;

	std::cout << "Fibonacci Series: ";

	for (int i = 0; i < num; ++i) {
		std::cout << fibonacci(i) << ", ";
	}
}

//   Recursive Solution (Faster 'Tail Recursion')
size_t fib(size_t term, size_t val = 1, size_t prev = 0)
{
	if (term == 0) return prev;
	return fib(term - 1, val + prev, val);
}
void fibonacci_tailrecursive_solution() {
	int num;
	std::cout << "\n\n|Tail Recursive Solution|\nEnter the number of terms: ";
	std::cin >> num;

	std::cout << "Fibonacci Series: ";

	for (int i = 0; i < num; ++i) {
		std::cout << fib(i) << ", ";
	}
}
int main()
{

	fibonacci_forloop_solution();
	fibonacci_whileloop_solution();
	//   I switch the order of recursive and tail recursive
	// functions. Try going '40' positions and watch the 
	// difference in the speed of the recursive funcitons.
	fibonacci_tailrecursive_solution();
	fibonacci_recursive_solution();

	std::string pause;
	std::cin >> pause;
	return 0;
}