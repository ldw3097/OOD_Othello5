#ifndef PRINT_H
#define PRINT_H


class Print_table {
 public:
  Print_table(int** table, int x, int y);
  static Print_table* GetInstance(int** table, int x, int y);
  const void Print() const;
 private:
  int** table_;
  int x_;
  int y_;
  static Print_table* instance_;
};

#endif  // PRINT_H