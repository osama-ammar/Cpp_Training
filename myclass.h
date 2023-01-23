// good practice for classes is to make 2 files the header (contain functions and variables declarations (prototypes)  and source file
#ifndef MYCLASS_H  //if not defined 	//  called conditional compilation  directive
#define MYCLASS_H  // define			//  called macro directive

class MyClass{
	public:
		MyClass();
		int var;

		void set_var(int x);

		//const int var2;

		void fun();

		const int cons();

		void sum(int a,int b);
		
	private:
	protected:	
	
};

#endif //MYCLASS_H













