 #ifndef _I_PRODUCT_H_
 #define _I_PRODUCT_H_

 #include <iostream>
 #include <fstream>
 #include <string>
 #include <array>
 #include <iomanip>

 namespace w6 {

     class iProduct {
       public:
         virtual double getPrice() const = 0;
         virtual void display(std::ostream& os) const = 0;
     };

	 std::ostream& operator<<(std::ostream& os, const iProduct& iProduct);
	 iProduct* readProduct(std::ifstream& file);
 }

 #endif

