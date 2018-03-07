#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

#define city cities8
#define array_size sizeof(city)/sizeof(string)

int main()
{
	int cache_size = 0;
	int action_time = 0;
	int cache_break_index = 0;

	vector<string> cache;

	string cities1[] = { "Jeju", "Pangyo", "Seoul", "NewYork", "LA", "Jeju", "Pangyo", "Seoul", "NewYork", "LA" };
	string cities2[] = { "Jeju", "Pangyo", "Seoul", "Jeju", "Pangyo", "Seoul", "Jeju", "Pangyo", "Seoul" };
	string cities3[] = { "Jeju", "Pangyo", "Seoul", "NewYork", "LA", "SanFrancisco", "Seoul", "Rome", "Paris", "Jeju", "NewYork", "Rome" };
	string cities4[] = { "Jeju", "Pangyo", "Seoul", "NewYork", "LA", "SanFrancisco", "Seoul", "Rome", "Paris", "Jeju", "NewYork", "Rome" };
	string cities5[] = { "Jeju", "Pangyo", "NewYork", "newyork" };
	string cities6[] = { "Jeju", "Pangyo", "Seoul", "NewYork", "LA" };
	string cities7[] = { "jeju", "jeju", "jeju", "newyork", "la", "jeju", "la", "rome" };
	string cities8[] = { "jeju", "newyork", "newyork", "newyork", "la", "jeju", "la", "rome" };

	cin >> cache_size;

	for (int i = 0; i < array_size; i++)
	{
		transform(city[i].begin(), city[i].end(), city[i].begin(), tolower);
	}

	if (cache_size != 0)
	{
		cache.push_back(city[0]);
		action_time += 5;
		cache_break_index++;
	}

	bool cache_hit = true;

	while (cache.size() != cache_size)
	{
		for (int i = 0; i < cache.size(); i++)
		{
			if (cache[i] == city[cache_break_index])
			{
				action_time += 1;
				cache_break_index++;
				cache_hit = false;
				break;
			}
		}

		if (cache_hit)
		{
			cache.push_back(city[cache_break_index]);
			cache_break_index++;
			action_time += 5;
		}

		cache_hit = true;
	}

	cache_hit = true;

	for (int i = cache_break_index; i < array_size; i++)
	{
		for (int j = 0; j < cache.size(); j++)
		{
			if (cache[j] == city[i])
			{
				action_time += 1;
				cache_hit = false;
				break;
			}
		}

		if (cache_hit)
		{
			if (cache_size != 0)
			{
				cache.erase(cache.begin() + 0);
				cache.push_back(city[i]);
			}
			action_time += 5;
		}

		cache_hit = true;
	}

	cout << action_time << endl;

	return 0;
}