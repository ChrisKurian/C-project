// a4.cpp
//CMPT 130 
// cvattath@sfu.ca
//Chris Vattathichirayil 
// student number: 301328090 
// References: Toby donaldson lecture material and notes for all functions and int main.
//Jack Thomas for int main and Dan Amarasinghe for int main, checkempty and loopcount.


#include <fstream> 
#include <string> 
#include <iostream> 

using namespace std; 




//number of words function adds 1 to number of words each time a new word is read. 
void num_words(string filename){
	ifstream wordinput(filename);
	int numberofwords = 0; 
	string word; 
	// >> automatically reads in word by word and skips over blank spaces.
	while(wordinput >> word){
		++numberofwords;
	}
	cout << filename << " has " << numberofwords << " words\n"; 
}

//number of lines function uses the getline fuction to read line by line 
void num_lines(string filename){ 
	ifstream lineinput(filename); 
		int linecount = 0; 
		string line;
	//adds one to number of lines until end of file. found in chapter 6 notes I/O section
		while(!lineinput.eof()){
			getline(lineinput,line);
			++linecount; 
		}
		cout << filename << " has " << linecount-1 << " lines\n";
}

//Uses .get(c) to read the next character in the fin stream and adds 1 to character count each time
void char_count(string filename){
	ifstream characterinput(filename); 
	char c; 
	int char_count = 0; 
	while (!characterinput.eof()){
		characterinput.get(c);
		++char_count; 
	
	}
	cout << filename << " has " << char_count-1 << " characters \n" ;
}


// count the number of lines that need to be read to be used in the int main loop.
//We are doing this because num_lines is a void function and we need a return int
int numberofloops(string file){
	    ifstream fin(file);

    if (fin.fail()) {
        cout << "Sorry, couldnt open the file " << file << "\n";
        return 0;
    }

    int numberofloopsneeded = 0;
    char c = fin.get();  
                         
    while (!fin.eof()) { 
       
        if (c == '\n'){
        ++numberofloopsneeded;
        }

        c = fin.get();
    }
    return numberofloopsneeded;
}

//modification of Toby Donaldson's character count program shown in chapter 6 notes.
int checkempty(string file){
	ifstream fin(file);
	int character_count = 0;

	//if the file is not in same directory or can't be opened for any reason there is a helpful error message.
	//and returns to zero thereby ending the program because it program only continues if return value is 1.
	if (fin.fail()) {
    cout << "Sorry, could not open file " << file << "\n";
     return 0;
    }
  	
    fin.get();  // at least one character needs to be read for fin.eof to work.
    while (!fin.eof()) {
        ++character_count;
        
        fin.get();
    }
    
    if(character_count == 0){
    	return 0;
    }
    //this will be the only situation int main will carry on with the program.
    else{
    	return 1;
    }

}



int main() {
	//initialize an integer for the number of times the loop has been executed.
	int numberofloopscompleted = 0;

	string commandfile = "commands.txt";
	
	// Takes the commandfile string and inputs into checkempty function 
	// If commandfile is not empty the loop which reads commandfile and executes it is initiated.
	if (checkempty(commandfile) == 1){
		
		ifstream fin(commandfile);
		//create two strings, one for the first word read in (command) and one for the second word (filename)
		string command;
		string filename;
		
		int numberofloopsneeded = numberofloops(commandfile);
		
	
		while (numberofloopscompleted < numberofloopsneeded) {
			char c = fin.get();	
			//keeps reading in next character and does nothing until its not a blank space character.
			while(c == ' '){
			c = fin.get();	
			}	
			//once there is a non-blankspace character, each character is added to the string command until.
			//there is a character that IS a blank space.
			while(c != ' '){
				command += c;
				c = fin.get();
				
			}
			//keeps reading in next character and does nothing until its not a blank space character.
			while(c == ' '){
				c = fin.get();	
				
			}
			// If the \n character is read after the first word, that means there was no filename 
			// there is supposed to be 2 words per line
			if (c == '\n'){
				cout << "Error: No filename";
			}

			//Makes the next word just like how we made the first word.
			while (c != '\n'){
				filename += c;
				c = fin.get();
				
			}
			// Executes commands based on what the string is for the first and second word.
			if(command == "num_lines"){
				num_lines(filename);
			}

			else if(command == "num_chars"){
				char_count(filename);
			}

			else if(command == "num_words"){
				num_words(filename);
			}
			else{
				cout << "Sorry, could not recognize the command \"" << command << "\" \n";
				
			}
	//go to the next line and reset the command and filename string. 	
	numberofloopscompleted++;
	command = "";
	filename = "";
	}
	}

	else{
		cout << "Sorry, the file is empty. \n";
	}

}




