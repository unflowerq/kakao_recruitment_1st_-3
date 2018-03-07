#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#define city cities5
#define array_size sizeof(city)/sizeof(string)

int main()
{
	int cache_size = 0;
	int action_time = 0;
	bool cache_hit = false;
	int reduntdancy_count = 0;		//초반에 같은 경우가 나오는 경우 카운트해서 빼줘야함

	string cities1[] = { "Jeju", "Pangyo", "Seoul", "NewYork", "LA", "Jeju", "Pangyo", "Seoul", "NewYork", "LA" };
	string cities2[] = {"Jeju", "Pangyo", "Seoul", "Jeju", "Pangyo", "Seoul", "Jeju", "Pangyo", "Seoul"};
	string cities3[] = { "Jeju", "Pangyo", "Seoul", "NewYork", "LA", "SanFrancisco", "Seoul", "Rome", "Paris", "Jeju", "NewYork", "Rome" };
	string cities4[] = { "Jeju", "Pangyo", "Seoul", "NewYork", "LA", "SanFrancisco", "Seoul", "Rome", "Paris", "Jeju", "NewYork", "Rome" };
	string cities5[] = { "Jeju", "Pangyo", "NewYork", "newyork" };
	string cities6[] = { "Jeju", "Pangyo", "Seoul", "NewYork", "LA" };
	string cities7[] = { "jeju", "jeju", "jeju", "newyork", "la", "jeju", "la", "rome" };
	string cities8[] = { "jeju", "newyork", "newyork", "newyork", "la", "jeju", "la", "rome" };

	cin >> cache_size;

	action_time = cache_size * 5;

	for (int i = 0; i < array_size; i++)
	{
		transform(city[i].begin(), city[i].end(), city[i].begin(), tolower);
	}

	for (int i = 0; i < cache_size - 1; i++)
	{
		for (int j = i + 1; j < cache_size; j++)
		{
			if (city[i] == city[j])
				reduntdancy_count++;
		}
	}

	if (reduntdancy_count == cache_size && cache_size != 0)
		reduntdancy_count--;
	else if (reduntdancy_count == 0)
		reduntdancy_count = 0;
	else
		reduntdancy_count++;

	for (int i = cache_size; i < array_size; i++)
	{
		for (int j = i - cache_size; j < i; j++)
		{
			if (city[i] == city[j])
			{
				cache_hit = true;
				cache_size++;
				break;
			}
		}
		if (cache_hit)
		{
			action_time += 1;
			cache_hit = false;
		}
		else
			action_time += 5;
	}

	action_time -= (4 * reduntdancy_count);

	cout << action_time << endl;
	
	return 0;
}