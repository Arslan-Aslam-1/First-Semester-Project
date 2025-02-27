#include<iostream>
using namespace std;
      
      // Function prototypes Declared at the Start of the Program
      void Login();
      void Registeration();
      void Decision(int check);
      void CheckRecords(int check);
      void DisplayVoters();
      void DisplayCandidates();
      void Vote();
      void InputHandling();
      void VoteSelect(string province,int check);
      void DisplayProvinceResult(string province, int candidate1, int candidate2, int candidate3, char cand1, char cand2, char cand3); 
      void Result();
  
  // Global variables to store vote counts for each candidate
  int A=0,B=0,C=0,D=0,E=0,F=0,G=0,H=0,I=0,J=0,K=0,L=0;    
  int choice;       // Stores the user's menu choice
  string tempID;    // Temporary variable to store user input for Voter ID
  string temppass;  // Temporary variable to store user input for password
  int AccountsCreated=0;  // Tracks the number of accounts created
struct Voter{             // Structure to store voter information           
  string ID[10];           // Array to store voter ID, Province, Account Number and other
  string province[10];
  string pass[10];
  int AccountNumber[10];
  char CandidateVoted[10];
  bool isFull[10];
};
  Voter Voting;          // Global instance of the Voter structure
int main(){  
      cout<<"   <--Welcome to Online Voting System!-->   "<<endl<<endl;
      cout<<"Following are the Rules for Online Voting System:"<<endl;
      cout<<"* User must Register in order to Login and Vote for any Candidate"<<endl;
      cout<<"* There is a Limit of only 10 Candidates Registeration"<<endl;
      cout<<"* On Registeration, User is asked to Select his Province"<<endl;
      cout<<"* One User can only Vote One Candidate"<<endl;
      cout<<"* User can Only Vote for Candidate that are Nominated from his Province only"<<endl<<endl;
 do{         // Main menu loop  
      cout<<"1. Login\n2. Register\n3. Display Voters\n4. Display Candidates\n5. End Voting\n6. Exit\n";
    cin>>choice;
 while(choice<=0 || choice>6){
      cout<<"Invalid Value Entered!\nEnter Again: ";
    cin>>choice;  
 }
 if(choice==1){       // Call the appropriate function based on user choice
      Login();    
 }
 else if(choice==2){
      Registeration();
 }
 else if(choice==3){
      DisplayVoters();
 }
 else if(choice==4){
      DisplayCandidates();
 }
 else if(choice==5){
      Result();
 }     
 else{
      cout<<"Exiting the System!....";
  return 0;     
  }
 }while(choice!=6);
 return 0;
}
void Vote(int check){           // Function to handle voting
      cout<<"An Online Election is being held in all Provinces of Pakistan\n";
 if(Voting.province[check]=="Punjab"){
      cout<<"Enter\n1. To Vote for Candidate A\n2. To Vote for Candidate B\n3. To Vote for Candidate C\n";
    cin>>choice;     
 }
 else if(Voting.province[check]=="Sindh"){
      cout<<"Enter\n1. To Vote for Candidate D\n2. To Vote for Candidate E\n3. To Vote for Candidate F\n";
    cin>>choice;  
 }
else if(Voting.province[check]=="Balochistan"){
      cout<<"Enter\n1. To Vote for Candidate G\n2. To Vote for Candidate H\n3. To Vote for Candidate I\n";
    cin>>choice;  
 }
 else if(Voting.province[check]=="KPK"){
      cout<<"Enter\n1. To Vote for Candidate J\n2. To Vote for Candidate K\n3. To Vote for Candidate L\n";
    cin>>choice;  
 }
      InputHandling();        // Validate the user's choice
      VoteSelect(Voting.province[check],check);        
    Voting.isFull[check]=false;            // Mark the voter as having voted
       cout<<"Voted Successfully!"<<endl<<endl;       
}
void InputHandling(){              // Function to handle invalid input for candidate selection   
 while(choice<=0 || choice>3){
      cout<<"Invalid Number Entered!\nEnter Again:";
    cin>>choice;
 } 
}
void VoteSelect(string province, int check) {
    // Pointers to store the vote count and candidate name for the selected province
    int* voteCount = nullptr;
    char* candidateName = nullptr;

    // Assign pointers based on the province and choice
    if (province == "Punjab") {         
        if (choice == 1) {
            voteCount = &A;
            Voting.CandidateVoted[check] = 'A';
            candidateName = &Voting.CandidateVoted[check];
        } else if (choice == 2) {
            voteCount = &B;
            Voting.CandidateVoted[check] = 'B';
            candidateName = &Voting.CandidateVoted[check];
        } else if (choice == 3) {
            voteCount = &C;
            Voting.CandidateVoted[check] = 'C';
            candidateName = &Voting.CandidateVoted[check];
        }
    } else if (province == "Sindh") {
        if (choice == 1) {
            voteCount = &D;
            Voting.CandidateVoted[check] = 'D';
            candidateName = &Voting.CandidateVoted[check];
        } else if (choice == 2) {
            voteCount = &E;
            Voting.CandidateVoted[check] = 'E';
            candidateName = &Voting.CandidateVoted[check];
        } else if (choice == 3) {
            voteCount = &F;
            Voting.CandidateVoted[check] = 'F';
            candidateName = &Voting.CandidateVoted[check];
        }
    } else if (province == "Balochistan") {
        if (choice == 1) {
            voteCount = &G;
            Voting.CandidateVoted[check] = 'G';
            candidateName = &Voting.CandidateVoted[check];
        } else if (choice == 2) {
            voteCount = &H;
            Voting.CandidateVoted[check] = 'H';
            candidateName = &Voting.CandidateVoted[check];
        } else if (choice == 3) {
            voteCount = &I;
            Voting.CandidateVoted[check] = 'I';
            candidateName = &Voting.CandidateVoted[check];
        }
    } else if (province == "KPK") {
        if (choice == 1) {
            voteCount = &J;
            Voting.CandidateVoted[check] = 'J';
            candidateName = &Voting.CandidateVoted[check];
        } else if (choice == 2) {
            voteCount = &K;
            Voting.CandidateVoted[check] = 'K';
            candidateName = &Voting.CandidateVoted[check];
        } else if (choice == 3) {
            voteCount = &L;
            Voting.CandidateVoted[check] = 'L';
            candidateName = &Voting.CandidateVoted[check];
        }
    }

    // Update the vote count
    if (voteCount != nullptr) {
        (*voteCount)++;
    }
}
void Decision(int check){
      cout<<"Enter\n1. To Vote, 2. To Check your Records\n3. To go Back to Login Page\n";
    cin>>choice;
 while(choice<=0 || choice>3){
      cout<<"Invalid Value Entered!\nEnter Again: ";
    cin>>choice;   
 }
  if(choice==1){         // Handle user choice
   if(Voting.isFull[check]==true){  
      Vote(check);
   }
   else if(Voting.isFull[check]==false){
      cout<<"This User has Already Voted!"<<endl; 
   }    
  }
  else if(choice==2){
      CheckRecords(check);   
  }
      cout<<endl;
}
void Login(){
      cout<<"Enter Voter ID: ";
    cin>>tempID;
  while(tempID.length()!=5){            // Validate Voter ID length
      cout<<"ID must be 5 Numbers Long\nEnter Again: ";  
    cin>>tempID;
  } 
      cout<<"Enter Password: ";
    cin>>temppass;
  bool isValid=false;  
 for(int check=0; check<AccountsCreated; check++){             // Check if the entered Voter ID and password match any registered voter
  if(Voting.ID[check]==tempID && Voting.pass[check]==temppass){
      cout<<"Login Successfully!"<<endl<<endl;
    isValid=true;
      Decision(check);
    break;  
  }    
 }
  if(!isValid){  
      cout<<"Given Information does not match our Record!"<<endl<<endl;    
 }
}
void Registeration(){
 if(AccountsCreated>=10){                 // Check if the maximum number of accounts has been reached
      cout<<"Maximum Account Limit Reached!"<<endl;
 }
 else{
  int Index=AccountsCreated;
  int ProvinceChoice;  
  bool isDuplicate;

        // Loop to ensure a unique and valid Voter ID
 do{
  isDuplicate=false; // Reset flag for each iteration
      cout<<"Enter Voter ID:\nID must consist of 5 Numbers:\n";
    cin>>Voting.ID[Index];
            // Check if the Voter ID is exactly 5 characters long
 if(Voting.ID[Index].length()!=5){
      cout<< "ID must be 5 Numbers Long\n";
    continue; // Skip the duplicate check and prompt again
 }
            // Check if the Voter ID already exists
  for(int i = 0; i < AccountsCreated; i++) {
   if(Voting.ID[Index]==Voting.ID[i]){
      cout<<"This Voter ID is already in use. Please enter a different ID.\n";
    isDuplicate = true;
    break; // Exit the loop as soon as a duplicate is found
   }
  }
 }while(isDuplicate || Voting.ID[Index].length()!=5); // Repeat if ID is duplicate or invalid       
      cout<<"Enter Password\nPassword must contain at Least Strength of 8 Letters: ";
    cin>>Voting.pass[Index];
 while(Voting.pass[Index].length()<8){
      cout<<"Strength of Password must be at least 8!\nEnter Again: ";
    cin>>Voting.pass[Index];   
 }
      cout<<"Select Your Province\n";
      cout<<"1. for Punjab, 2. for Sindh\n3. for Balochistan\n4. for KPK"<<endl;
    cin>>ProvinceChoice;
    cin.ignore();
 while(ProvinceChoice<=0 ||ProvinceChoice>4){
      cout<<"Invalid Option Entered!\nEnter Again: ";
    cin>>ProvinceChoice;
    cin.ignore();
 }
 if(ProvinceChoice==1){
      Voting.province[Index]="Punjab"; 
 }
 else if(ProvinceChoice==2){
      Voting.province[Index]="Sindh"; 
 }
 else if(ProvinceChoice==3){
      Voting.province[Index]="Balochistan"; 
 }
 else if(ProvinceChoice==4){
      Voting.province[Index]="KPK"; 
 }      
      cout<<"Signedup Successfully!"<<endl;
    Voting.AccountNumber[Index]=Index+1;
    Voting.isFull[Index]=true;
      cout<<"Your Account Number is "<<Voting.AccountNumber[Index]<<endl<<endl; 
    AccountsCreated++;
 }         
}
void CheckRecords(int check){
     cout<<"\nYour Account Number is "<<Voting.AccountNumber[check];
     cout<<"\nYour ID is "<<Voting.ID[check];
     cout<<"\nYour Province is "<<Voting.province[check];
 if(Voting.isFull[check]==false){
     cout<<"\nYou have Voted for Candidate "<<Voting.CandidateVoted[check]<<endl;
 }
 else if(Voting.isFull[check]==true){
     cout<<"\nYou haven't Voted for any Candidate Yet!"<<endl;
 }
     cout<<endl;          
}
void DisplayVoters(){
 if(AccountsCreated==0){
      cout<<"No Account has been Created Yet!"<<endl<<endl; 
 }
 else{                 // Loop through all registered voters and display their information
  for(int i=0; i<AccountsCreated; i++){
      cout<<"\nAccount Number: "<<Voting.AccountNumber[i]<<"\nID Number: "<<Voting.ID[i];
      cout<<"\nProvince: "<<Voting.province[i]<<endl;
   if(Voting.isFull[i]==false){
      cout<<"Voter has Voted for Candidate "<<Voting.CandidateVoted[i]<<endl<<endl; 
   }
   else if(Voting.isFull[i]==true){
      cout<<"This Voter hasn't Voted for any Candidate Yet!"<<endl<<endl;
   }    
  }
 }
}
void DisplayCandidates(){
  int CandidateSelect;    
      cout<<"Enter\n1. to Display Candidates from Punjab\n2. to Display Candidates from Sindh";
      cout<<"\n3. to Display Candidates from Balochistan\n4. to Display Candidates from KPK"<<endl;
    cin>>CandidateSelect;
 while(CandidateSelect<=0 && CandidateSelect>4){
      cout<<"Invalid Option Entered!\nEnter Again:";
    cin>>CandidateSelect;   
 }   
 if(CandidateSelect==1){             // Display candidates and their vote counts based on the selected province
      cout<<"\nCandidate A has "<<A<<" Votes";
      cout<<"\nCandidate B has "<<B<<" Votes";
      cout<<"\nCandidate C has "<<C<<" Votes"<<endl<<endl; 
 }
 else if(CandidateSelect==2){
      cout<<"\nCandidate D has "<<D<<" Votes";
      cout<<"\nCandidate E has "<<E<<" Votes";
      cout<<"\nCandidate F has "<<F<<" Votes"<<endl<<endl;
 }
 else if(CandidateSelect==3){
      cout<<"\nCandidate G has "<<G<<" Votes";
      cout<<"\nCandidate H has "<<H<<" Votes";
      cout<<"\nCandidate I has "<<I<<" Votes"<<endl<<endl;
 }
 else if(CandidateSelect==4){
      cout<<"\nCandidate J has "<<J<<" Votes";
      cout<<"\nCandidate K has "<<K<<" Votes";
      cout<<"\nCandidate L has "<<L<<" Votes"<<endl<<endl;
 }     
}
void DisplayProvinceResult(string province, int candidate1, int candidate2, int candidate3, char cand1, char cand2, char cand3){
    if (candidate1 > candidate2 && candidate1 > candidate3) {
        cout << "Candidate " << cand1 << " won from Province " << province << endl;
    } else if (candidate2 > candidate1 && candidate2 > candidate3) {
        cout << "Candidate " << cand2 << " won from Province " << province << endl;
    } else if (candidate3 > candidate1 && candidate3 > candidate2) {
        cout << "Candidate " << cand3 << " won from Province " << province << endl;
    } else if (candidate1 == candidate2 && candidate1 > candidate3) {
        cout << "Candidate " << cand1 << " and Candidate " << cand2 << " are tied for the highest votes in Province " << province << endl;
    } else if (candidate1 == candidate3 && candidate1 > candidate2) {
        cout << "Candidate " << cand1 << " and Candidate " << cand3 << " are tied for the highest votes in Province " << province << endl;
    } else if (candidate2 == candidate3 && candidate2 > candidate1) {
        cout << "Candidate " << cand2 << " and Candidate " << cand3 << " are tied for the highest votes in Province " << province << endl;
    } else if (candidate1 == 0 && candidate2 == 0 && candidate3 == 0) {
        cout << "No Voter has Voted any Candidate in Province " << province << endl;
    } else if (candidate1 == candidate2 && candidate2 == candidate3) {
        cout << "All candidates (" << cand1 << ", " << cand2 << ", and " << cand3 << ") have the same number of votes in Province " << province << endl;
    } else {
        cout << "No clear winner due to a tie or invalid vote counts" << endl;
    }
}
void Result() {
    DisplayProvinceResult("Punjab", A, B, C, 'A', 'B', 'C');
    DisplayProvinceResult("Sindh", D, E, F, 'D', 'E', 'F');
    DisplayProvinceResult("Balochistan", G, H, I, 'G', 'H', 'I');
    DisplayProvinceResult("KPK", J, K, L, 'J', 'K', 'L');
    cout << endl;
}