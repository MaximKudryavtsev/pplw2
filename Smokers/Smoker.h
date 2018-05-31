#pragma once

class Smoker
{
public:
	Smoker(size_t idSmoker, Ingredient ingredient);
	void TwistCigarette();
	void SmokeCigerette();
	void SetIngredient(Ingredient ingrdedient);
	Ingredient GetIngredient();
	size_t GetId();
	bool CanSmoke(ListOfIngredients list);
	~Smoker();
private:
	Ingredient m_ingredient;
	size_t m_idSmoker;
	std::shared_ptr<Event> m_wakeSmoker;
	std::shared_ptr<Event> m_wakeMediator;
};

