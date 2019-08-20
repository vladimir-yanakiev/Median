#pragma once
#ifndef MEDIAN
#define MEDIAN

#include <queue>
#include <functional>

class MedianStruct
{
public:
	MedianStruct();
	~MedianStruct();

	using T = int;
	void Add(T element);
	double GetMedian();

private:
	std::priority_queue<T> left;
	std::priority_queue<T, std::vector<int>, std::greater<T>> right;
};

#endif
