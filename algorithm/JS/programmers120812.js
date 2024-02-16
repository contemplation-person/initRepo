let max = {
  num: -1,
  cnt: -1,
  isDuplicate: false,
};

let cmp = {
  num: 0,
  cnt: 0,
};

function solution(array) {
  array.sort((a, b) => a - b);

  array.map((x) => {
    if (cmp.num !== x) {
      if (cmp.cnt > max.cnt) {
        max.num = cmp.num;
        max.cnt = cmp.cnt;
        max.isDuplicate = false;
      } else if (cmp.cnt === max.cnt) max.isDuplicate = true;
      cmp.num = x;
      cmp.cnt = 0;
    }
    cmp.cnt++;
  });
  return max.cnt < cmp.cnt
    ? cmp.num
    : max.num === -1
    ? cmp.num
    : max.cnt === cmp.cnt || max.isDuplicate
    ? -1
    : max.num;
}
