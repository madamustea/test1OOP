#pragma once
#include"domain.h"


template <typename Type>
class DynamicArray
{	private:
		Type* elems;
		int capacity;
		int nrOfElems;
	public:
		
		/*constructor*/
		DynamicArray(int capacity = 10);
		/*destructor*/
		~DynamicArray();
		/*copy constructor*/
		DynamicArray(const DynamicArray& otherDynamicArray);
		/*assignment operator*/
		DynamicArray operator=(const DynamicArray& otherDynamicArray);
		
		int getCapacity() { return capacity; }
		
		/*Function that resize the capacity of the array.*/
		void resize();
		/*input- object of type -Type-
		output- adds the object in the array*/
		void add(Type elem);
		
		/*Function that returns the size of the array*/
		int getNrOfElems() { return nrOfElems; }
		/*Function that returns the objects from the array*/
		Type* GetElems() {
			return elems;
		}
		int GetSize() { return nrOfElems; }
		Type& operator[](int pos);
		/*input- object of type -Type-
		output- deletes the object from the array*/
		void remove(Type ElemToBeRemoved);
		/*input- object of type -Type-
		output- updates the object in the array*/
		void update(Type ElemToBeUpdated); 
		
};

template<typename Type>
inline DynamicArray<Type>::DynamicArray(int capacity)
{
	this->nrOfElems = 0;
	this->capacity = capacity;
	this->elems = new Type[capacity];

}


template<typename Type>
inline DynamicArray<Type>::~DynamicArray()
{
	delete[]this->elems;
}

template<typename Type>
inline DynamicArray<Type>::DynamicArray(const DynamicArray& otherDynamicArray)
{
	this->nrOfElems = otherDynamicArray.nrOfElems;
	this->capacity = otherDynamicArray.capacity;
	this->elems = new Type[this->capacity];
	for (int i=0; i < this->nrOfElems; i++) {
		this->elems[i] = otherDynamicArray.elems[i];}
}

template<typename Type>
inline DynamicArray<Type> DynamicArray<Type>::operator=(const DynamicArray& otherDynamicArray)
{
	this->nrOfElems = otherDynamicArray.nrOfElems;
	this->capacity = otherDynamicArray.capacity;
	this->elems = new Type[this->capacity];
	for (int i=0; i < this->nrOfElems; i++) {
		this->elems[i] = otherDynamicArray.elems[i];}
	return otherDynamicArray;
}



template<typename Type>
inline void DynamicArray<Type>::resize()
{
	this->capacity *= 2;
	Type* newArray = new Type[this->capacity];
	for (int i = 0; i < this->nrOfElems; i++) {
		newArray[i] = this->elems[i];}
	delete[]this->elems;
	this->elems = newArray;
}

template<typename Type>
inline void DynamicArray<Type>::add(Type elem)
{	
	if (this->nrOfElems == this->capacity)this->resize();
	else {
		this->elems[this->nrOfElems++] = elem;
	}
}

template<typename Type>
inline Type& DynamicArray<Type>::operator[](int pos)
{
	return this->elems[pos];
}

template<typename Type>
inline void DynamicArray<Type>::remove(Type ElemToBeRemoved)
{
	for (int i = 0; i < this->nrOfElems; i++) {
		
		if (this->elems[i] == ElemToBeRemoved) {
			

			for (int j = i; j < this->nrOfElems-1; j++) {
				this->elems[j] = this->elems[j + 1];}
			this->nrOfElems--;
			
		}
	}
}

template<typename Type>
inline void DynamicArray<Type>::update(Type ElemToBeUpdated)
{
	for (int i = 0; i < this->nrOfElems; i++)
	{
		if (this->elems[i]==ElemToBeUpdated)
		{	
			this->elems[i] = ElemToBeUpdated;
		}
	}


}







