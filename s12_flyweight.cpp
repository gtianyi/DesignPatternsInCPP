#include <sstream>
#include <ctype.h>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

struct Sentence
{
  struct WordToken
  {
    string plain_text;
    bool capitalize;
  };

  Sentence(const string& text)
  {
    stringstream ss(text);
    string curText;
    while(ss >> curText){
        cout << curText << endl;
        tokens.push_back({curText, false});
    }
  }

  WordToken& operator[](size_t index)
  {
    return tokens[index];
  }

  string str() const
  {
    string s;
    for (const auto& tk : tokens){
        if (tk.capitalize){
            for (int i = 0; i < tk.plain_text.size(); ++i){
                s += toupper(tk.plain_text[i]);
            }
        }
        else{
            s += tk.plain_text;
        }
        s += ' ';
    }
    if (s.size() > 2)
        s.pop_back();
    return s;
  }
 
private:
  vector<WordToken> tokens;
};
