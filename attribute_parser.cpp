#include <iostream>
#include <algorithm>
#include <map>
#include <sstream>
using namespace std;

//Plan: convert each attribute into we find in HRML to
// tag1.tag2~name form and store its value using a map string string pair
// fixed a bug were if a tag had no attributes is wasn't keyed properly

class HRML_Interpreter
{
private:
    int line_Count_Code;
    int line_Count_Queries;
    map<string, string> mp;

public:
    HRML_Interpreter();
    //void print_Map();
    void query_Resolver();
};

HRML_Interpreter::HRML_Interpreter()
{
    cin >> line_Count_Code >> line_Count_Queries;
    cin.ignore(); //ignores white spaces
    string text;
    string keymap = "";
    string keytag = "";
    string value = "";
    while (line_Count_Code != 0)
    {
        getline(cin, text);
        if (text[1] != '/')
        {
            istringstream ss(text); //we only take input from this string
            string tag_name;
            ss >> tag_name;
            tag_name = tag_name.substr(1);

            if (tag_name.find_last_of('>') != std::string::npos)
            {
                tag_name.pop_back();
            }

            if (keytag.empty())
            {
                keytag = tag_name;
            }
            else
            {
                keytag = keytag + '.' + tag_name;
            }

            string token;
            while (ss >> token)
            {
                if (token == "=")
                {
                    continue;
                }
                else if (token[0] == '\"') //we have a value
                {
                    value = token.substr(1, token.find_last_of('\"') - 1);
                    mp.insert(make_pair(keymap, value));
                    keymap = "";
                    value = "";
                }
                else
                {
                    keymap = keytag + '~' + token;
                }
            }
        }
        else // text[1] == '/'
        {
            int index = keytag.find_last_of('.');
            if (index == string::npos)
            {
                keytag = "";
            }
            else
            {
                keytag = keytag.substr(0, index);
            }
        }
        line_Count_Code--;
    }
}
/* 
void HRML_Interpreter::print_Map()
{
    for (auto &x : mp)
    {
        cout << x.first << ' ' << x.second << '\n';
    }
}
*/
void HRML_Interpreter::query_Resolver()
{
    string query;
    while (line_Count_Queries != 0)
    {
        getline(cin, query);
        if (mp.find(query) != mp.end())
        {
            cout << mp[query] << '\n';
        }
        else
        {
            cout << "Not Found!\n";
        }
        line_Count_Queries--;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    HRML_Interpreter o;
    //o.print_Map();
    o.query_Resolver();
    return 0;
}
