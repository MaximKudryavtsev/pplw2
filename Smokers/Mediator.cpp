#include "stdafx.h"
#include "Mediator.h"


Mediator::Mediator()
{
	std::random_device rd;
	std::mt19937 randMT(rd());
	m_mediatorIngredients = { "tobacco", "paper", "matches" };
	std::shuffle(m_mediatorIngredients.begin(), m_mediatorIngredients.end(), randMT);
	m_mediatorIngredients.pop_back();
}


ListOfIngredients Mediator::GetIngredients()
{
	return m_mediatorIngredients;
}

void Mediator::PrintIngredients()
{
	std::cout << "Mediator's ingredients: ";
	copy(m_mediatorIngredients.begin(), m_mediatorIngredients.end(), std::ostream_iterator<Ingredient>(std::cout, " "));
	std::cout << std::endl;
	std::cout << std::endl;
}

Mediator::~Mediator()
{
}
