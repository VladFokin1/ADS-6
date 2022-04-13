// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

struct SYM {
  char ch;
  int prior;
};

template<class T, int size>
class TPQueue {
 private:
     struct SYM arr[size];
     int count = 0;
 public:
     void push(SYM x) {
         if (count < size) {
             for (int i = count++; i >= 0; i--) {
                 if (x.prior <= arr[i - 1].prior && i > 0) {
                     arr[i] = arr[i - 1];
                 } else {
                     arr[i] = x;
                     break;
                 }
             }
         }
     }
     SYM pop() {
       if (count > 0) {
           return arr[--count];
       } else {
           throw "ERROR!!!";
       }
     }
};


#endif  // INCLUDE_TPQUEUE_H_
