#include "cuckoohash.h"
#include "hashfunctions.h"
#include <assert.h>  

/*
* a suite of test functions of cuckoo hash 
* test with more input strings, 2 more hash functions 
*/

/*
* test insertion
*/
void test_insert(CuckooHash coo){
	// no cycle
  std::string str1 ("test");
  std::string str2 ("estt");
  std::string str3 ("def");

  coo.insert(str1); 
  coo.insert(str2);    

  coo.insert(str1); 

  assert(coo.lookup(str1) == true); 
  assert(coo.lookup(str2) == true);
  assert(coo.lookup(str3) == false); 

}

void test_insert_cycle(CuckooHash coo){
	// four cycle
  std::string str1 ("cp");
  std::string str2 ("ce");
  std::string str3 ("de");
  std::string str4 ("dp"); 
   
	// collision 
  std::string str5 ("cke");  

  coo.insert(str1); 

  coo.insert(str2);
  coo.insert(str3); 
  coo.insert(str4); 
  coo.insert(str5); 

  assert(coo.lookup(str1) == true); 
  assert(coo.lookup(str2) == true);
  assert(coo.lookup(str3) == true); 
  assert(coo.lookup(str4) == true); 
  assert(coo.lookup(str5) == true); 

}

/*
* test deletion
*/
void test_lookup(CuckooHash coo){
  std::string str1 ("test");
  std::string str2 ("estt");
  std::string str3 ("def");

  assert(coo.lookup(str1) == false); 
  assert(coo.lookup(str2) == false);
  assert(coo.lookup(str3) == false);
}


void test_remove(CuckooHash coo){
  std::string str1 ("test");
  std::string str2 ("estt");
  std::string str3 ("def");

  coo.insert(str1); 
  coo.insert(str2); 
  coo.insert(str3); 

  assert(coo.lookup(str1) == true); 
  assert(coo.lookup(str2) == true);
  assert(coo.lookup(str3) == true); 

  coo.remove(str1); 
  coo.remove(str2); 
  coo.remove(str3); 

  assert(coo.lookup(str1) == false); 
  assert(coo.lookup(str2) == false);
  assert(coo.lookup(str3) == false); 

}
/*
* performance measure, with plots (possibly do this in python)
*/

/*
* OPTIONAL: performance comparison with std set, i.e. ::unordered_map 
*/


 int main(){
   CuckooHash coo;

  std::string str1 ("cp");
  std::string str2 ("ce");
  std::string str3 ("de");
  std::string str4 ("dp");  
  std::string str5 ("cke");  

  std::string str6 ("");
  std::cout << (str6 == "") << "\n";

	std::cout << str1 << "\n";
  std::cout << hashfun1(str1) << "\n";   
  std::cout << hashfun2(str1) << "\n";
  std::cout << hashfun3(str1) << "\n";
  std::cout << hashfun4(str1) << "\n";

	std::cout << str2 << "\n";
  std::cout << hashfun1(str2) << "\n";   
  std::cout << hashfun2(str2) << "\n";
  std::cout << hashfun3(str2) << "\n";
  std::cout << hashfun4(str2) << "\n";

	std::cout << str3 << "\n";
  std::cout << hashfun1(str3) << "\n";   
  std::cout << hashfun2(str3) << "\n";
  std::cout << hashfun3(str3) << "\n";
  std::cout << hashfun4(str3) << "\n";

	std::cout << str4 << "\n";
  std::cout << hashfun1(str4) << "\n";   
  std::cout << hashfun2(str4) << "\n";
  std::cout << hashfun3(str4) << "\n";
  std::cout << hashfun4(str4) << "\n";

	std::cout << str5 << "\n";
  std::cout << hashfun1(str5) << "\n";   
  std::cout << hashfun2(str5) << "\n";
  std::cout << hashfun3(str5) << "\n";
  std::cout << hashfun4(str5) << "\n";
  // std::string str3 ("");
  // std::cout << hashfun2(str3) << "\n";

  // test_insert(coo);
  // test_lookup(coo);
  // test_remove(coo);
  test_insert_cycle(coo);


 }
