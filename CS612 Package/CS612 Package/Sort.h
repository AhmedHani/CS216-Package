using namespace std;

template <class T>
class Sort {
private:
	T* data;
	T data_size;

public:
	Sort(T data[], T data_size) {
		this->data = data;
		this->data_size = data_size;
	}

	T* bubble_sort() {
		T* sorted_list = this->data;

		for (size_t i = 0; i < this->data_size; i++) {
			for (size_t j = 0; j < this->data_size - 1; j++) {
				if (sorted_list[j] > sorted_list[j + 1]) {
					T temp = sorted_list[j];
					sorted_list[j] = sorted_list[j + 1];
					sorted_list[j + 1] = temp;
				}
			}
		}

		return sorted_list;
	}
};


