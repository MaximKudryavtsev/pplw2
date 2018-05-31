#pragma once
class Event
{
public:
	Event(bool signalled);
	void SetSignalled();
	void SetUnsignalled();
	void WaitUntilSignalled();
	~Event();
private:
	HANDLE m_handle;
};

