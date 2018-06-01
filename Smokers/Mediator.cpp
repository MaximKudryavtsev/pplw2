#include "stdafx.h"
#include "Mediator.h"


Mediator::Mediator(Table &table, std::shared_ptr<Event> wakeMediator, std::shared_ptr<Event> wakeSmoker)
	:m_table(table)
	,m_wakeMediator(wakeMediator)
	,m_wakeSmoker(wakeSmoker)
{
	Shuffle();
	table.SetIngredients(m_mediatorIngredients);
}

std::vector<std::string> &Mediator::GetIngredients()
{
	Shuffle();
	return m_mediatorIngredients;
}

void Mediator::Work()
{
	while (true)
	{
		m_wakeSmoker->WaitUntilSignalled();
		
		if (m_table.IsEmpty())
		{
			m_table.SetIngredients(GetIngredients());
			m_wakeMediator->SetSignalled();
			m_wakeSmoker->SetUnsignalled();
		}
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
