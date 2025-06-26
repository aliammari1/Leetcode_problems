// https://leetcode.com/problems/html-entity-parser

class Solution {
public:
    string entityParser(string text) {
        map<string,string> m = {{"&quot;","\""},{"&apos;","'"},{"&amp;","&"},{"&gt;",">"},{"&lt;","<"},{"&frasl;","/"}};
        int firstFound = -1, secondFound = -1;
        for(int i = 0;i < text.length();i++)
        {    
            if(text[i] == '&')
            firstFound = i;
            cout << firstFound << " " << i << endl;
            if(firstFound != -1 && text[i] == ';')
            secondFound = i;
            if(firstFound != -1 && secondFound != -1)
            {
            cout << text.substr(firstFound,secondFound+1-firstFound) << endl;
            auto it = m.find(text.substr(firstFound,secondFound+1-firstFound));
            if(it != m.end())
            {
            text.replace(firstFound,secondFound+1-firstFound,it->second);
            i-=it->first.length();
            }
            firstFound = -1;
            secondFound = -1;
            }
        }
        return text;
    }
};