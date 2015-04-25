// a set of hash functions 
#ifndef HASHFUN_H
#define HASHFUN_H


#include <iostream>
#include <string>

/* a simple hash algorithm :  
 * input: string 
 * output : ascii representation mod M
 * 
 */

// int hashfun3(std::string s, int M=101) {
int hashfun3(std::string s) {
  int sum = 0;
  for (std::string::iterator it=s.begin(); it!=s.end(); ++it){
    sum += (int) *it;
    // std::cout << (int) *it << "\n";
  }
  return sum % 101;
}

/* a simple hash algorithm :  
 * input: string 
 * output : ascii representation mod M
 * 
 */

// int hashfun3(std::string s, int M=101) {
int hashfun4(std::string s) {
  int p = 1;
  for (std::string::iterator it=s.begin(); it!=s.end(); ++it){
    p += (int) *it;
    // std::cout << (int) *it << "\n";
  }
  return p % 71;
}




/* a simple hash algorithm : divide the string into segments of size 4, convert each 
 * segment into binary as it is, mod the sum   
 * input: string 
 * output : hash value 
 *
 */


// int hashfun4(std::string s, int M=101) {
int hashfun5(std::string s) {
  int subLength = 4;
  int intLength = s.length() / subLength;
  int sum = 0;

  for (int j = 0; j < intLength; j++) {
    const char* c = s.substr(j * 4, (j * 4) + 4).data();
    int mult = 1;
    for (int k = 0; k < subLength; k++) {
      sum += c[k] * mult;
      mult *= 256;
    }
  }

/*
  const char* c = s.substr(intLength * 4).data();
  long mult = 1;
  for (int k = 0; k < c.length; k++) {
    sum += c[k] * mult;
    mult *= 256;
  }
  */

  return(abs(sum) % 101);
}


/* a hash algorithm : hash by first alphabet in the string 
 * input: string 
 * output : hash value 
 * 
 */

// int hashfun1(std::string s, int M=101) {
 int hashfun1(std::string s) {
  return (int) s.front();
 }


/* a hash algorithm : hash by last alphabet in the string  
 * input: string 
 * output : hash value 
 * 
 */

// int hashfun2(std::string s, int M=101) {
 int hashfun2(std::string s) {
  return (int) s.back();
}


 #endif






