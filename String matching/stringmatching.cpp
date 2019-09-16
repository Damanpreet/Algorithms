#include<iostream>
#include<cstring>
// #include<bits/stdc++.h> 
using namespace std;
#define NO_OF_CHARS 256

/* Brute force method for string matching.
m - length of template string 
n - length of query string
Complexity - O(m-n+1) */
int brute_force_str_matching(string s_template, string s_query){
    cout << "Query: " << s_query << endl;
    cout << "Template string: " << s_template << endl;

    int n, m;
    n = s_query.length();
    m = s_template.length();
    cout << "Length of query string: " << n << endl;
    cout << "Length of template string: " << m << endl;

    int i, j;
    for(i=0; i<n; i++){
        j=0;
        while((j<m) && (s_query[i+j]==s_template[j])){
            j+=1;
        }

        if(j==m){
            return i;
        }
    }
    return -1;
}

/*  
    Using finite automata for string matching based on rules.
    str_template - string to be matched.
    str_query - string to be matched with.
    
    considering there are only four possible characters in the string. finite set of states {"a, b, c, d"}
    match the string only if it ends with a c and has even number of a's.
    start state - 0, final state - 3
*/
int string_matching_fautomata(string match_string){
    
    int flag = 0, i=0;
    int len_match;
    len_match = match_string.length();
   
    int quit;
    if(len_match>0) quit=0;

    while(!quit){
        switch(flag){
            case 0:
                if(match_string[i]=='a'){
                    flag = 1;
                    i+=1;
                    if (i==len_match) quit=1; break;
                }
                else if(match_string[i]=='b'){
                    flag = 0;
                    i+=1;
                    if (i==len_match) quit=1; break;
                }
                else if(match_string[i]=='c'){
                    flag = 3;
                    i+=1;
                    if (i==len_match) quit=1; break;
                }
                else if(match_string[i]=='d'){
                    flag = 0;
                    i+=1;
                    if (i==len_match) quit=1; break;
                }
                
            case 1:
                if(match_string[i]=='a'){
                    flag = 2;
                    i+=1;
                    if (i==len_match) quit=1; break;
                }
                else if(match_string[i]=='b'){
                    flag = 1;
                    i+=1;
                    if (i==len_match) quit=1; break;
                }
                else if(match_string[i]=='c'){
                    flag = 1;
                    i+=1;
                    // if (i==len_match) goto EndWhile;
                    if (i==len_match) quit=1; break;
                }
                else if(match_string[i]=='d'){
                    flag = 1;
                    i+=1;
                    if (i==len_match) quit=1; break;
                }
                
            case 2:
                if(match_string[i]=='a'){
                    flag = 1;
                    i+=1;
                    if (i==len_match) quit=1; break;
                }
                else if(match_string[i]=='b'){
                    flag = 2;
                    i+=1;
                    if (i==len_match) quit=1; break;
                }
                else if(match_string[i]=='c'){
                    flag = 3;
                    i+=1;
                    if (i==len_match) quit=1; break;
                }
                else if(match_string[i]=='d'){
                    flag = 2;
                    i+=1;
                    if (i==len_match) quit=1; break;
                }
                
            case 3:
                if(match_string[i]=='a'){
                    flag = 1;
                    i+=1;
                    if (i==len_match) quit=1; break;
                }
                else if(match_string[i]=='b'){
                    flag = 0;
                    i+=1;
                    if (i==len_match) quit=1; break;
                }
                else if(match_string[i]=='c'){
                    cout << "yoo1!!" << endl;
                    flag = 3;
                    i+=1;
                    if (i==len_match) quit=1; break;
                }
                else if(match_string[i]=='d'){
                    flag = 0;
                    i+=1;
                    if (i==len_match) quit=1; break;
                }
        }
    }
    // EndWhile: cout<<"while ended";  
    if(flag == 3)
        return 0;
    else
        return 1;
}

/* 
    Prefix table
*/
void prefix_table(char* stemplate, int len_template, int* prefix_tbl){
    int i, j;
    i=1; j=0;
    prefix_tbl[0] = 0;
    while(i<len_template){
        if(stemplate[i]==stemplate[j]){
            prefix_tbl[i]=j+1;
            i++;
            j++;
        }
        else if(j>0){
            j=prefix_tbl[j-1];
        }
        else{
            prefix_tbl[i]=0;
            i++;
        }
    }
}

