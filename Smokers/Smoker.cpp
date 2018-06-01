#include "stdafx.h"
#include "Smoker.h"


Smoker::Smoker(size_t idSmoker, std::string ingredient, std::vector<std::string> &table, std::shared_ptr<Event> wakeMediator, std::shared_ptr<Event> wakeSmoker)
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


bool Smoker::CanSmoke(const std::vector<std::string> &list)
{
	return std::find(list.begin(), list.end(), m_ingredient) == list.end();
}

void Smoker::SmokeCigerette()
{
	while (true)
	{
		m_wakeSmoker->WaitUntilSignalled();
		m_wakeMediator->SetUnsignalled();
		
		if (CanSmoke(m_table))
		{
			Sleep(500);
			std::printf("Smoker #%zd ", m_idSmoker);
			std::printf("%s ", m_ingredient);
			
			/*for (size_t i = 0; i < m_table.size(); i++)
			{
				std::printf("%s ", m_table[i]);
			}*/
			std::printf("\n");
			m_wakeMediator->SetSignalled();
		}
		
	}
}

Smoker::~Smoker()
{
}
