function solution(a, b, c) {
  arrCur = [
    0,
    a + b + c,
    (a + b + c) * (Math.pow(a, 2) + Math.pow(c, 2) + Math.pow(b, 2)),
    (a + b + c) *
      (Math.pow(a, 2) + Math.pow(c, 2) + Math.pow(b, 2)) *
      (Math.pow(a, 3) + Math.pow(c, 3) + Math.pow(b, 3)),
  ];
  arr = [0, 0, 0, 0, 0, 0, 0];
  arr[a]++;
  arr[b]++;
  arr[c]++;

  return arrCur[Math.max(...arr)];
}
/*
function solution(a, b, c) {
  setSize = new Set([a, b, c]).size;
  arr = [
    0,
    (a + b + c),
    (a + b + c) * (a**2 + c**2 + b**2),
    (a + b + c) * (a**2 + c**2 + b**2) * (a**3 + c**3 + b**3)
  ];

  return arr[setSize];
}
*/
