function solution(s) {
  arr = new Array('z'.codePointAt() - 'a'.codePointAt() + 1);
  arr.fill(0);
  for (c of s) {
    arr[c.codePointAt() - 'a'.codePointAt()]++;
  }
  return arr
    .map((v, i) => {
      if (v === 1) return String.fromCharCode(i + 'a'.codePointAt());
    })
    .filter((v) => v)
    .join('');
}

/*
function solution(s) {
  let res = [];
  for (let c of s) if (s.indexOf(c) === s.lastIndexOf(c)) res.push(c);
  return res.sort().join('');
}
*/
