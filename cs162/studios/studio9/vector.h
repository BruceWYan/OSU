#include <stdlib.h>
#include <iostream>
#include <exception> //base class of all built-in exceptions
#include <stdexcept> //where out_of_range lives

template <class T>
class vector {
   private:
      T *v;  //a dynamic array of elements of type T
      int s; //size
      int c; //capacity
   public:
      //default constructor
      vector(){
        this->c = 0;
	     this->s = 0;
	     this->v = NULL;
      }

      //destructor	  
      ~vector(){
	     delete [] this->v;
	     this->v = NULL;
      }

      //copy constructor
      vector(vector &other){
         this->c = other.s;
         this->s = other.s;
         this->v = new T[this->c];
         for (int i = 0; i < s; ++i){
            this->v[i] = other.v[i];
         }
      }
	
      //AOO
      vector& operator=(vector<T> &other){
         this->s = other.s;
         this->c = other.c;
         // for (int i = 0; i < s; ++i){
         //    other.push_back(v[i])
         // }

         if (this->v != NULL){
            delete this->v;
         }

         this->v = new T[this->c];

         for (int i = 0; i < s; ++i){
            this->v[i] = other.v[i];
         }

         return *this;
      }
      

      //push_back: add an element to the end	  
      // void push_back(T ele) {
	   //   T *temp;
	   //   temp = new T[++this->c];
	   //   for(int i = 0; i < this->s-1; i++)
	   //      temp[i] = this->v[i];

	   //   if (this->v != NULL)
	   //   	delete [] this->v;
	   //   this->v = temp;
	   //   this->v[s-1] = ele;
      // }

      int size() {
         return this->s;
      }

      void resize(){
         this->c = c * 2;
         T *temp;
         temp = new T[++this->c];

         if (s>0){
            for (int i = 0; i < this->s-1; i++){
               temp[i] = this->v[i];
            }
         }
         
         if (this->v != NULL){
            delete [] this->v;
         }

         this->v = temp;
      }

      void push_back(T ele){
         if (this->c == this->s){
            resize();
         }
         s++;
         this->v[this->s-1] = ele;
      }

      T operator[](int a){
         return v[a];
      }

      T at(int a){
         if (a != 0){
            throw std::out_of_range("out of my vector range");
         }
      }



};
