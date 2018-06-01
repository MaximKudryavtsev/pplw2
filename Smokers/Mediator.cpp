#include "stdafx.h"
#include "Mediator.h"


Mediator::Mediator(std::vector<std::string> &table, std::shared_ptr<Event> wakeMediator, std::shared_ptr<Event> wakeSmoker)
	:m_table(table)
	,m_wakeMediator(wakeMediator)
	,m_wakeSmoker(wakeSmoker)
{
	Shuffle();
	m_mediatorIngredients = table;
}


std::vector<std::string> &Mediator::GetIngredients()
{
	return m_mediatorIngredients;
}

void Mediator::Work()
{
	while (true)
	{
		m_wakeMediator->WaitUntilSignalled();
		m_wakeSmoker->SetUnsignalled();

		
		m_table.clear();
		for (size_t i = 0; i < m_mediatorIngredients.size(); i++)
		{
			m_table.push_back(m_mediatorIngredients[i]);
		}
		Shuffle();
		m_wakeMediator->SetUnsignalled();
		m_wakeSmoker->SetSignalled();
	}
}



Mediator::~Mediator()
{
}

void Mediator::Shuffle()
{
	std::random_device rd;
	std::mt19937 randMT(rd());
	m_mediatorIngredients = { "tobacco", "paper", "matches" };
	std::shuffle(m_mediatorIngredients.begin(), m_mediatorIngredients.end(), randMT);
	m_mediatorIngredients.pop_back();
}
