int main()
{
  int * array = new int[5];
  delete [] array;
  delete [] array;
  return 0;
}
