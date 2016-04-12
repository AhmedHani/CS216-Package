using namespace std;

template <class T>
class Sort {
private:
	T* data;
	size_t data_size;

public:
	Sort(T data[], size_t data_size) {
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

	T* selection_sort() {
		T* sorted_list = this->data;

		for (size_t i = 0; i < this->data_size - 1; i++) {
			int current_min_index = i;

			for (size_t j = i + 1; j < this->data_size; j++) {
				if (sorted_list[j] < sorted_list[current_min_index]) {
					current_min_index = j;
				}
			}

			if (current_min_index != i) {
				T temp = sorted_list[i];
				sorted_list[i] = sorted_list[current_min_index];
				sorted_list[current_min_index] = temp;
			}
		}

		return sorted_list;
	}

	T* insertion_sort() {
		T* sorted_list = this->data;

		for (int i = 1; i < this->data_size; i++) {
			T current = sorted_list[i];
			int prev = i - 1;

			while (prev >= 0 && sorted_list[prev] > current) {
				sorted_list[prev + 1] = sorted_list[prev];
				prev -= 1;
			}

			sorted_list[prev + 1] = current;
		}

		return sorted_list;
	}

};


