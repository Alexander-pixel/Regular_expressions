#include <iostream>
#include <regex>
#include <string>
using namespace std;


void PrintMatches(string str, regex reg)
{
    smatch matches;
    cout<<boolalpha;
    while(regex_search(str, matches, reg))
    {
        
        cout<<"Is there a match: "<<matches.ready()<<endl;
        
        cout<<"Are there no matches: "<<matches.empty()<<endl;
        
        cout<<"Number of matches: "<<matches.size()<<endl;
        
        cout<<matches.str(1)<<endl;
        
        str = matches.suffix().str();
        
        cout<<endl;
        
    }
}

void PrintMatches2(string str, regex reg)
{
    
    sregex_iterator currentMatch(str.begin(), str.end(), reg);
    
    sregex_iterator lastMatch;
    
    while(currentMatch != lastMatch)
    {
        smatch match = *currentMatch;
        cout<<match.str()<<endl;
        currentMatch++;
    }
    
    cout<<endl;
    
}

int main()
{
    string s1 = "The ape was at the apex";
    smatch matches;
    regex reg("(ape[^ ]?)");
    PrintMatches(s1, reg);
    
    string s2 = "I picked the pickle";
    regex reg2("(pick[^ ]+)?)");
    PrintMatches2(s2, reg2);
    
    string s3 = "Cat rat mat fat pat";
    regex reg3("([crmfp]at)");
    PrintMatches2(s3, reg3);
    
    string s4 = "Cat rat mat fat pat";
    regex reg4("([C-Fc-f]at)");
    PrintMatches2(s4, reg4);
    
    string s5 = "Cat rat mat fat pat";
    regex reg5("([^Cr]at)");
    PrintMatches2(s5, reg5);
    
    string s6 = "Cat rat mat fat pat";
    regex reg6("([Cr]at)");
    PrintMatches2(s6, reg6);
    
    string owlFood = regex_replace(s6, reg6, "Owl");
    cout<<owlFood<<endl;
    
    cout<<endl;
    
    string s7 = "F.B.I I.R.S. CIA";
    regex reg7("([^ ]\..\..\.)");
    PrintMatches2(s7, reg7);
    
    string s8 = "This is a\n multiline string\n" "that has many lines";
    regex reg8("\n");
    string noLBstring = regex_replace(s8, reg8, " ");
    cout<<noLBstring<<endl;
   
    // \d [0-9]
    // \D [^0-9]
    
    string s9 = "12345";
    regex reg9("\\d");
    PrintMatches2(s9, reg9);
    
    string s10 = "123 12345 123456 1234567";
    regex reg10("\\d{5,7}");
    PrintMatches2(s10, reg10);
    
    // \w [a-zA-Z0-9]
    // \W [a-zA-Z0-9]
    
    string s11 = "412-867-5309";
    regex reg11("\\w{3}-\\w{3}-\\w{4}");
    PrintMatches2(s11, reg11);
    
    // \s [\f\n\r\t\v]
    // \S [^\f\n\r\t\v]
    
    string s12 = "Toshio Muramatsu";
    regex reg12("\\w{2,20}\\s\\w{2,20}");
    PrintMatches2(s12, reg12);
    
    string s13 = "a as ape bug";
    regex reg13("a[a-z]+");
    PrintMatches2(s13, reg13);
    
    return 0;
}
