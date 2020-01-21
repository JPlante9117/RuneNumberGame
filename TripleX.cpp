#include <iostream>
#include <ctime>

void PrintIntroduction()
{
    std::cout << "\n \n In an abandoned castle are unfathomable treasures. Unforutnately, there are five strange magical runes that seal the door to it.";
    std::cout << "\nYou've been hired as an expert on decrypting runes.\n";
    std::cout << "You've managed to decrypt runes based on two numerical qualities they are related to.\n";
}

void PrintLevelDifficulty(int LevelDiff)
{
    std::cout << "\n * * * * * * * * * * * * * * * * * * * * \n";
    std::cout << "\n R U N E " << LevelDiff << '\n';
}

bool PlayGame(int LevelDiff)
{
    PrintLevelDifficulty(LevelDiff);

    // Declares 3 number code
    const int CodeA = rand() % LevelDiff + LevelDiff;
    const int CodeB = rand() % LevelDiff + LevelDiff;
    const int CodeC = rand() % LevelDiff + LevelDiff;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    // Prints the riddle out in the terminal
    std::cout << "\n+ There are three numbers in the code.";
    std::cout << "\n+ The codes add up to: " << CodeSum;
    std::cout << "\n+ The codes multiply to: " << CodeProduct;
    std::cout << "\nWhat are the three numbers? You may enter them each with ENTER or just separated by SPACES.\n";

    // Player Input
    int PlayerGuessA, PlayerGuessB, PlayerGuessC;

    std::cin >> PlayerGuessA >> PlayerGuessB >> PlayerGuessC;

    int GuessSum = PlayerGuessA + PlayerGuessB + PlayerGuessC;
    int GuessProduct = PlayerGuessA * PlayerGuessB * PlayerGuessC;

    // Win or Loss Message
    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        if (LevelDiff != 5){
            std::cout << "\n That seemed to work! The rune has faded. On to the next rune. \n";
        }
        else
        {
            std::cout << "\n The final rune has faded away!\n";
        }
        
        return true;
    }
    else
    {
        if (LevelDiff == 1){
            std::cout << "\n Hmm, that didn't seem to do anything. Maybe try a different combination.\n";
        }
        else
        {
            std::cout << "\n Oh no, that wasn't it! It seems that your error caused the rune to shift! It seems different!\n";
        }
        return false;
    }
}

void PrintASCII()
{
    std::cout << '\n' << R"(               T~~
               |
              /"\
      T~~     |'| T~~
  T~~ |    T~ WWWW|
  |  /"\   |  |  |/\T~~
 /"\ WWW  /"\ |' |WW|
WWWWW/\| /   \|'/\|/"\
|   /__\/]WWW[\/__\WWWW
|"  WWWW'|I_I|'WWWW'  |
|   |' |/  -  \|' |'  |
|'  |  |LI=H=LI|' |   |
|   |' | |[_]| |  |'  |
|   |  |_|###|_|  |   |
'---'--'-/___\-'--'---'

PRESS ENTER TO CONTINUE)" << '\n';
    std::cin.ignore();
}

void PrintTreasure()
{
    std::cout << R"(
 _____.______.______._____
 \`\                   /'/
  \ |                 | /
   >|___,____,____,___|<
  /d$$$P ,ssssssssssss. \
 /d$$$P ,d$$$$$$$$$$$$$b \
<=====w======w======w=====>
 \ \____> \_____/ <____/ /
  \_____________________/ 
    )";
}

int main()
{
    PrintASCII();
    PrintIntroduction();

    srand(time(NULL));

    int LevelDifficulty = 1;
    int const MaxDifficulty = 5;
    while (LevelDifficulty <= MaxDifficulty)
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear();
        std::cin.ignore();

        if (bLevelComplete)
        {
            ++LevelDifficulty;
        }
        

    }

    PrintTreasure();
    std::cout << "\n You've solved the final rune and the door opens! Inside is a large treasure chest filled with gold! You can take as much as you wish.";
    std::cout << "\n \n Congratulations on completing the game. Press ENTER to exit the program.";
    std::cin.ignore();
    return 0;
}