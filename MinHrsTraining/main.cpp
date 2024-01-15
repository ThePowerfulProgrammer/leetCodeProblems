#include <iostream>

using namespace std;


/*
Problem Analysis:
    Given 2 integers: initialEnergy representing my starting Energy
    &                 initialExperience representing my starting Experience

    Given 2 arrays: energy representing the energy of the ith opponent of length n
    &               experience representing the experience of the ith opponent of length n

    When I face an opponent it is required that I have a greater energy and experience than said
    opponent.

    To acheive this I am required to train.
    For every hour of training I can either increase my energy or my experience.

    I need to train for the least number of hours.

    BUT defeating an opponent increasing my experience by my opponent experience
    and decreases my energy by my opponent energy.

Program design:
    Concepts considered: Greedy, sliding window

    I traverse the energy array:
    Determine if initialEnergy > energy[i] && initialExperience > experience[i]:
        if true:
            initialEnergy -= energy[i]
            initialExperience += experience[i]
        else if (initialEnergy < energy[i]):

            hrsTrainig += 1
            initialEnergy += 1
            loop - 1
        else if (initalExp < exp[i]):
            hrsTraining += 1
            initialExp += 1
            loop - 1

*/

class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience)
    {
        int hrsOfTraining = 0;


        for (int i=0;i<energy.size();i++)
        {
            if (initialEnergy <= energy[i])
                {
                    int difference = energy[i] - initialEnergy;
                    initialEnergy = initialEnergy + difference + 1;
                    hrsOfTraining += (difference + 1);
                }
            if (initialExperience <= experience[i])
                {
                    int difference = experience[i] - initialExperience;
                    initialExperience = initialExperience + difference + 1;
                    hrsOfTraining += (difference + 1);
                }
            if (initialEnergy > energy[i] && initialExperience > experience[i])
                {
                    initialEnergy -= energy[i];
                    initialExperience += experience[i];
                }

        }

        return hrsOfTraining;

    }
};

int main()
{
    cout << "Min Hrs of Training Required to win a competition!" << endl;
    return 0;
}
