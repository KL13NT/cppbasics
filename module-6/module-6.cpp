#include <iostream>
#include <string>

using namespace std;

/************
 * User and gameplay data
 * ************/
int userBalance = 5000;
int userShield = 1000;
int userEnergy = 500;
int userHealth = 1000;
string userName;
string stages[5] = {"Home", "Kids Playground", "No Man's Land", "Central Battleship", "HQ"};
string currentStage = "Home";
//struct user
//struct array enemies
//struct enemy {name, health, power, etc...}
//struct array inventory
//struct array pocket
//struct array map
//struct array battleRecord

/**************
 * Utilities
 * ************/
void clearScreen(){
  //Clears text
  cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
}
void pause(){
  //Pauses the program
  cout << "Press any key to continue...\n";
  cin.get();
}

/*************
 * Resources and data
 * ***********/
void updateUserName(){
  //This function sets the username
  string newName;
  getline(cin, newName);
  userName = newName;
}
void updateUserBalance(int amount){
  //This function adds or subtracts the passed amount parameter to/from userBalance
  userBalance += amount;
}
void updateUserShield(int amount){
  //This function adds or subtracts the passed amount parameter to/from userShield
  userShield += amount;
}
void updateUserHealth(int amount){
  //This function adds or subtracts the passed amount parameter to/from userHealth
  userHealth += amount;
}
void updateUserEnergy(int amount){
  //This function adds or subtracts the passed amount parameter to/from userEnergy
  userEnergy += amount;
}

/****************
 * Main functionality
 * ***************/
bool handleChoice(string expectedInput){
  //returns true if the user input is equal to the passed parameter
  cout << "Please enter your choice\n";
  char choice[100];
  cin.getline(choice, 100);
  if(choice == expectedInput) return true;
}
void stageOne(){
  //Stage one of five in our game
  cout << "You wake up after being unconscious, having taken a hard hit on your head, and realise that your kids are nowhere to be found.\n";
  cout << "There's a note on the wall, pinned with a knife. It might say where you can find your kids!\nAvailable Options: [read note]\n";
  if(handleChoice("read note")){
    cout << "You walk slowly, your body hurting from the attack, the house destroyed and your vision not 100\% clear yet.\nYou approach the knife, pulling it out of the wall and taking hold of the message. \nIt reads: Come to the kids playground. We're waiting for you.\nThe note is not signed.\nYou hurry to the playgrounds...\n";
  }
}
void stageTwo(){
  //Stage two of our five stages
  cout << "You arrive at the playgrounds, only to find 2 enemies standing in front of the entrance, ready to fight you.\n";
}
void changeCurrentStage(int indexOfStage){
  cout << "Loading stage: " << stages[indexOfStage] << endl;
  currentStage = stages[indexOfStage];
  switch(indexOfStage){
    case 0: stageOne(); break;
    case 1: stageTwo(); break;
  }
}

int main(){
  cout << "Welcome to our C++ game! Please enter your name!\n";
  updateUserName();
  cout << "Hello, " << userName << "! A great adventure awaits you!\n";
  cout << "You start with health: " << userHealth << ", balance: " << userBalance << ", and shield: " << userShield << endl;
  pause();
  cout << "Starting game...\n";
  pause();
  clearScreen();
  changeCurrentStage(0);
  // pause();
  // clearScreen();
  // changeCurrentStage(1);
  //More stages and functionality to be implemented later
}