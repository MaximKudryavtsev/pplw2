// Smokers.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"


int main()
{
	Mediator mediator;
	ListOfIngredients ing = mediator.GetIngredients();
	mediator.PrintIngredients();
	std::random_device rd;
	std::mt19937 randMT(rd());
	ListOfIngredients i = { "paper", "matches", "tobacco" };
	std::shuffle(i.begin(), i.end(), randMT);
	Smoker smoker1(1, i.back());
	i.pop_back();
	Smoker smoker2(2, i.back());
	i.pop_back();
	Smoker smoker3(3, i.back());

	std::cout << "smoker1's ingredients: " << smoker1.GetIngredient() << std::endl;
	std::cout << "smoker2's ingredients: " << smoker2.GetIngredient() << std::endl;
	std::cout << "smoker3's ingredients: " << smoker3.GetIngredient() << std::endl;
	std::cout << std::endl;

	if (smoker1.CanSmoke(ing))
	{
		smoker1.TwistCigarette();
		smoker1.SmokeCigerette();
	}
	else if (smoker2.CanSmoke(ing))
	{
		smoker2.TwistCigarette();
		smoker2.SmokeCigerette();
	}
	else if (smoker3.CanSmoke(ing))
	{
		smoker3.TwistCigarette();
		smoker3.SmokeCigerette();
	}
	std::cout << "_____________________________" << std::endl;
	
    return 0;
}

