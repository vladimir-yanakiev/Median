#include "MedianStruct.h"
#include <iostream>


MedianStruct::MedianStruct()
{
}


MedianStruct::~MedianStruct()
{
}


void MedianStruct::Add(T element)
{
	if ((left.size()==0) || (left.top() > element))
	{
		left.push(element);
	}
	else
	{
		right.push(element);
	}

	if (int(left.size()) - int(right.size()) > 1)
	{
		auto temp = left.top();
		left.pop();
		right.push(temp);
	}

	if (int(right.size()) - int(left.size()) > 1)
	{
		auto temp = right.top();
		right.pop();
		left.push(temp);
	}

	//std::cout << "left" << left.top() << " " << left.size() << std::endl;
	//if (right.size())
	//	std::cout << "right" << right.top() << " " << right.size() << std::endl;

}

double MedianStruct::GetMedian()
{
	auto leftSize = left.size();
	auto rightSize = right.size();

	if ((leftSize > 0) || (rightSize > 0))
	{
		if (leftSize > rightSize)
		{
			return left.top();
		}

		if (leftSize < rightSize)
		{
			return right.top();
		}

		return ((left.top() + right.top()) / 2);
	}

	return 0;
}