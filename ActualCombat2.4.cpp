#include <iostream>
#include <vector>
#include <string>
using namespace std;
int BlockNum = 0;
vector<int> Blocks[25];

void FindBLock(int blocknum, int &blockpile, int &height)
{
    for (blockpile = 0; blockpile < BlockNum; blockpile++)
    {
        for (height = 0; height < Blocks[blockpile].size(); height++)
        {
            if (Blocks[blockpile][height] == blocknum)
                return;
        }
    }
}

void Homing(int blockpile, int height)
{
    int i;
    int temp;
    for (i = height + 1; i < Blocks[blockpile].size(); i++)
    {
        temp = Blocks[blockpile][i];
        Blocks[temp].push_back(temp);
    }
    Blocks[blockpile].resize(height + 1);
}

void moveAoverB(int blockpileA, int blockpileB, int heightA)
{
    int i;
    for (i = heightA; i < Blocks[blockpileA].size(); i++)
    {
        Blocks[blockpileB].push_back(Blocks[blockpileA][i]);
    }
    Blocks[blockpileA].resize(heightA);
}
int main()
{
    int i = 0;
    string man1, man2;
    int block1, block2;
    cin >> BlockNum;
    int pile1, pile2, height1, height2;
    while (i < BlockNum)
    {
        Blocks[i].push_back(i);
        i++;
    }
    i = 0;
    while (true)
    {
        cin >> man1;
        if (man1 != "move" && man1 != "pile")
            break;
        cin >> block1 >> man2 >> block2;
        FindBLock(block1, pile1, height1);
        FindBLock(block2, pile2, height2);
        if (pile1 == pile2)
            continue;
        if (man1 == "move")
        {

            Homing(pile1, height1);
        }
        if (man2 == "onto")
        {

            Homing(pile2, height2);
        }
        moveAoverB(pile1, pile2, height1);
    }
    for (i = 0; i < BlockNum; i++)
    {
        cout << i << ": ";
        for (int j = 0; j < Blocks[i].size(); j++)
        {
            cout << Blocks[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}
