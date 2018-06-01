#include "stdafx.h"
#include "Table.h"


Table::Table()
{
	m_ingredients.reserve(2);
	Clear();
}

void Table::SetIngredients(std::vector<std::string> ingredients)
{
	m_ingredients = ingredients;
}

std::vector<std::string> Table::GetIngredients()
{
	return m_ingredients;
}

bool Table::IsEmpty()
{
	return m_ingredients.empty();
}

void Table::Clear()
{
	m_ingredients.clear();
}

void Table::PrintIngredients()
{
	for (size_t i = 0; i < m_ingredients.size(); i++)
	{
		std::cout << m_ingredients[i].c_str() << " ";
	}
	std::cout << std::endl;
}

Table::~Table()
{
}
