/*
	Cuckoo hash in C++
*/
#ifndef CUCKOO_H
#define CUCKOO_H

#include "hashfunctions.h"

class CuckooHash{
/* private Data: define two tables of constant size arrays that values 
	* will be hashed into.
	* invariants: each entry is unique  
	* Assume : do not need to rehash more than once 
	*/
	typedef int (*hashf) (std::string); 

private: 
		std::string table1[150];  
		std::string table2[150];
		

	/* define two hash functions. Will be replaced when rehashing occurs */
		// hashf hashf[] = {&hashfun1, &hashfun2, &hashfun3, &hashfun4};
		hashf hash1 = hashfun1;
		hashf hash2 = hashfun2;				
	
	// public method 
public: 
		/* lookup a value 
		* O(1)
		*/ 
		bool lookup (std::string value){
			int key1 = hash1(value);
			int key2 = hash2(value);
			return table1[key1] == value || table2[key2] == value; 
		}


		/* delete a value : set to 0? 
		* O(1)
		*/ 
		void remove (std::string value){
			int key1 = hash1(value);
			int key2 = hash2(value);	

			if (table1[key1] == value)
			 	table1[key1] = "";

			if (table2[key2] == value)
				table2[key2] = "";
		}
		 

		/* insert a value. when a cycle is detected (collision) then 
		 * rehash
		 * O(M) 
		 */ 
		bool insert (std::string value){
			/* try_insert(value);
			 return true; 
			*/
			bool r = try_insert(value); 
			std::cout << r << " " << value << " inserted! \n"; 
 			if (!r){
 				std::cout << value << "rehash \n"; 
 				rehash();
 			}
			r = try_insert(value); 
			std::cout << r << " " << value << " inserted! \n"; 			
			return true; 	
		}

	/* private helper functions, 
		* true : insert successful 
		* false : insert not successful because of a cycle 
		*/
		bool try_insert (std::string value){
			if (!lookup (value)) {
				if (!insert_helper(value, table1, hash1, value)){
					return false;  
				}
				else {
					return true; 
				}
			}
			else {
				return true;
			}
		}


	/* private helper functions, 
		* ether insert successfully, or detect a cycle, 
		* table1, table 2 not modified 
		*/
		bool insert_helper (std::string value, std::string * table, int (*curr_hash) (std::string), 
			std::string cycle_value){
			
			std::cout << value << " insert helper \n"; 

			int key = curr_hash(value); 
			if (table[key] == "") {
				table[key] = value;
				return true;
			}
// 			cycle_value != value, cycle exists
			else if (table[key] == cycle_value){
					table[key] = value; 
					return false; 
			}			
			else {
				std::string * other_table; 
				if (table1 == table)
					other_table = table2; 
				else 
					other_table = table1; 	
				
				hashf other_hash;
				if (hash1 == curr_hash)			
					other_hash = hash2; 
				else 
					other_hash = hash1;
					
				std::string tmp = table[key];
				table[key] = value; 
				return insert_helper(tmp, other_table, other_hash, cycle_value); 
			}
		}

		/* input : 2 tables  
		 * table1, table2 
		 * try rehash old tables until successful 
		 * O(M)
		 */
		void rehash () {

			std::string new_table1[150];  
			std::string new_table2[150];

			// make a copy of the old table 
			// initialize old table 
			for (int i=0; i < 150; ++i){
				if (table1[i] != ""){
					new_table1[i] = table1[i];
					table1[i] = "";
				}

				if (table2[i] != ""){
					new_table2[i] = table2[i];		
					table2[i] = "";
				}		
				// std::cout << " first i : " << i  << "\n";
			}

			// reinsert using new hash functions 
			hash1 = &hashfun3;
			hash2 = &hashfun4;

			for (int i=0; i < 150; ++i){
				if (new_table1[i] != "" && !try_insert(new_table1[i])){
					std::cout << " bad rehash : " << i << " " << new_table1[i]  << "\n"; 
// 					rehash();
				}
			}

			std::cout << " done 1 \n";

			for (int i=0; i < 150; ++i){
				if (new_table2[i] != "" && !try_insert(new_table2[i])){
					std::cout << " bad rehash : " << i << " " << new_table1[i]  << "\n"; 
// 					rehash();
				}
			}
		}


};

#endif

