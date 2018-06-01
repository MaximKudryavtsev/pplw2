#pragma once

typedef HANDLE Thread;
typedef std::vector<Thread> Threads;

class ThreadHandler
{
public:
	ThreadHandler();
	~ThreadHandler();
	void AddThread(Thread const& thread);
	void Wait();
private:
	Threads m_threads;
};

