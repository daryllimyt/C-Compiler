int f1(int y){
  return y;
}

int f2(int i, int j){
  return i + j;
}

int fmain(){
  int i = f2(f1(1), 0);
  return i;
}





