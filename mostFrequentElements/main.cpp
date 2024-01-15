#include <iostream>
#include <string>
#include <unordered_map>
#include <map>
#include <vector>
/*
Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.
Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
*/

/*
vector<int> topKFrequent(vector<int>& nums, int k) {

}
*/

void firstIteration()
{
 std::unordered_map<std::string,int> dictionary;
    int numbers[] = {1,1,1,1,1,2,3,4,4,4,5};
    int length = sizeof(numbers) / sizeof(numbers[0]);


    for (int i=0;i<length;i++)
        {

            std::string key = std::to_string(numbers[i]);
            auto it = dictionary.find(key);

            if (it != dictionary.end())
                {
                    dictionary[key] = dictionary[key] + 1;
                }
            else
                {
                    dictionary[key] = 1;
                    std::cout << key << "<- Key " << std::endl;
                }


        }

    int first = dictionary.begin()->second;
    std::string firstKey = dictionary.begin()->first;


    std::cout << "FKey:  "<< firstKey << " First: " << first << std::endl;
    int Second;
    std::string SecondKey;

    // set first and second iterators of dictionary
    if (dictionary.size() >= 2)
        {
            int counter = 0;
            for (auto& it: dictionary)
                {
                    if (counter == 1)
                        {
                            Second = it.second;
                            SecondKey = it.first;
                        }
                    if (counter ==2) { break ;}
                    counter +=1;
                }
        }

    std::cout << "SKey:  "<< SecondKey << " Second: " << Second << std::endl;

    for (const auto& current : dictionary) {

        if (current.second > first)
            {
                first = current.second;
                firstKey = current.first;
            }

        if ( (current.second > Second) )
            {
                std::cout << "Change: " << current.second << std::endl;
                Second = current.second;
                SecondKey = current.first;
                std::cout << "SecondKey: " << SecondKey << " Value: "<< Second << std::endl;
            }
        std::cout << "Key: "<< current.first << " Value: "<< current.second << std::endl;

    }
    // arrage dictionary from lowest to highest
    std::cout << "Highest key value pair " << "Key: " << firstKey << " value: " << first << std::endl;
    std::cout << "SecondHighest key value pair " << "Key: " << SecondKey << " value: " << Second << std::endl;

}

void secondIteration()
{
    std::map<int,int> dictionary;
    std::vector<int> Vector = {1,1,1,3,3,5};
    for (const auto& num: Vector)
        {
            ++dictionary[num];
        }



    // find, add and elimate highest value
    std::vector<int> keys;
    int k = 2;

    for (int i=0;i<k;i++)
        {
            int highestKey = dictionary.begin()->first;
            int highest = dictionary.begin()->second;
            for (const auto& [k,v]: dictionary)
                {
                    if (v > highest)
                        {
                            highest = v;
                            highestKey = k;
                        }
                }
            keys.push_back(highestKey);
            dictionary.erase(highestKey);
        }

    for (const auto& [key,value]: dictionary)
        {
            std::cout << "Key: " << key << " Value: " << value << std::endl;
        }

    for (int j=0;j<keys.size();j++)
        {
            std::cout << keys[j] << std::endl;
        }
}

std::vector<int> topKFrequent(const std::vector<int>& nums, int k)
{
    std::map<int,int> dictionary;
    //2,2,3
    for (const auto& n: nums)
        {
            ++dictionary[n];

        }

    std::vector<int> keys;

    for (int i=0;i<k;i++)
        {
            int highestKey = dictionary.begin()->first;
            int highest = dictionary.begin()->second;
            for (const auto& [k,v]: dictionary)
                {
                    if (v > highest)
                        {
                            highest = v;
                            highestKey = k;
                        }
                }
            keys.push_back(highestKey);
            dictionary.erase(highestKey);
        }
    return keys;
}


int main()
{
   std::vector<int> mostFrequent = topKFrequent({1,1,1,2,2,3}, 2);
    for (int elem: mostFrequent)
        {
            std::cout << elem << std::endl;
        }

    return 0;
}
