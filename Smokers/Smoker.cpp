#include "stdafx.h"
#include "Smoker.h"
#include "Event.h"
#include "ThreadHandler.h"
#include "Table.h"

Smoker::Smoker(size_t idSmoker, std::string ingredient, Table &table, std::shared_ptr<Event> wakeMediator, std::shared_ptr<Event> wakeSmoker)
	:m_idSmoker(idSmoker)
	,m_ingredient(ingredient)
	,m_table(table)
	,m_wakeSmoker(wakeSmoker)
	,m_wakeMediator(wakeMediator)
{
}

std::string Smoker::GetIngredient()
{
	return m_ingredient;
}

size_t Smoker::GetId()
{
	return m_idSmoker;
}


bool Smoker::CanSmoke(const std::vector<std::string> list)
{
	return std::find(list.begin(), list.end(), m_ingredient) == list.end();
}

void Smoker::SmokeCigerette()
{
	while (true)
	{
		m_wakeMediator->WaitUntilSignalled();
		if (!m_table.IsEmpty() && CanSmoke(m_table.GetIngredients()))
		{
			std::cout << "Mediator puts on table: ";
			m_table.PrintIngredients();
			m_wakeMediator->SetUnsignalled();
			m_wakeSmoker->SetUnsignalled();
			std::cout << "Smoker #" << m_idSmoker << " is smoking, ingredient: " << m_ingredient << std::endl;
			std::cout << std::endl;
			Sleep(500);
			m_wakeSmoker->SetSignalled();
			m_table.Clear();
		}
	}
}

Smoker::~Smoker()
{
}
