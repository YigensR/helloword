#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

// Funktioner
string getComputerChoice() {
    int randNum = rand() % 3; // Genererar ett tal mellan 0 och 2
    if (randNum == 0) return "sten";
    if (randNum == 1) return "sax";
    return "påse";
}

void showStatistics(int userScore, int computerScore) {
    cout << "Aktuell ställning: Du: " << userScore << " - Dator: " << computerScore << endl;
    std::cout << "******************************\n";
}

void playRound(int &userScore, int &computerScore) {
    string userChoice;
    cout << "Välj 'sten', 'sax' eller 'påse': ";
    cin >> userChoice;
    std::cout << "******************************\n";

    string computerChoice = getComputerChoice();
    cout << "Datorn valde: " << computerChoice << endl;
    std::cout << "=====================\n";

    if (userChoice == computerChoice) {
        cout << "Det blev oavgjort!" << endl;
    } else if ((userChoice == "sten" && computerChoice == "sax") ||
               (userChoice == "sax" && computerChoice == "påse") ||
               (userChoice == "påse" && computerChoice == "sten")) {
        cout << "Du vann!" << endl;
        std::cout << "=====================\n";
        userScore++;
    } else {
        cout << "Datorn vann!" << endl;
        std::cout << "=====================\n";
        computerScore++;
    }
}

int main() {
    srand(static_cast<unsigned int>(time(0))); // Initierar slumpgeneratorn
    int userScore = 0;
    int computerScore = 0;
    const int maxScore = 3;
    int choice;

    do {
        cout << "\n======Välkommen till spelan!======\n";
        cout << "\n******* Sten, Sax, Påse **********\n";
        cout << "1. Starta nytt spel\n";
        cout << "2. Visa statistik\n";
        cout << "3. Avsluta spelet\n";
        cout << "Välj ett alternativ: ";
        cin >> choice;
        std::cout << "******************************\n";
       

        switch (choice) {
            case 1: // Starta nytt spel
                userScore = 0;
                computerScore = 0;
                while (userScore < maxScore && computerScore < maxScore) {
                    playRound(userScore, computerScore);
                    showStatistics(userScore, computerScore);
                }
                if (userScore == maxScore) {
                    cout << "Grattis! Du vann spelet!" << endl;
                    std::cout << "=====================\n";
                } else {
                    cout << "Datorn vann spelet! Bättre lycka nästa gång!" << endl;
                    std::cout << "******************************\n";
                }
                break;
            case 2: // Visa statistik
                showStatistics(userScore, computerScore);
                break;
            case 3: // Avsluta spelet
                cout << "Avslutar spelet. Tack för att du spelade!" << endl;
                break;
            default:
                cout << "Ogiltigt val, försök igen!" << endl;
        }
    } while (choice != 3);
    std::cout << "======AVslutar spelet======\n";
    return 0;
}
