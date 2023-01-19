#include <iostream>
#include <fstream>
#include <string>

using namespace std;


//also i passed inFile by refrence since its more efficient and i got an error when i didnt
bool isLogin(string comb, ifstream &file); //login class to determine if username/password is valid (in file)
int main(){
    
    ofstream myFile;
    ifstream inFile; //created seperate in file in order to do getline 
   // myFile.open("UsPass.txt", ios::app); Trying to open differently depending on weather logging in(read) or registering(write)

    int ans; //where user decision stored

    string username; //where user name is stored
    string password; //where user password is stored

    cout <<"Enter # to select choice"<<endl;
    cout<<"1 Registration"<<endl;
    cout<<"2 Login"<<endl;
    cout<<"3 End"<<endl;

    cin >> ans; //USER ANSWER
    if (ans ==1){
        myFile.open("UsPass.txt", ios::app);
         cout<< "Create a Username"<<endl; //TODO allow user to enter user and pass and store in file
            cin >> username;
            myFile << username;
         cout<< "Create a Password"<<endl;
            cin >> password;
            myFile << password <<endl;
        myFile.close(); //IDK about this, did this cause i may have to reopen it 
                        //with different ios (instead of ios::app)in order to read file
    }
    else if (ans == 2){

        cout<< "Enter your username"<<endl;
            cin >> username;
        cout<<"Enter your password"<<endl;
            cin >> password;
        
        //combine the username and password for easier linear search of doc
        string comb = username + password;
        //cout << comb;

        //look through File to find comb, if not send error
        // I think i should make separate funciton to handle this (cause return statements can break double loop)
        isLogin(comb, inFile);

    }
    else{

        cout<< "Goodbye!"<<endl;
    }
   
    return 0;
}

//i passed myFile in order to access file (i think idk i was getting error)
bool isLogin (string comb, ifstream &myFile){

    myFile.open("UsPass.txt");

    while(!myFile.eof()){
       
        string line; //used to copy a line from file into this var, then compare the line to comb

        while(getline(myFile, line)){

                if(line.find(comb) != std::string::npos){

                cout<< "Login Success! :D"<<endl;

                return true; //return true to end file search and close function

                }
        }


    }

    cout <<"Login Failed! D:"<<endl; //if not found

    return false;

}