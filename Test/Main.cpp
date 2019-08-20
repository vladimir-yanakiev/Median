#include "MedianStruct.h"
#include <iostream>

void main()
{
	int passedtests = 0;
	int failtests = 0;
	auto testCond = [&passedtests, &failtests](bool cond)
	{
		if (cond)
		{
			passedtests++;
		}
		else
		{
			failtests++;
			std::cout << "Error" << std::endl;
		}
	};

	auto testReport = [&passedtests, &failtests]()
	{
		std::cout << "Tests failed:" << failtests << std::endl;
		std::cout << "Tests passed:" << passedtests << std::endl;
	};



	MedianStruct medS;

	testCond(medS.GetMedian() == 0.0);


	medS.Add(1);
	testCond(medS.GetMedian() == 1.0);

	medS.Add(101);
	testCond(medS.GetMedian() == 51.0);

	for (int i = 0; i < 100; i++)
	{
		medS.Add(10);
		testCond(medS.GetMedian() == 10.0);
	}

	
	MedianStruct medS2;

	for (int i = 0; i < 10; i++)
	{
		medS2.Add(30);
		testCond(medS2.GetMedian() == 30.0);
	}

	for (int i = 0; i < 20; i++)
	{
		medS2.Add(40);
		if (i < 9)
		{
			testCond(medS2.GetMedian() == 30.0);
		}
		else if (i < 10)
		{
			testCond(medS2.GetMedian() == 35.0);
		}
		else
		{
			testCond(medS2.GetMedian() == 40.0);
		}
	}

	testReport();

}
