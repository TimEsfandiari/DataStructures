#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

#include "Match.h"
#include "Player.h"
#include "Tag.h"
#include "Team.h"

using namespace std;

int main(int argc, char *argv[])
{
    /*** input/output streams ***/
    ifstream inputA (argv[1]);
    ifstream inputB (argv[2]);
    ifstream match (argv[3]);
    ofstream output (argv[4]);

    string line;
    int i;
    int count;

    Team* teamA = new Team();

    if(inputA.is_open())
    {
        getline(inputA, line);
        teamA->setTeamName(line);

        inputA >> i;
        teamA->setRosterSize(i);
        teamA->getRosterSize();

        count = 0;
        while (count < teamA->getRosterSize() && !inputA.eof())
        {
            inputA >> i;
            getline(inputA, line);

            teamA->addPlayer(i, line);
        }


    }


    return 0;
}

