#include<iostream>
#include<cstring>

using namespace std;

struct String{
	public :
	    int n;
	    char* str;
	    
	    String(const char* s)
		{
	        n = strlen(s);
	        str = new char[n];
	        for (int i = 0; i < n; i++) str[i] = s[i];
	    }
	    
	    ~String()
		{
	        delete [] str;
	    }
	    
	    void print()
		{
			cout << str << endl;
		}
		
	    void append(const char* ss)
		{
	        int l = n + strlen(ss);
	        char* sstr = new char[l];
	        for (int i = 0; i < n; i++) sstr[i] = str[i];
	        for( int i = n; i < l; i++) sstr[i] = ss[i-n];
	        sstr[l]='\0';
	        delete str;
	        str = sstr;
	        n = l;
    	}
};


int main ()
{
    String s("Hi");
    s.append(" there");
    s.print();
    return 0;
}
