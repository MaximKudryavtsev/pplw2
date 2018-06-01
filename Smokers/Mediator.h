#pragma once


class Mediator
{
public:
	Mediator(std::vector<std::string> &table, std::shared_ptr<Event> wakeMediator, std::shared_ptr<Event> wakeSmoker);
	std::vector<std::string> &GetIngredients();
	void Work();
	~Mediator();
private:
	std::vector<std::string> m_mediatorIngredients;
	std::shared_ptr<Event> m_wakeSmoker;
	std::shared_ptr<Event> m_wakeMediator;
	std::vector<std::string> &m_table;
	void Shuffle();
};

