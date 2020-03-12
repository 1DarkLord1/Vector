namespace my_vector {

template <typename T>
std::size_t my_vector<T>::size() const {
	return size_;
}

template <typename T>
std::size_t my_vector<T>::capacity() const {
	return capacity_;
}

template <typename T>
bool my_vector<T>::empty() const {
	return size_ == 0;
}

template <typename T>
void my_vector<T>::pop_back() {
	if(size_ == 0) {
		return;
	}
	size_--;
	array_[size_].~T();
}

template <typename T>
void my_vector<T>::init_default(std::size_t l, std::size_t r) {
	if(r < l) {
		return;
	}
	for(std::size_t i = l; i < r; i++) {
		new (&array_[i]) T();
	}
}

template <typename T>
void my_vector<T>::pop_under(std::size_t lsize) {
	while(size_ != lsize) {
		pop_back();
	}
}

template <typename T>
void my_vector<T>::resize(std::size_t n) {
	if(size_ <= n) {
		reserve(n);
		init_default(size_, n);   
		size_ = n;
	}
	else {
		pop_under(n);
	}
}

template <typename T>
void my_vector<T>::clear() {
	pop_under(0);
}

template <typename T>
void my_vector<T>::free() {
	if(capacity_ == 0) {
		return;
	}
	clear();
	delete [] (uint8_t*)array_;
	array_ = nullptr;
	capacity_ = 0;
}

template <typename T>
my_vector<T>::~my_vector() {
	free();
}

template <typename T>
void my_vector<T>::array_copy(T*& dest) const {
	for(std::size_t i = 0; i < size_; i++) {
		new (&dest[i]) T(array_[i]);
	}
}

template <typename T>
std::size_t my_vector<T>::new_capacity(std::size_t n) const {
	std::size_t new_capacity_ = 1;
	while(new_capacity_ < n) {
		new_capacity_ <<= 1;
	}
	return new_capacity_;
}

template <typename T>
void my_vector<T>::reserve(std::size_t n) {
	if(capacity_ >= n || n == 0) {
		return;
	}
	size_t new_capacity_ = new_capacity(n);
	if(array_ != nullptr) {
		T* new_array = (T*)new uint8_t[new_capacity_ * sizeof(T)];
		array_copy(new_array);
		size_t old_size = size_;
		free();
		array_ = new_array;
		size_ = old_size;
	}
	else {
		array_ = (T*)new uint8_t[new_capacity_ * sizeof(T)];
	}
	capacity_ = new_capacity_;
}

template <typename T>
void my_vector<T>::push_back(const T& t) {
	if(size_ >= capacity_) {
		reserve((size_ == 0 ? 1: 2 * size_));
	}
	new (&array_[size_]) T(t);
	size_++;
}

template <typename T>
my_vector<T>::my_vector(): capacity_(0), size_(0), array_(nullptr) {}

template <typename T>
my_vector<T>::my_vector(std::size_t n): my_vector() {
	resize(n);
}

template <typename T>
my_vector<T>& my_vector<T>::operator=(const my_vector<T>& other) {
	free();
	size_ = other.size_;
	reserve(other.capacity());
	other.array_copy(array_);
	return *this;
}

template <typename T>
my_vector<T>::my_vector(const my_vector<T>& other): my_vector() {	
	*this = other;
}

template <typename T>
T& my_vector<T>::operator[](std::size_t index) {
	return array_[index];
}

template <typename T>
const T& my_vector<T>::operator[](std::size_t index) const {
	return array_[index];
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const my_vector<T>& vec) {
	for(std::size_t i = 0; i < vec.size(); i++) {
		if(i != 0) {
			os << ' ';
		}
		os << vec[i];
	}
	return os;
}
}

