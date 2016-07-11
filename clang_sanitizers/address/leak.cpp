int main()
{
  int * array = new int[5];
  array = new int[10];
  delete [] array;
  return 0;
}
