// good practice for classes is to make 2 files the header (contain functions and variables declarations (prototypes)  and source file
#ifndef MYCLASS_H  //if not defined 
#define MYCLASS_H  // define

class MyClass{
	public:
		MyClass();
		int var;
		//const int var2;
		void fun();
		const int cons();
		void sum(int a,int b);
	private:
	protected:	
	
};

#endif //MYCLASS_H













