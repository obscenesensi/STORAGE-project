#include <iostream>
#include <string>
using namespace std;

string removeChars(string str, string rm){

  int i,s,d=-1;  // s : source index, d : dest index

  for( s=0; s<str.length(); s++ ){
    for( i=0; i<rm.length(); i++ ){

      if(rm[i] != str[s] && i == rm.length()-1){
          // 지울 글자가 없으면 d 증가시키고 복사 수행
          str[++d] = str[s];
        } else if (rm[i] == str[s]) {
          // 지울 글자가 있으면 s만 증가하고 d는 유지한채로 break
          break;
        }
    }
 }//for

 // cout << "after copy addr : " << &str << endl;
  str.erase(d+1,str.length()-1);
//  cout << "after erase addr : " << &str << endl;
// -> erase 전후 같은 주소

  return str;
}

int main(){

  string sample = "Overwatch is a multiplayer first-person shooter video game.";
  string removeStr = "aeiou";

  cout << "sample : " << sample << endl;
  sample = removeChars(sample,removeStr);
  cout << "sample : " << sample << endl;

  return 0;
}
