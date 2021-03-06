// Smokers.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

DWORD WINAPI RunSmoker(LPVOID lp)
{
	Smoker* smoker = reinterpret_cast<Smoker*>(lp);
	smoker->SmokeCigerette();
	return 0;
}

DWORD WINAPI RunMediator(LPVOID lp)
{
	Mediator* mediator = reinterpret_cast<Mediator*>(lp);
	mediator->Work();
	return 0;
}

bool CanSmoke(const std::vector<std::string> list, std::string m_ingredient)
{
	return std::find(list.begin(), list.end(), m_ingredient) == list.end();
}

int main()
{
	std::shared_ptr<Event> mediatorEvent = std::make_shared<Event>(true);
	std::shared_ptr<Event> smokerEvent = std::make_shared<Event>(false);
	Table table;
	Mediator mediator(table, mediatorEvent, smokerEvent);

	Smoker smoker1(1, "paper", table, mediatorEvent, smokerEvent);
	Smoker smoker2(2, "matches", table, mediatorEvent, smokerEvent);
	Smoker smoker3(3, "tobacco", table, mediatorEvent, smokerEvent);
	ThreadHandler handler;
	
	handler.AddThread(CreateThread(NULL, NULL, &RunSmoker, &smoker1, NULL, NULL));
	handler.AddThread(CreateThread(NULL, NULL, &RunSmoker, &smoker2, NULL, NULL));
	handler.AddThread(CreateThread(NULL, NULL, &RunSmoker, &smoker3, NULL, NULL));
	handler.AddThread(CreateThread(NULL, NULL, &RunMediator, &mediator, NULL, NULL));
	
	handler.Wait();
    return 0;
}

