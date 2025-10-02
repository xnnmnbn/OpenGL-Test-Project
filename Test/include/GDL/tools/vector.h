#pragma once

#include "typedefs.h"
#include <cstdlib>

template<typename T>
class Vector{
private:

	T* _data;
	u32 _size;
	u32 _cap;

public:

	template<typename T>
	inline Vector(u32 cap = 0){
		this->_cap = cap;
		_size = 0;

		_data = new T[_cap];
	}

	inline void add(const T& t){
		if(_size >= _cap){
			_cap += 8;

			T* new_data = new T[_cap];

			for(u32 i = 0; i < _size; i++){
				new_data[i] = _data[i];
			}

			delete[] _data;

			_data = new_data;
		}

		_data[_size] = t;
		_size += 1;
	}

	inline void remove(const T& t){
		for(u32 i = 0; i < _size; i++){
			if(_data[i] == t){



			}
		}
	}





};






