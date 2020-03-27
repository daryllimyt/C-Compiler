int f1(int y){
  return y;
}

int f2(int i){
  return i;
}

int fmain(){
  int i = f2(f1(1));
  return i;
}





