int must_return_value()
{
  int result = 0;
  result += 1;
}

int main()
{
  int value = must_return_value();
  return value;
}
