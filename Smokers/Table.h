#pragma once
class Table
{
public:
	Table();
	void SetIngredients(std::vector<std::string> ingredients);
	std::vector<std::string> GetIngredients();
	bool IsEmpty();
	void PrintIngredients();
	void Clear();
	~Table();
private:
	std::vector<std::string> m_ingredients;
	std::vector<std::string> m_list = { "tobacco", "paper", "matches" };
};

