#pragma once


class Mediator
{
public:
	Mediator();
	ListOfIngredients GetIngredients();
	void PrintIngredients();
	~Mediator();
private:
	ListOfIngredients m_mediatorIngredients;
	std::shared_ptr<Event> m_wakeSmoker;
	std::shared_ptr<Event> m_wakeMediator;
};

