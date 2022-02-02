#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<queue>
#include<stack>
#include<math.h>
#include<set>
#include <chrono>

using namespace std;

void print(int a[], int n) {

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void print(vector<char> a) {
    int n = a.size();
    for (int i = 0; i < n; i++) {
        cout << a[i] ;
    }
}
void print(vector<int> a) {int n = a.size();
    for (int i = 0; i < n; i++) {
        cout << a[i] <<" ";
    }}

int min(int a,int b)
{
    if(a<b)
    {
        return a;
    }
    return b;
}
vector<int> search(vector<char> header, vector<char> dna, int q)
{vector<int> ans;
    int d=26;
    int ind, ind1,position=0,postion2=0,head=1;//position is hash for header and position 1 is hash for dna and head is total hash value
    for (ind = 0; ind < header.size() - 1; ind++)//caluculate head exactly header size-1
        head = (head * d) ;
    for (ind = 0; ind < header.size(); ind++) {
        position = (d * position + header[ind]) ;//caluculate hash for header sliding window
        postion2 = (d * postion2 + dna[ind]);//caluculate hash for first sliding window
    }
    for (ind = 0; ind <= dna.size() - header.size(); ind++) {
        if (position == postion2) {//if hash equals compare next characters
            for (ind1 = 0; ind1 < header.size(); ind1++) {
                if (dna[ind + ind1] != header[ind1])
                    break;
            }
            if (ind1 == header.size())//if hash and total string is equal push to answer
                ans.push_back(ind+1);
        }
        if (ind < dna.size() - header.size()) {
            postion2 = (d * (postion2 - dna[ind] * head) +
                        dna[ind + header.size()]);//drop hash of first character and add hash of next character
        }
    }
    return ans;
}
int32_t main() {
    auto start = chrono::steady_clock::now();
    int q = 101;
    string txt1="AATCCTGGTTGGACATACCGTTTTCCACACAAATGCCCCAGACACTGTACGGAGACCCTCTAGTCTAGTCTAGTCTAGTCTAGTCTAGTCTAGTCTAGTCTAGTCTAGTCTAGTCTAGTCTAGTCTAGTTTTTTCTTTTTTTCTTTTTTTCTTTTTTTCTTTTTTTCTTTTTTTCTTTTTTTCTTTTTTTCTTTTTTTCTTTTTTTCTTTTTTTCTTTTTTTCTTTTTTTCTTTTTTTCTTTTTTTCTTTTTTTCTTTTTTTCTTTTTTTCTTTTTTTCTTTTTTTCTTTTTTTCTTTTTTTCTTTTTTTCTTTTTTTCTAAGAACCGGGGTTTTGGCTGATTCACCGAGTCAACCTAAGACACTAGTTAAACATGTTTGTCGATTATATCACCTTTCATATATTCCGAGCGACACTTTTCAATGCTATATGGTGCTTATTCCTGCTTACCATTTTCGGACCCAGGCCTCAACTTTTGCTTGTACGACATGAAAGGTGCAGCTCTACTTGGATAAGGTGTACTACCTAGCTTACTCGCACCGGACCATTAGCTATTACAGGGTTTGGATAGTTACGTGATGATCGAGGCAGACACCGTAAGACTCTTACGCGCCCGACGGTCCCCGTTAATGATGACAGTGACGAAAGGATTGAGAGGCGCGTCAGACCCCTGTTCCCATATTGTATGTTGTCGTTGGTACGGGCGCCTTACGGAGTAAGGTGTTAGGCAGGAATGGCCAAAGGTTGGTGAACCTGAATCATGGTTGACACGCAGCTCTCTACATTTATGGGCGTATTCCTATTCGCGACTACTACAACTCTTCGGCCGCCGGTAACCGTACGGTGGCTAGATGCCGCTCATACAAAGTATGCGAGCCGTATTCAGAGTATAATGACCTGAAGGAGTACATGAGGGTCATGGTCCGCAGGGACTCCCTGTCATATGCTGAGATGGAGCCATAATCCCTGCCAGCCGTGTGGACTCAGGCATTCCTGTATTAAGCACTCTAGCCCTCGTGAATGCTTGGAAGAGTCACCCAAGGAATCGATTATCACAGGTTGGGAGAGGATGTTTTTCAAGGCCCTGAAAATTTGAAGGGGCTATTGACTGCGGCGTTACAACCAAAGAGATGACGGAACCATTGCTTCCGTCATGCTGGTGTCCCTGTGCGACCCACCGTGTTTGCTCCAATAAGTGGAAGGGTAAATTGATTACTACCGGTTTCATAGGAAGTTCGAGGTGCACGGTTGAGTAGCATTAGAGCTTCGAGCCAGGTTACCATAGTTATCTTTATGGGGCACTCGCCCTGATGTTTACGCCAGGGTTTAGCTTTGTGATCCGTTAGGGGGTTACCTACGACGCAGCAATTAGCGGGTGTCGCAGGTGTGTAGTTTGTGGCACCAAGCCAGCGGGCTTTACTTAACCAACCCTGGGAAGATCACTTCATCCGAATATGAGATCGCCCAACGCTAATACGCCGAAATGGGAACTGAAGGTCTTAGACTAGCTCACGAACCGTATACCTTAAGTTCCCTAAGCGGACGAATTTTTACTAAGTAAGGATTGCAGGAATATGGAAATCATCCGTACGTGCTTTGACGACCCAAAAAGAGGATCAATGGTATCTACCCAAAGCGTTATTCCTAGTACCAGGAGCCTAAATCATTTATAAAAAAATGCAACCTTTACCGTGGAGCGAAGGAAACTCTACTTATCTATCTATCTATCTATCTATCTATCTATCTATCTATCTATCTATCTATCTATCTATCTATCTATCTATCTATCTATCTCTGTCTGTCTGTCTGTCTGTCTGTCTGTCTGTCTGTCTGTCTGTCTGTCTGTCTGTCTGTCTGTCTGTCTGTCTGTCTGTCTGTCTGTCTGTCTGTCTGGTGTCAACCGTAGCCTGGTAGATGGAGGATGGTCGACTGGCTCAGATCCACCCTTGTGGCGGCATAACAAAATGTTCACTGAATTGGGCGAAAAATTAGCGAGTGTCACTTGACAAGGACTGAATAGCAGCAACAACCGTCGAGATCGTTGTCCAGTCACGCGGACTGATGATCTTAGATATAACGCAGAACTCAATGGCTCCTCCTGTACTATGATAGGGCGATATAGCGAGCCGAAAACTCGGGCCGGATGAGCGCTCACTGCGGTCCCGCAGCGCTGTTACGACGCCACGTTACCCTTGATCCGTGGTTGGTAGTGTCGCGTGATGAATGCACGAGTTGGTACCGTTCTAAGATCGACTACACGTGGCTCGATTTTAGCAAGTGTGCGATACCTGAATAGTCTGTAACAGTCCGGCGACCCATGGAAGCCGTTTCGTCCCGTATGCCAAGGCCCCGTTTATCCCTCAGCATGGGAATGACGGCCACCAGTGGTCCGTGTTCGCGATCAGTCTCGGGGAGGTACACACCCTCACTGTAAACTGGCAAGGAGGTGATTTTGCCCAATCTGAGAGCCTAAAGTGGCAGTACAGGTTCCTCACACATAACGAGGTACTTGCCTAACTACGTCCTATGTAGACAGGATAAGAAAACGCAGAGCGCGACCGCCGTGCAGTAATGAGTACTAAGGTAACTGGCCGCTCATATGTTCAGTACTGTCACCGTGTTGGTTAGAAAGAAAGAAAGAAAGAAAGAAAGAAAGAAAGAAAGAAAGAAAGAAAGAAAGAAAGAAATCGACGCTAAGTCGGCTTCAGACTCTTGCGATGATTCCGATTCGGCCTTTTCCCTCAGTGCTTCTCAGCAGGCAACTTGCGAAAAGCATATCGCGCATTAGTACAACAGCAATTACTACACGACCAAAACGTCGTGGAGAGTCGCTGTACTGCAGCTCAAGGGTGGCCGACCATAGAACATTTAACGATATGCACGATCCGGTCAAATATCACAACAGAATTGTGTGCTAGTAGGGGAAAAGGGGAAGGCCCTTCCTTGGGATAGATAGATAGATAGATAGATAGATAGATAGATAGATAGATAGATAACCGACTCATTGCGGAATTTTCAGTTTTACAATGCGGTGACCACTAGCCAACGGCGTCATTGATAATGATACTAACTTCCTTGGGGCGACTCCGGTTTAAAAGTGGCCGGTACGCTTGTTCGACATCATGTGTAGCGTTATTAGGACTGAATTACCGGGCCCCGTTCCGAGATGTTCTTTTTCGGCCCCTGGCGCAGAGGCGCTTGAGCTGCATATACTGGAATATAAGAGGTCACTCGCGAGAACGGTCACGCTACCATGTCGGCAGGATGCAGGATCAGGAATAATGTGGTAGACCTGTGTTCAACGGTGATCTCGGTGTGGATCGGGTGAGCACCAGATCGACTAACTAAGGGATATGCAAGCAGATTCTTCGGACGCCTTTGCCGGTAACACATGGAACACGCCTATGCGCTCCATTACTGGGTGCCTTGTTGAGACGGATAGGTCGGGTTCAATGATTATTAAGGTTTATCAACGTATTACTGCTTGTAACGGCTTGTAAGTGCCAATTGTCATTCGACCCCGGCTGGTCTGACAAGGTTTGTACGCCGATTTGGCATGAGGGGACTAGAGTGGAATAGGATTGTGCACTAAGCTGCGGTCCCGCCTGCGTACCCGCGTATCAAGTGGCTCGGTGGCTGGTTGCGATTACTGAGCTCGTGCATTGCTATCAGTGCGTCCCCTGCAAGAACAGGTATCAAGTGTGGTTCCGTATTGCACGATTGACAATTTCATCGGGTATTCGCTCGTCGGCAAACATTGAAGGCTTCATAGGTTCACAACCGCGTTCCCTGTGATGCGGAATCGCGAGATCTGGATCATCCTTCTAAGACACTCAAAATGCAGACGTCGAGAGACGTATGCGTCCGCGGGAACTATGGCATCTGCCCTTAACATGTGAAGAGACTGCTTTAGCTCGATCTAACCGTAGGCCCTTCATGAAGAGAAGCCATTGTCGGGGGTAGTGACTTTTGGCCGTACGTGATTAAATAACACGGAGTCAAACTCGGAGCGTTCCGTCTCTGATATCGCCAACATCGCAAGCTCCCTACGTACCACCCTGGGTGAACACGACTTTAATGCTTTGAAAATATTGATGGAGACGGCACAAATTTCCGAAAACTCGAAACTTAGTAAATTTACACTGAAAAACCCGGGCGGACAAGTACAAGAGTCCGCGCTCGTAGTGCTCTGTTGAAGCGTTGACCTCTGTCGCTTAAAATCGTAAAGACTTTATACACGAATATTGAGTGAGAAAGAGTCCCCGATCTATCATTACAAATATTCCGTTCTACAATCTGAGGCCAGACAGTTTTGTTCCCTCTCCTTACCTAGTGCCATATCGAGGGACAGAAATTTGACACCTTGCAGTCACACGTTGTTTTGAGATATGCAAACCACGCCCAGTGTCGAGATCCCACATATCTTCATTATAAGCTCGACCACTTGAGACTGCAGCACGAAGGCAGATCAGATCAGATCAGATCAGATCAGATCAGATCAGATCAGATCAGATCAGATCAGATCAGATCAGATCAGATCAGATCAGATCAGATCAGATCAGAAATTCCAAGCAATGGCTTCAGCGCTCGGACGCCCCGCCCGTGCCCGGCGTGAACATATGGATGTATGAATTATTGCATGGTCTGTATCTTAATGCGCGCTTGGCAACACATGTGAGAACGGTCTCACGTGCGACTACGTATGATCTATGCAAATGTGCGGTGGCGCCCGGCCTTTTTAGGAGGTTCCTAGACCAGGAGCCTGTGTGGTAAGGGCCGGCAGACGTTTCCGGTACGCTCCGCCAAGAAGGTAACCATGCGGCCCGGTAATGTAACCAGGTCTCGAAAAAATTAGGCGAATCGAAAGGGTTCTATCGGACCGTTAACAATTTACGGTCATTCTAGTATGCATTCAAGGAACCGACTCTCGTCTCACATTTATGTCATCATTATGACTAACGCAAGCTGTTACAACGTGACTACTCACCTGGATCGTCATCACGCGCGATGTGCATGAACTCGCAAAAACGAACCTAATCGAACGGTTATCGGTGACATTTGATTTTGAGTCTGCGGCACGTAAAAGCTCTGGGATGCAGCTCCTATATCAGCCTAGGGGTCGGGCTCTCTGGTTCTGCTCGCTAGAATGAATGAATGAATGAATGAATGAATGAATGAATGAATGAATGAATGAATGAATGAATGAATGAATGAATGAATGAATGAATGAATGAATGAATGAATGAATGAATGAATGAATGAATGAATGAATGAATGAATGAATGAATGCAGTCCCGTGAGTGAGTAGTATACGCGATCTTGTGTGTCTAAGTTATTGCCACACACGAATGACCAAATACGAGATCTAGACTCGTGTATATGAGACAGGTTGCACAATCAGCCTTTATTCTGAGACAGTGGTGCTGGGGATGGCTTGAGATACATACGCACACAAGCCCAGGGGGATTAATTGCTGCGCAGATAGCCCGCCCAAAGTTGTCCCAGTGACCTTAGAAGGACCCTGTACCTGGCGTTGGGTAAGACACGTCACCCGTCGTAGCCGTGTATAGCCGAGCGTCCTGCAAAAGCGTATCTTTTTGATGAGCGAAATCGCGTCCAAAGACTTCGCTCAATTCAGAAGGCTCGAATTGCCGATCGTCGCAGGGCTGCATTAGGCACGCCAGTTCTTCTAGGTCCCGGGCCGAGAGTGTTCGGCGGTAACTGCCTTTTAGGGGCCGCACACCTCGGCTGCGGCCGGGCGGAAGGCGCTTACTTCTGGATGCGGCTTCAGACGGCTGTAATATGTCTCGGAATACCGCTCAGCATACGAGGAGTCTCCGCTTTCGACAGCCTGGGGCCACGTCGTGTTGAA";
    vector<char> dna1;
    for(int i=0;i<txt1.size();i++)
    {
        dna1.push_back(txt1[i]);
    }
    string s="AGATC TTTTTTCT AATG TCTAG GATA TATC GAAA TCTG";
    vector<vector<char>> headers;
    vector<char> v;
    for(int i=0;i<s.size();i++)
    {if(s[i]==' ')
        {
            headers.push_back(v);
            v.clear();
        }
        else
        {
            v.push_back(s[i]);
        }
    }
    headers.push_back(v);
    vector<int> counts;
    for(int i=0;i<headers.size();i++)
    {vector<int> ans=search(headers[i], dna1,q);
        int size=headers[i].size();
        int count=min(1,ans.size());
        int fcount=min(1,ans.size());
        for(int i=1;i<ans.size();i++)
        {
            if(ans[i]-ans[i-1]==size)
            {
                count++;
                fcount=max(fcount,count);
            }
            else
            {
                count=1;
            }
        }
        print(headers[i]);
        cout<<":"<<fcount<<endl;
        counts.push_back(fcount);
    }
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration <double, milli> (diff).count() << " ms" << endl;

}