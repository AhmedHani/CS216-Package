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

	T* merge_sort(T begin, T end) {
		if (begin == end)
			return 0;

		T mid = (begin + end) / 2;
		merge_sort(begin, mid);
		merge_sort(mid + 1, end);

		T i = begin;
		T j = mid + 1;
		T array_length = end - begin + 1;
		T* temp = new T[array_length];

		for (size_t it = 0; it < array_length; it++) {
			if (j > end || (i <= mid && this->data[i] < this->data[j])) {
				temp[it] = this->data[i];
				i++;
			} else {
				temp[it] = this->data[j];
				j++;
			}
		}

		for (size_t it = 0, i = begin; it < array_length; it++, i++) {
			this->data[i] = temp[it];
		}

		return this->data;
	}

	int partition(int start, int end, int pivot) {
		int left = start - 1;
		int right= end;

		while(true) {
			while(this->data[++left] < pivot) {

			}

			while(right > 0 && this->data[--right] > pivot) {

			}

			if (left >= right) {
				break;
			} else {
				swap(this->data[left], this->data[right]);
			}
		}

		swap(this->data[left], this->data[end]);

		return left;
	}

	T* quick_sort(int start, int end) {
		if (end - start <= 0) {
			return 0;
		} else {
			int pivot = this->data[end];
			int partition_index = partition(start, end, pivot);

			quick_sort(start, partition_index - 1);
			quick_sort(partition_index + 1, end);
		}

		return this->data;
	}
};


