#include "stdafx.h"
#include "Smoker.h"


Smoker::Smoker(size_t idSmoker, Ingredient ingredient)
	:m_idSmoker(idSmoker)
	,m_ingredient(ingredient)
{
}

void Smoker::SetIngredient(Ingredient ingredient)
{
	m_ingredient = ingredient;
}

Ingredient Smoker::GetIngredient()
{
	return m_ingredient;
}

size_t Smoker::GetId()
{
	return m_idSmoker;
}



bool Smoker::CanSmoke(ListOfIngredients list)
{
	return std::find(list.begin(), list.end(), m_ingredient) == list.end();
}

void Smoker::TwistCigarette()
{
	std::cout << "Smoker #" << m_idSmoker << " is twisting a cigarette..." << std::endl;
	
	Sleep(TWISTING_TIME);
	std::cout << "Smoker #" << m_idSmoker << " has finished to twist a cigarette" << std::endl;
}

void Smoker::SmokeCigerette()
{
	std::cout << "Smoker #" << m_idSmoker << " is smoking a cigarette" << std::endl;
	Sleep(SMOKING_TIME);
}

Smoker::~Smoker()
{
}
