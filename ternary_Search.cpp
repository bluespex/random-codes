//ternary search on integer / array
while (L + 3 < R) {
  int M1 = (2*L + R) / 3;
  int M2 = (L + 2*R) / 3;
  if (a[M1] <= a[M2]) R = M2;
  else L = M1;
}
int mn = a[L++];
while (L <= R) mn = min(mn, a[L++]);
return mn;


//ternary search on real numbers
while (R - L > EPS) {
  double M1 = (2*L + R) / 3;
  double M2 = (L + 2*R) / 3;
  if (f(M1) <= f(M2)) R = M2;
  else L = M1;
}
return f(L);