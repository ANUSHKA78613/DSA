class Solution {
public:
    bool isValid(string s) {
      stack<int>ss;
      for(int i  = 0;i<s.length();i++){
        if(s[i] == '(' || s[i] == '{' || s[i] == '['){
        ss.push(s[i]);
        }
       else if(ss.empty()){ return false;}
       else if( ss.top() == '(' && s[i] == ')' ||ss.top() == '{' && s[i] == '}' || ss.top() == '[' && s[i] == ']' ){
        ss.pop();
      }
    else { return false;}
 
      }
      return ss.empty();
    }
 };
// stack<char>ss; 
// for(int i=0;i<s.size();i++){
//  if(s[i]=='('||s[i]=='{'||s[i]=='['){ 
//     ss.push(s[i]);
//      } 
//      else if(ss.empty()){
//          return false;
//           }
//            else if(s[i]==')'&&ss.top()=='('||s[i]=='}'&&ss.top()=='{'||s[i]==']'&&ss.top()=='[')
//             { ss.pop(); } 
//             else {
//                  return false; 
//                  } 
//                  }
//                   return ss.empty();