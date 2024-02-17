/* 다른사람 풀이
function solution(num_list) {
    return num_list.map(v => v.toString(2).length - 1).reduce((a, c) => a + c);
}
*/

function solution(num_list) {
  let n = 0;
  num_list.map((x) => {
    while (x !== 1) {
      switch (x % 2) {
        case 0:
          x /= 2;
          break;
        case 1:
          x = (x - 1) / 2;
      }
      n++;
    }
  });
  return n;
}
