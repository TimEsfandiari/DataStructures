#include <iostream>
#include <fstream>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>

#include "Player.h"
#include "Tag.h"
#include "Team.h"

using namespace std;

int main(int argc, char *argv[])
{
    /*** input/output streams ***/
    ifstream inputA (argv[1]);
    ifstream inputB (argv[2]);
    ifstream matchFile (argv[3]);
    ofstream outputFile (argv[4]);

    char teamName[64];
    int rosterSize = 0;


    Team* teamA = new Team();

    //TeamA Inputs
    if(inputA.is_open())
    {
        //setting the name of Team A
        inputA.getline(teamName, 64);
        teamA->setTeamName(teamName);

        //setting the roster size of Team A
        inputA >> rosterSize;
        teamA->setRosterSize(rosterSize);

        //preparing variables for teamA->fillRoster()
        int* IDs_A = new int[teamA->getRosterSize()];
        char** names_A = new char*[teamA->getRosterSize()];


        for (int i = 0; i < teamA->getRosterSize(); ++i)
        {
            names_A[i] = new char[64];
        }

        //self explanatory
        teamA->fillRoster(teamA->getRosterSize(), IDs_A, names_A, inputA);



    }

    Team* teamB = new Team();

    //TeamB Inputs
    if(inputB.is_open())
    {
        //setting the name of Team B
        inputB.getline(teamName, 64);
        teamB->setTeamName(teamName);

        //setting the roster size of Team B
        inputB >> rosterSize;
        teamB->setRosterSize(rosterSize);

        //preparing variables for teamA->fillRoster()
        int* IDs_B = new int[teamA->getRosterSize()];
        char** names_B = new char*[teamA->getRosterSize()];

        for (int i = 0; i < teamB->getRosterSize(); ++i)
        {
            names_B[i] = new char[64];
        }

        teamB->fillRoster(teamB->getRosterSize(), IDs_B, names_B, inputB);
    }

    //Working on Match File
    if(matchFile.is_open())
    {
        int numTags;

        int tagger;
        int target;
        int time;
        int hitBox;

        matchFile >> numTags;

        //created Tag objects within the players in order for each Tag to be
        //attributed on a player and easy to link up later on. As you go down
        //you'll notice taggingPlayer and targetPlayer that were created for this case.
        //Jarrett helped me with this.
        for(int i = 0; i < numTags; i++)
        {
            matchFile >> tagger;
            matchFile >> target;
            matchFile >> time;
            matchFile >> hitBox;

            if (teamA->isPlayerInTeam(tagger))
            {
                const Player* taggingPlayer = teamA->getPlayerByID(tagger);
                const Player* targetPlayer = teamB->getPlayerByID(target);

                teamA->addTagToPlayer(new Tag(taggingPlayer, targetPlayer, time, hitBox), tagger);
            }

            else
            {
                const Player* taggingPlayer = teamB->getPlayerByID(tagger);
                const Player* targetPlayer = teamA->getPlayerByID(target);

                teamB->addTagToPlayer(new Tag(taggingPlayer, targetPlayer, time, hitBox), tagger);
            }
        }
    }



    //Working the different verbosities. Fairly self explanatory.
    if(outputFile.is_open())
    {

        if(strcmp(argv[5],"vlow") == 0)
        {
                outputFile << teamA->getTeamName() << ": ";
                int totalA = 0;

                totalA = teamA->getTotalScore();

                outputFile << totalA << " points." << endl;

                outputFile << teamB->getTeamName() << ": ";
                int totalB = 0;

                totalB = teamB->getTotalScore();

                outputFile << totalB << " points." << endl;
        }

        if(strcmp(argv[5],"vmed") == 0)
        {
            outputFile << teamA->getTeamName() << ": " << endl;
            teamA->printRoster(outputFile);
            outputFile << teamB->getTeamName() << ": " << endl;
            teamB->printRoster(outputFile);


            outputFile << "Best score from the " << teamA->getTeamName() << ": ";
            int totalA = 0;

            totalA = teamA->getTotalScore();

            outputFile << totalA << " points." << endl;

            outputFile << teamB->getTeamName() << ": ";
            int totalB = 0;

            totalB = teamB->getTotalScore();

            outputFile << totalB << " points." << endl;

            if(teamA->getTotalScore() > teamB->getTotalScore())
                outputFile << "Overall Winners: " << teamA->getTeamName() << endl;
            else
                outputFile << "Overall Winners: " << teamB->getTeamName() << endl;
        }


        if(strcmp(argv[5],"vhigh") == 0)
        {
            outputFile << teamA->getTeamName() << ": " << endl;
            teamA->printRoster(outputFile);
            outputFile << teamB->getTeamName() << ": " << endl;
            teamB->printRoster(outputFile);


            outputFile << "Best score from the " << teamA->getTeamName() << ": ";
            int totalA = 0;

            totalA = teamA->getTotalScore();

            outputFile << totalA << " points." << endl;

            outputFile << teamB->getTeamName() << ": ";
            int totalB = 0;

            totalB = teamB->getTotalScore();

            outputFile << totalB << " points." << endl;

            if(teamA->getTotalScore() > teamB->getTotalScore())
                outputFile << "Overall Winners: " << teamA->getTeamName() << endl;
            else
                outputFile << "Overall Winners: " << teamB->getTeamName() << endl;
        }
    }
    return 0;
}

