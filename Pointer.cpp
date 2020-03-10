#include <iostream>

using namespace std;

int main(){

	// int x = 10;
	// cout<<(&x)<<endl;//address of x in memory

	// int* xptr = &x;//int* is a data type which stores address of a variable which is in hexadecimal format

	// cout<<xptr<<endl;//address of x

	// cout<<(&xptr)<<endl;//address of address variable

	// cout<<(*xptr)<<endl;//dereference operator gives value at that address
	// cout<<x<<endl;
	// cout<<10<<endl;

	// cout<<"******Float******"<<endl;

	// float f = 10.78;
	// float* fptr = &f;

	// cout<<&f<<endl;
	// cout<<fptr<<endl;

	// cout<<(*fptr)<<endl;

	// char ch = 'A';
	// char* cptr;
	// cptr = &ch;

	// cout<<cptr<<endl;//in char data type this gives value
	// cout<<(void*)cptr<<endl;//when (void*) is used only then address is printed
	// cout<<&ch<<endl;//this also gives value of ch not the address

	// cout<<"********INT*******"<<endl;

	// int x = 10;
	// int* xptr = &x;

	// cout<<xptr<<endl;
	// cout<<(xptr+1)<<endl;

	// cout<<"********LONG*******"<<endl;

	// long l = 20;
	// long*lptr = &l;

	// cout<<lptr<<endl;
	// cout<<(lptr + 1)<<endl;

	int x = 10;
	int &z = x; // z is alloted same location as x

	z++;

	cout<<x<<endl;

	return 0;
}