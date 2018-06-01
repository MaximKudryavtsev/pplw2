#pragma once


class Mediator
{
public:
	Mediator(Table &table, std::shared_ptr<Event> wakeMediator, std::shared_ptr<Event> wakeSmoker);
	std::vector<std::string> &GetIngredients();
	void Work();
	~Mediator();
private:
	std::vector<std::string> m_mediatorIngredients;
	std::shared_ptr<Event> m_wakeSmoker;
	std::shared_ptr<Event> m_wakeMediator;
	Table& m_table;
	void Shuffle();
};

