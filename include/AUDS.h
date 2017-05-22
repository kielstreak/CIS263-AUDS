/*****************************************************************
 * Homework 3 solution working with class including private data
 * push and pop from the array with a generic data type
 *
 * @author Evan Kiel
 * @version 5/21/2017
 * *****************************************************************/

/** Required includes for rand*/
#include <time.h>
#include <stdlib.h>

/** Generic Data Type*/
template <class T>

/** Almost Useless Data Structure */
class AUDS {
public:

	/** Default Constructor */
	AUDS(){
		data = new T[numData];
		addedData = 0;
	}

	/** Copy Constructor */
	AUDS(const AUDS &other){
		data = new T[other.numData];
		numData = other.numData;
		setAddedData(other.addedData);
		for(int i=0; i<addedData; i++){
			this->data[i] = other.data[i];
		}		
	}

	/** Override for = operator */
	AUDS& operator=(AUDS other){
		swap(*this, other);
		return *this;
	}

	/** Destructor */
	~AUDS(){
		delete[] data;
	}

 	/*****************************************************
 	* push new data onto the structure and increase the 
 	* number for stored data
 	*****************************************************/ 
	void push(T x){
    		T* tmp;
    		if(addedData >= numData){
      			numData = numData * 2;
      			tmp = new T[numData];
      			for(int i=0; i<addedData; i++){
        			tmp[i] = data[i];
      			}				
      			delete[] data;
      			data = tmp;
    		}
    		data[addedData++] = x;
  	}

	/****************************************************
 	* Pop Random data off of the structure and replace
 	* its spot with the last item in the structure 
 	* decrement number added to effectivly delete last
 	****************************************************/
	T pop(){
		srand(time(NULL));
		int x = rand()%addedData;
		data[x] = data[addedData-1];
		addedData--;
		return data[x];	
	}
	
	/** return number of items stored in the structure */
	int size(){
		return addedData;
	}
	
	/** swap data in two structure for deep copy */
  	friend void swap(T& first, T& second){
    		std::swap(first.numData, second.numData);
    		std::swap(first.data, second.data);
    		std::swap(first.addedData, second.addedData);
  	}

private:
	int numData = 100;
	T* data;
	int addedData;
};
