#include <iostream>

using namespace std;

bool isPalindrome(string str)
{
    int i=0;
    int j = str.size() - 1;
    while(i <= j)
    {
        if(str[i] != str[j])
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

string repeat(string s, int n) {
  string repeat = "";

  for (int i = 1; i < n; i++)
  {
    repeat += s;
  }

  return repeat;
}


//Main:
int main(int argc, char const *argv[])
{
    int t;
    cin>>t;

    while(t--)
    {
        string str;
        cin>>str;
        int size = str.size();
        cout<<size<<endl;
        string check = "";
        for(int i =0;i<size;i++)
        {
            check += str[i];
            int len = check.size();
            if((size % len) == 0)
            {
                bool res = isPalindrome(check);
                if(res == true)
                {
                    int n = (size / (len));
                    string result = repeat(check , n);
                    if(result == str)
                    {
                        cout<<result<<endl;
                        break;
                    }
                }
            }
        }


    }
    return 0;
}
