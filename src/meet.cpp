void append(int*& arr, int& size, int& capacity, int value) {
   if (size == capacity) {
      int newCap = capacity * 2;
      int* newArr = new int[newCap];
      for (int i = 0; i < size; i++) {
         newArr[i] = arr[i];
      }
      delete[] arr;
      arr = newArr;
      capacity = newCap;
   }
   arr[size] = value;
   size++;
}