/* 
    KMP string matching.
    Return -1 if the template string not found in the query. 
    Else, return the position of the start of the matched pattern.
*/
int kmp_str_matching(char *stemplate, char *query){
    int len_template, len_query;
    len_template = strlen(stemplate);
    len_query = strlen(query);
    int prefix_tbl[len_template];
    
    prefix_table(stemplate, len_template, prefix_tbl);

    // size_t n = sizeof(prefix_tbl)/sizeof(prefix_tbl[0]);
    // for(size_t i=0; i<n; i++)
    //     cout << prefix_tbl[i] << endl;
    
    int i, j;
    i=0, j=0;
    while(i<len_query){
        if(stemplate[j]==query[i]){
            i++; j++;
        }
        else{
            if(j>0){
                j=prefix_tbl[j-1];
            }
            else{
                i++;
            }
        }
        if (j==len_template){
            return (i-j);
        }
    }
    return -1;
}

/* Create a Bad Match Table (Helper function for Boyer-Moore String Matching) */
void BadMatchTable(char* str_template, int qlen, int* badMatch){
    int i;
    for(i=0; i<NO_OF_CHARS; i++){
        badMatch[i]=-1;
    }
    for(i=0; i<qlen; i++)
    {
        badMatch[(int)str_template[i]] = i;
    }
}

/*  
    Boyer-Moore String Matching Algorithm (Bad character rule).
    Return -1 if the pattern is not found in the text.
    else, return the position of the pattern.  
    
    Worst case - equivalent to Brute Force when the query is like cbbbbb and pattern is like bbbbbbbbbbbbbb. 
    Since it traverses from right to left. (Rare scenario)
*/
int boyer_moore_string_match(char* str_query, char* str_template){
    //create a bad match table.
    int querylen, templatelen;
    int badMatch[NO_OF_CHARS], i, j, jump, MatchFlag;

    querylen = strlen(str_query);
    templatelen = strlen(str_template); 
    BadMatchTable(str_template, templatelen, badMatch);

    jump = 1;
    MatchFlag = 0;

    for(i=0; i<querylen-templatelen; i+=jump){
        j=templatelen-1;
        while(j>=0){
            if(str_query[i+j]!=str_template[j]){
                jump = max(1, j-badMatch[(int)str_query[i+j]]); 
                // cout << jump << endl;
                break;
            }
            j--;
            if(j<0){
                jump=templatelen-1; 
                cout << "Pattern match found at: " << i << endl;
                MatchFlag = 1;
            }
        }
    }
    return MatchFlag;
}

/* 
    Boyer Moore Algorithm: Good suffix rule. 
*/
int boyer_moore_suffix_rule(char* str_template, char* str_query){

}

int main(){

    // Brute force string matching
    string str_template = "abmz";
    string str_query {"baeabmtmdaydsjabjabmabmjabmztaghhfff"};
    int ret_val = brute_force_str_matching(str_template, str_query);
    if(ret_val == -1)       
        cout << "Template string not found in the query." << endl;
    else
        cout << "String found in the query string. Position of the match in the query is: " << ret_val+1 << endl;
    
    // String matching using Finite automata.
    string query_str = "abcadbaaabcccaac";
    ret_val = string_matching_fautomata(query_str);
    if(ret_val == 0)
        cout << "String accepted" << endl;
    else 
        cout << "String not accepted. Return value: " << ret_val << endl;


    // String matching using KMP (Knuth Morris Pratt) Algorithm
    cout << "*************************************" << endl;
    cout << "String matching using KMP Algorithm" << endl;
    char query[] = "bababarababacaaadddcbabababacacaddeeeeababacadsaas";
    char stemplate[] = "ababaca";
    
    int ret_value = kmp_str_matching(stemplate, query);
    if (ret_value == -1){
        cout << "String not found!" << endl;
    }
    else{
        cout << "String match found at index: "<< ret_value << endl;
    }

    cout << "*************************************" << endl;
    cout << "String matching using Boyer-Moore Algorithm" << endl;
    // char query1[] = "ababacdabdcabacd";
    // char stemplate1[] = "abac";
    int rval = boyer_moore_string_match(query, stemplate);
    if (rval == 1){
        cout << "String match found!" << endl;
    }
    else{
        cout << "String not found!" << endl;
    }

    return 0;
}