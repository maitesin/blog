struct my_struct {
  int x;
  void value();
};

void my_struct::value() {
  [=, *this](){};
}

