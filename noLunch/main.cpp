#include <iostream>
#include <vector>
using namespace std;

/**
    Understand the problem: Given 2 vector, students (reflects a students sandwich preference) && sandwiches (type of sandwich).
    Write a program that returns the length of students after determining how many students cannot eat.

    The problem requirements:



*/



class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches)
    {
        int cycle = students.size();
        int studentNumber = 0;
        int sandwichesNumber = 0;

        while (cycle > 0 || students.size() > 0)
            {
                // student can eat
                if (students[studentNumber] == sandwiches[sandwichesNumber])
                    {
                        students.erase(students.begin()); // student has food
                        sandwiches.erase(sandwiches.begin()); // food is eaten
                        cycle = students.size(); // restart the cycle
                    }
                else if (students[studentNumber] != sandwiches[sandwichesNumber]) // student cannot eat
                    {
                        int student = students[0]; // refer to student
                        cout << "student: " << student << endl;
                        students.erase(students.begin()); // remove student
                        students.push_back(student); // student goes to back of queue
                        cycle -= 1;
                    }
            }

        return students.size();
    }


};

int main()
{
    cout << "Students cannot eat!!!" << endl;

    Solution s1;
    vector<int> students = {1,1,1,0,0,1};
    vector<int> sandwiches = {1,0,0,0,1,1};
    cout << s1.countStudents(students,sandwiches) << endl;


    return 0;
}
