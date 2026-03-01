#include <iostream>
#include <string>

using namespace std;

int main(){
   string input;

   while(true){
      cout << "mini-shell> ";
      getline(cin, input);

      if(cin.eof()){
         break;        //handle Ctrl+D
      }

      if(input=="exit"){
         break;
      }

      cout << "You typed: " << input << endl;
   }

   return 0;
}
