#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>

template <class T>

class AUDS {

public:
	AUDS(){
		data = new T[numData];
		addedData = 0;
	}

	AUDS(const AUDS &other){
		data = new T[other.numData];
		numData = other.numData;
		setAddedData(other.addedData);
		for(int i=0; i<addedData; i++){
			this->data[i] = other.data[i];
		}		
	}

	AUDS& operator=(AUDS other){
		swap(*this, other);
		return *this;
	}

	~AUDS(){
		delete[] data;
	}

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

	T pop(){
		srand(time(NULL));
		int x = rand()%addedData;
		data[x] = data[addedData-1];
		addedData--;
		return data[x];	
	}

	int size(){
		return addedData;
	}

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

/*int getAddedData(){
		return addedData;
	}

	int getNumData(){
		return numData;
	}

	T getData(){
		return data[addedData];
	}

	void setAddedData(int x){
		addedData = x;
	{

	void setNumData(int x){
		numData = x;
	}

	void addData(T tox, int x){
		data[x] = tox;
	} 

	int plusAddedData(){
		setAddedData(getAddedData() + 1);
		return addedData;
	}*/
