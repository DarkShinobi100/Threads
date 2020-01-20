// Simple threading example
// Adam Sampson <a.sampson@abertay.ac.uk>

#include <chrono>
#include <iostream>
#include <thread>

// Import things we need from the standard library
using std::chrono::seconds;
using std::chrono::milliseconds;
using std::cout;
using std::endl;
using std::ofstream;
using std::this_thread::sleep_for;
using std::thread;

struct ThreadArgs
{
	int foo;
	int bar;
};

struct ThreadMultiArgs
{
	int Id;
	int Delay;
};

void myThreadFunc(int ID, int Delay)
{
	//sleep_for(seconds(3));
	//cout << "I am myThreadFunc\n";
	// cout << val<<endl;
	//Args->bar = 0;
//	cout << Args->foo<<","<<Args->bar << endl;

		cout << ID << endl;
		sleep_for(milliseconds(Delay));	
}


int main(int argc, char *argv[])
{
	// At the moment our program is only running one thread (the initial one the operating system gave us).
	ThreadArgs Args;
	Args.foo = 4;
	Args.bar = 2;

	thread myThread[5];
	for (int i = 0; i < 5; i++)
	{
		myThread[i] = thread(myThreadFunc, i, i * 600);
	}
	//thread myThread(myThreadFunc,42, &MultiArgs);

	// Now our program is running two threads in parallel (the initial one, and myThread).
	
	cout << "I am main\n";

	// Wait for myThread to finish.
	for (int i = 0; i < 5; i++)
	{
		myThread[i].join();
	}

	//myThread.join();
	//cout << Args.foo << "," << Args.bar << endl;

	// Now we just have the initial thread. So it's safe to exit.

	cout << "All done\n";
	sleep_for(seconds(3));

	return 0;
}
