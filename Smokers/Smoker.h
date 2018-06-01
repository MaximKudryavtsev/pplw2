#pragma once

class Smoker
{
public:
	Smoker(size_t idSmoker, std::string ingredient, std::vector<std::string> &table, std::shared_ptr<Event> wakeMediator, std::shared_ptr<Event> wakeSmoker);

	void SmokeCigerette();
	std::string GetIngredient();
	size_t GetId();
	bool CanSmoke(const std::vector<std::string> &list);
	~Smoker();
private:
	std::string m_ingredient;
	size_t m_idSmoker;
	std::vector<std::string> &m_table;
	std::shared_ptr<Event> m_wakeSmoker;
	std::shared_ptr<Event> m_wakeMediator;
};

