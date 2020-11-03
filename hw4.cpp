#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int Brute_Force(string a, string b)
{
    if (a.empty() || b.empty())
    {
        return -1;
    }
    for (string::iterator Ia = a.begin(); Ia != a.end(); Ia++)
    {
        if (a.end() - Ia < b.length()) //优化：剩余串长度小于模式串长度时退出
        {
            return -1;
        }
        string::iterator Imark = Ia;
        if (*(Ia + b.length() - 1) != *(b.end() - 1)) //优化：先比较模式串的最后一位
        {
            continue;
        }
        for (string::iterator Ib = b.begin(); Ib != b.end(); Ib++)
        {
            if (*Ia != *Ib)
            {
                break;
            }
            if (Ib + 1 == b.end())
            {
                return Imark - a.begin();
            }
            Ia++;
        }
    }
}
void KMPSearch(string txt, string pat) 
{ 
    int M = pat.length(); 
    int N = txt.length(); 
  
    // create lps[] that will hold the longest prefix suffix 
    // values for pattern 
    int lps[M]; 
  
    // Preprocess the pattern (calculate lps[] array) 
    computeLPSArray(pat, M, lps); 
  
    int i = 0; // index for txt[] 
    int j = 0; // index for pat[] 
    while (i < N) { 
        if (pat[j] == txt[i]) { 
            j++; 
            i++; 
        } 
  
        if (j == M) { 
            printf("Found pattern at index %d ", i - j); 
            j = lps[j - 1]; 
        } 
  
        // mismatch after j matches 
        else if (i < N && pat[j] != txt[i]) { 
            // Do not match lps[0..lps[j-1]] characters, 
            // they will match anyway 
            if (j != 0) 
                j = lps[j - 1]; 
            else
                i = i + 1; 
        } 
    } 
} 
  
// Fills lps[] for given patttern pat[0..M-1] 
void computeLPSArray(string pat, int M, int* lps) 
{ 
    // length of the previous longest prefix suffix 
    int len = 0; 
  
    lps[0] = 0; // lps[0] is always 0 
  
    // the loop calculates lps[i] for i = 1 to M-1 
    int i = 1; 
    while (i < M) { 
        if (pat[i] == pat[len]) { 
            len++; 
            lps[i] = len; 
            i++; 
        } 
        else // (pat[i] != pat[len]) 
        { 
            // This is tricky. Consider the example. 
            // AAACAAAA and i = 7. The idea is similar 
            // to search step. 
            if (len != 0) { 
                len = lps[len - 1]; 
  
                // Also, note that we do not increment 
                // i here 
            } 
            else // if (len == 0) 
            { 
                lps[i] = 0; 
                i++; 
            } 
        } 
    } 
} 
    
int main()
{
    string a = "12jadxxthaj345";
    string b = "xxt";
    KMPSearch(a, b);
}