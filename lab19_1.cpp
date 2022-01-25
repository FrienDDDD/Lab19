#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<cstdlib>
#include<cstring>
using namespace std;

char score2grade(int score){
    if(score >= 80) return 'A';
    if(score >= 70) return 'B';
    if(score >= 60) return 'C';
    if(score >= 50) return 'D';
    else return 'F';
}

string toUpperStr(string x){
    string y = x;
    for(unsigned i = 0; i < x.size();i++) y[i] = toupper(x[i]);
    return y;
}

void importDataFromFile(string file,vector<string> &names,vector<int> &scores,vector<char> &grades){
    ifstream filename("name_score.txt") ;
    string line ;
    char name[100] ;
    char format[] = "%[^:]: %d %d %d"  ;
    int a,b,c,sum ;
    while(getline(filename,line)){
        sscanf(line.c_str(),format,name,&a,&b,&c) ;
        sum = a+b+c ;
        names.push_back(name) ;
        scores.push_back(sum) ;
        grades.push_back(score2grade(sum)) ;
    
    }
    
}

void getCommand(string &command,string &key){
    cout << "Please input your command: " ;
    getline(cin,command) ;
    int start = 0 ;
    int end = command.find_first_of(" ") ;
    string data1,data2 ;   
    data1 = command.substr(start,end-start)  ;
    start = end+1 ;
    end = command.find_first_of(" ",start) ;
    data2 = command.substr(start,command.size()-start) ;
    
    command = data1 ;
    key = data2 ; 
    

}

void searchName(vector<string> names,vector<int> scores,vector<char> grades,string key){
     
    
    int count ;
    for(int i = 0;i < 26 ;i++){
        if(toUpperStr(names[i]) == key){
            cout <<  "---------------------------------\n";
            cout << names[i] << "'s score = " << scores[i] << endl ;
            cout << names[i] << "'s grade = " << grades[i] << endl ;
            count = 1 ;
        }
    }
    if(count != 1){
        cout << "---------------------------------\n";
        cout << "Cannot found." << endl ;
        cout << "---------------------------------\n";
    }  
        
    
}

void searchGrade(vector<string> names,vector<int> scores,vector<char> grades,string key){

    cout << "---------------------------------\n";
    for(int i = 0; i < 26 ;i++){
        if(scores[i] >= 80 && key == "A"){
            cout << names[i] << " " << "(" << scores[i] << ")" << "\n" ;
        }else if(scores[i]  >= 70 && scores[i] < 80 && key == "B" ){
            cout << names[i] << " " << "(" << scores[i] << ")" << "\n";
        }else if(scores[i] >= 60 &&  scores[i] < 70 && key == "C" ){
            cout << names[i] << " " << "(" << scores[i] << ")" << "\n";
        }else if(scores[i] >= 50 &&  scores[i] < 60 && key == "D" ){
            cout << names[i] << " " << "(" << scores[i] << ")" << "\n";
        }else if(scores[i] < 50 && key == "F"){   
            cout << names[i] << " " << "(" << scores[i] << ")" << "\n";
        }
    }
    cout << "---------------------------------\n";

}

int main(){
    string filename = "name_score.txt";
    vector<string> names;
    vector<int> scores;
    vector<char> grades; 
    importDataFromFile(filename, names, scores, grades);

    do{
        string command, key;
        getCommand(command,key);
        command = toUpperStr(command);
        key = toUpperStr(key);
        if(command == "EXIT") break;
        else if(command == "GRADE") searchGrade(names, scores, grades, key) ;
        else if(command == "NAME") searchName(names, scores, grades, key);
        else{
            cout << "---------------------------------\n";
            cout << "Invalid command.\n";
            cout << "---------------------------------\n";
        }
    
    }while(true);
   
    return 0;
}
