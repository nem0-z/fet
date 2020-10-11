namespace V12 {

template <typename T>
void Lista<T>::push_back(T val) {
  auto newNode = new Node();
  newNode->value = val;
  newNode->next = nullptr;
  if (poc_ == nullptr) {
    poc_ = newNode;
  } else {
    auto it = poc_;
    while (it->next != nullptr) {
      it = it->next;
    }
    it->next = newNode;
  }
}

template <typename T>
void Lista<T>::print() const {
  auto it = poc_;
  while (it != nullptr) {
    std::cout << it->value << std::endl;
    it = it->next;
  }
}

template <typename T>
void Lista<T>::copy(const Lista<T>& other) {
  auto it = other.poc_;
  while (it != nullptr) {
    push_back(it->value);
    it = it->next;
  }
}

template <typename T>
template <typename A>
void Lista<T>::copy(const std::vector<A>& other) {
  // auto it = other.poc_;
  // while (it != nullptr) {
  //   push_back(it->value);
  //   it = it->next;
  // } redo this
}

template <typename T>
Lista<T>::Lista(const Lista<T>& other) {
  copy(other);
}

template <typename T>
Lista<T>::Lista(Lista<T>&& other) : poc_{other.poc_} {
  other.poc_ = nullptr;
}

template <typename T>
Lista<T>& Lista<T>::operator=(const Lista<T>& other) {
  destroy();
  copy(other);
  return *this;
}

template <typename T>
Lista<T>& Lista<T>::operator=(Lista<T>&& other) {
  destroy();
  poc_ = other.poc_;
  other.poc_ = nullptr;
  return *this;
}

template <typename T>
void Lista<T>::destroy() {
  auto pom = poc_;
  while (pom != nullptr) {
    auto next = pom->next;
    delete pom;
    pom = next;
  }
  poc_ = nullptr;
}

template <typename T>
template <typename A>
Lista<T>& Lista<T>::operator=(const std::vector<A>& vec) {
  for(int i = 0; i<vec.size();){
    push_back(vec[i]);
    ++i;
  }
    return *this;
  }

  template <typename T>
  template <typename A>
  Lista<T> Lista<T>::operator+(const std::vector<A>& vec) const {
    Lista tmp;
  }

}  // namespace V12

