#include "stdafx.h"
#include "ThreadHandler.h"


ThreadHandler::ThreadHandler()
{
}

void ThreadHandler::AddThread(Thread const& thread)
{
	m_threads.push_back(thread);
}

void ThreadHandler::Wait()
{
	WaitForMultipleObjects(m_threads.size(), m_threads.data(), TRUE, INFINITE);
}

ThreadHandler::~ThreadHandler()
{
	for (auto & thread : m_threads)
	{
		CloseHandle(thread);
	}
}