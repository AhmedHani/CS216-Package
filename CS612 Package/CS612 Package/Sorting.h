#ifndef SORT_H
#define SORT_H

template <class T>
class Sort {

private:
	T data_size;
	T* data;

public:
	Sort(T* data, T data_size) {
		this->data = data;
		this->data_size = data_size;
	}

	void bubble_sort();
	//T* selection_sort();
	//T* insertion_sort();

	//T* get_data() { return data; }
	//T get_data_size() { return data_size; } 
};


#endif