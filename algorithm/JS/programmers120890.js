function solution(array, n) {
  array.push(n);
  let idx = array.sort((a, b) => a - b).indexOf(n);
  if (idx === 0) return array[idx + 1];
  return n - array[idx - 1] > array[idx + 1] - n
    ? array[idx + 1]
    : array[idx - 1];
}

/*
다른사람 풀이
function solution(array, n) {
  array.sort((a,b) => Math.abs(n - a) - Math.abs(n - b) || a - b);

  return array[0];
}
*/
