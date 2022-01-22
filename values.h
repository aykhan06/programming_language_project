#ifndef VALUES_H
#define VALUES_H

#include <string>

namespace Values {

  class Number {
   public:
     long long int value;

     inline Number(long long int);

     inline operator std::string const();
  };
		class String{
			public:
				std::string value_;
				
				String(std::string);
				operator std::string const();
		};
		void print_number(Number&);
		
  void print_str(String&);
}
#endif // VALUES_H
