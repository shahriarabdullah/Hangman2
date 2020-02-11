//Hangman v2
//Abdullah Shahriar
//10.02.2020

#include <iostream>
#include <fstream>
#include <string.h>
#include <sstream>
#include <vector>
#include <time.h>
#include <algorithm>


using namespace std;

//Function for counting number of correctly guessed letter
int count(string s) 
{ 
    
    int result = 0; 
    for (int i=0;i<s.length();i++) 
  
        if (s[i] == '0') 
            result++; 
  
    return result; 
} 


//Function for replacing all occurence of correctly guessed letter
void findAndReplaceAll(string & data, string toSearch, string replaceStr)
{
	// Get the first occurrence
	size_t pos = data.find(toSearch);
 
	// Repeat till end is reached
	while( pos != string::npos)
	{
		// Replace this occurrence of Sub String
		data.replace(pos, toSearch.size(), replaceStr);
		// Get the next occurrence from the current position
		pos =data.find(toSearch, pos + replaceStr.size());
	}
}

//Function for drawing hangman board
void show_file(string filename){
ifstream inFile;
    inFile.open(filename); //open the input file
    stringstream strStream;
    strStream << inFile.rdbuf(); //read the file
    string str = strStream.str(); //str holds the content of the file
    cout << str << "\n\n\n"; 
}


int main()
{

//Printing the Hangman title
show_file("res\\title.txt"); 
cout << "\t\t\t\tAbdullah Shahriar\n\t\t\t\t2020\n\n\n";
//end

int game_status=0,len;
string guess;

vector<string> w;

//Getting each line of the file in a vector
string line;    
ifstream fin("res\\words.txt");
while(getline(fin,line)){
    w.push_back(line);
}
//end


srand(time(0)); 
int word_index = (rand() % (w.size())); 


//string words[]={"apple","bucket","random"} ;
//string word=words[0];
string word=w[word_index];
string word2=word;

len=word.length();

transform(word.begin(), word.end(), word.begin(), ::tolower);


//Printing underscore for each letter
for(int i=0;i<len;i++){
    cout << "____" << " ";
}
//end

while(game_status<6){ //Loop runs until the full hangman is drawn

    cout << "\n\nGuess a letter: ";
    cin>>guess;
    

    if (word.find(guess) != string::npos) { //Checking if the word contains our guessed letter
    
findAndReplaceAll(word, guess, "0"); //If a letter is correctly guessed, all occurence of the letter in the word is replaced

//Checking if the word is completely guessed
if(count(word)==len){ 
    cout << endl << word2 << endl;
    cout << "\nCongratulation! Either you are lucky or really very good at vocabulary. :) " << endl;
    game_status=7; //Breaks the loop
}
//end

} else {
    //If a wrong letter is guessed, hangman is drawn corresponding to game_status
    game_status++;

    switch(game_status){
        case 1:
        show_file("res\\1.txt");
        break;
        case 2:
        show_file("res\\2.txt");
        break;
        case 3:
        show_file("res\\3.txt");
        break;
        case 4:
        show_file("res\\4.txt");
        break;
        case 5:
        show_file("res\\5.txt");
        break;
        case 6:
        show_file("res\\6.txt"); //Aw..this means you've lost the game
        cout << "\nOops! You made hangman hung. :( \n";
        cout << "The word was \"" << word2 <<"\"" <<endl;
        
        break;
    }
    
    
        }
//Checking game status
if(game_status<6)
{
for(int i=0;i<len;i++){
        if(word.at(i)!='0'){
           cout << "____" << " ";
        } else {
            
            cout << word2.at(i) << "  ";

    
}
}
}
//end



 
}

system("PAUSE");

}