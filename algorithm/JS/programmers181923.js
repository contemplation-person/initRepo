function solution(arr, queries) {
  let answer = [];
  queries.map((x) => {
    let sliceArr = arr.slice(x[0], x[1] + 1);
    let min = 1000000;
    for (i of sliceArr) {
      if (i > x[2] && min > i) min = i;
    }
    if (min == 1000000) min = -1;
    answer.push(min);
  });
  return answer;
}

/*
// 다른 사람 풀이
function solution(arr, queries) {
  return queries.map(
    ([s, e, k]) =>
      arr
        .slice(s, e + 1)
        .filter((n) => n > k)
        .sort((a, b) => a - b)[0] || -1
  );
}
*/
